C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/ptracers/Attic/PTRACERS.h,v 1.5 2003/10/09 04:19:20 edhill Exp $
C $Name:  $

#ifdef ALLOW_PTRACERS

CBOP
C    !ROUTINE: PTRACERS.h
C    !INTERFACE:
C #include PTRACERS.h
 
C    !DESCRIPTION:
C Contains passive tracer fields and parameters.

C     Package flag
      logical PTRACERSisON
      COMMON /PTRACERS_PACKAGE/ PTRACERSisON

C NUMBER_OF_PTRACERS defines how many passive tracers are allocated/exist.
C This CPP macro is *only* used in PTRACERS.h to set an integer parameter.
C <Please> do not make use of it elsewhere.
C
C NUMBER_OF_PTRACERS should be defined in PTRACERS_OPTIONS.h
C
C If NUMBER_OF_PTRACERS is not specified elsewhere and ALLOW_PTRACERS
C is set then NUMBER_OF_PTRACERS is set here (default 1)
#ifndef NUMBER_OF_PTRACERS
#define NUMBER_OF_PTRACERS 1
#endif

C     Number of tracers
      INTEGER PTRACERS_num
      PARAMETER(PTRACERS_num = NUMBER_OF_PTRACERS)

C     PTRACERS parameters
      _RL PTRACERS_diffKh(PTRACERS_num)
      _RL PTRACERS_diffK4(PTRACERS_num)
      _RL PTRACERS_diffKr(PTRACERS_num)
      INTEGER PTRACERS_advScheme(PTRACERS_num)
      INTEGER PTRACERS_numInUse
      LOGICAL PTRACERS_useGMRedi(PTRACERS_num)
      LOGICAL PTRACERS_useKPP(PTRACERS_num)
      LOGICAL PTRACERS_useRecords
      CHARACTER*(MAX_LEN_FNAM) PTRACERS_initialFile(PTRACERS_num)
      COMMON /PTRACERS_PARAMS/
     &                   PTRACERS_diffKh,
     &                   PTRACERS_diffK4,
     &                   PTRACERS_diffKr,
     &                   PTRACERS_numInUse,
     &                   PTRACERS_advScheme,
     &                   PTRACERS_initialFile,
     &                   PTRACERS_useGMRedi,
     &                   PTRACERS_useKPP,
     &                   PTRACERS_useRecords
      NAMELIST /PTRACERS_PARM01/
     &                   PTRACERS_advScheme,
     &                   PTRACERS_diffKh,
     &                   PTRACERS_diffK4,
     &                   PTRACERS_diffKr,
     &                   PTRACERS_useGMRedi,
     &                   PTRACERS_useKPP,
     &                   PTRACERS_numInUse,
     &                   PTRACERS_initialFile,
     &                   PTRACERS_useRecords

C     pTracer  :: passive tracer concentration (tr per unit volume).
C     gPtr     :: work-space for time-stepping
C     gPtrNM1  :: work-space for time-stepping
      _RL  pTracer (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy,
     &              PTRACERS_num)
      _RL  gPtr    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy,
     &              PTRACERS_num)
      _RL  gPtrNM1 (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy,
     &              PTRACERS_num)
      _RL  surfaceTendencyPtr (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy,
     &              PTRACERS_num)
      COMMON /PTRACERS_FIELDS/
     &              pTracer, gPtr, gPtrNM1, surfaceTendencyPtr

CEOP
#endif /* ALLOW_PTRACERS */
