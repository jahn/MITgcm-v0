C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/kpp/KPP.h,v 1.6 2001/02/04 14:38:49 cnh Exp $
C $Name:  $

#ifdef ALLOW_KPP

C     /==========================================================\
C     | KPP.h                                                    |
C     | o Basic header for KPP vertical mixing parameterization. |
C     |   Contains all KPP field declarations.                   |
C     \==========================================================/

C-----------------------------------------------------------------------
C
C Time varying parameters computed by subroutine kpp_calc
C     KPPviscAz  - Vertical eddy viscosity coefficient                (m^2/s)
C     KPPdiffKzS - Vertical diffusion coefficient for salt and tracers(m^2/s)
C     KPPdiffKzT - Vertical diffusion coefficient for heat            (m^2/s)
C     KPPghat    - Nonlocal transport coefficient                     (s/m^2)
C     KPPhbl     - Mixing layer depth                                     (m)
C     KPPfrac    - Fraction of short-wave flux penetrating mixing layer
C
C-----------------------------------------------------------------------

      _RL KPPviscAz  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL KPPdiffKzS (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL KPPdiffKzT (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL KPPghat    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL KPPhbl     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,   nSx,nSy)
      _RL KPPfrac    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,   nSx,nSy)
      COMMON /kpp/ KPPviscAz, KPPdiffKzT, KPPdiffKzS
     &              , KPPghat, KPPhbl
      COMMON /kpp_short/ KPPfrac

#endif /* ALLOW_KPP */
