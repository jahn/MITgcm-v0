C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/sbo/SBO.h,v 1.8 2010/01/03 20:03:36 jmc Exp $
C $Name:  $

#ifdef ALLOW_SBO

C     *==========================================================*
C     | SBO.h
C     | o Basic header for SBO
C     *==========================================================*

C     xoamc       :: x-comp oam due to currents        (kg-m**2/s)
C     yoamc       :: y-comp oam due to currents        (kg-m**2/s)
C     zoamc       :: z-comp oam due to currents        (kg-m**2/s)
C     xoamp       :: x-comp oam due to pressure        (kg-m**2/s)
C     yoamp       :: y-comp oam due to pressure        (kg-m**2/s)
C     zoamp       :: z-comp oam due to pressure        (kg-m**2/s)
C     mass        :: mass of oceans                           (kg)
C     xcom        :: x-comp of center-of-mass of oceans        (m)
C     ycom        :: y-comp of center-of-mass of oceans        (m)
C     zcom        :: z-comp of center-of-mass of oceans        (m)
C     obp         :: ocean-bottom pressure               (Pascals)
cph(
C     area        :: surface wet area                       (m**2)
C     sboempmrwet :: net E-P-R over the ocean            (kg/m2/s)
C     sboqnetwet  :: net heat flux over the ocean         (W/m**2)
cph)
C
      _RL xoamc, yoamc, zoamc, xoamp, yoamp, zoamp
      _RL mass, xcom, ycom, zcom
      _RL sbobp, sboarea, sboempmrwet, sboqnetwet
      _RL obp (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      common /sbo/ xoamc, yoamc, zoamc, xoamp, yoamp, zoamp,
     &             mass, xcom, ycom, zcom, obp, sbobp,
     &             sboarea, sboempmrwet, sboqnetwet

C     sbo_taveFreq :: SBO time-averaging frequency              (s)
C
      _RL sbo_taveFreq
      COMMON /sbo_r/ sbo_taveFreq

#ifdef ALLOW_TIMEAVE

C----------------------------------------------------------------
C     sbo_timeAve - time of temporal integration (s) for each thread
C----------------------------------------------------------------

      _RL sbo_timeAve(nSx,nSy)
      COMMON /SBO_TAVE_COUNT/ sbo_timeAve

C----------------------------------------------------------------
C     OBPtave      - time-averaged ocean-bottom pressure (Pascals)
C----------------------------------------------------------------

      _RL OBPtave (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /SBO_TAVE_FIELDS/ OBPtave

#endif /* ALLOW_TIMEAVE */

#endif /* ALLOW_SBO */
