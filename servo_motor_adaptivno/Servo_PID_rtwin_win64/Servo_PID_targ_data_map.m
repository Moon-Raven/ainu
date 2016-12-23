  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Servo_PID_P)
    ;%
      section.nData     = 70;
      section.data(70)  = dumData; %prealloc
      
	  ;% Servo_PID_P.MATLABFunction_Tfiltra
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Servo_PID_P.MATLABFunction_Tsampling
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Servo_PID_P.MATLABFunction_ksi
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Servo_PID_P.MATLABFunction_ksie
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Servo_PID_P.MATLABFunction_lambda
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Servo_PID_P.MATLABFunction_omega
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Servo_PID_P.MATLABFunction_omegae
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Servo_PID_P.Encoder_P1_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Servo_PID_P.Encoder_P1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% Servo_PID_P.Encoder_P2_Size
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% Servo_PID_P.Encoder_P2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 12;
	
	  ;% Servo_PID_P.Encoder1024PPR_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 13;
	
	  ;% Servo_PID_P.Converttorad_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Servo_PID_P.SineWave_Amp
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Servo_PID_P.SineWave_Bias
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 16;
	
	  ;% Servo_PID_P.SineWave_Freq
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 17;
	
	  ;% Servo_PID_P.SineWave_Phase
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 18;
	
	  ;% Servo_PID_P.Step_Time
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Servo_PID_P.Step_Y0
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Servo_PID_P.Step_YFinal
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% Servo_PID_P.Simplefilter_A
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
	  ;% Servo_PID_P.Simplefilter_C
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 23;
	
	  ;% Servo_PID_P.Constant_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 24;
	
	  ;% Servo_PID_P.Constant1_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 25;
	
	  ;% Servo_PID_P.Normal_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 26;
	
	  ;% Servo_PID_P.Reset_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 27;
	
	  ;% Servo_PID_P.Saturation_UpperSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 28;
	
	  ;% Servo_PID_P.Saturation_LowerSat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 29;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P1_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 30;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P1
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P2_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P2
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P3_Size
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 37;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P3
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 39;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P4_Size
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 41;
	
	  ;% Servo_PID_P.RTDACAnalogInputs1_P4
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 43;
	
	  ;% Servo_PID_P.Converttorads_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 44;
	
	  ;% Servo_PID_P.Saturation_UpperSat_i
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 45;
	
	  ;% Servo_PID_P.Saturation_LowerSat_f
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 46;
	
	  ;% Servo_PID_P.PWM_P1_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 47;
	
	  ;% Servo_PID_P.PWM_P1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 49;
	
	  ;% Servo_PID_P.PWM_P2_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 50;
	
	  ;% Servo_PID_P.PWM_P2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 52;
	
	  ;% Servo_PID_P.PWMGain_Gain
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 53;
	
	  ;% Servo_PID_P.ResetEncoder_P1_Size
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 54;
	
	  ;% Servo_PID_P.ResetEncoder_P1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 56;
	
	  ;% Servo_PID_P.ResetEncoder_P2_Size
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 57;
	
	  ;% Servo_PID_P.ResetEncoder_P2
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 59;
	
	  ;% Servo_PID_P.ResetEncoderGain_Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 60;
	
	  ;% Servo_PID_P.BitstreamVersion_P1_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 61;
	
	  ;% Servo_PID_P.BitstreamVersion_P1
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 63;
	
	  ;% Servo_PID_P.BitstreamVersion_P2_Size
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 64;
	
	  ;% Servo_PID_P.BitstreamVersion_P2
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 66;
	
	  ;% Servo_PID_P.PWMPrescalerSource_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 67;
	
	  ;% Servo_PID_P.PWMPrescaler_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 68;
	
	  ;% Servo_PID_P.PWMPrescaler_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 70;
	
	  ;% Servo_PID_P.PWMPrescaler_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 71;
	
	  ;% Servo_PID_P.PWMPrescaler_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 73;
	
	  ;% Servo_PID_P.PWMPrescalerGain_Gain
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 74;
	
	  ;% Servo_PID_P.ThermStatus_P1_Size
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 75;
	
	  ;% Servo_PID_P.ThermStatus_P1
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 77;
	
	  ;% Servo_PID_P.ThermStatus_P2_Size
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 78;
	
	  ;% Servo_PID_P.ThermStatus_P2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 80;
	
	  ;% Servo_PID_P.PWMThermStatus_Gain
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 81;
	
	  ;% Servo_PID_P.ThermFlagSource_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 82;
	
	  ;% Servo_PID_P.ThermFlag_P1_Size
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 83;
	
	  ;% Servo_PID_P.ThermFlag_P1
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 85;
	
	  ;% Servo_PID_P.ThermFlag_P2_Size
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 86;
	
	  ;% Servo_PID_P.ThermFlag_P2
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 88;
	
	  ;% Servo_PID_P.ThermFlagGain_Gain
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 89;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Servo_PID_P.ResetEncodersRealtimeonly_CurrentSetting
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Servo_PID_B)
    ;%
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% Servo_PID_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Servo_PID_B.Converttorad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Servo_PID_B.Sum
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Servo_PID_B.filterdvelocity
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Servo_PID_B.pos
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Servo_PID_B.Constant1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% Servo_PID_B.Reset
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% Servo_PID_B.RTDACAnalogInputs1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 9;
	
	  ;% Servo_PID_B.Converttorads
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 11;
	
	  ;% Servo_PID_B.Saturation
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% Servo_PID_B.PWM
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% Servo_PID_B.PWMGain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% Servo_PID_B.ResetEncoder
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
	  ;% Servo_PID_B.ResetEncoderGain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% Servo_PID_B.BitstreamVersion
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 19;
	
	  ;% Servo_PID_B.PWMPrescaler
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 20;
	
	  ;% Servo_PID_B.PWMPrescalerGain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 21;
	
	  ;% Servo_PID_B.ThermStatus
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 22;
	
	  ;% Servo_PID_B.PWMThermStatus
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 23;
	
	  ;% Servo_PID_B.ThermFlag
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 24;
	
	  ;% Servo_PID_B.ThermFlagGain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 25;
	
	  ;% Servo_PID_B.u
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 26;
	
	  ;% Servo_PID_B.x1hatnew
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 27;
	
	  ;% Servo_PID_B.x2hatnew
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 28;
	
	  ;% Servo_PID_B.ahat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 29;
	
	  ;% Servo_PID_B.bhat
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Servo_PID_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Servo_PID_DW.x1hat
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Servo_PID_DW.x2hat
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Servo_PID_DW.uprev
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Servo_PID_DW.ufp
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Servo_PID_DW.x2fp
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Servo_PID_DW.P
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Servo_PID_DW.theta
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Servo_PID_DW.AngleReferencevelocity_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Servo_PID_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Servo_PID_DW.Scope2_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Servo_PID_DW.x1hat_not_empty
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Servo_PID_DW.x2hat_not_empty
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Servo_PID_DW.uprev_not_empty
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 637846459;
  targMap.checksum1 = 2016294438;
  targMap.checksum2 = 3733618528;
  targMap.checksum3 = 4224207977;

