C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/bulk_force/BULKF.h,v 1.4 2003/11/23 01:36:55 jmc Exp $
C $Name:  $

#ifdef ALLOW_BULK_FORCE
cswdblk
c     !ROUTINE: BULKF.h
c -------------------------------
c   BULKF.h
C  variable for forcing using bulk
c  formula
c -------------------------------
c   FORCING VARIABLES
C Mandatory:
c  tair      - air temperature (K)
c  qair      - specific humidity at surface (Kg/Kg)
c  rain      - precipitation, which may become snow (m/s), (>0: rain)
c  solar     - downward shortwave radiation (W/m^2), (>0: downward)
c  flw       - downward longwave radiation  (W/m^2), (>0: downward)
c              (jmc:  flwdwn  would be a better name)
c  wspeed    - wind speed (m/s)
C
C Optional:
c  uwind      - zonal wind speed (m/s)
c  vwind      - meridional wind speed (m/s)
c  runoff     - freshwater runoff
c  qnetch     - net heat flux (cheating)
c  empch      - E-P (cheating)
c  cloud      - fraction sky covered in cloud
c
      COMMON /BULKF_FFIELDS_PARMS/
     &       Tair, Qair, Rain, Solar,  flw, 
     &       uwind, vwind, runoff, wspeed,
     &       qnetch, empch, cloud,
     &       AirTempFile, AirHumidityFile, RainFile,
     &       SolarFile, LongwaveFile, UWindFile, VWindFile,
     &       RunoffFile, WSpeedFile, readwindstress, 
     &       readsurface,
     &       QnetFile,EmPFile, CloudFile, SnowFile
c    &    ,evapora  

      _RL  Tair  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  Qair  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  Rain  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  Solar (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  flw   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  uwind  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  vwind  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL runoff  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL wspeed  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL qnetch  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL empch   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL cloud   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
c     _RL evapora (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      CHARACTER*(MAX_LEN_FNAM) AirTempFile
      CHARACTER*(MAX_LEN_FNAM) AirHumidityFile
      CHARACTER*(MAX_LEN_FNAM) RainFile
      CHARACTER*(MAX_LEN_FNAM) SolarFile
      CHARACTER*(MAX_LEN_FNAM) LongwaveFile
      CHARACTER*(MAX_LEN_FNAM) UWindFile
      CHARACTER*(MAX_LEN_FNAM) VWindFile
      CHARACTER*(MAX_LEN_FNAM) RunoffFile
      CHARACTER*(MAX_LEN_FNAM) WSpeedFile
      CHARACTER*(MAX_LEN_FNAM) QnetFile
      CHARACTER*(MAX_LEN_FNAM) EmPFile
      CHARACTER*(MAX_LEN_FNAM) CloudFile
      CHARACTER*(MAX_LEN_FNAM) SnowFile
      LOGICAL readwindstress
      LOGICAL readsurface

#endif /* ALLOW_BULK_FORCE */
