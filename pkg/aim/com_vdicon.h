C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/com_vdicon.h,v 1.2.8.1 2003/03/06 22:46:51 heimbach Exp $
C $Name:  $

#ifdef ALLOW_AIM

C--   COMMON /VDICON/: Constants for vertical dif. and sh. conv. 
C                     (init. in INPHYS)
C      TRVDI  = relaxation time (in hours) for moisture diffusion
C      TRSHC  = relaxation time (in hours) for shallow convection
      COMMON /VDICON/ TRVDI, TRSHC
      _RL TRVDI, TRSHC

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
#endif /* ALLOW_AIM */ 
