C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/SOLVE_FOR_PRESSURE.h,v 1.1.2.1 2001/04/12 10:52:49 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | SOLVE_FOR_PRESSURE.h                                     |
C     | o Globals used by Fortran pressure solver routine        |
C     \==========================================================/
      COMMON / SFP_COMMON_R8 / cg2d_x, cg2d_b
      _RL cg2d_x(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL cg2d_b(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
