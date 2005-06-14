C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/fizhi/fizhi_ocean_coms.h,v 1.3 2005/06/14 18:14:21 molod Exp $
C $Name:  $

c Ocean Exports
c -------------------
      common /ocean_exports/ sst, sice, ksst, kice
      _RL sst(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nsx,Nsy)
      _RL sice(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nsx,Nsy)
      integer ksst, kice

