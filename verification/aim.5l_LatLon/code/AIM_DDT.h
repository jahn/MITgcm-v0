C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/aim.5l_LatLon/code/Attic/AIM_DDT.h,v 1.1.2.1 2001/04/09 18:10:55 jmc Exp $
C $Name:  $

#ifdef ALLOW_AIM

C     /==========================================================\
C     | AIM_DDT.h                                                |
C     | o AIM tendency fields in dynamics conforming arrays      |
C     \==========================================================/

C     AIM_UT - Holds AIM dudt in dynamics conforming array ( m/s^2  )
C     AIM_VT - Holds AIM dvdt in dynamics conforming array ( m/s^2  )
C              Values for both fields are on the AIM 'A' grid. This
C              aligns with the P-points on the dynamics 'C'-grid.
C
      COMMON /AIM_DDT/
     &                   AIM_UT, AIM_VT
      _RL  AIM_UT    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
      _RL  AIM_VT    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)

#endif /* ALLOW_AIM */
