C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/FFIELDS.h,v 1.12.4.1 2002/11/07 16:48:46 heimbach Exp $
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
C     | The arrays here will need changing and customising for a  
C     | particular experiment.                                    
C     *==========================================================*
C     \ev
CEOP
C
C--   For a classical "gyre" type experiment just one term is needed.
C
C     fu     - Zonal surface wind stress
C                Units are           N/m^2 (>0 from East to West)
C
C     fv     - Meridional surface wind stress
C                Units are           N/m^2 (>0 from North to South))
C
C     EmPmR  - Evaporation - Precipitation - Runoff
C                Units are           m/s (>0 for ocean salting)
C
C     Qnet   - Upward surface heat flux
C                Units are           W/m^2=kg/s^3 (>0 for ocean cooling)
C
C     Qsw    - Upward short-wave surface heat flux
C                Units are           W/m^2=kg/s^3 (>0 for ocean cooling)
C
C     dQdT   - Thermal relaxation coefficient
C                                 (W/m^2/degrees -> degrees/second)

C     SST    - Sea surface temperature (degrees) for relaxation
C     SSS    - Sea surface salinity (psu) for relaxation

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
