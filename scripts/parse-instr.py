import json
from typing import Match

SPEC = None
with open("third/SPIRV-Headers/include/spirv/unified1/spirv.core.grammar.json") as f:
    SPEC = json.load(f)

KIND2CATEGORY = {}
for operand_kind in SPEC["operand_kinds"]:
    kind = operand_kind["kind"]
    category = operand_kind["category"]
    KIND2CATEGORY[kind] = category

class EnforceLast:
    """
    A marker object to annotate note the generator that the operand should be
    the last one. Any extra operand should trigger an error.
    """
    pass
    def __repr__():
        return ""

def gen_operand_proc(out_path, match_dict):
    FOUND_INSTR = set()

    BODY = [
        "// THIS IS A GENERATED SOURCE. MODIFICATION WILL BE OVERWRITTEN.\n",
        "// @PENGUINLIONG\n",
        "#pragma once\n",
    ]
    BODY += match_dict["include"]
    BODY += [
        '#include "liella/spv-instr.hpp"\n',
        "namespace liella {\n",
        "\n",
    ]
    BODY += match_dict["header"]
    BODY += [
        "  switch (instr.opcode) {\n",
    ]

    for instr in SPEC['instructions']:
        opcode = instr["opcode"]
        opname = instr["opname"]
        if opcode in FOUND_INSTR:
            BODY += [f"  // Ignored alias op {opname}.\n"]
            continue
        FOUND_INSTR.add(opcode)

        if 'operands' not in instr:
            BODY += [f"  case spv::{opname}: break;\n"]
            continue

        BODY += [f"  case spv::{instr['opname']}:\n"]

        uncertain_size = False
        body = []
        for operand in instr['operands']:
            if uncertain_size:
                raise RuntimeError("unexpected params after a context-dependent param")
            body += ["    "]

            if "quantifier" in operand:
                quantifier = operand["quantifier"]
                if quantifier == '*':
                    body += ["while (!it.ate()) "]
                elif quantifier == '?':
                    body += ["if (!it.ate()) "]

            kind = operand['kind']
            category = KIND2CATEGORY[kind]

            if kind in match_dict["kind"]:
                seg = match_dict["kind"][kind]
            elif category in match_dict["category"]:
                seg = match_dict["category"][category]
            else:
                raise RuntimeError("unexpected operand category/kind")

            uncertain_size = uncertain_size or any(type(x) == EnforceLast for x in seg)
            seg = [x for x in seg if type(x) is str]

            body += seg
        body += ["    break;\n"]

        BODY += body

    BODY += [
        "  }\n",
    ]
    BODY += match_dict["footer"]
    BODY += [
        "\n",
        "} // namespace liella\n",
    ]

    with open(out_path, "w") as f:
        f.writelines(BODY)

COLLECT_ID_REFS = {
    "include": ["#include <map>\n"],
    "header": [
        "void parse_instr(\n",
            "  int32_t idx,\n"
            "  const Instruction& instr,\n",
            "  std::map<spv::Id, InstrIdx>& id2idx,\n"
            "  std::map<InstrIdx, std::shared_ptr<Instr>>& idx2instr\n",
        ") {\n",
        "  auto deref = [&](spv::Id id) {\n",
        "    auto it = id2idx.find(id);\n"
        "    return it == id2idx.end() ? nullptr : idx2instr.at(it->second);\n",
        "  };\n",
        "  int32_t result_id = -1;\n"
        "  OperandIterator it = instr.iter();\n",
        "  InstrBuilder ib(instr.opcode);\n",
    ],
    "footer": [
        "  if (result_id >= 0) id2idx[result_id] = idx;\n"
        "  idx2instr[idx] = ib.build();\n"
        "}\n",
    ],
    "kind": {
        "IdResult": ["result_id = it.id();\n"],
        "LiteralString": [
            "{ uint32_t w; while (it.str_u32(w)) ib.push(w); }\n"
        ],
        "PairLiteralIntegerIdRef": [
            "{ ",
            "ib.push(it.u32()); ",
            "ib.push(deref(it.id())); ",
            "}\n",
        ],
        "PairIdRefLiteralInteger": [
            "{ ",
            "ib.push(deref(it.id())); ",
            "ib.push(it.u32()); ",
            "}\n",
        ],
        "PairIdRefIdRef": [
            "{ ",
            "ib.push(deref(it.id())); ",
            "ib.push(deref(it.id())); ",
            "}\n",
        ],
        "LiteralContextDependentNumber": [
            "{ while (!it.ate()) ib.push(it.u32()); }\n",
            EnforceLast()
        ],
    },
    "category": {
        "BitEnum": ["ib.push(it.u32());\n"],
        "ValueEnum": ["ib.push(it.u32());\n"],
        "Id": ["ib.push(deref(it.id()));\n"],
        "Literal": ["ib.push(it.u32());\n"],
    },
}

gen_operand_proc("include/liella/parse-instr.hpp", COLLECT_ID_REFS)
