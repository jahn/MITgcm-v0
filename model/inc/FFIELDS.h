C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/FFIELDS.h,v 1.24 2004/07/12 20:18:56 jmc Exp $
C $Name:  $
CBOP
C     !ROUTINE: FFIELDS.h 
C     !INTERFACE:
C     include "FFIELDS.h"
C     !DESCRIPTION:
C     \bv
C     *==========================================================*
C     | FFIELDS.h                                                 
C     | o Model forcing fields                                    
C     *==========================================================*
C     | More flexible surface forcing configurations are
C     | available via pkg/exf and pkg/seaice
C     *==========================================================*
C     \ev
CEOP
C
C     fu    :: Zonal surface wind stress in N/m^2
C              > 0 for increase in uVel, which is west to
C                  east for cartesian and spherical polar grids
C              Typical range: -0.5 < fu < 0.5
C              Southwest C-grid U point
C
C     fv    :: Meridional surface wind stress in N/m^2
C              > 0 for increase in vVel, which is south to
C                  north for cartesian and spherical polar grids
C              Typical range: -0.5 < fv < 0.5
C              Southwest C-grid V point
C
C     EmPmR :: Net upward freshwater flux in m/s
C              EmPmR = Evaporation - precipitation - runoff
C              > 0 for increase in salt (ocean salinity)
C              Typical range: -1e-7 < EmPmR < 1e-7
C              Southwest C-grid tracer point
C
C  saltFlux :: Net upward salt flux in psu.kg/m^2/s
C              flux of Salt taken out of the ocean per time unit (second).
C              Note: a) only used when salty sea-ice forms or melts.
C                    b) units: when salinity (unit= psu) is expressed
C              	        in g/kg, saltFlux unit becomes g/m^2/s.
C              > 0 for decrease in SSS.
C              Southwest C-grid tracer point
C
C     Qnet  :: Net upward surface heat flux excluding shortwave in W/m^2
C              Qnet = latent + sensible + net longwave
C              > 0 for decrease in theta (ocean cooling)
C              Typical range: -250 < Qnet < 600
C              Southwest C-grid tracer point
C
C              NOTE: #ifndef SHORTWAVE_HEATING,
C              Qnet = latent + sensible + net longwave + net shortwave
C
C     Qsw   :: Net upward shortwave radiation in W/m^2
C              Qsw = - ( downward - ice and snow absorption - reflected )
C              > 0 for decrease in theta (ocean cooling)
C              Typical range: -350 < Qsw < 0
C              Southwest C-grid tracer point
C
C     dQdT  :: Thermal relaxation coefficient in W/m^2/degrees
C              Southwest C-grid tracer point
C
C     SST   :: Sea surface temperature in degrees C for relaxation
C              Southwest C-grid tracer point
C
C     SSS   :: Sea surface salinity in psu for relaxation
C              Southwest C-grid tracer point
C
C     pload :: for the ocean:      atmospheric pressure at z=eta
C                Units are           Pa=N/m^2
C              for the atmosphere: geopotential of the orography 
C                Units are           meters (converted)
C  sIceLoad :: sea-ice loading, expressed in Mass of ice+snow / area unit
C                Units are           kg/m^2
C              Note: only used with Sea-Ice & RealFreshWater formulation

      COMMON /FFIELDS/
     &                 fu
     &               , fv
     &               , Qnet
     &               , Qsw
     &               , dQdT
     &               , EmPmR
     &               , saltFlux
     &               , SST
     &               , SSS
#ifdef ATMOSPHERIC_LOADING
     &               , pload
     &               , sIceLoad
#endif

      _RS  fu       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  fv       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qnet     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qsw      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  dQdT     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  EmPmR    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  saltFlux (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SST      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SSS      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#ifdef ATMOSPHERIC_LOADING
      _RS  pload    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  sIceLoad (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

#ifndef ALLOW_EXF
C     taux[01]  :: Temp. for zonal wind stress
C     tauy[01]  :: Temp. for merid. wind stress
C     qnet[01]  :: Temp. for heat flux
C     empmr[01] :: Temp. for fresh water flux
C     sst[01]   :: Temp. for theta climatalogy
C     sss[01]   :: Temp. for theta climatalogy
C     qsw[01]   :: Temp. for short wave component of heat flux
C     [01]      :: End points for interpolation
C     Above use static heap storage to allow exchange.

      COMMON /TDFIELDS/
     &                 taux0, tauy0, Qnet0, EmPmR0, SST0, SSS0,
     &                 taux1, tauy1, Qnet1, EmPmR1, SST1, SSS1
#ifdef SHORTWAVE_HEATING
     &               , Qsw0, Qsw1
#endif 
#ifdef ATMOSPHERIC_LOADING
     &               , pload0, pload1
#endif

      _RS  taux0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  tauy0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qnet0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  EmPmR0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SST0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SSS0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  taux1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  tauy1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qnet1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  EmPmR1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SST1     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SSS1     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#ifdef ATMOSPHERIC_LOADING
      _RS  pload0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  pload1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif
#ifdef SHORTWAVE_HEATING
      _RS  Qsw1     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qsw0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif
#endif /* ALLOW_EXF */

C     surfaceTendencyU       (units are  m/s^2)
C                -> usage in gU:     gU = gU + surfaceTendencyU[m/s^2]
C
C     surfaceTendencyV       (units are  m/s^2)
C                -> usage in gV:     gV = gV + surfaceTendencyV[m/s^2]
C
C     surfaceTendencyS       (units are  psu/s)
C            - EmPmR plus salinity relaxation term
C                -> calculate        -lambda*(S(model)-S(clim))
C                -> usage in gS:     gS = gS + surfaceTendencyS[psu/s]
C
C     surfaceTendencyT       (units are  degrees/s)
C            - Qnet plus temp. relaxation
C                -> calculate        -lambda*(T(model)-T(clim))
C            >>> Qnet assumed to be total flux minus s/w rad. <<<
C                -> usage in gT:     gT = gT + surfaceTendencyT[K/s]
C
C     surfaceTendencyTice
C            - Temperature tendency in the top level due to the
C              melting or freezing of sea-ice.
C              Note that the surface level temperature is modified
C              directly by the sea-ice model in order to maintain
C              water temperature under sea-ice at the freezing
C              point.  But we need to keep track of the
C              equivalent amount of heat that this surface-level
C              temperature change implies because it is used by
C              the KPP package (kpp_calc.F and kpp_transport_t.F).
C              Units are degrees-C/s (>0 for ocean warming).
C
      COMMON /TENDENCY_FORCING/
     &                         surfaceTendencyU,
     &                         surfaceTendencyV,
     &                         surfaceTendencyT,
     &                         surfaceTendencyS, 
     &                         surfaceTendencyTice
      _RS  surfaceTendencyU   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  surfaceTendencyV   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  surfaceTendencyT   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  surfaceTendencyS   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  surfaceTendencyTice(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
