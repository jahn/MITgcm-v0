C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/com_sflcon.h,v 1.3 2002/09/27 20:01:57 jmc Exp $
C $Name:  $

#ifdef ALLOW_AIM

C--   COMMON /SFLCON/: Constants for surface fluxes (initial. in INPHYS)
C      FWIND0 = ratio of near-sfc wind to lowest-level wind
C      FTEMP0 = weight for near-sfc temperature extrapolation (0-1) :
C               1 : linear extrapolation from two lowest levels
C               0 : constant potential temperature ( = lowest level)
C      FHUM0  = weight for near-sfc specific humidity extrapolation (0-1) :
C               1 : extrap. with constant relative hum. ( = lowest level)
C               0 : constant specific hum. ( = lowest level)
C      CDL    = drag coefficient for momentum over land
C      CDS    = drag coefficient for momentum over sea
C      CHL    = heat exchange coefficient over land
C      CHS    = heat exchange coefficient over sea
C      VGUST  = wind speed for sub-grid-scale gusts
C      SWMAX  = Soil wetness (in mm) corresp. to potential evapotranspiration
      COMMON /SFLCON/ FWIND0, FTEMP0, FHUM0,
     &                CDL, CDS, CHL, CHS, VGUST, SWMAX
      _RL FWIND0, FTEMP0, FHUM0
      _RL CDL, CDS, CHL, CHS, VGUST, SWMAX

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
#endif /* ALLOW_AIM */ 
