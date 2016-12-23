/*
 * Servo_PID_data.c
 *
 * Code generation for model "Servo_PID".
 *
 * Model version              : 1.286
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Wed Dec 21 15:01:11 2016
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Servo_PID.h"
#include "Servo_PID_private.h"

/* Block parameters (auto storage) */
P_Servo_PID_T Servo_PID_P = {
  1.0,                                 /* Expression: Tfiltra
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  0.1,                                 /* Expression: Tsampling
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  1.0,                                 /* Expression: ksi
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  1.0,                                 /* Expression: ksie
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  0.95,                                /* Expression: lambda
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  3.0,                                 /* Expression: omega
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */
  9.0,                                 /* Expression: omegae
                                        * Referenced by: '<Root>/MATLAB Function'
                                        */

  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S3>/Encoder'
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/Encoder'
                                        */

  /*  Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S3>/Encoder'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/Encoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Encoder 1024 PPR'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S3>/Convert to rad'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.31415926535897931,                 /* Expression: 2*pi/20
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  300.0,                               /* Expression: 300
                                        * Referenced by: '<Root>/Step'
                                        */
  -20.0,                               /* Computed Parameter: Simplefilter_A
                                        * Referenced by: '<S2>/Simple filter'
                                        */
  20.0,                                /* Computed Parameter: Simplefilter_C
                                        * Referenced by: '<S2>/Simple filter'
                                        */
  1.0,                                 /* Expression: a
                                        * Referenced by: '<Root>/Constant'
                                        */
  186.0,                               /* Expression: b
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */

  /*  Computed Parameter: RTDACAnalogInputs1_P1_Size
   * Referenced by: '<S3>/RT-DAC Analog Inputs1'
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/RT-DAC Analog Inputs1'
                                        */

  /*  Computed Parameter: RTDACAnalogInputs1_P2_Size
   * Referenced by: '<S3>/RT-DAC Analog Inputs1'
   */
  { 1.0, 2.0 },

  /*  Expression: [1 0]
   * Referenced by: '<S3>/RT-DAC Analog Inputs1'
   */
  { 1.0, 0.0 },

  /*  Computed Parameter: RTDACAnalogInputs1_P3_Size
   * Referenced by: '<S3>/RT-DAC Analog Inputs1'
   */
  { 1.0, 2.0 },

  /*  Expression: [1 1]
   * Referenced by: '<S3>/RT-DAC Analog Inputs1'
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: RTDACAnalogInputs1_P4_Size
   * Referenced by: '<S3>/RT-DAC Analog Inputs1'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/RT-DAC Analog Inputs1'
                                        */
  20.4,                                /* Expression: 20.4
                                        * Referenced by: '<S3>/Convert to rad//s'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Saturation'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S3>/PWM'
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWM'
                                        */

  /*  Computed Parameter: PWM_P2_Size
   * Referenced by: '<S3>/PWM'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/PWMGain'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S3>/ResetEncoder'
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */

  /*  Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S3>/ResetEncoder'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/ResetEncoderGain'
                                        */

  /*  Computed Parameter: BitstreamVersion_P1_Size
   * Referenced by: '<S3>/Bitstream Version'
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/Bitstream Version'
                                        */

  /*  Computed Parameter: BitstreamVersion_P2_Size
   * Referenced by: '<S3>/Bitstream Version'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/Bitstream Version'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S3>/PWMPrescalerSource'
                                        */

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S3>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */

  /*  Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S3>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/PWMPrescalerGain'
                                        */

  /*  Computed Parameter: ThermStatus_P1_Size
   * Referenced by: '<S3>/Therm Status'
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/Therm Status'
                                        */

  /*  Computed Parameter: ThermStatus_P2_Size
   * Referenced by: '<S3>/Therm Status'
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/Therm Status'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/PWM Therm Status'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/ThermFlagSource'
                                        */

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S3>/ThermFlag '
   */
  { 1.0, 1.0 },
  52992.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ThermFlag '
                                        */

  /*  Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S3>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.002,                               /* Expression: T0
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/ThermFlagGain'
                                        */
  0U                                   /* Computed Parameter: ResetEncodersRealtimeonly_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders Real-time only'
                                        */
};
