C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/seaice/SEAICE.h,v 1.31 2007/05/09 14:31:46 mlosch Exp $
C $Name:  $

CBOP
C !ROUTINE: SEAICE.h

C !DESCRIPTION: \bv
C     /==========================================================\
C     | SEAICE.h                                                 |
C     | o Basic header for sea ice model.                        |
C     |   Contains most sea ice field declarations.              |
C     \==========================================================/
C
C     UICE  - zonal ice velocity in m/s at South-West B-grid 
C             (or C-grid #ifdef SEAICE_CGRID) U point
C             >0 from West to East
C     UICEC - average of UICE(1) between last two time steps
C     VICE  - meridional ice velocity in m/s at South-West B-grid
C             (or C-grid #ifdef SEAICE_CGRID) V point
C             >0 from South to North
C             note: the South-West B-grid U and V points are on
C                the lower, left-hand corner of each grid cell
C     VICEC - average of VICE(1) between last two time steps
C     AREA  - fractional ice-covered area in m^2/m^2
C             at center of grid, i.e., tracer point
C             0 is no cover, 1 is 100% cover
C     HEFF  - effective ice thickness in m
C             at center of grid, i.e., tracer point
C             note: for non-zero AREA, actual ice
C                thickness is HEFF / AREA
C     HSNOW - effective snow thickness in m
C             at center of grid, i.e., tracer point
C             note: for non-zero AREA, actual snow
C                thickness is HEFF / AREA
C \ev
CEOP
      COMMON/SEAICE_DYNVARS_1/AREA
      _RL AREA       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,3,nSx,nSy)

      COMMON/SEAICE_DYNVARS_2/UICE,VICE
      _RL UICE       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,3,nSx,nSy)
      _RL VICE       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,3,nSx,nSy)

      COMMON/SEAICE_DYNVARS_3/
     &     ETA,ZETA,DRAGS,DRAGA,FORCEX,FORCEY,UICEC,VICEC
      _RL ETA        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL ZETA       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL DRAGS      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL DRAGA      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL FORCEX     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL FORCEY     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL UICEC      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL VICEC      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)

#ifndef SEAICE_CGRID
      COMMON/SEAICE_DYNVARS_BGRID/ AMASS, DAIRN
      _RL AMASS      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL DAIRN      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
#else 
      COMMON/SEAICE_DYNVARS_CGRID/
     &     seaiceMassC, seaiceMassU, seaiceMassV
      _RL seaiceMassC(1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL seaiceMassU(1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL seaiceMassV(1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
#endif

      COMMON/SEAICE_DYNVARS_4/
     &     DWATN, PRESS0, FORCEX0, FORCEY0, ZMAX, ZMIN
      _RL DWATN      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL PRESS0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL FORCEX0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL FORCEY0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL ZMAX       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL ZMIN       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)

      COMMON/SEAICE_TRANS/HEFF,HSNOW
      _RL HEFF       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,3,nSx,nSy)
      _RL HSNOW      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)

      COMMON/ARRAY/HEFFM
      _RL HEFFM      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
#ifdef SEAICE_CGRID
      COMMON/ARRAYC/ seaiceMaskU, seaiceMaskV
      _RL seaiceMaskU(1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL seaiceMaskV(1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
#else
      COMMON/ARRAYB/ UVM
      _RL UVM        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
#endif /* SEAICE_CGRID */
      COMMON/OFL/YNEG
      COMMON/RIV/RIVER
      _RL YNEG       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)
      _RL RIVER      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)

#ifdef SEAICE_MULTICATEGORY
      INTEGER MULTDIM
      PARAMETER (MULTDIM=7)
      COMMON/MULTICATEGORY/TICES
      _RL TICES      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,MULTDIM,nSx,nSy)
#endif

#if (defined (SEAICE_CGRID) && defined (SEAICE_ALLOW_EVP))
C
C     additional fields needed by the EVP solver
C
C     seaice_sigma1  - sigma11+sigma22, defined at C-points
C     seaice_sigma2  - sigma11-sigma22, defined at C-points
C     seaice_sigma12 - off-diagonal term, defined at Z-points
C     stressDivergenceX/Y - divergence of stress tensor
      COMMON /SEAICE_EVP_FIELDS/
     &     stressDivergenceX, stressDivergenceY,
     &     seaice_sigma1, seaice_sigma2, seaice_sigma12
      _RL stressDivergenceX(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL stressDivergenceY(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL seaice_sigma1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL seaice_sigma2    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL seaice_sigma12   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif /* SEAICE_ALLOW_EVP and SEAICE_CGRID */

      COMMON/MIX/TMIX,TICE
      COMMON/GWATXY/GWATX,GWATY
      COMMON/WIND/WINDX,WINDY,TAUX,TAUY
      _RL TMIX       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL TICE       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL GWATX      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL GWATY      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
C     TAUX   - zonal      wind stress over ice at U point
C     TAUY   - meridional wind stress over ice at V point
C     WINDX  - zonal      wind stress over water at C points
C     WINDY  - meridional wind stress over water at C points
      _RL WINDX      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL WINDY      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL TAUX       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL TAUY       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON/COUNT/ICOUNT
      COMMON/DAY/IDELT
      INTEGER ICOUNT, IDELT

C--   KGEO    Level used as a proxy for geostrophic velocity.
      COMMON/SEAICE_KGEO/KGEO
      integer KGEO   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,  nSx,nSy)

#ifdef ALLOW_AUTODIFF_TAMC
      integer iicekey
      integer nEVPstepMax
      parameter ( nEVPstepMax=60 )
#endif

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
