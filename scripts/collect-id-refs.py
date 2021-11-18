import json

SPEC = None
with open("third/SPIRV-Headers/include/spirv/unified1/spirv.core.grammar.json") as f:
    SPEC = json.load(f)

KIND2CATEGORY = {}
for operand_kind in SPEC["operand_kinds"]:
    kind = operand_kind["kind"]
    category = operand_kind["category"]
    KIND2CATEGORY[kind] = category

BODY = [
    "// THIS IS A GENERATED SOURCE. MODIFICATION WILL BE OVERWRITTEN.\n",
    "// @PENGUINLIONG\n",
    "#pragma once\n",
    '#include "liella/spv-instr.hpp"\n',
    "namespace liella {\n",
    "\n",
    "std::vector<spv::Id> collect_id_refs(const Instruction& instr) {\n",
    "  OperandIterator it = instr.iter();\n",
    "  std::vector<spv::Id> out;\n",
    "  switch (instr.opcode) {\n",
]
FOUND_INSTR = set()
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
        if category == "BitEnum" or category == "ValueEnum":
            body += ["it.u32();\n"]
        elif category == "Id":
            if kind == "IdResult":
                body += ["it.id();\n"]
            else:
                body += ["out.emplace_back(it.id());\n"]
        elif category == "Literal":
            if kind == "LiteralContextDependentNumber":
                # Context dependent literals usually only appear at the end of
                # literals.
                uncertain_size = True
            elif kind == "LiteralString":
                body += ["it.str();\n"]
            else:
                body += ["it.u32();\n"]
        elif category == "Composite":
            if kind == "PairLiteralIntegerIdRef":
                body += [
                    "{ ",
                    "it.u32(); ",
                    "out.emplace_back(it.id()); ",
                    "}\n",
                ]
            elif kind == "PairIdRefLiteralInteger":
                body += [
                    "{ ",
                    "out.emplace_back(it.id()); ",
                    "it.u32(); ",
                    "}\n",
                ]
            elif kind == "PairIdRefIdRef":
                body += [
                    "{ ",
                    "out.emplace_back(it.id()); ",
                    "out.emplace_back(it.id()); ",
                    "}\n",
                ]
            else:
                raise RuntimeError("unexpected composite operand kind")
    body += ["    break;\n"]

    BODY += body

BODY += [
    "  }\n",
    "  return out;\n"
    "}\n",
    "\n",
    "} // namespace liella\n",
]

with open("include/liella/collect-id-refs.hpp", "w") as f:
    f.writelines(BODY)
