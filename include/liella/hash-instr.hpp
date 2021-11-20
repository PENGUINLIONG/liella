// THIS IS A GENERATED SOURCE. MODIFICATION WILL BE OVERWRITTEN.
// @PENGUINLIONG
#pragma once
#include "liella/fnv.hpp"
#include "liella/spv-instr.hpp"
namespace liella {

void hash_instr(Fnv& hasher, const Instruction& instr) {
  OperandIterator it = instr.iter();
  hasher.feed(instr.opcode);
  switch (instr.opcode) {
  case spv::OpNop: break;
  case spv::OpUndef:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSourceContinued:
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpSource:
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    if (!it.ate()) it.id(); hasher.feed(0);
    if (!it.ate()) { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpSourceExtension:
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpName:
    it.id(); hasher.feed(0);
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpMemberName:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpString:
    it.id(); hasher.feed(0);
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpLine:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpExtension:
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpExtInstImport:
    it.id(); hasher.feed(0);
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpExtInst:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpMemoryModel:
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpEntryPoint:
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpExecutionMode:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpCapability:
    hasher.feed(it.u32());
    break;
  case spv::OpTypeVoid:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeBool:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeInt:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpTypeFloat:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpTypeVector:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpTypeMatrix:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpTypeImage:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpTypeSampler:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeSampledImage:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeArray:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeRuntimeArray:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeStruct:
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpTypeOpaque:
    it.id(); hasher.feed(0);
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpTypePointer:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeFunction:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpTypeEvent:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeDeviceEvent:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeReserveId:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeQueue:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypePipe:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpTypeForwardPointer:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpConstantTrue:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConstantFalse:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConstant:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpConstantComposite:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpConstantSampler:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpConstantNull:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSpecConstantTrue:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSpecConstantFalse:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSpecConstant:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpSpecConstantComposite:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpSpecConstantOp:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpFunction:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpFunctionParameter:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFunctionEnd: break;
  case spv::OpFunctionCall:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpVariable:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpImageTexelPointer:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpLoad:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpStore:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpCopyMemory:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpCopyMemorySized:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpAccessChain:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpInBoundsAccessChain:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpPtrAccessChain:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpArrayLength:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpGenericPtrMemSemantics:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpInBoundsPtrAccessChain:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpDecorate:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpMemberDecorate:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpDecorationGroup:
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupDecorate:
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupMemberDecorate:
    it.id(); hasher.feed(0);
    while (!it.ate()) { it.id(); hasher.feed(0); hasher.feed(it.u32()); }
    break;
  case spv::OpVectorExtractDynamic:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpVectorInsertDynamic:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpVectorShuffle:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpCompositeConstruct:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpCompositeExtract:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpCompositeInsert:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpCopyObject:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTranspose:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSampledImage:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageSampleImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSampleExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageSampleDrefImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSampleDrefExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageSampleProjImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSampleProjExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageSampleProjDrefImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSampleProjDrefExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageFetch:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageGather:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageDrefGather:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageRead:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageWrite:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImage:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageQueryFormat:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageQueryOrder:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageQuerySizeLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageQuerySize:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageQueryLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageQueryLevels:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageQuerySamples:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertFToU:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertFToS:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertSToF:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertUToF:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUConvert:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSConvert:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFConvert:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpQuantizeToF16:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertPtrToU:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSatConvertSToU:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSatConvertUToS:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertUToPtr:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpPtrCastToGeneric:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGenericCastToPtr:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGenericCastToPtrExplicit:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpBitcast:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSNegate:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFNegate:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIAdd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFAdd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpISub:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFSub:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIMul:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFMul:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUDiv:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSDiv:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFDiv:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUMod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSRem:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSMod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFRem:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFMod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpVectorTimesScalar:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpMatrixTimesScalar:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpVectorTimesMatrix:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpMatrixTimesVector:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpMatrixTimesMatrix:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpOuterProduct:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDot:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIAddCarry:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpISubBorrow:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUMulExtended:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSMulExtended:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAny:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAll:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIsNan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIsInf:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIsFinite:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIsNormal:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSignBitSet:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpLessOrGreater:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpOrdered:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUnordered:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpLogicalEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpLogicalNotEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpLogicalOr:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpLogicalAnd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpLogicalNot:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSelect:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpINotEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUGreaterThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSGreaterThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUGreaterThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSGreaterThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpULessThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSLessThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpULessThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSLessThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFOrdEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFUnordEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFOrdNotEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFUnordNotEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFOrdLessThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFUnordLessThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFOrdGreaterThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFUnordGreaterThan:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFOrdLessThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFUnordLessThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFOrdGreaterThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFUnordGreaterThanEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpShiftRightLogical:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpShiftRightArithmetic:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpShiftLeftLogical:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitwiseOr:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitwiseXor:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitwiseAnd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpNot:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitFieldInsert:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitFieldSExtract:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitFieldUExtract:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitReverse:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBitCount:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDPdx:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDPdy:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFwidth:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDPdxFine:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDPdyFine:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFwidthFine:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDPdxCoarse:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDPdyCoarse:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFwidthCoarse:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpEmitVertex: break;
  case spv::OpEndPrimitive: break;
  case spv::OpEmitStreamVertex:
    it.id(); hasher.feed(0);
    break;
  case spv::OpEndStreamPrimitive:
    it.id(); hasher.feed(0);
    break;
  case spv::OpControlBarrier:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpMemoryBarrier:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicLoad:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicStore:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicExchange:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicCompareExchange:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicCompareExchangeWeak:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicIIncrement:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicIDecrement:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicIAdd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicISub:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicSMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicUMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicSMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicUMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicAnd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicOr:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicXor:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpPhi:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) { it.id(); hasher.feed(0); it.id(); hasher.feed(0); }
    break;
  case spv::OpLoopMerge:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpSelectionMerge:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpLabel:
    it.id(); hasher.feed(0);
    break;
  case spv::OpBranch:
    it.id(); hasher.feed(0);
    break;
  case spv::OpBranchConditional:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpSwitch:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) { hasher.feed(it.u32()); it.id(); hasher.feed(0); }
    break;
  case spv::OpKill: break;
  case spv::OpReturn: break;
  case spv::OpReturnValue:
    it.id(); hasher.feed(0);
    break;
  case spv::OpUnreachable: break;
  case spv::OpLifetimeStart:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpLifetimeStop:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpGroupAsyncCopy:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupWaitEvents:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupAll:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupAny:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupBroadcast:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupIAdd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupFAdd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupFMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupUMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupSMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupFMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupUMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupSMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpReadPipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpWritePipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpReservedReadPipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpReservedWritePipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpReserveReadPipePackets:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpReserveWritePipePackets:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpCommitReadPipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpCommitWritePipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIsValidReserveId:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetNumPipePackets:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetMaxPipePackets:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupReserveReadPipePackets:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupReserveWritePipePackets:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupCommitReadPipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupCommitWritePipe:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpEnqueueMarker:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpEnqueueKernel:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGetKernelNDrangeSubGroupCount:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetKernelNDrangeMaxSubGroupSize:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetKernelWorkGroupSize:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetKernelPreferredWorkGroupSizeMultiple:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRetainEvent:
    it.id(); hasher.feed(0);
    break;
  case spv::OpReleaseEvent:
    it.id(); hasher.feed(0);
    break;
  case spv::OpCreateUserEvent:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIsValidEvent:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSetUserEventStatus:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpCaptureEventProfilingInfo:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetDefaultQueue:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBuildNDRange:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageSparseSampleImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSparseSampleExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageSparseSampleDrefImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSparseSampleDrefExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageSparseSampleProjImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSparseSampleProjExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageSparseSampleProjDrefImplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSparseSampleProjDrefExplicitLod:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpImageSparseFetch:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSparseGather:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSparseDrefGather:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpImageSparseTexelsResident:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpNoLine: break;
  case spv::OpAtomicFlagTestAndSet:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicFlagClear:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageSparseRead:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpSizeOf:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypePipeStorage:
    it.id(); hasher.feed(0);
    break;
  case spv::OpConstantPipeStorage:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpCreatePipeFromPipeStorage:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetKernelLocalSizeForSubgroupCount:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGetKernelMaxNumSubgroups:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeNamedBarrier:
    it.id(); hasher.feed(0);
    break;
  case spv::OpNamedBarrierInitialize:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpMemoryNamedBarrier:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpModuleProcessed:
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpExecutionModeId:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpDecorateId:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpGroupNonUniformElect:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformAll:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformAny:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformAllEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBroadcast:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBroadcastFirst:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBallot:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformInverseBallot:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBallotBitExtract:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBallotBitCount:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBallotFindLSB:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBallotFindMSB:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformShuffle:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformShuffleXor:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformShuffleUp:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformShuffleDown:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformIAdd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformFAdd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformIMul:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformFMul:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformSMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformUMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformFMin:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformSMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformUMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformFMax:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBitwiseAnd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBitwiseOr:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformBitwiseXor:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformLogicalAnd:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformLogicalOr:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformLogicalXor:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    if (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformQuadBroadcast:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupNonUniformQuadSwap:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpCopyLogical:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpPtrEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpPtrNotEqual:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpPtrDiff:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTerminateInvocation: break;
  case spv::OpSubgroupBallotKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupFirstInvocationKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAllKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAnyKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAllEqualKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupReadInvocationKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTraceRayKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpExecuteCallableKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertUToAccelerationStructureKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIgnoreIntersectionKHR: break;
  case spv::OpTerminateRayKHR: break;
  case spv::OpSDotKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpUDotKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpSUDotKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpSDotAccSatKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpUDotAccSatKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpSUDotAccSatKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpTypeRayQueryKHR:
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryInitializeKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryTerminateKHR:
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGenerateIntersectionKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryConfirmIntersectionKHR:
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryProceedKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionTypeKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupIAddNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupFAddNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupFMinNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupUMinNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupSMinNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupFMaxNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupUMaxNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpGroupSMaxNonUniformAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    break;
  case spv::OpFragmentMaskFetchAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFragmentFetchAMD:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpReadClockKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpImageSampleFootprintNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpGroupNonUniformPartitionNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpWritePackedPrimitiveIndices4x8NV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpReportIntersectionNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  // Ignored alias op OpReportIntersectionKHR.
  case spv::OpIgnoreIntersectionNV: break;
  case spv::OpTerminateRayNV: break;
  case spv::OpTraceNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTraceMotionNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTraceRayMotionNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAccelerationStructureNV:
    it.id(); hasher.feed(0);
    break;
  // Ignored alias op OpTypeAccelerationStructureKHR.
  case spv::OpExecuteCallableNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeCooperativeMatrixNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpCooperativeMatrixLoadNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpCooperativeMatrixStoreNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    if (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpCooperativeMatrixMulAddNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpCooperativeMatrixLengthNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpBeginInvocationInterlockEXT: break;
  case spv::OpEndInvocationInterlockEXT: break;
  case spv::OpDemoteToHelperInvocationEXT: break;
  case spv::OpIsHelperInvocationEXT:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertUToImageNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertUToSamplerNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertImageToUNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertSamplerToUNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertUToSampledImageNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConvertSampledImageToUNV:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSamplerImageAddressingModeNV:
    hasher.feed(it.u32());
    break;
  case spv::OpSubgroupShuffleINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupShuffleDownINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupShuffleUpINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupShuffleXorINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupBlockReadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupBlockWriteINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupImageBlockReadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupImageBlockWriteINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupImageMediaBlockReadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupImageMediaBlockWriteINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUCountLeadingZerosINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUCountTrailingZerosINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAbsISubINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAbsUSubINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIAddSatINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUAddSatINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIAverageINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUAverageINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIAverageRoundedINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUAverageRoundedINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpISubSatINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUSubSatINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpIMul32x16INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpUMul32x16INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpConstantFunctionPointerINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFunctionPointerCallINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpAsmTargetINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpAsmINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    { const char* str = it.str(); hasher.feed(str, strlen(str)); }
    break;
  case spv::OpAsmCallINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicFMinEXT:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicFMaxEXT:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAssumeTrueKHR:
    it.id(); hasher.feed(0);
    break;
  case spv::OpExpectKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpDecorateString:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  // Ignored alias op OpDecorateStringGOOGLE.
  case spv::OpMemberDecorateString:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  // Ignored alias op OpMemberDecorateStringGOOGLE.
  case spv::OpVmeImageINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeVmeImageINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcImePayloadINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcRefPayloadINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcSicPayloadINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcMcePayloadINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcMceResultINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcImeResultINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcImeResultSingleReferenceStreamoutINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcImeResultDualReferenceStreamoutINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcImeSingleReferenceStreaminINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcImeDualReferenceStreaminINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcRefResultINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeAvcSicResultINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterBaseMultiReferencePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetInterBaseMultiReferencePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterShapePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetInterShapePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterDirectionPenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetInterDirectionPenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraLumaShapePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultInterMotionVectorCostTableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultHighPenaltyCostTableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultMediumPenaltyCostTableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultLowPenaltyCostTableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetMotionVectorCostFunctionINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraLumaModePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultNonDcLumaIntraPenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetDefaultIntraChromaModeBasePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetAcOnlyHaarINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetSourceInterlacedFieldPolarityINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetSingleReferenceInterlacedFieldPolarityINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceSetDualReferenceInterlacedFieldPolaritiesINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceConvertToImePayloadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceConvertToImeResultINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceConvertToRefPayloadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceConvertToRefResultINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceConvertToSicPayloadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceConvertToSicResultINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetMotionVectorsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetInterDistortionsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetBestInterDistortionsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetInterMajorShapeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetInterMinorShapeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetInterDirectionsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetInterMotionVectorCountINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetInterReferenceIdsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcMceGetInterReferenceInterlacedFieldPolaritiesINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeInitializeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeSetSingleReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeSetDualReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeRefWindowSizeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeAdjustRefOffsetINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeConvertToMcePayloadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeSetMaxMotionVectorCountINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeSetUnidirectionalMixDisableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeSetEarlySearchTerminationThresholdINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeSetWeightedSadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreamoutINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreamoutINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithSingleReferenceStreaminoutINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeEvaluateWithDualReferenceStreaminoutINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeConvertToMceResultINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetSingleReferenceStreaminINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetDualReferenceStreaminINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeStripSingleReferenceStreamoutINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeStripDualReferenceStreamoutINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeMotionVectorsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeDistortionsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetStreamoutSingleReferenceMajorShapeReferenceIdsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeMotionVectorsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeDistortionsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetStreamoutDualReferenceMajorShapeReferenceIdsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetBorderReachedINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetTruncatedSearchIndicationINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetUnidirectionalEarlySearchTerminationINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetWeightingPatternMinimumMotionVectorINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcImeGetWeightingPatternMinimumDistortionINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcFmeInitializeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcBmeInitializeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefConvertToMcePayloadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefSetBidirectionalMixDisableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefSetBilinearFilterEnableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefEvaluateWithSingleReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefEvaluateWithDualReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefEvaluateWithMultiReferenceInterlacedINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcRefConvertToMceResultINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicInitializeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicConfigureSkcINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicConfigureIpeLumaINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicConfigureIpeLumaChromaINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetMotionVectorMaskINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicConvertToMcePayloadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicSetIntraLumaShapePenaltyINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicSetIntraLumaModeCostFunctionINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicSetIntraChromaModeCostFunctionINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicSetBilinearFilterEnableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicSetSkcForwardTransformEnableINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicSetBlockBasedRawSkipSadINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicEvaluateIpeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicEvaluateWithSingleReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicEvaluateWithDualReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicEvaluateWithMultiReferenceInterlacedINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicConvertToMceResultINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetIpeLumaShapeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetBestIpeLumaDistortionINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetBestIpeChromaDistortionINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetPackedIpeLumaModesINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetIpeChromaModeINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetPackedSkcLumaCountThresholdINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetPackedSkcLumaSumThresholdINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSubgroupAvcSicGetInterRawSadsINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpVariableLengthArrayINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpSaveMemoryINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRestoreMemoryINTEL:
    it.id(); hasher.feed(0);
    break;
  case spv::OpArbitraryFloatSinCosPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatCastINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatCastFromIntINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatCastToIntINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatAddINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatSubINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatMulINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatDivINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatGTINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatGEINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatLTINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatLEINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatEQINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatRecipINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatRSqrtINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatCbrtINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatHypotINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatSqrtINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatLogINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatLog2INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatLog10INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatLog1pINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatExpINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatExp2INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatExp10INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatExpm1INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatSinINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatCosINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatSinCosINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatSinPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatCosPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatASinINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatASinPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatACosINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatACosPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatATanINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatATanPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatATan2INTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatPowINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatPowRINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpArbitraryFloatPowNINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpLoopControlINTEL:
    while (!it.ate()) hasher.feed(it.u32());
    break;
  case spv::OpFixedSqrtINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedRecipINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedRsqrtINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedSinINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedCosINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedSinCosINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedSinPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedCosPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedSinCosPiINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedLogINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpFixedExpINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    hasher.feed(it.u32());
    break;
  case spv::OpPtrCastToCrossWorkgroupINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpCrossWorkgroupCastToPtrINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpReadPipeBlockingINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpWritePipeBlockingINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpFPGARegINTEL:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetRayTMinKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetRayFlagsKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionTKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionInstanceCustomIndexKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionInstanceIdKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionInstanceShaderBindingTableRecordOffsetKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionGeometryIndexKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionPrimitiveIndexKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionBarycentricsKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionFrontFaceKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionCandidateAABBOpaqueKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionObjectRayDirectionKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionObjectRayOriginKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetWorldRayDirectionKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetWorldRayOriginKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionObjectToWorldKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpRayQueryGetIntersectionWorldToObjectKHR:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpAtomicFAddEXT:
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    it.id(); hasher.feed(0);
    break;
  case spv::OpTypeBufferSurfaceINTEL:
    it.id(); hasher.feed(0);
    hasher.feed(it.u32());
    break;
  case spv::OpTypeStructContinuedINTEL:
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpConstantCompositeContinuedINTEL:
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  case spv::OpSpecConstantCompositeContinuedINTEL:
    while (!it.ate()) it.id(); hasher.feed(0);
    break;
  }
}

} // namespace liella
