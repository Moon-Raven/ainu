/*
 * Servo_PID_private.h
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
#ifndef RTW_HEADER_Servo_PID_private_h_
#define RTW_HEADER_Servo_PID_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void Servo_Encoder(SimStruct *rts);
extern void servo_analoginputs(SimStruct *rts);
extern void Servo_PWM(SimStruct *rts);
extern void Servo_ResetEncoder(SimStruct *rts);
extern void Servo_BitstreamVersion(SimStruct *rts);
extern void Servo_PWMPrescaler(SimStruct *rts);
extern void Servo_PWMTherm(SimStruct *rts);
extern void Servo_ThermFlag(SimStruct *rts);

/* private model entry point functions */
extern void Servo_PID_derivatives(void);

#endif                                 /* RTW_HEADER_Servo_PID_private_h_ */
