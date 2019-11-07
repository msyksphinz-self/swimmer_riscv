#!/usr/bin/ruby

load "msyksphinz_env.rb"
load "rumy-cpp.rb"

compile_options = []
compile_options = compile_options + ["-O0"]
compile_options = compile_options + ["-g"]
compile_options = compile_options + ["-Wall"]
# compile_options = compile_options + ["-std=c++0x"]

compile_options = compile_options + ["-I../SoftFloat-3d/source/riscv/"]
compile_options = compile_options + ["-I../SoftFloat-3d/source/include/"]
compile_options = compile_options + ["-I./"]

compile_options = compile_options + ["-DINLINE_LEVEL=0"]
compile_options = compile_options + ["-DSOFTFLOAT_FAST_DIV32TO32"]
compile_options = compile_options + ["-DSOFTFLOAT_FAST_DIV64TO32"]
compile_options = compile_options + ["-DSOFTFLOAT_FAST_INT64"]
compile_options = compile_options + ["-DSOFTFLOAT_ROUND_ODD"]

make_library "libsoftfloat.a",
             ["../SoftFloat-3d/source/extF80M_add.c",
              "../SoftFloat-3d/source/extF80M_div.c",
              "../SoftFloat-3d/source/extF80M_eq.c",
              "../SoftFloat-3d/source/extF80M_eq_signaling.c",
              "../SoftFloat-3d/source/extF80M_le.c",
              "../SoftFloat-3d/source/extF80M_le_quiet.c",
              "../SoftFloat-3d/source/extF80M_lt.c",
              "../SoftFloat-3d/source/extF80M_lt_quiet.c",
              "../SoftFloat-3d/source/extF80M_mul.c",
              "../SoftFloat-3d/source/extF80M_rem.c",
              "../SoftFloat-3d/source/extF80M_roundToInt.c",
              "../SoftFloat-3d/source/extF80M_sqrt.c",
              "../SoftFloat-3d/source/extF80M_sub.c",
              "../SoftFloat-3d/source/extF80M_to_f128M.c",
              "../SoftFloat-3d/source/extF80M_to_f16.c",
              "../SoftFloat-3d/source/extF80M_to_f32.c",
              "../SoftFloat-3d/source/extF80M_to_f64.c",
              "../SoftFloat-3d/source/extF80M_to_i32.c",
              "../SoftFloat-3d/source/extF80M_to_i32_r_minMag.c",
              "../SoftFloat-3d/source/extF80M_to_i64.c",
              "../SoftFloat-3d/source/extF80M_to_i64_r_minMag.c",
              "../SoftFloat-3d/source/extF80M_to_ui32.c",
              "../SoftFloat-3d/source/extF80M_to_ui32_r_minMag.c",
              "../SoftFloat-3d/source/extF80M_to_ui64.c",
              "../SoftFloat-3d/source/extF80M_to_ui64_r_minMag.c",
              "../SoftFloat-3d/source/extF80_add.c",
              "../SoftFloat-3d/source/extF80_div.c",
              "../SoftFloat-3d/source/extF80_eq.c",
              "../SoftFloat-3d/source/extF80_eq_signaling.c",
              "../SoftFloat-3d/source/extF80_isSignalingNaN.c",
              "../SoftFloat-3d/source/extF80_le.c",
              "../SoftFloat-3d/source/extF80_le_quiet.c",
              "../SoftFloat-3d/source/extF80_lt.c",
              "../SoftFloat-3d/source/extF80_lt_quiet.c",
              "../SoftFloat-3d/source/extF80_mul.c",
              "../SoftFloat-3d/source/extF80_rem.c",
              "../SoftFloat-3d/source/extF80_roundToInt.c",
              "../SoftFloat-3d/source/extF80_sqrt.c",
              "../SoftFloat-3d/source/extF80_sub.c",
              "../SoftFloat-3d/source/extF80_to_f128.c",
              "../SoftFloat-3d/source/extF80_to_f16.c",
              "../SoftFloat-3d/source/extF80_to_f32.c",
              "../SoftFloat-3d/source/extF80_to_f64.c",
              "../SoftFloat-3d/source/extF80_to_i32.c",
              "../SoftFloat-3d/source/extF80_to_i32_r_minMag.c",
              "../SoftFloat-3d/source/extF80_to_i64.c",
              "../SoftFloat-3d/source/extF80_to_i64_r_minMag.c",
              "../SoftFloat-3d/source/extF80_to_ui32.c",
              "../SoftFloat-3d/source/extF80_to_ui32_r_minMag.c",
              "../SoftFloat-3d/source/extF80_to_ui64.c",
              "../SoftFloat-3d/source/extF80_to_ui64_r_minMag.c",
              "../SoftFloat-3d/source/f128M_add.c",
              "../SoftFloat-3d/source/f128M_div.c",
              "../SoftFloat-3d/source/f128M_eq.c",
              "../SoftFloat-3d/source/f128M_eq_signaling.c",
              "../SoftFloat-3d/source/f128M_le.c",
              "../SoftFloat-3d/source/f128M_le_quiet.c",
              "../SoftFloat-3d/source/f128M_lt.c",
              "../SoftFloat-3d/source/f128M_lt_quiet.c",
              "../SoftFloat-3d/source/f128M_mul.c",
              "../SoftFloat-3d/source/f128M_mulAdd.c",
              "../SoftFloat-3d/source/f128M_rem.c",
              "../SoftFloat-3d/source/f128M_roundToInt.c",
              "../SoftFloat-3d/source/f128M_sqrt.c",
              "../SoftFloat-3d/source/f128M_sub.c",
              "../SoftFloat-3d/source/f128M_to_extF80M.c",
              "../SoftFloat-3d/source/f128M_to_f16.c",
              "../SoftFloat-3d/source/f128M_to_f32.c",
              "../SoftFloat-3d/source/f128M_to_f64.c",
              "../SoftFloat-3d/source/f128M_to_i32.c",
              "../SoftFloat-3d/source/f128M_to_i32_r_minMag.c",
              "../SoftFloat-3d/source/f128M_to_i64.c",
              "../SoftFloat-3d/source/f128M_to_i64_r_minMag.c",
              "../SoftFloat-3d/source/f128M_to_ui32.c",
              "../SoftFloat-3d/source/f128M_to_ui32_r_minMag.c",
              "../SoftFloat-3d/source/f128M_to_ui64.c",
              "../SoftFloat-3d/source/f128M_to_ui64_r_minMag.c",
              "../SoftFloat-3d/source/f128_add.c",
              "../SoftFloat-3d/source/f128_div.c",
              "../SoftFloat-3d/source/f128_eq.c",
              "../SoftFloat-3d/source/f128_eq_signaling.c",
              "../SoftFloat-3d/source/f128_isSignalingNaN.c",
              "../SoftFloat-3d/source/f128_le.c",
              "../SoftFloat-3d/source/f128_le_quiet.c",
              "../SoftFloat-3d/source/f128_lt.c",
              "../SoftFloat-3d/source/f128_lt_quiet.c",
              "../SoftFloat-3d/source/f128_mul.c",
              "../SoftFloat-3d/source/f128_mulAdd.c",
              "../SoftFloat-3d/source/f128_rem.c",
              "../SoftFloat-3d/source/f128_roundToInt.c",
              "../SoftFloat-3d/source/f128_sqrt.c",
              "../SoftFloat-3d/source/f128_sub.c",
              "../SoftFloat-3d/source/f128_to_extF80.c",
              "../SoftFloat-3d/source/f128_to_f16.c",
              "../SoftFloat-3d/source/f128_to_f32.c",
              "../SoftFloat-3d/source/f128_to_f64.c",
              "../SoftFloat-3d/source/f128_to_i32.c",
              "../SoftFloat-3d/source/f128_to_i32_r_minMag.c",
              "../SoftFloat-3d/source/f128_to_i64.c",
              "../SoftFloat-3d/source/f128_to_i64_r_minMag.c",
              "../SoftFloat-3d/source/f128_to_ui32.c",
              "../SoftFloat-3d/source/f128_to_ui32_r_minMag.c",
              "../SoftFloat-3d/source/f128_to_ui64.c",
              "../SoftFloat-3d/source/f128_to_ui64_r_minMag.c",
              "../SoftFloat-3d/source/f16_add.c",
              "../SoftFloat-3d/source/f16_div.c",
              "../SoftFloat-3d/source/f16_eq.c",
              "../SoftFloat-3d/source/f16_eq_signaling.c",
              "../SoftFloat-3d/source/f16_isSignalingNaN.c",
              "../SoftFloat-3d/source/f16_le.c",
              "../SoftFloat-3d/source/f16_le_quiet.c",
              "../SoftFloat-3d/source/f16_lt.c",
              "../SoftFloat-3d/source/f16_lt_quiet.c",
              "../SoftFloat-3d/source/f16_mul.c",
              "../SoftFloat-3d/source/f16_mulAdd.c",
              "../SoftFloat-3d/source/f16_rem.c",
              "../SoftFloat-3d/source/f16_roundToInt.c",
              "../SoftFloat-3d/source/f16_sqrt.c",
              "../SoftFloat-3d/source/f16_sub.c",
              "../SoftFloat-3d/source/f16_to_extF80.c",
              "../SoftFloat-3d/source/f16_to_extF80M.c",
              "../SoftFloat-3d/source/f16_to_f128.c",
              "../SoftFloat-3d/source/f16_to_f128M.c",
              "../SoftFloat-3d/source/f16_to_f32.c",
              "../SoftFloat-3d/source/f16_to_f64.c",
              "../SoftFloat-3d/source/f16_to_i32.c",
              "../SoftFloat-3d/source/f16_to_i32_r_minMag.c",
              "../SoftFloat-3d/source/f16_to_i64.c",
              "../SoftFloat-3d/source/f16_to_i64_r_minMag.c",
              "../SoftFloat-3d/source/f16_to_ui32.c",
              "../SoftFloat-3d/source/f16_to_ui32_r_minMag.c",
              "../SoftFloat-3d/source/f16_to_ui64.c",
              "../SoftFloat-3d/source/f16_to_ui64_r_minMag.c",
              "../SoftFloat-3d/source/f32_add.c",
              "../SoftFloat-3d/source/f32_div.c",
              "../SoftFloat-3d/source/f32_eq.c",
              "../SoftFloat-3d/source/f32_eq_signaling.c",
              "../SoftFloat-3d/source/f32_isSignalingNaN.c",
              "../SoftFloat-3d/source/f32_le.c",
              "../SoftFloat-3d/source/f32_le_quiet.c",
              "../SoftFloat-3d/source/f32_lt.c",
              "../SoftFloat-3d/source/f32_lt_quiet.c",
              "../SoftFloat-3d/source/f32_mul.c",
              "../SoftFloat-3d/source/f32_mulAdd.c",
              "../SoftFloat-3d/source/f32_rem.c",
              "../SoftFloat-3d/source/f32_roundToInt.c",
              "../SoftFloat-3d/source/f32_sqrt.c",
              "../SoftFloat-3d/source/f32_sub.c",
              "../SoftFloat-3d/source/f32_to_extF80.c",
              "../SoftFloat-3d/source/f32_to_extF80M.c",
              "../SoftFloat-3d/source/f32_to_f128.c",
              "../SoftFloat-3d/source/f32_to_f128M.c",
              "../SoftFloat-3d/source/f32_to_f16.c",
              "../SoftFloat-3d/source/f32_to_f64.c",
              "../SoftFloat-3d/source/f32_to_i32.c",
              "../SoftFloat-3d/source/f32_to_i32_r_minMag.c",
              "../SoftFloat-3d/source/f32_to_i64.c",
              "../SoftFloat-3d/source/f32_to_i64_r_minMag.c",
              "../SoftFloat-3d/source/f32_to_ui32.c",
              "../SoftFloat-3d/source/f32_to_ui32_r_minMag.c",
              "../SoftFloat-3d/source/f32_to_ui64.c",
              "../SoftFloat-3d/source/f32_to_ui64_r_minMag.c",
              "../SoftFloat-3d/source/f64_add.c",
              "../SoftFloat-3d/source/f64_div.c",
              "../SoftFloat-3d/source/f64_eq.c",
              "../SoftFloat-3d/source/f64_eq_signaling.c",
              "../SoftFloat-3d/source/f64_isSignalingNaN.c",
              "../SoftFloat-3d/source/f64_le.c",
              "../SoftFloat-3d/source/f64_le_quiet.c",
              "../SoftFloat-3d/source/f64_lt.c",
              "../SoftFloat-3d/source/f64_lt_quiet.c",
              "../SoftFloat-3d/source/f64_mul.c",
              "../SoftFloat-3d/source/f64_mulAdd.c",
              "../SoftFloat-3d/source/f64_rem.c",
              "../SoftFloat-3d/source/f64_roundToInt.c",
              "../SoftFloat-3d/source/f64_sqrt.c",
              "../SoftFloat-3d/source/f64_sub.c",
              "../SoftFloat-3d/source/f64_to_extF80.c",
              "../SoftFloat-3d/source/f64_to_extF80M.c",
              "../SoftFloat-3d/source/f64_to_f128.c",
              "../SoftFloat-3d/source/f64_to_f128M.c",
              "../SoftFloat-3d/source/f64_to_f16.c",
              "../SoftFloat-3d/source/f64_to_f32.c",
              "../SoftFloat-3d/source/f64_to_i32.c",
              "../SoftFloat-3d/source/f64_to_i32_r_minMag.c",
              "../SoftFloat-3d/source/f64_to_i64.c",
              "../SoftFloat-3d/source/f64_to_i64_r_minMag.c",
              "../SoftFloat-3d/source/f64_to_ui32.c",
              "../SoftFloat-3d/source/f64_to_ui32_r_minMag.c",
              "../SoftFloat-3d/source/f64_to_ui64.c",
              "../SoftFloat-3d/source/f64_to_ui64_r_minMag.c",
              "../SoftFloat-3d/source/i32_to_extF80.c",
              "../SoftFloat-3d/source/i32_to_extF80M.c",
              "../SoftFloat-3d/source/i32_to_f128.c",
              "../SoftFloat-3d/source/i32_to_f128M.c",
              "../SoftFloat-3d/source/i32_to_f16.c",
              "../SoftFloat-3d/source/i32_to_f32.c",
              "../SoftFloat-3d/source/i32_to_f64.c",
              "../SoftFloat-3d/source/i64_to_extF80.c",
              "../SoftFloat-3d/source/i64_to_extF80M.c",
              "../SoftFloat-3d/source/i64_to_f128.c",
              "../SoftFloat-3d/source/i64_to_f128M.c",
              "../SoftFloat-3d/source/i64_to_f16.c",
              "../SoftFloat-3d/source/i64_to_f32.c",
              "../SoftFloat-3d/source/i64_to_f64.c",
              "../SoftFloat-3d/source/s_add128.c",
              "../SoftFloat-3d/source/s_add256M.c",
              "../SoftFloat-3d/source/s_addCarryM.c",
              "../SoftFloat-3d/source/s_addComplCarryM.c",
              "../SoftFloat-3d/source/s_addM.c",
              "../SoftFloat-3d/source/s_addMagsExtF80.c",
              "../SoftFloat-3d/source/s_addMagsF128.c",
              "../SoftFloat-3d/source/s_addMagsF16.c",
              "../SoftFloat-3d/source/s_addMagsF32.c",
              "../SoftFloat-3d/source/s_addMagsF64.c",
              "../SoftFloat-3d/source/s_approxRecip32_1.c",
              "../SoftFloat-3d/source/s_approxRecipSqrt32_1.c",
              "../SoftFloat-3d/source/s_approxRecipSqrt_1Ks.c",
              "../SoftFloat-3d/source/s_approxRecip_1Ks.c",
              "../SoftFloat-3d/source/s_compare128M.c",
              "../SoftFloat-3d/source/s_compare96M.c",
              "../SoftFloat-3d/source/s_compareNonnormExtF80M.c",
              "../SoftFloat-3d/source/s_countLeadingZeros16.c",
              "../SoftFloat-3d/source/s_countLeadingZeros32.c",
              "../SoftFloat-3d/source/s_countLeadingZeros64.c",
              "../SoftFloat-3d/source/s_countLeadingZeros8.c",
              "../SoftFloat-3d/source/s_eq128.c",
              "../SoftFloat-3d/source/s_invalidExtF80M.c",
              "../SoftFloat-3d/source/s_isNaNF128M.c",
              "../SoftFloat-3d/source/s_le128.c",
              "../SoftFloat-3d/source/s_lt128.c",
              "../SoftFloat-3d/source/s_mul128By32.c",
              "../SoftFloat-3d/source/s_mul128MTo256M.c",
              "../SoftFloat-3d/source/s_mul128To256M.c",
              "../SoftFloat-3d/source/s_mul64ByShifted32To128.c",
              "../SoftFloat-3d/source/s_mul64To128.c",
              "../SoftFloat-3d/source/s_mul64To128M.c",
              "../SoftFloat-3d/source/s_mulAddF128.c",
              "../SoftFloat-3d/source/s_mulAddF16.c",
              "../SoftFloat-3d/source/s_mulAddF32.c",
              "../SoftFloat-3d/source/s_mulAddF64.c",
              "../SoftFloat-3d/source/s_negXM.c",
              "../SoftFloat-3d/source/s_normExtF80SigM.c",
              "../SoftFloat-3d/source/s_normRoundPackMToExtF80M.c",
              "../SoftFloat-3d/source/s_normRoundPackMToF128M.c",
              "../SoftFloat-3d/source/s_normRoundPackToExtF80.c",
              "../SoftFloat-3d/source/s_normRoundPackToF128.c",
              "../SoftFloat-3d/source/s_normRoundPackToF16.c",
              "../SoftFloat-3d/source/s_normRoundPackToF32.c",
              "../SoftFloat-3d/source/s_normRoundPackToF64.c",
              "../SoftFloat-3d/source/s_normSubnormalExtF80Sig.c",
              "../SoftFloat-3d/source/s_normSubnormalF128Sig.c",
              "../SoftFloat-3d/source/s_normSubnormalF128SigM.c",
              "../SoftFloat-3d/source/s_normSubnormalF16Sig.c",
              "../SoftFloat-3d/source/s_normSubnormalF32Sig.c",
              "../SoftFloat-3d/source/s_normSubnormalF64Sig.c",
              "../SoftFloat-3d/source/s_remStepMBy32.c",
              "../SoftFloat-3d/source/s_roundMToI64.c",
              "../SoftFloat-3d/source/s_roundMToUI64.c",
              "../SoftFloat-3d/source/s_roundPackMToExtF80M.c",
              "../SoftFloat-3d/source/s_roundPackMToF128M.c",
              "../SoftFloat-3d/source/s_roundPackToExtF80.c",
              "../SoftFloat-3d/source/s_roundPackToF128.c",
              "../SoftFloat-3d/source/s_roundPackToF16.c",
              "../SoftFloat-3d/source/s_roundPackToF32.c",
              "../SoftFloat-3d/source/s_roundPackToF64.c",
              "../SoftFloat-3d/source/s_roundToI32.c",
              "../SoftFloat-3d/source/s_roundToI64.c",
              "../SoftFloat-3d/source/s_roundToUI32.c",
              "../SoftFloat-3d/source/s_roundToUI64.c",
              "../SoftFloat-3d/source/s_shiftLeftM.c",
              "../SoftFloat-3d/source/s_shiftNormSigF128M.c",
              "../SoftFloat-3d/source/s_shiftRightJam128.c",
              "../SoftFloat-3d/source/s_shiftRightJam128Extra.c",
              "../SoftFloat-3d/source/s_shiftRightJam256M.c",
              "../SoftFloat-3d/source/s_shiftRightJam32.c",
              "../SoftFloat-3d/source/s_shiftRightJam64.c",
              "../SoftFloat-3d/source/s_shiftRightJam64Extra.c",
              "../SoftFloat-3d/source/s_shiftRightJamM.c",
              "../SoftFloat-3d/source/s_shiftRightM.c",
              "../SoftFloat-3d/source/s_shortShiftLeft128.c",
              "../SoftFloat-3d/source/s_shortShiftLeft64To96M.c",
              "../SoftFloat-3d/source/s_shortShiftLeftM.c",
              "../SoftFloat-3d/source/s_shortShiftRight128.c",
              "../SoftFloat-3d/source/s_shortShiftRightExtendM.c",
              "../SoftFloat-3d/source/s_shortShiftRightJam128.c",
              "../SoftFloat-3d/source/s_shortShiftRightJam128Extra.c",
              "../SoftFloat-3d/source/s_shortShiftRightJam64.c",
              "../SoftFloat-3d/source/s_shortShiftRightJam64Extra.c",
              "../SoftFloat-3d/source/s_shortShiftRightJamM.c",
              "../SoftFloat-3d/source/s_shortShiftRightM.c",
              "../SoftFloat-3d/source/s_sub128.c",
              "../SoftFloat-3d/source/s_sub1XM.c",
              "../SoftFloat-3d/source/s_sub256M.c",
              "../SoftFloat-3d/source/s_subM.c",
              "../SoftFloat-3d/source/s_subMagsExtF80.c",
              "../SoftFloat-3d/source/s_subMagsF128.c",
              "../SoftFloat-3d/source/s_subMagsF16.c",
              "../SoftFloat-3d/source/s_subMagsF32.c",
              "../SoftFloat-3d/source/s_subMagsF64.c",
              "../SoftFloat-3d/source/s_tryPropagateNaNExtF80M.c",
              "../SoftFloat-3d/source/s_tryPropagateNaNF128M.c",
              "../SoftFloat-3d/source/softfloat_state.c",
              "../SoftFloat-3d/source/ui32_to_extF80.c",
              "../SoftFloat-3d/source/ui32_to_extF80M.c",
              "../SoftFloat-3d/source/ui32_to_f128.c",
              "../SoftFloat-3d/source/ui32_to_f128M.c",
              "../SoftFloat-3d/source/ui32_to_f16.c",
              "../SoftFloat-3d/source/ui32_to_f32.c",
              "../SoftFloat-3d/source/ui32_to_f64.c",
              "../SoftFloat-3d/source/ui64_to_extF80.c",
              "../SoftFloat-3d/source/ui64_to_extF80M.c",
              "../SoftFloat-3d/source/ui64_to_f128.c",
              "../SoftFloat-3d/source/ui64_to_f128M.c",
              "../SoftFloat-3d/source/ui64_to_f16.c",
              "../SoftFloat-3d/source/ui64_to_f32.c",
              "../SoftFloat-3d/source/ui64_to_f64.c",
              "../SoftFloat-3d/source/riscv/s_commonNaNToF128UI.c",
              "../SoftFloat-3d/source/riscv/s_commonNaNToF16UI.c",
              "../SoftFloat-3d/source/riscv/s_commonNaNToF32UI.c",
              "../SoftFloat-3d/source/riscv/s_commonNaNToF64UI.c",
              "../SoftFloat-3d/source/riscv/s_f128UIToCommonNaN.c",
              "../SoftFloat-3d/source/riscv/s_f16UIToCommonNaN.c",
              "../SoftFloat-3d/source/riscv/s_f32UIToCommonNaN.c",
              "../SoftFloat-3d/source/riscv/s_f64UIToCommonNaN.c",
              "../SoftFloat-3d/source/riscv/s_propagateNaNF128UI.c",
              "../SoftFloat-3d/source/riscv/s_propagateNaNF16UI.c",
              "../SoftFloat-3d/source/riscv/s_propagateNaNF32UI.c",
              "../SoftFloat-3d/source/riscv/s_propagateNaNF64UI.c",
              "../SoftFloat-3d/source/riscv/softfloat_raiseFlags.c"],
             compile_options, [], []


if ARGV.length == 0 then
  exec_target "libsoftfloat.a"
elsif ARGV[0] == "clean" then
  clean_target "libsoftfloat.a"
elsif ARGV[0] == "draw" then
  draw_target "libsoftfloat.a"
else
  instance_eval("exec_target ARGV[0]")
end
