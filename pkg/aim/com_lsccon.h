C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/com_lsccon.h,v 1.2.8.1 2003/03/06 22:46:50 heimbach Exp $
C $Name:  $

#ifdef ALLOW_AIM

C--   COMMON /LSCCON/: Constants for large-scale condendation 
C                       (initial. in INPHYS)
C      RHLSC  = Relative humidity threshold
C      TRLSC  = Relaxation time (in hours) for supersat. specific humidity 

      COMMON /LSCCON/ RHLSC, TRLSC
      _RL RHLSC, TRLSC

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
#endif /* ALLOW_AIM */ 
