C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/FFIELDS.h,v 1.12.4.2 2003/01/12 08:20:09 dimitri Exp $
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

      COMMON /FFIELDS/
     &                 fu,
     &                 fv,
     &                 Qnet,
     &                 Qsw,
     &                 dQdT,
     &                 EmPmR,
     &                 SST,
     &                 SSS
      _RS  fu       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  fv       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qnet     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qsw      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  dQdT     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  EmPmR    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SST      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SSS      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

#ifndef INCLUDE_EXTERNAL_FORCING_PACKAGE
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
     &                 taux0, tauy0, Qnet0, EmPmR0, SST0, SSS0, Qsw0,
     &                 taux1, tauy1, Qnet1, EmPmR1, SST1, SSS1, Qsw1
      _RS  taux0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  tauy0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qnet0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  EmPmR0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SST0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SSS0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qsw0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  taux1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  tauy1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qnet1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  EmPmR1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SST1     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  SSS1     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  Qsw1     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif /* INCLUDE_EXTERNAL_FORCING_PACKAGE undef */

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
      COMMON /TENDENCY_FORCING/
     &                         surfaceTendencyU,
     &                         surfaceTendencyV,
     &                         surfaceTendencyT,
     &                         surfaceTendencyS, 
     &                         tempQsw
      _RS  surfaceTendencyU  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  surfaceTendencyV  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  surfaceTendencyT  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  surfaceTendencyS  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS  tempQsw           (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
