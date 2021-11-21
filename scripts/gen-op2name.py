import json
from typing import Match

SPEC = None
with open("third/SPIRV-Headers/include/spirv/unified1/spirv.core.grammar.json") as f:
    SPEC = json.load(f)

FOUND_INSTR = set()

BODY = [
    "// THIS IS A GENERATED SOURCE. MODIFICATION WILL BE OVERWRITTEN.\n",
    "// @PENGUINLIONG\n",
    "#pragma once\n",
]
BODY += [
    '#include "liella/spv-instr.hpp"\n',
    "namespace liella {\n",
    "\n",
    "const char* op2name(spv::Op op) {\n",
    "  switch (op) {\n",
]

for instr in SPEC['instructions']:
    opcode = instr["opcode"]
    opname = instr["opname"]
    if opcode in FOUND_INSTR:
        BODY += [f"  // Ignored alias op {opname}.\n"]
        continue
    FOUND_INSTR.add(opcode)
    BODY += [f'  case spv::{opname}: return "{opname[2:]}";\n']

BODY += [
    '  default: return "UNKNOWN";\n',
    "  }\n",
    "}\n",
    "\n",
    "} // namespace liella\n",
]

with open("include/liella/op2name.hpp", "w") as f:
    f.writelines(BODY)
