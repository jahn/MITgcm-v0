C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/com_cnvcon.h,v 1.3.8.1 2003/03/06 22:46:50 heimbach Exp $
C $Name:  $
C $Namer: $

#ifdef ALLOW_AIM
C--
C--   /CNVCON/: Convection constants (init. in INPHYS)
C--    RHBL   = relative hum. threshold in the boundary (lowest) layer
C--    TRCNV  = time of relaxation (in hours) towards neutral equilibrium
C--    ENTMAX = max. entrainment as a fraction of cloud-base mass flux
 
      COMMON /CNVCON/ RHBL, TRCNV, ENTMAX
      _RL RHBL, TRCNV, ENTMAX

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
#endif /* ALLOW_AIM */
