// THIS IS A GENERATED SOURCE. MODIFICATION WILL BE OVERWRITTEN.
// @PENGUINLIONG
#pragma once
#include "liella/spv-instr.hpp"
namespace liella {

std::vector<spv::Id> collect_id_refs(const Instruction& instr) {
  OperandIterator it = instr.iter();
  std::vector<spv::Id> out;
  switch (instr.opcode) {
  case spv::OpNop: break;
  case spv::OpUndef:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSourceContinued:
    it.str();
    break;
  case spv::OpSource:
    it.u32();
    it.u32();
    if (!it.ate()) out.emplace_back(it.id());
    if (!it.ate()) it.str();
    break;
  case spv::OpSourceExtension:
    it.str();
    break;
  case spv::OpName:
    out.emplace_back(it.id());
    it.str();
    break;
  case spv::OpMemberName:
    out.emplace_back(it.id());
    it.u32();
    it.str();
    break;
  case spv::OpString:
    it.id();
    it.str();
    break;
  case spv::OpLine:
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    break;
  case spv::OpExtension:
    it.str();
    break;
  case spv::OpExtInstImport:
    it.id();
    it.str();
    break;
  case spv::OpExtInst:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpMemoryModel:
    it.u32();
    it.u32();
    break;
  case spv::OpEntryPoint:
    it.u32();
    out.emplace_back(it.id());
    it.str();
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpExecutionMode:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpCapability:
    it.u32();
    break;
  case spv::OpTypeVoid:
    it.id();
    break;
  case spv::OpTypeBool:
    it.id();
    break;
  case spv::OpTypeInt:
    it.id();
    it.u32();
    it.u32();
    break;
  case spv::OpTypeFloat:
    it.id();
    it.u32();
    break;
  case spv::OpTypeVector:
    it.id();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpTypeMatrix:
    it.id();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpTypeImage:
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    if (!it.ate()) it.u32();
    break;
  case spv::OpTypeSampler:
    it.id();
    break;
  case spv::OpTypeSampledImage:
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpTypeArray:
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTypeRuntimeArray:
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpTypeStruct:
    it.id();
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpTypeOpaque:
    it.id();
    it.str();
    break;
  case spv::OpTypePointer:
    it.id();
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpTypeFunction:
    it.id();
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpTypeEvent:
    it.id();
    break;
  case spv::OpTypeDeviceEvent:
    it.id();
    break;
  case spv::OpTypeReserveId:
    it.id();
    break;
  case spv::OpTypeQueue:
    it.id();
    break;
  case spv::OpTypePipe:
    it.id();
    it.u32();
    break;
  case spv::OpTypeForwardPointer:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpConstantTrue:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpConstantFalse:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpConstant:
    out.emplace_back(it.id());
    it.id();
        break;
  case spv::OpConstantComposite:
    out.emplace_back(it.id());
    it.id();
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpConstantSampler:
    out.emplace_back(it.id());
    it.id();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpConstantNull:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSpecConstantTrue:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSpecConstantFalse:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSpecConstant:
    out.emplace_back(it.id());
    it.id();
        break;
  case spv::OpSpecConstantComposite:
    out.emplace_back(it.id());
    it.id();
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpSpecConstantOp:
    out.emplace_back(it.id());
    it.id();
    it.u32();
    break;
  case spv::OpFunction:
    out.emplace_back(it.id());
    it.id();
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpFunctionParameter:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpFunctionEnd: break;
  case spv::OpFunctionCall:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpVariable:
    out.emplace_back(it.id());
    it.id();
    it.u32();
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpImageTexelPointer:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpLoad:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpStore:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpCopyMemory:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    if (!it.ate()) it.u32();
    break;
  case spv::OpCopyMemorySized:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    if (!it.ate()) it.u32();
    break;
  case spv::OpAccessChain:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpInBoundsAccessChain:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpPtrAccessChain:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpArrayLength:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpGenericPtrMemSemantics:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpInBoundsPtrAccessChain:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpDecorate:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpMemberDecorate:
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    break;
  case spv::OpDecorationGroup:
    it.id();
    break;
  case spv::OpGroupDecorate:
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupMemberDecorate:
    out.emplace_back(it.id());
    while (!it.ate()) { out.emplace_back(it.id()); it.u32(); }
    break;
  case spv::OpVectorExtractDynamic:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpVectorInsertDynamic:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpVectorShuffle:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    while (!it.ate()) it.u32();
    break;
  case spv::OpCompositeConstruct:
    out.emplace_back(it.id());
    it.id();
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpCompositeExtract:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    while (!it.ate()) it.u32();
    break;
  case spv::OpCompositeInsert:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    while (!it.ate()) it.u32();
    break;
  case spv::OpCopyObject:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpTranspose:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSampledImage:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpImageSampleImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSampleExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageSampleDrefImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSampleDrefExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageSampleProjImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSampleProjExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageSampleProjDrefImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSampleProjDrefExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageFetch:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageGather:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageDrefGather:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageRead:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageWrite:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImage:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpImageQueryFormat:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpImageQueryOrder:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpImageQuerySizeLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpImageQuerySize:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpImageQueryLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpImageQueryLevels:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpImageQuerySamples:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertFToU:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertFToS:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertSToF:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertUToF:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpUConvert:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSConvert:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpFConvert:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpQuantizeToF16:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertPtrToU:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSatConvertSToU:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSatConvertUToS:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertUToPtr:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpPtrCastToGeneric:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpGenericCastToPtr:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpGenericCastToPtrExplicit:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpBitcast:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSNegate:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpFNegate:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpIAdd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFAdd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpISub:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFSub:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIMul:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFMul:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUDiv:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSDiv:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFDiv:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUMod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSRem:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSMod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFRem:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFMod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpVectorTimesScalar:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpMatrixTimesScalar:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpVectorTimesMatrix:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpMatrixTimesVector:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpMatrixTimesMatrix:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpOuterProduct:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpDot:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIAddCarry:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpISubBorrow:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUMulExtended:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSMulExtended:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAny:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpAll:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpIsNan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpIsInf:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpIsFinite:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpIsNormal:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSignBitSet:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpLessOrGreater:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpOrdered:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUnordered:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpLogicalEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpLogicalNotEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpLogicalOr:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpLogicalAnd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpLogicalNot:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSelect:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpINotEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUGreaterThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSGreaterThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUGreaterThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSGreaterThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpULessThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSLessThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpULessThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSLessThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFOrdEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFUnordEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFOrdNotEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFUnordNotEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFOrdLessThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFUnordLessThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFOrdGreaterThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFUnordGreaterThan:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFOrdLessThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFUnordLessThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFOrdGreaterThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFUnordGreaterThanEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpShiftRightLogical:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpShiftRightArithmetic:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpShiftLeftLogical:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpBitwiseOr:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpBitwiseXor:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpBitwiseAnd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpNot:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpBitFieldInsert:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpBitFieldSExtract:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpBitFieldUExtract:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpBitReverse:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpBitCount:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpDPdx:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpDPdy:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpFwidth:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpDPdxFine:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpDPdyFine:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpFwidthFine:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpDPdxCoarse:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpDPdyCoarse:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpFwidthCoarse:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpEmitVertex: break;
  case spv::OpEndPrimitive: break;
  case spv::OpEmitStreamVertex:
    out.emplace_back(it.id());
    break;
  case spv::OpEndStreamPrimitive:
    out.emplace_back(it.id());
    break;
  case spv::OpControlBarrier:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpMemoryBarrier:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicLoad:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicStore:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicExchange:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicCompareExchange:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicCompareExchangeWeak:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicIIncrement:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicIDecrement:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicIAdd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicISub:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicSMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicUMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicSMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicUMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicAnd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicOr:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicXor:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpPhi:
    out.emplace_back(it.id());
    it.id();
    while (!it.ate()) { out.emplace_back(it.id()); out.emplace_back(it.id()); }
    break;
  case spv::OpLoopMerge:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpSelectionMerge:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpLabel:
    it.id();
    break;
  case spv::OpBranch:
    out.emplace_back(it.id());
    break;
  case spv::OpBranchConditional:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    while (!it.ate()) it.u32();
    break;
  case spv::OpSwitch:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    while (!it.ate()) { it.u32(); out.emplace_back(it.id()); }
    break;
  case spv::OpKill: break;
  case spv::OpReturn: break;
  case spv::OpReturnValue:
    out.emplace_back(it.id());
    break;
  case spv::OpUnreachable: break;
  case spv::OpLifetimeStart:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpLifetimeStop:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpGroupAsyncCopy:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupWaitEvents:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupAll:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupAny:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupBroadcast:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupIAdd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupFAdd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupFMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupUMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupSMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupFMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupUMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupSMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpReadPipe:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpWritePipe:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpReservedReadPipe:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpReservedWritePipe:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpReserveReadPipePackets:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpReserveWritePipePackets:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpCommitReadPipe:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpCommitWritePipe:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIsValidReserveId:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpGetNumPipePackets:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGetMaxPipePackets:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupReserveReadPipePackets:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupReserveWritePipePackets:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupCommitReadPipe:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupCommitWritePipe:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpEnqueueMarker:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpEnqueueKernel:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGetKernelNDrangeSubGroupCount:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGetKernelNDrangeMaxSubGroupSize:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGetKernelWorkGroupSize:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGetKernelPreferredWorkGroupSizeMultiple:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRetainEvent:
    out.emplace_back(it.id());
    break;
  case spv::OpReleaseEvent:
    out.emplace_back(it.id());
    break;
  case spv::OpCreateUserEvent:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpIsValidEvent:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSetUserEventStatus:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpCaptureEventProfilingInfo:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGetDefaultQueue:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpBuildNDRange:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpImageSparseSampleImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSparseSampleExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageSparseSampleDrefImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSparseSampleDrefExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageSparseSampleProjImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSparseSampleProjExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageSparseSampleProjDrefImplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSparseSampleProjDrefExplicitLod:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpImageSparseFetch:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSparseGather:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSparseDrefGather:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpImageSparseTexelsResident:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpNoLine: break;
  case spv::OpAtomicFlagTestAndSet:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicFlagClear:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpImageSparseRead:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpSizeOf:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpTypePipeStorage:
    it.id();
    break;
  case spv::OpConstantPipeStorage:
    out.emplace_back(it.id());
    it.id();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpCreatePipeFromPipeStorage:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpGetKernelLocalSizeForSubgroupCount:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGetKernelMaxNumSubgroups:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTypeNamedBarrier:
    it.id();
    break;
  case spv::OpNamedBarrierInitialize:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpMemoryNamedBarrier:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpModuleProcessed:
    it.str();
    break;
  case spv::OpExecutionModeId:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpDecorateId:
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpGroupNonUniformElect:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformAll:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformAny:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformAllEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBroadcast:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBroadcastFirst:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBallot:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformInverseBallot:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBallotBitExtract:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBallotBitCount:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBallotFindLSB:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBallotFindMSB:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformShuffle:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformShuffleXor:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformShuffleUp:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformShuffleDown:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformIAdd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformFAdd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformIMul:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformFMul:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformSMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformUMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformFMin:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformSMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformUMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformFMax:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBitwiseAnd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBitwiseOr:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformBitwiseXor:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformLogicalAnd:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformLogicalOr:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformLogicalXor:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    if (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformQuadBroadcast:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupNonUniformQuadSwap:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpCopyLogical:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpPtrEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpPtrNotEqual:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpPtrDiff:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTerminateInvocation: break;
  case spv::OpSubgroupBallotKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupFirstInvocationKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAllKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAnyKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAllEqualKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupReadInvocationKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTraceRayKHR:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpExecuteCallableKHR:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpConvertUToAccelerationStructureKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpIgnoreIntersectionKHR: break;
  case spv::OpTerminateRayKHR: break;
  case spv::OpSDotKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpUDotKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpSUDotKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpSDotAccSatKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpUDotAccSatKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpSUDotAccSatKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpTypeRayQueryKHR:
    it.id();
    break;
  case spv::OpRayQueryInitializeKHR:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryTerminateKHR:
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGenerateIntersectionKHR:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryConfirmIntersectionKHR:
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryProceedKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionTypeKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpGroupIAddNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupFAddNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupFMinNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupUMinNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupSMinNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupFMaxNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupUMaxNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpGroupSMaxNonUniformAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    break;
  case spv::OpFragmentMaskFetchAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFragmentFetchAMD:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpReadClockKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpImageSampleFootprintNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpGroupNonUniformPartitionNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpWritePackedPrimitiveIndices4x8NV:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpReportIntersectionNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  // Ignored alias op OpReportIntersectionKHR.
  case spv::OpIgnoreIntersectionNV: break;
  case spv::OpTerminateRayNV: break;
  case spv::OpTraceNV:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTraceMotionNV:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTraceRayMotionNV:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTypeAccelerationStructureNV:
    it.id();
    break;
  // Ignored alias op OpTypeAccelerationStructureKHR.
  case spv::OpExecuteCallableNV:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTypeCooperativeMatrixNV:
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpCooperativeMatrixLoadNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpCooperativeMatrixStoreNV:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    if (!it.ate()) it.u32();
    break;
  case spv::OpCooperativeMatrixMulAddNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpCooperativeMatrixLengthNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpBeginInvocationInterlockEXT: break;
  case spv::OpEndInvocationInterlockEXT: break;
  case spv::OpDemoteToHelperInvocationEXT: break;
  case spv::OpIsHelperInvocationEXT:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpConvertUToImageNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertUToSamplerNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertImageToUNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertSamplerToUNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertUToSampledImageNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpConvertSampledImageToUNV:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSamplerImageAddressingModeNV:
    it.u32();
    break;
  case spv::OpSubgroupShuffleINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupShuffleDownINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupShuffleUpINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupShuffleXorINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupBlockReadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupBlockWriteINTEL:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupImageBlockReadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupImageBlockWriteINTEL:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupImageMediaBlockReadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupImageMediaBlockWriteINTEL:
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUCountLeadingZerosINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpUCountTrailingZerosINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpAbsISubINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAbsUSubINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIAddSatINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUAddSatINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIAverageINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUAverageINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIAverageRoundedINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUAverageRoundedINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpISubSatINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUSubSatINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpIMul32x16INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpUMul32x16INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpConstantFunctionPointerINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpFunctionPointerCallINTEL:
    out.emplace_back(it.id());
    it.id();
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpAsmTargetINTEL:
    out.emplace_back(it.id());
    it.id();
    it.str();
    break;
  case spv::OpAsmINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.str();
    it.str();
    break;
  case spv::OpAsmCallINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpAtomicFMinEXT:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicFMaxEXT:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAssumeTrueKHR:
    out.emplace_back(it.id());
    break;
  case spv::OpExpectKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpDecorateString:
    out.emplace_back(it.id());
    it.u32();
    break;
  // Ignored alias op OpDecorateStringGOOGLE.
  case spv::OpMemberDecorateString:
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    break;
  // Ignored alias op OpMemberDecorateStringGOOGLE.
  case spv::OpVmeImageINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTypeVmeImageINTEL:
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpTypeAvcImePayloadINTEL:
    it.id();
    break;
  case spv::OpTypeAvcRefPayloadINTEL:
    it.id();
    break;
  case spv::OpTypeAvcSicPayloadINTEL:
    it.id();
    break;
  case spv::OpTypeAvcMcePayloadINTEL:
    it.id();
    break;
  case spv::OpTypeAvcMceResultINTEL:
    it.id();
    break;
  case spv::OpTypeAvcImeResultINTEL:
    it.id();
    break;
  case spv::OpTypeAvcImeResultSingleReferenceStreamoutINTEL:
    it.id();
    break;
  case spv::OpTypeAvcImeResultDualReferenceStreamoutINTEL:
    it.id();
    break;
  case spv::OpTypeAvcImeSingleReferenceStreaminINTEL:
    it.id();
    break;
  case spv::OpTypeAvcImeDualReferenceStreaminINTEL:
    it.id();
    break;
  case spv::OpTypeAvcRefResultINTEL:
    it.id();
    break;
  case spv::OpTypeAvcSicResultINTEL:
    it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceSetInterShapePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceSetInterDirectionPenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpSubgroupAvcMceSetAcOnlyHaarINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceConvertToImePayloadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceConvertToImeResultINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceConvertToRefPayloadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceConvertToRefResultINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceConvertToSicPayloadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceConvertToSicResultINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetMotionVectorsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetInterDistortionsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetBestInterDistortionsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetInterMajorShapeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetInterMinorShapeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetInterDirectionsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetInterMotionVectorCountINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetInterReferenceIdsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeInitializeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeSetSingleReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeSetDualReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeRefWindowSizeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeAdjustRefOffsetINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeConvertToMcePayloadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeSetMaxMotionVectorCountINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeSetWeightedSadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeConvertToMceResultINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetSingleReferenceStreaminINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetDualReferenceStreaminINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeStripDualReferenceStreamoutINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetBorderReachedINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcFmeInitializeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcBmeInitializeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefConvertToMcePayloadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefSetBidirectionalMixDisableINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefSetBilinearFilterEnableINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefEvaluateWithDualReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcRefConvertToMceResultINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicInitializeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicConfigureSkcINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicConfigureIpeLumaINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicConfigureIpeLumaChromaINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetMotionVectorMaskINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicConvertToMcePayloadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicSetBilinearFilterEnableINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicEvaluateIpeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicEvaluateWithDualReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicConvertToMceResultINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetIpeLumaShapeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetPackedIpeLumaModesINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetIpeChromaModeINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSubgroupAvcSicGetInterRawSadsINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpVariableLengthArrayINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpSaveMemoryINTEL:
    out.emplace_back(it.id());
    it.id();
    break;
  case spv::OpRestoreMemoryINTEL:
    out.emplace_back(it.id());
    break;
  case spv::OpArbitraryFloatSinCosPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatCastINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatCastFromIntINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatCastToIntINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatAddINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatSubINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatMulINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatDivINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatGTINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpArbitraryFloatGEINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpArbitraryFloatLTINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpArbitraryFloatLEINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpArbitraryFloatEQINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    break;
  case spv::OpArbitraryFloatRecipINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatRSqrtINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatCbrtINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatHypotINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatSqrtINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatLogINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatLog2INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatLog10INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatLog1pINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatExpINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatExp2INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatExp10INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatExpm1INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatSinINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatCosINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatSinCosINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatSinPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatCosPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatASinINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatASinPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatACosINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatACosPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatATanINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatATanPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatATan2INTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatPowINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatPowRINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpArbitraryFloatPowNINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    it.u32();
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpLoopControlINTEL:
    while (!it.ate()) it.u32();
    break;
  case spv::OpFixedSqrtINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedRecipINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedRsqrtINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedSinINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedCosINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedSinCosINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedSinPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedCosPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedSinCosPiINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedLogINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpFixedExpINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    it.u32();
    break;
  case spv::OpPtrCastToCrossWorkgroupINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpCrossWorkgroupCastToPtrINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpReadPipeBlockingINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpWritePipeBlockingINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpFPGARegINTEL:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetRayTMinKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetRayFlagsKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionTKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionInstanceCustomIndexKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionInstanceIdKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionGeometryIndexKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionPrimitiveIndexKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionBarycentricsKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionFrontFaceKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionCandidateAABBOpaqueKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionObjectRayDirectionKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionObjectRayOriginKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetWorldRayDirectionKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetWorldRayOriginKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionObjectToWorldKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpRayQueryGetIntersectionWorldToObjectKHR:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpAtomicFAddEXT:
    out.emplace_back(it.id());
    it.id();
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    out.emplace_back(it.id());
    break;
  case spv::OpTypeBufferSurfaceINTEL:
    it.id();
    it.u32();
    break;
  case spv::OpTypeStructContinuedINTEL:
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpConstantCompositeContinuedINTEL:
    while (!it.ate()) out.emplace_back(it.id());
    break;
  case spv::OpSpecConstantCompositeContinuedINTEL:
    while (!it.ate()) out.emplace_back(it.id());
    break;
  }
  return out;
}

} // namespace liella
