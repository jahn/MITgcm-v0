C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/AIM2DYN.h,v 1.1.6.1 2003/03/06 22:46:50 heimbach Exp $
C $Name:  $

#ifdef ALLOW_AIM

C     /==========================================================\
C     | AIM2DYN.h                                                |
C     | o AIM output fields in dynamics conforming arrays        |
C     \==========================================================/

C     aim_drag - Holds AIM surface drag term : C_drag*Rho*|V| ( kg.m-2.s-1 )
C                location : AIM "A" grid = center of the dynamics "C" grid
C     aim_dTdt - Net tendency for potential temperature ( oK/s    )
C     aim_dSdt - Net tendency for water vapor           ( g/kg/s )
C
      COMMON /AIM_DDT/
     &                   aim_drag, 
     &                   aim_dTdt,
     &                   aim_dSdt
      _RL  aim_drag  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  aim_dTdt  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL  aim_dSdt  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)

#endif /* ALLOW_AIM */
