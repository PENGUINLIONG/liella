// THIS IS A GENERATED SOURCE. MODIFICATION WILL BE OVERWRITTEN.
// @PENGUINLIONG
#pragma once
#include <map>
#include "liella/spv-instr.hpp"
namespace liella {

void parse_instr(
  int32_t idx,
  const Instruction& instr,
  std::map<spv::Id, InstrIdx>& id2idx,
  std::map<InstrIdx, std::shared_ptr<Instr>>& idx2instr
) {
  auto deref = [&](spv::Id id) {
    auto it = id2idx.find(id);
    return it == id2idx.end() ? nullptr : idx2instr.at(it->second);
  };
  int32_t result_id = -1;
  OperandIterator it = instr.iter();
  InstrBuilder ib(instr.opcode);
  switch (instr.opcode) {
  case spv::OpNop: break;
  case spv::OpUndef:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSourceContinued:
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpSource:
    ib.push(it.u32());
    ib.push(it.u32());
    if (!it.ate()) ib.push(deref(it.id()));
    if (!it.ate()) { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpSourceExtension:
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpName:
    ib.push(deref(it.id()));
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpMemberName:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpString:
    result_id = it.id();
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpLine:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpExtension:
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpExtInstImport:
    result_id = it.id();
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpExtInst:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpMemoryModel:
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpEntryPoint:
    ib.push(it.u32());
    ib.push(deref(it.id()));
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpExecutionMode:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpCapability:
    ib.push(it.u32());
    break;
  case spv::OpTypeVoid:
    result_id = it.id();
    break;
  case spv::OpTypeBool:
    result_id = it.id();
    break;
  case spv::OpTypeInt:
    result_id = it.id();
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpTypeFloat:
    result_id = it.id();
    ib.push(it.u32());
    break;
  case spv::OpTypeVector:
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpTypeMatrix:
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpTypeImage:
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpTypeSampler:
    result_id = it.id();
    break;
  case spv::OpTypeSampledImage:
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeArray:
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeRuntimeArray:
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeStruct:
    result_id = it.id();
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpTypeOpaque:
    result_id = it.id();
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpTypePointer:
    result_id = it.id();
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeFunction:
    result_id = it.id();
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpTypeEvent:
    result_id = it.id();
    break;
  case spv::OpTypeDeviceEvent:
    result_id = it.id();
    break;
  case spv::OpTypeReserveId:
    result_id = it.id();
    break;
  case spv::OpTypeQueue:
    result_id = it.id();
    break;
  case spv::OpTypePipe:
    result_id = it.id();
    ib.push(it.u32());
    break;
  case spv::OpTypeForwardPointer:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpConstantTrue:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpConstantFalse:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpConstant:
    ib.push(deref(it.id()));
    result_id = it.id();
    { while (!it.ate()) ib.push(it.u32()); }
    break;
  case spv::OpConstantComposite:
    ib.push(deref(it.id()));
    result_id = it.id();
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpConstantSampler:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpConstantNull:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSpecConstantTrue:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSpecConstantFalse:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSpecConstant:
    ib.push(deref(it.id()));
    result_id = it.id();
    { while (!it.ate()) ib.push(it.u32()); }
    break;
  case spv::OpSpecConstantComposite:
    ib.push(deref(it.id()));
    result_id = it.id();
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpSpecConstantOp:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(it.u32());
    break;
  case spv::OpFunction:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpFunctionParameter:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpFunctionEnd: break;
  case spv::OpFunctionCall:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpVariable:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(it.u32());
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpImageTexelPointer:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpLoad:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpStore:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpCopyMemory:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpCopyMemorySized:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpAccessChain:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpInBoundsAccessChain:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpPtrAccessChain:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpArrayLength:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpGenericPtrMemSemantics:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpInBoundsPtrAccessChain:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpDecorate:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpMemberDecorate:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpDecorationGroup:
    result_id = it.id();
    break;
  case spv::OpGroupDecorate:
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupMemberDecorate:
    ib.push(deref(it.id()));
    while (!it.ate()) { ib.push(deref(it.id())); ib.push(it.u32()); }
    break;
  case spv::OpVectorExtractDynamic:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpVectorInsertDynamic:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpVectorShuffle:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpCompositeConstruct:
    ib.push(deref(it.id()));
    result_id = it.id();
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpCompositeExtract:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpCompositeInsert:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpCopyObject:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpTranspose:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSampledImage:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpImageSampleImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSampleExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageSampleDrefImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSampleDrefExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageSampleProjImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSampleProjExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageSampleProjDrefImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSampleProjDrefExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageFetch:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageGather:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageDrefGather:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageRead:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageWrite:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImage:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpImageQueryFormat:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpImageQueryOrder:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpImageQuerySizeLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpImageQuerySize:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpImageQueryLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpImageQueryLevels:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpImageQuerySamples:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertFToU:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertFToS:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertSToF:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertUToF:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpUConvert:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSConvert:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpFConvert:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpQuantizeToF16:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertPtrToU:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSatConvertSToU:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSatConvertUToS:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertUToPtr:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpPtrCastToGeneric:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpGenericCastToPtr:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpGenericCastToPtrExplicit:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpBitcast:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSNegate:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpFNegate:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpIAdd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFAdd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpISub:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFSub:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIMul:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFMul:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUDiv:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSDiv:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFDiv:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUMod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSRem:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSMod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFRem:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFMod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpVectorTimesScalar:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpMatrixTimesScalar:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpVectorTimesMatrix:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpMatrixTimesVector:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpMatrixTimesMatrix:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpOuterProduct:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpDot:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIAddCarry:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpISubBorrow:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUMulExtended:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSMulExtended:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAny:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpAll:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpIsNan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpIsInf:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpIsFinite:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpIsNormal:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSignBitSet:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpLessOrGreater:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpOrdered:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUnordered:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpLogicalEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpLogicalNotEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpLogicalOr:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpLogicalAnd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpLogicalNot:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSelect:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpINotEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUGreaterThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSGreaterThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUGreaterThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSGreaterThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpULessThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSLessThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpULessThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSLessThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFOrdEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFUnordEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFOrdNotEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFUnordNotEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFOrdLessThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFUnordLessThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFOrdGreaterThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFUnordGreaterThan:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFOrdLessThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFUnordLessThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFOrdGreaterThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFUnordGreaterThanEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpShiftRightLogical:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpShiftRightArithmetic:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpShiftLeftLogical:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpBitwiseOr:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpBitwiseXor:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpBitwiseAnd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpNot:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpBitFieldInsert:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpBitFieldSExtract:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpBitFieldUExtract:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpBitReverse:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpBitCount:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpDPdx:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpDPdy:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpFwidth:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpDPdxFine:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpDPdyFine:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpFwidthFine:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpDPdxCoarse:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpDPdyCoarse:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpFwidthCoarse:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpEmitVertex: break;
  case spv::OpEndPrimitive: break;
  case spv::OpEmitStreamVertex:
    ib.push(deref(it.id()));
    break;
  case spv::OpEndStreamPrimitive:
    ib.push(deref(it.id()));
    break;
  case spv::OpControlBarrier:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpMemoryBarrier:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicLoad:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicStore:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicExchange:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicCompareExchange:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicCompareExchangeWeak:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicIIncrement:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicIDecrement:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicIAdd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicISub:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicSMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicUMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicSMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicUMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicAnd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicOr:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicXor:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpPhi:
    ib.push(deref(it.id()));
    result_id = it.id();
    while (!it.ate()) { ib.push(deref(it.id())); ib.push(deref(it.id())); }
    break;
  case spv::OpLoopMerge:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpSelectionMerge:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpLabel:
    result_id = it.id();
    break;
  case spv::OpBranch:
    ib.push(deref(it.id()));
    break;
  case spv::OpBranchConditional:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpSwitch:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    while (!it.ate()) { ib.push(it.u32()); ib.push(deref(it.id())); }
    break;
  case spv::OpKill: break;
  case spv::OpReturn: break;
  case spv::OpReturnValue:
    ib.push(deref(it.id()));
    break;
  case spv::OpUnreachable: break;
  case spv::OpLifetimeStart:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpLifetimeStop:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpGroupAsyncCopy:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupWaitEvents:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupAll:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupAny:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupBroadcast:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupIAdd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupFAdd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupFMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupUMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupSMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupFMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupUMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupSMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpReadPipe:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpWritePipe:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpReservedReadPipe:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpReservedWritePipe:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpReserveReadPipePackets:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpReserveWritePipePackets:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpCommitReadPipe:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpCommitWritePipe:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIsValidReserveId:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpGetNumPipePackets:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGetMaxPipePackets:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupReserveReadPipePackets:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupReserveWritePipePackets:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupCommitReadPipe:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupCommitWritePipe:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpEnqueueMarker:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpEnqueueKernel:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGetKernelNDrangeSubGroupCount:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGetKernelNDrangeMaxSubGroupSize:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGetKernelWorkGroupSize:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGetKernelPreferredWorkGroupSizeMultiple:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRetainEvent:
    ib.push(deref(it.id()));
    break;
  case spv::OpReleaseEvent:
    ib.push(deref(it.id()));
    break;
  case spv::OpCreateUserEvent:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpIsValidEvent:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSetUserEventStatus:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpCaptureEventProfilingInfo:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGetDefaultQueue:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpBuildNDRange:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpImageSparseSampleImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSparseSampleExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageSparseSampleDrefImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSparseSampleDrefExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageSparseSampleProjImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSparseSampleProjExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageSparseSampleProjDrefImplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSparseSampleProjDrefExplicitLod:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpImageSparseFetch:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSparseGather:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSparseDrefGather:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpImageSparseTexelsResident:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpNoLine: break;
  case spv::OpAtomicFlagTestAndSet:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicFlagClear:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpImageSparseRead:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpSizeOf:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpTypePipeStorage:
    result_id = it.id();
    break;
  case spv::OpConstantPipeStorage:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpCreatePipeFromPipeStorage:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpGetKernelLocalSizeForSubgroupCount:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGetKernelMaxNumSubgroups:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeNamedBarrier:
    result_id = it.id();
    break;
  case spv::OpNamedBarrierInitialize:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpMemoryNamedBarrier:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpModuleProcessed:
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpExecutionModeId:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpDecorateId:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpGroupNonUniformElect:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformAll:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformAny:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformAllEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBroadcast:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBroadcastFirst:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBallot:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformInverseBallot:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBallotBitExtract:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBallotBitCount:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBallotFindLSB:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBallotFindMSB:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformShuffle:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformShuffleXor:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformShuffleUp:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformShuffleDown:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformIAdd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformFAdd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformIMul:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformFMul:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformSMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformUMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformFMin:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformSMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformUMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformFMax:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBitwiseAnd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBitwiseOr:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformBitwiseXor:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformLogicalAnd:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformLogicalOr:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformLogicalXor:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformQuadBroadcast:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupNonUniformQuadSwap:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpCopyLogical:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpPtrEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpPtrNotEqual:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpPtrDiff:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTerminateInvocation: break;
  case spv::OpSubgroupBallotKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupFirstInvocationKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAllKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAnyKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAllEqualKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupReadInvocationKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTraceRayKHR:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpExecuteCallableKHR:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertUToAccelerationStructureKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpIgnoreIntersectionKHR: break;
  case spv::OpTerminateRayKHR: break;
  case spv::OpSDotKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpUDotKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpSUDotKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpSDotAccSatKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpUDotAccSatKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpSUDotAccSatKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpTypeRayQueryKHR:
    result_id = it.id();
    break;
  case spv::OpRayQueryInitializeKHR:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryTerminateKHR:
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGenerateIntersectionKHR:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryConfirmIntersectionKHR:
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryProceedKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionTypeKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupIAddNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupFAddNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupFMinNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupUMinNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupSMinNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupFMaxNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupUMaxNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpGroupSMaxNonUniformAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    break;
  case spv::OpFragmentMaskFetchAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFragmentFetchAMD:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpReadClockKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpImageSampleFootprintNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpGroupNonUniformPartitionNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpWritePackedPrimitiveIndices4x8NV:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpReportIntersectionNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  // Ignored alias op OpReportIntersectionKHR.
  case spv::OpIgnoreIntersectionNV: break;
  case spv::OpTerminateRayNV: break;
  case spv::OpTraceNV:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTraceMotionNV:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTraceRayMotionNV:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeAccelerationStructureNV:
    result_id = it.id();
    break;
  // Ignored alias op OpTypeAccelerationStructureKHR.
  case spv::OpExecuteCallableNV:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeCooperativeMatrixNV:
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpCooperativeMatrixLoadNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpCooperativeMatrixStoreNV:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    if (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpCooperativeMatrixMulAddNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpCooperativeMatrixLengthNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpBeginInvocationInterlockEXT: break;
  case spv::OpEndInvocationInterlockEXT: break;
  case spv::OpDemoteToHelperInvocationEXT: break;
  case spv::OpIsHelperInvocationEXT:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpConvertUToImageNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertUToSamplerNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertImageToUNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertSamplerToUNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertUToSampledImageNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpConvertSampledImageToUNV:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSamplerImageAddressingModeNV:
    ib.push(it.u32());
    break;
  case spv::OpSubgroupShuffleINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupShuffleDownINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupShuffleUpINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupShuffleXorINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupBlockReadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupBlockWriteINTEL:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupImageBlockReadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupImageBlockWriteINTEL:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupImageMediaBlockReadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupImageMediaBlockWriteINTEL:
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUCountLeadingZerosINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpUCountTrailingZerosINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpAbsISubINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAbsUSubINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIAddSatINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUAddSatINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIAverageINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUAverageINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIAverageRoundedINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUAverageRoundedINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpISubSatINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUSubSatINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpIMul32x16INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpUMul32x16INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpConstantFunctionPointerINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpFunctionPointerCallINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpAsmTargetINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpAsmINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    { uint32_t w; while (it.str_u32(w)) ib.push(w); }
    break;
  case spv::OpAsmCallINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpAtomicFMinEXT:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicFMaxEXT:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAssumeTrueKHR:
    ib.push(deref(it.id()));
    break;
  case spv::OpExpectKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpDecorateString:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  // Ignored alias op OpDecorateStringGOOGLE.
  case spv::OpMemberDecorateString:
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  // Ignored alias op OpMemberDecorateStringGOOGLE.
  case spv::OpVmeImageINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeVmeImageINTEL:
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeAvcImePayloadINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcRefPayloadINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcSicPayloadINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcMcePayloadINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcMceResultINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcImeResultINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcImeResultSingleReferenceStreamoutINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcImeResultDualReferenceStreamoutINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcImeSingleReferenceStreaminINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcImeDualReferenceStreaminINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcRefResultINTEL:
    result_id = it.id();
    break;
  case spv::OpTypeAvcSicResultINTEL:
    result_id = it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceSetInterShapePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceSetInterDirectionPenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpSubgroupAvcMceSetAcOnlyHaarINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceConvertToImePayloadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceConvertToImeResultINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceConvertToRefPayloadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceConvertToRefResultINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceConvertToSicPayloadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceConvertToSicResultINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetMotionVectorsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetInterDistortionsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetBestInterDistortionsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetInterMajorShapeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetInterMinorShapeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetInterDirectionsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetInterMotionVectorCountINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetInterReferenceIdsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeInitializeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeSetSingleReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeSetDualReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeRefWindowSizeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeAdjustRefOffsetINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeConvertToMcePayloadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeSetMaxMotionVectorCountINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeSetWeightedSadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeConvertToMceResultINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetSingleReferenceStreaminINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetDualReferenceStreaminINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeStripDualReferenceStreamoutINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetBorderReachedINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcFmeInitializeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcBmeInitializeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefConvertToMcePayloadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefSetBidirectionalMixDisableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefSetBilinearFilterEnableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefEvaluateWithDualReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcRefConvertToMceResultINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicInitializeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicConfigureSkcINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicConfigureIpeLumaINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicConfigureIpeLumaChromaINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetMotionVectorMaskINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicConvertToMcePayloadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicSetBilinearFilterEnableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicEvaluateIpeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicEvaluateWithDualReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicConvertToMceResultINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetIpeLumaShapeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetPackedIpeLumaModesINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetIpeChromaModeINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSubgroupAvcSicGetInterRawSadsINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpVariableLengthArrayINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpSaveMemoryINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    break;
  case spv::OpRestoreMemoryINTEL:
    ib.push(deref(it.id()));
    break;
  case spv::OpArbitraryFloatSinCosPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatCastINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatCastFromIntINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatCastToIntINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatAddINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatSubINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatMulINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatDivINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatGTINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatGEINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatLTINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatLEINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatEQINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatRecipINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatRSqrtINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatCbrtINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatHypotINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatSqrtINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatLogINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatLog2INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatLog10INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatLog1pINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatExpINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatExp2INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatExp10INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatExpm1INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatSinINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatCosINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatSinCosINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatSinPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatCosPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatASinINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatASinPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatACosINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatACosPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatATanINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatATanPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatATan2INTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatPowINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatPowRINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpArbitraryFloatPowNINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpLoopControlINTEL:
    while (!it.ate()) ib.push(it.u32());
    break;
  case spv::OpFixedSqrtINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedRecipINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedRsqrtINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedSinINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedCosINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedSinCosINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedSinPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedCosPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedSinCosPiINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedLogINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpFixedExpINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    ib.push(it.u32());
    break;
  case spv::OpPtrCastToCrossWorkgroupINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpCrossWorkgroupCastToPtrINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpReadPipeBlockingINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpWritePipeBlockingINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpFPGARegINTEL:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetRayTMinKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetRayFlagsKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionTKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionInstanceCustomIndexKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionInstanceIdKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionGeometryIndexKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionPrimitiveIndexKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionBarycentricsKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionFrontFaceKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionCandidateAABBOpaqueKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionObjectRayDirectionKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionObjectRayOriginKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetWorldRayDirectionKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetWorldRayOriginKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionObjectToWorldKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpRayQueryGetIntersectionWorldToObjectKHR:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpAtomicFAddEXT:
    ib.push(deref(it.id()));
    result_id = it.id();
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    ib.push(deref(it.id()));
    break;
  case spv::OpTypeBufferSurfaceINTEL:
    result_id = it.id();
    ib.push(it.u32());
    break;
  case spv::OpTypeStructContinuedINTEL:
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpConstantCompositeContinuedINTEL:
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  case spv::OpSpecConstantCompositeContinuedINTEL:
    while (!it.ate()) ib.push(deref(it.id()));
    break;
  }
  if (result_id >= 0) id2idx[result_id] = idx;
  idx2instr[idx] = ib.build();
}

} // namespace liella
