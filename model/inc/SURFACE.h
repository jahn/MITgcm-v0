C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/SURFACE.h,v 1.1.2.1 2001/03/30 22:45:06 jmc Exp $
C $Name:  $
C
C     /==========================================================\
C     | SURFACE.h                                                |
C     | o Header file defining surface-related model varaibles   |
C     |==========================================================|
C     | Contains variables relative to the surface position      |
C     | that are held fixed in linear free-surface formulation   |
C     | but can vary with time with a non-linear free-surface.   |
C     \==========================================================/

C--   COMMON /SOLVE_BAROT/  Barotropic variables common block
C     Bo_surf  -Boyancy|1/rho [ocean|atmos] at surface level [= g | alpha(p_o)]
C     recip_Bo     = 1/Bo_surf
      COMMON /SOLVE_BAROT/ Bo_surf, recip_Bo
      _RL  Bo_surf(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  recip_Bo(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

C--   COMMON /SURF_INDEX/ Common block for surface related index
C     k_surf - vertical index of the surface tracer cell
      COMMON /SURF_INDEX/ k_surf
      INTEGER k_surf(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
