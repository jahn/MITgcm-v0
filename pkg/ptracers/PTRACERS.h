C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/ptracers/Attic/PTRACERS.h,v 1.9 2004/09/03 20:10:47 edhill Exp $
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

C     PTRACERS_taveFreq :: Frequency with which time-averaged PTRACERS
C                          are written to post-processing files.

C     PTRACERS parameters
      _RL PTRACERS_taveFreq
      _RL PTRACERS_diffKh(PTRACERS_num)
      _RL PTRACERS_diffK4(PTRACERS_num)
      _RL PTRACERS_diffKr(PTRACERS_num)
      INTEGER PTRACERS_advScheme(PTRACERS_num)
      INTEGER PTRACERS_numInUse
      LOGICAL PTRACERS_useGMRedi(PTRACERS_num)
      LOGICAL PTRACERS_useKPP(PTRACERS_num)
      LOGICAL PTRACERS_useRecords
      CHARACTER*(MAX_LEN_FNAM) PTRACERS_initialFile(PTRACERS_num)
      CHARACTER*(MAX_LEN_FNAM) PTRACERS_names(PTRACERS_num)
      CHARACTER*(MAX_LEN_FNAM) PTRACERS_long_names(PTRACERS_num)
      CHARACTER*(MAX_LEN_FNAM) PTRACERS_units(PTRACERS_num)
      INTEGER PTRACERS_iotypes
      LOGICAL PTRACERS_mnc_read
      LOGICAL PTRACERS_mnc_write
      COMMON /PTRACERS_PARAMS/
     &     PTRACERS_taveFreq,
     &     PTRACERS_diffKh,
     &     PTRACERS_diffK4,
     &     PTRACERS_diffKr,
     &     PTRACERS_numInUse,
     &     PTRACERS_advScheme,
     &     PTRACERS_initialFile,
     &     PTRACERS_useGMRedi,
     &     PTRACERS_useKPP,
     &     PTRACERS_useRecords,
     &     PTRACERS_names,
     &     PTRACERS_long_names,
     &     PTRACERS_units,
     &     PTRACERS_mnc_read,
     &     PTRACERS_mnc_write,
     &     PTRACERS_iotypes

C     pTracer  :: passive tracer concentration (tr per unit volume).
C     gPtr     :: work-space for time-stepping
C     gPtrNM1  :: work-space for time-stepping
      _RL  pTracer (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy,
     &              PTRACERS_num)
      _RL  gPtr    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy,
     &              PTRACERS_num)
      _RL  gPtrNM1 (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy,
     &              PTRACERS_num)
      _RL  surfaceForcingPtr (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy,
     &              PTRACERS_num)
      COMMON /PTRACERS_FIELDS/
     &              pTracer, gPtr, gPtrNM1, surfaceForcingPtr

CEOP
#endif /* ALLOW_PTRACERS */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
