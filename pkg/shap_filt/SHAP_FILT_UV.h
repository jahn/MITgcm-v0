C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/shap_filt/Attic/SHAP_FILT_UV.h,v 1.1.2.1 2001/04/12 10:52:50 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | SHAP_FILT_UV.h                                           |
C     | o Globals used by Fortran shapiro filter routine.        |
C     \==========================================================/
      COMMON / SHFT_UV_COMMON_R8 / tmpFldU, tmpFldV
      _RL tmpFldU(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL tmpFldV(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
