C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/shap_filt/Attic/SHAP_FILT_TRACER.h,v 1.1.2.1 2001/04/12 10:52:49 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | SHAP_FILT_TRACER.h                                       |
C     | o Globals used by Fortran shapiro filter routine.        |
C     \==========================================================/
      COMMON / SHFT_COMMON_R8 / tmpFld
      _RL tmpFld(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
