#ifdef ALLOW_BULK_FORCE
cswdblk
c     !ROUTINE: BULKF.h
c -------------------------------
c   BULKF.h
C  variable for forcing using bulk
c  formula
c -------------------------------
c   FORCING VARIABLES
c  tair      - air temperature
c  qair      - specific humidity at surface
c  rain      - precipitation, which may become snow
c  solar     - shortwave radiation
c  flw       - downward longwave flux
c  uwind      - zonal wind speed
c  vwind      - meridional wind speed
c  wspeed     - wind speed
c  runoff     - freshwater runoff
c  qnetch     - net heat flux (cheating)
c  empch      - E-P (cheating)
c  cloud      - fraction sky covered in cloud
c
      COMMON /BULKF_FFIELDS_PARMS/
     &       Tair, Qair, Rain, Solar,  flw, 
     &       uwind, vwind, runoff, wspeed,
     &       qnetch, empch, cloud, evapora,  
     &       AirTempFile, AirHumidityFile, RainFile,
     &       SolarFile, LongwaveFile, UWindFile, VWindFile,
     &       RunoffFile, WSpeedFile, readwindstress, 
     &       readsurface,
     &       QnetFile,EmPFile, CloudFile, SnowFile

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
      _RL evapora (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
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
#endif

