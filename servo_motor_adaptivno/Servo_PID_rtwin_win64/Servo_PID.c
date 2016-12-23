/*
 * Servo_PID.c
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
#include "Servo_PID_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.002, 0.0,
};

/* Block signals (auto storage) */
B_Servo_PID_T Servo_PID_B;

/* Continuous states */
X_Servo_PID_T Servo_PID_X;

/* Block states (auto storage) */
DW_Servo_PID_T Servo_PID_DW;

/* Real-time model */
RT_MODEL_Servo_PID_T Servo_PID_M_;
RT_MODEL_Servo_PID_T *const Servo_PID_M = &Servo_PID_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Servo_PID_M->Timing.TaskCounters.TID[2])++;
  if ((Servo_PID_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.1s, 0.0s] */
    Servo_PID_M->Timing.TaskCounters.TID[2] = 0;
  }

  Servo_PID_M->Timing.sampleHits[2] = (Servo_PID_M->Timing.TaskCounters.TID[2] ==
    0);
}

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Servo_PID_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  Servo_PID_output();
  Servo_PID_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  Servo_PID_output();
  Servo_PID_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  Servo_PID_output();
  Servo_PID_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  Servo_PID_output();
  Servo_PID_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  Servo_PID_output();
  Servo_PID_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Servo_PID_output(void)
{
  real_T p;
  real_T uf;
  real_T A;
  real_T rtb_control;
  real_T tmp[4];
  int32_T i;
  real_T tmp_0[4];
  real_T phi_idx;
  real_T phi_idx_0;
  real_T phi_idx_1;
  real_T phi_idx_2;
  real_T phi_idx_3;
  real_T phi_idx_4;
  if (rtmIsMajorTimeStep(Servo_PID_M)) {
    /* set solver stop time */
    if (!(Servo_PID_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Servo_PID_M->solverInfo,
                            ((Servo_PID_M->Timing.clockTickH0 + 1) *
        Servo_PID_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Servo_PID_M->solverInfo,
                            ((Servo_PID_M->Timing.clockTick0 + 1) *
        Servo_PID_M->Timing.stepSize0 + Servo_PID_M->Timing.clockTickH0 *
        Servo_PID_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Servo_PID_M)) {
    Servo_PID_M->Timing.t[0] = rtsiGetT(&Servo_PID_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S3>/Encoder' (Servo_Encoder) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/Convert to rad' incorporates:
     *  Gain: '<S3>/Encoder 1024 PPR'
     */
    Servo_PID_B.Converttorad[0] = Servo_PID_P.Encoder1024PPR_Gain *
      Servo_PID_B.Encoder[0] * Servo_PID_P.Converttorad_Gain;
    Servo_PID_B.Converttorad[1] = Servo_PID_P.Encoder1024PPR_Gain *
      Servo_PID_B.Encoder[1] * Servo_PID_P.Converttorad_Gain;
  }

  /* Step: '<Root>/Step' */
  if (Servo_PID_M->Timing.t[0] < Servo_PID_P.Step_Time) {
    phi_idx = Servo_PID_P.Step_Y0;
  } else {
    phi_idx = Servo_PID_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  Servo_PID_B.Sum = (sin(Servo_PID_P.SineWave_Freq * Servo_PID_M->Timing.t[0] +
    Servo_PID_P.SineWave_Phase) * Servo_PID_P.SineWave_Amp +
                     Servo_PID_P.SineWave_Bias) + phi_idx;

  /* TransferFcn: '<S2>/Simple filter' */
  Servo_PID_B.filterdvelocity = 0.0;
  Servo_PID_B.filterdvelocity += Servo_PID_P.Simplefilter_C *
    Servo_PID_X.Simplefilter_CSTATE;
  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[2] == 0) {
    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S1>:1' */
    if ((!Servo_PID_DW.x1hat_not_empty) || (!Servo_PID_DW.x2hat_not_empty) ||
        (!Servo_PID_DW.uprev_not_empty)) {
      /* '<S1>:1:4' */
      /* '<S1>:1:5' */
      Servo_PID_DW.x1hat = 0.0;
      Servo_PID_DW.x1hat_not_empty = TRUE;

      /* '<S1>:1:6' */
      Servo_PID_DW.x2hat = 0.0;
      Servo_PID_DW.x2hat_not_empty = TRUE;

      /* '<S1>:1:7' */
      Servo_PID_DW.uprev = 0.0;
      Servo_PID_DW.uprev_not_empty = TRUE;
    }

    /*  Filtering */
    /* '<S1>:1:17' */
    p = exp(-Servo_PID_P.MATLABFunction_Tsampling /
            Servo_PID_P.MATLABFunction_Tfiltra);

    /* '<S1>:1:19' */
    uf = (1.0 - p) * Servo_PID_DW.uprev + p * Servo_PID_DW.ufp;

    /* '<S1>:1:20' */
    Servo_PID_DW.ufp = uf;

    /* '<S1>:1:22' */
    p = (1.0 - p) * Servo_PID_B.filterdvelocity + p * Servo_PID_DW.x2fp;

    /* '<S1>:1:23' */
    A = p - Servo_PID_DW.x2fp;

    /* '<S1>:1:24' */
    Servo_PID_DW.x2fp = p;

    /*  Kalman */
    /* '<S1>:1:33' */
    phi_idx = -p;
    phi_idx_0 = uf;

    /* '<S1>:1:35' */
    uf = 1.0 / Servo_PID_P.MATLABFunction_lambda;
    p = ((-p * Servo_PID_DW.P[0] + phi_idx_0 * Servo_PID_DW.P[1]) * -p + (-p *
          Servo_PID_DW.P[2] + phi_idx_0 * Servo_PID_DW.P[3]) * phi_idx_0) +
      Servo_PID_P.MATLABFunction_lambda;
    phi_idx_1 = phi_idx * phi_idx;
    phi_idx_2 = phi_idx * phi_idx_0;
    phi_idx_3 = phi_idx_0 * phi_idx;
    phi_idx_4 = phi_idx_0 * phi_idx_0;
    for (i = 0; i < 2; i++) {
      tmp[i] = 0.0;
      tmp[i] += Servo_PID_DW.P[i << 1] * phi_idx_1;
      tmp[i] += Servo_PID_DW.P[(i << 1) + 1] * phi_idx_3;
      tmp[i + 2] = 0.0;
      tmp[i + 2] += Servo_PID_DW.P[i << 1] * phi_idx_2;
      tmp[i + 2] += Servo_PID_DW.P[(i << 1) + 1] * phi_idx_4;
    }

    for (i = 0; i < 2; i++) {
      tmp_0[i] = (tmp[i + 2] * Servo_PID_DW.P[1] + tmp[i] * Servo_PID_DW.P[0]) /
        p + Servo_PID_DW.P[i];
      tmp_0[i + 2] = (tmp[i + 2] * Servo_PID_DW.P[3] + tmp[i] * Servo_PID_DW.P[2])
        / p + Servo_PID_DW.P[i + 2];
    }

    Servo_PID_DW.P[0] = uf * tmp_0[0];
    Servo_PID_DW.P[1] = uf * tmp_0[1];
    Servo_PID_DW.P[2] = uf * tmp_0[2];
    Servo_PID_DW.P[3] = uf * tmp_0[3];

    /* '<S1>:1:36' */
    p = A / Servo_PID_P.MATLABFunction_Tsampling - (phi_idx *
      Servo_PID_DW.theta[0] + phi_idx_0 * Servo_PID_DW.theta[1]);
    Servo_PID_DW.theta[0] += (Servo_PID_DW.P[0] * phi_idx + Servo_PID_DW.P[2] *
      phi_idx_0) * p;
    Servo_PID_DW.theta[1] += (Servo_PID_DW.P[1] * phi_idx + Servo_PID_DW.P[3] *
      phi_idx_0) * p;

    /* '<S1>:1:37' */
    Servo_PID_B.ahat = Servo_PID_DW.theta[0];

    /* '<S1>:1:38' */
    Servo_PID_B.bhat = Servo_PID_DW.theta[1];

    /*  Control & observer */
    /* '<S1>:1:42' */
    /* '<S1>:1:45' */
    uf = Servo_PID_P.MATLABFunction_omega * Servo_PID_P.MATLABFunction_omega /
      186.0;

    /* '<S1>:1:46' */
    /* '<S1>:1:49' */
    p = 2.0 * Servo_PID_P.MATLABFunction_ksie;

    /* '<S1>:1:50' */
    /* '<S1>:1:52' */
    phi_idx = ((p * Servo_PID_P.MATLABFunction_omegae - 1.0) *
               (Servo_PID_B.Converttorad[1] - Servo_PID_DW.x1hat) +
               Servo_PID_DW.x2hat) * Servo_PID_P.MATLABFunction_Tsampling +
      Servo_PID_DW.x1hat;

    /* '<S1>:1:53' */
    A = ((Servo_PID_P.MATLABFunction_omegae * Servo_PID_P.MATLABFunction_omegae
          - (p * Servo_PID_P.MATLABFunction_omegae - 1.0)) *
         (Servo_PID_B.Converttorad[1] - Servo_PID_DW.x1hat) + (186.0 *
          Servo_PID_DW.uprev + -Servo_PID_DW.x2hat)) *
      Servo_PID_P.MATLABFunction_Tsampling + Servo_PID_DW.x2hat;

    /* '<S1>:1:54' */
    Servo_PID_DW.x1hat = phi_idx;

    /* '<S1>:1:55' */
    Servo_PID_DW.x2hat = A;

    /*  u=-k1*y-k2*dy+kr*r; */
    /* '<S1>:1:58' */
    p = (-uf * Servo_PID_DW.x1hat - (2.0 * Servo_PID_P.MATLABFunction_ksi *
          Servo_PID_P.MATLABFunction_omega - 1.0) / 186.0 * Servo_PID_DW.x2hat)
      + uf * Servo_PID_B.Sum;
    if (p > 1.0) {
      /* '<S1>:1:60' */
      /* '<S1>:1:61' */
      p = 1.0;
    } else {
      if (p < -1.0) {
        /* '<S1>:1:62' */
        /* '<S1>:1:63' */
        p = -1.0;
      }
    }

    /* '<S1>:1:66' */
    Servo_PID_DW.uprev = p;
    Servo_PID_B.u = p;
    Servo_PID_B.x1hatnew = phi_idx;
    Servo_PID_B.x2hatnew = A;

    /* End of MATLAB Function: '<Root>/MATLAB Function' */
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[2] == 0) {
    /* Constant: '<Root>/Constant' */
    Servo_PID_B.pos = Servo_PID_P.Constant_Value;

    /* Constant: '<Root>/Constant1' */
    Servo_PID_B.Constant1 = Servo_PID_P.Constant1_Value;
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[1] == 0) {
    /* ManualSwitch: '<Root>/Reset Encoders Real-time only' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (Servo_PID_P.ResetEncodersRealtimeonly_CurrentSetting == 1) {
      Servo_PID_B.Reset = Servo_PID_P.Reset_Value;
    } else {
      Servo_PID_B.Reset = Servo_PID_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders Real-time only' */
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[2] == 0) {
    /* Saturate: '<Root>/Saturation' */
    if (Servo_PID_B.u >= Servo_PID_P.Saturation_UpperSat) {
      rtb_control = Servo_PID_P.Saturation_UpperSat;
    } else if (Servo_PID_B.u <= Servo_PID_P.Saturation_LowerSat) {
      rtb_control = Servo_PID_P.Saturation_LowerSat;
    } else {
      rtb_control = Servo_PID_B.u;
    }

    /* End of Saturate: '<Root>/Saturation' */
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S3>/RT-DAC Analog Inputs1' (servo_analoginputs) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/Convert to rad//s' */
    Servo_PID_B.Converttorads = Servo_PID_P.Converttorads_Gain *
      Servo_PID_B.RTDACAnalogInputs1[0];
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[2] == 0) {
    /* Saturate: '<S3>/Saturation' */
    if (rtb_control >= Servo_PID_P.Saturation_UpperSat_i) {
      Servo_PID_B.Saturation = Servo_PID_P.Saturation_UpperSat_i;
    } else if (rtb_control <= Servo_PID_P.Saturation_LowerSat_f) {
      Servo_PID_B.Saturation = Servo_PID_P.Saturation_LowerSat_f;
    } else {
      Servo_PID_B.Saturation = rtb_control;
    }

    /* End of Saturate: '<S3>/Saturation' */
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<S3>/PWM' (Servo_PWM) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/PWMGain' */
    Servo_PID_B.PWMGain = Servo_PID_P.PWMGain_Gain * Servo_PID_B.PWM;

    /* Level2 S-Function Block: '<S3>/ResetEncoder' (Servo_ResetEncoder) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/ResetEncoderGain' */
    Servo_PID_B.ResetEncoderGain[0] = Servo_PID_P.ResetEncoderGain_Gain *
      Servo_PID_B.ResetEncoder[0];
    Servo_PID_B.ResetEncoderGain[1] = Servo_PID_P.ResetEncoderGain_Gain *
      Servo_PID_B.ResetEncoder[1];

    /* Level2 S-Function Block: '<S3>/Bitstream Version' (Servo_BitstreamVersion) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Servo_PWMPrescaler) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/PWMPrescalerGain' */
    Servo_PID_B.PWMPrescalerGain = Servo_PID_P.PWMPrescalerGain_Gain *
      Servo_PID_B.PWMPrescaler;

    /* Level2 S-Function Block: '<S3>/Therm Status' (Servo_PWMTherm) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/PWM Therm Status' */
    Servo_PID_B.PWMThermStatus = Servo_PID_P.PWMThermStatus_Gain *
      Servo_PID_B.ThermStatus;

    /* Level2 S-Function Block: '<S3>/ThermFlag ' (Servo_ThermFlag) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/ThermFlagGain' */
    Servo_PID_B.ThermFlagGain = Servo_PID_P.ThermFlagGain_Gain *
      Servo_PID_B.ThermFlag;
  }
}

/* Model update function */
void Servo_PID_update(void)
{
  if (rtmIsMajorTimeStep(Servo_PID_M)) {
    rt_ertODEUpdateContinuousStates(&Servo_PID_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Servo_PID_M->Timing.clockTick0)) {
    ++Servo_PID_M->Timing.clockTickH0;
  }

  Servo_PID_M->Timing.t[0] = rtsiGetSolverStopTime(&Servo_PID_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Servo_PID_M->Timing.clockTick1)) {
      ++Servo_PID_M->Timing.clockTickH1;
    }

    Servo_PID_M->Timing.t[1] = Servo_PID_M->Timing.clockTick1 *
      Servo_PID_M->Timing.stepSize1 + Servo_PID_M->Timing.clockTickH1 *
      Servo_PID_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(Servo_PID_M) &&
      Servo_PID_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Servo_PID_M->Timing.clockTick2)) {
      ++Servo_PID_M->Timing.clockTickH2;
    }

    Servo_PID_M->Timing.t[2] = Servo_PID_M->Timing.clockTick2 *
      Servo_PID_M->Timing.stepSize2 + Servo_PID_M->Timing.clockTickH2 *
      Servo_PID_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Servo_PID_derivatives(void)
{
  XDot_Servo_PID_T *_rtXdot;
  _rtXdot = ((XDot_Servo_PID_T *) Servo_PID_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S2>/Simple filter' */
  _rtXdot->Simplefilter_CSTATE = 0.0;
  _rtXdot->Simplefilter_CSTATE += Servo_PID_P.Simplefilter_A *
    Servo_PID_X.Simplefilter_CSTATE;
  _rtXdot->Simplefilter_CSTATE += Servo_PID_B.Converttorads;
}

/* Model initialize function */
void Servo_PID_initialize(void)
{
  /* InitializeConditions for TransferFcn: '<S2>/Simple filter' */
  Servo_PID_X.Simplefilter_CSTATE = 0.0;

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function' */
  Servo_PID_DW.P[0] = 50.0;
  Servo_PID_DW.P[1] = 0.0;
  Servo_PID_DW.P[2] = 0.0;
  Servo_PID_DW.P[3] = 50.0;
  Servo_PID_DW.x1hat_not_empty = FALSE;
  Servo_PID_DW.x2hat_not_empty = FALSE;
  Servo_PID_DW.uprev_not_empty = FALSE;
  Servo_PID_DW.ufp = 0.0;
  Servo_PID_DW.x2fp = 0.0;
  Servo_PID_DW.theta[0] = 0.0;
  Servo_PID_DW.theta[1] = 0.0;
}

/* Model terminate function */
void Servo_PID_terminate(void)
{
  /* Level2 S-Function Block: '<S3>/Encoder' (Servo_Encoder) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/RT-DAC Analog Inputs1' (servo_analoginputs) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWM' (Servo_PWM) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetEncoder' (Servo_ResetEncoder) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Bitstream Version' (Servo_BitstreamVersion) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Servo_PWMPrescaler) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/Therm Status' (Servo_PWMTherm) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ThermFlag ' (Servo_ThermFlag) */
  {
    SimStruct *rts = Servo_PID_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Servo_PID_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Servo_PID_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Servo_PID_initialize();
}

void MdlTerminate(void)
{
  Servo_PID_terminate();
}

/* Registration function */
RT_MODEL_Servo_PID_T *Servo_PID(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Servo_PID_M, 0,
                sizeof(RT_MODEL_Servo_PID_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Servo_PID_M->solverInfo,
                          &Servo_PID_M->Timing.simTimeStep);
    rtsiSetTPtr(&Servo_PID_M->solverInfo, &rtmGetTPtr(Servo_PID_M));
    rtsiSetStepSizePtr(&Servo_PID_M->solverInfo, &Servo_PID_M->Timing.stepSize0);
    rtsiSetdXPtr(&Servo_PID_M->solverInfo, &Servo_PID_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Servo_PID_M->solverInfo, (real_T **)
                         &Servo_PID_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Servo_PID_M->solverInfo,
      &Servo_PID_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Servo_PID_M->solverInfo, (&rtmGetErrorStatus
      (Servo_PID_M)));
    rtsiSetRTModelPtr(&Servo_PID_M->solverInfo, Servo_PID_M);
  }

  rtsiSetSimTimeStep(&Servo_PID_M->solverInfo, MAJOR_TIME_STEP);
  Servo_PID_M->ModelData.intgData.y = Servo_PID_M->ModelData.odeY;
  Servo_PID_M->ModelData.intgData.f[0] = Servo_PID_M->ModelData.odeF[0];
  Servo_PID_M->ModelData.intgData.f[1] = Servo_PID_M->ModelData.odeF[1];
  Servo_PID_M->ModelData.intgData.f[2] = Servo_PID_M->ModelData.odeF[2];
  Servo_PID_M->ModelData.intgData.f[3] = Servo_PID_M->ModelData.odeF[3];
  Servo_PID_M->ModelData.intgData.f[4] = Servo_PID_M->ModelData.odeF[4];
  Servo_PID_M->ModelData.intgData.f[5] = Servo_PID_M->ModelData.odeF[5];
  Servo_PID_M->ModelData.contStates = ((real_T *) &Servo_PID_X);
  rtsiSetSolverData(&Servo_PID_M->solverInfo, (void *)
                    &Servo_PID_M->ModelData.intgData);
  rtsiSetSolverName(&Servo_PID_M->solverInfo,"ode5");
  Servo_PID_M->solverInfoPtr = (&Servo_PID_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Servo_PID_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Servo_PID_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Servo_PID_M->Timing.sampleTimes = (&Servo_PID_M->Timing.sampleTimesArray[0]);
    Servo_PID_M->Timing.offsetTimes = (&Servo_PID_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Servo_PID_M->Timing.sampleTimes[0] = (0.0);
    Servo_PID_M->Timing.sampleTimes[1] = (0.002);
    Servo_PID_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    Servo_PID_M->Timing.offsetTimes[0] = (0.0);
    Servo_PID_M->Timing.offsetTimes[1] = (0.0);
    Servo_PID_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Servo_PID_M, &Servo_PID_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Servo_PID_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    Servo_PID_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Servo_PID_M, 30.0);
  Servo_PID_M->Timing.stepSize0 = 0.002;
  Servo_PID_M->Timing.stepSize1 = 0.002;
  Servo_PID_M->Timing.stepSize2 = 0.1;

  /* External mode info */
  Servo_PID_M->Sizes.checksums[0] = (637846459U);
  Servo_PID_M->Sizes.checksums[1] = (2016294438U);
  Servo_PID_M->Sizes.checksums[2] = (3733618528U);
  Servo_PID_M->Sizes.checksums[3] = (4224207977U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Servo_PID_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Servo_PID_M->extModeInfo,
      &Servo_PID_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Servo_PID_M->extModeInfo, Servo_PID_M->Sizes.checksums);
    rteiSetTPtr(Servo_PID_M->extModeInfo, rtmGetTPtr(Servo_PID_M));
  }

  Servo_PID_M->solverInfoPtr = (&Servo_PID_M->solverInfo);
  Servo_PID_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Servo_PID_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Servo_PID_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Servo_PID_M->ModelData.blockIO = ((void *) &Servo_PID_B);

  {
    Servo_PID_B.Encoder[0] = 0.0;
    Servo_PID_B.Encoder[1] = 0.0;
    Servo_PID_B.Converttorad[0] = 0.0;
    Servo_PID_B.Converttorad[1] = 0.0;
    Servo_PID_B.Sum = 0.0;
    Servo_PID_B.filterdvelocity = 0.0;
    Servo_PID_B.pos = 0.0;
    Servo_PID_B.Constant1 = 0.0;
    Servo_PID_B.Reset = 0.0;
    Servo_PID_B.RTDACAnalogInputs1[0] = 0.0;
    Servo_PID_B.RTDACAnalogInputs1[1] = 0.0;
    Servo_PID_B.Converttorads = 0.0;
    Servo_PID_B.Saturation = 0.0;
    Servo_PID_B.PWM = 0.0;
    Servo_PID_B.PWMGain = 0.0;
    Servo_PID_B.ResetEncoder[0] = 0.0;
    Servo_PID_B.ResetEncoder[1] = 0.0;
    Servo_PID_B.ResetEncoderGain[0] = 0.0;
    Servo_PID_B.ResetEncoderGain[1] = 0.0;
    Servo_PID_B.BitstreamVersion = 0.0;
    Servo_PID_B.PWMPrescaler = 0.0;
    Servo_PID_B.PWMPrescalerGain = 0.0;
    Servo_PID_B.ThermStatus = 0.0;
    Servo_PID_B.PWMThermStatus = 0.0;
    Servo_PID_B.ThermFlag = 0.0;
    Servo_PID_B.ThermFlagGain = 0.0;
    Servo_PID_B.u = 0.0;
    Servo_PID_B.x1hatnew = 0.0;
    Servo_PID_B.x2hatnew = 0.0;
    Servo_PID_B.ahat = 0.0;
    Servo_PID_B.bhat = 0.0;
  }

  /* parameters */
  Servo_PID_M->ModelData.defaultParam = ((real_T *)&Servo_PID_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Servo_PID_X;
    Servo_PID_M->ModelData.contStates = (x);
    (void) memset((void *)&Servo_PID_X, 0,
                  sizeof(X_Servo_PID_T));
  }

  /* states (dwork) */
  Servo_PID_M->ModelData.dwork = ((void *) &Servo_PID_DW);
  (void) memset((void *)&Servo_PID_DW, 0,
                sizeof(DW_Servo_PID_T));
  Servo_PID_DW.x1hat = 0.0;
  Servo_PID_DW.x2hat = 0.0;
  Servo_PID_DW.uprev = 0.0;
  Servo_PID_DW.ufp = 0.0;
  Servo_PID_DW.x2fp = 0.0;
  Servo_PID_DW.P[0] = 0.0;
  Servo_PID_DW.P[1] = 0.0;
  Servo_PID_DW.P[2] = 0.0;
  Servo_PID_DW.P[3] = 0.0;
  Servo_PID_DW.theta[0] = 0.0;
  Servo_PID_DW.theta[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Servo_PID_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Servo_PID_M->NonInlinedSFcns.sfcnInfo;
    Servo_PID_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Servo_PID_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Servo_PID_M->Sizes.numSampTimes);
    Servo_PID_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Servo_PID_M)[0]);
    Servo_PID_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(Servo_PID_M)[1]);
    Servo_PID_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(Servo_PID_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,Servo_PID_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Servo_PID_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Servo_PID_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Servo_PID_M));
    rtssSetStepSizePtr(sfcnInfo, &Servo_PID_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Servo_PID_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Servo_PID_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Servo_PID_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Servo_PID_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Servo_PID_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Servo_PID_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Servo_PID_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Servo_PID_M->solverInfoPtr);
  }

  Servo_PID_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&Servo_PID_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    Servo_PID_M->childSfunctions =
      (&Servo_PID_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        Servo_PID_M->childSfunctions[i] =
          (&Servo_PID_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/Encoder (Servo_Encoder) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Servo_PID_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/Encoder");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.Encoder_P2_Size);
      }

      /* registration */
      Servo_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/RT-DAC Analog Inputs1 (servo_analoginputs) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Servo_PID_B.RTDACAnalogInputs1));
        }
      }

      /* path info */
      ssSetModelName(rts, "RT-DAC\nAnalog Inputs1");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/RT-DAC Analog Inputs1");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.RTDACAnalogInputs1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.RTDACAnalogInputs1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Servo_PID_P.RTDACAnalogInputs1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Servo_PID_P.RTDACAnalogInputs1_P4_Size);
      }

      /* registration */
      servo_analoginputs(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/PWM (Servo_PWM) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Servo_PID_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Servo_PID_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Servo_PID_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/PWM");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.PWM_P2_Size);
      }

      /* registration */
      Servo_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/ResetEncoder (Servo_ResetEncoder) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Servo_PID_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Servo_PID_B.Reset;
          sfcnUPtrs[1] = &Servo_PID_B.Reset;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Servo_PID_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/ResetEncoder");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.ResetEncoder_P2_Size);
      }

      /* registration */
      Servo_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/Bitstream Version (Servo_BitstreamVersion) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Servo_PID_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/Bitstream Version");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      Servo_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/PWMPrescaler (Servo_PWMPrescaler) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Servo_PID_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &Servo_PID_P.PWMPrescalerSource_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Servo_PID_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/PWMPrescaler");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      Servo_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/Therm Status (Servo_PWMTherm) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Servo_PID_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/Therm Status");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.ThermStatus_P2_Size);
      }

      /* registration */
      Servo_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Servo_PID/<S3>/ThermFlag  (Servo_ThermFlag) */
    {
      SimStruct *rts = Servo_PID_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Servo_PID_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Servo_PID_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Servo_PID_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Servo_PID_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, Servo_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Servo_PID_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Servo_PID_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Servo_PID_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Servo_PID_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &Servo_PID_P.ThermFlagSource_Value;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Servo_PID_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Servo_PID_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "Servo_PID/Subsystem/Servo/ThermFlag ");
      ssSetRTModel(rts,Servo_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Servo_PID_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Servo_PID_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Servo_PID_P.ThermFlag_P2_Size);
      }

      /* registration */
      Servo_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  Servo_PID_M->Sizes.numContStates = (1);/* Number of continuous states */
  Servo_PID_M->Sizes.numY = (0);       /* Number of model outputs */
  Servo_PID_M->Sizes.numU = (0);       /* Number of model inputs */
  Servo_PID_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Servo_PID_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Servo_PID_M->Sizes.numBlocks = (41); /* Number of blocks */
  Servo_PID_M->Sizes.numBlockIO = (26);/* Number of block outputs */
  Servo_PID_M->Sizes.numBlockPrms = (91);/* Sum of parameter "widths" */
  return Servo_PID_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
