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
    "include": [],
    "header": [
        "std::vector<spv::Id> collect_id_refs(const Instruction& instr) {\n",
        "  OperandIterator it = instr.iter();\n",
        "  std::vector<spv::Id> out;\n",
    ],
    "footer": [
        "  return out;\n"
        "}\n",
    ],
    "kind": {
        "IdResult": ["it.id();\n"],
        "LiteralString": ["it.str();\n"],
        "PairLiteralIntegerIdRef": [
            "{ ",
            "it.u32(); ",
            "out.emplace_back(it.id()); ",
            "}\n",
        ],
        "PairIdRefLiteralInteger": [
            "{ ",
            "out.emplace_back(it.id()); ",
            "it.u32(); ",
            "}\n",
        ],
        "PairIdRefIdRef": [
            "{ ",
            "out.emplace_back(it.id()); ",
            "out.emplace_back(it.id()); ",
            "}\n",
        ],
        "LiteralContextDependentNumber": [EnforceLast()],
    },
    "category": {
        "BitEnum": ["it.u32();\n"],
        "ValueEnum": ["it.u32();\n"],
        "Id": ["out.emplace_back(it.id());\n"],
        "Literal": ["it.u32();\n"],
    },
}

gen_operand_proc("include/liella/collect-id-refs.hpp", COLLECT_ID_REFS)

HASH_INSTR = {
    "include": [
        '#include "liella/fnv.hpp"\n',
    ],
    "header": [
        "void hash_instr(Fnv& hasher, const Instruction& instr) {\n",
        "  OperandIterator it = instr.iter();\n",
        "  hasher.feed(instr.opcode);\n"
    ],
    "footer": [
        "}\n",
    ],
    "kind": {
        # A zero is hashed to keep track of optional id operands.
        "IdResult": ["it.id(); hasher.feed(0);\n"],
        "LiteralString": [
            "{ ",
            "const char* str = it.str(); "
            "hasher.feed(str, strlen(str)); "
            "}\n"
        ],
        "PairLiteralIntegerIdRef": [
            "{ ",
            "hasher.feed(it.u32()); ",
            "it.id(); hasher.feed(0); ",
            "}\n",
        ],
        "PairIdRefLiteralInteger": [
            "{ ",
            "it.id(); hasher.feed(0); ",
            "hasher.feed(it.u32()); ",
            "}\n",
        ],
        "PairIdRefIdRef": [
            "{ ",
            "it.id(); hasher.feed(0); ",
            "it.id(); hasher.feed(0); ",
            "}\n",
        ],
        "LiteralContextDependentNumber": [
            "while (!it.ate()) hasher.feed(it.u32());\n",
            EnforceLast()
        ],
    },
    "category": {
        "BitEnum": ["hasher.feed(it.u32());\n"],
        "ValueEnum": ["hasher.feed(it.u32());\n"],
        "Id": ["it.id(); hasher.feed(0);\n"],
        "Literal": ["hasher.feed(it.u32());\n"],
    },
}

gen_operand_proc("include/liella/hash-instr.hpp", HASH_INSTR)
