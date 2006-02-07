C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/shelfice/Attic/SHELFICE_DIAGS.h,v 1.1 2006/02/07 11:45:21 mlosch Exp $
C $Name:  $

C     /==========================================================\
C     | SHELFICE_DIAGS.h                                         |
C     | o Header for SHELFICE diagnostic output                  |
C     \==========================================================/

#ifdef ALLOW_TIMEAVE

C     Keep track of time
      _RL SHELFICE_TimeAve(nSx,nSy)
      COMMON /SHELFICE_TAVE/ SHELFICE_TimeAve

C     Storage arrays for time-averages
      _RL shelfice_heatFluxtave (1-OLx:sNx+OLx,1-OLy:sNy+OLy,1,nSx,nSy)
      _RL shelfice_frshFluxtave (1-OLx:sNx+OLx,1-OLy:sNy+OLy,1,nSx,nSy)
      COMMON /SHELFICE_TAVE_DIAGS/
     &     shelfice_heatFluxtave,
     &     shelfice_frshFluxtave

#endif /* ALLOW_TIMEAVE */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
