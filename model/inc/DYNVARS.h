C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/DYNVARS.h,v 1.3 1998/05/26 21:29:44 cnh Exp $
C
C     /==========================================================\
C     | DYNVARS.h                                                |
C     | o Dynamical model variables (common block DYNVARS_R)     |
C     |==========================================================|
C     | The value and two levels of time tendency are held for   |
C     | each prognostic variable.                                |
C     \==========================================================/
C
C     uVel  - zonal velocity (m/s, i=1 held at western face)
C     vVel  - meridional velocity (m/s, j=1 held at southern face)
C     theta - potential temperature (oC, held at pressure/tracer point)
C     salt  - salinity (ppt, held at pressure/tracer point)
C     rho   - density ( kg/m^3 )
      COMMON /DYNVARS_R/ uVel,vVel,theta,salt,
     &                   gu,gv,gt,gs,guNm1,gvNm1,gtNm1,gsNm1
      _RL  uVel (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  vVel (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  theta(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  salt (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  gu(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  gv(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  gt(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  gs(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  guNm1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  gvNm1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  gtNm1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
      _RL  gsNm1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nz,nSx,nSy)
