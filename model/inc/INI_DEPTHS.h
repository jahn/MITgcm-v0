C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/Attic/INI_DEPTHS.h,v 1.1.2.1 2001/04/13 10:55:23 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | INI_DEPTHS.h                                             |
C     | o Globals used by Fortran depth map initialization       |
C     \==========================================================/
      COMMON / INIDEP_COMMON_RS / H
      _RS H(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
