C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim_v23/AIM_GRID.h,v 1.1 2002/11/22 17:16:06 jmc Exp $
C $Name:  $

#ifdef ALLOW_AIM
C     *==========================================================*
C     | AIM_GRID.h  define grid arrays required for AIM Physics  |
C     *==========================================================*

C--   COMMON /AIM_GRID_R/: AIM surface and grid-related arrays
C     WVSurf  : weights for vertical interpolation down to the surface 
C               (replace WVI(NLEV,2) in com_physcon.h, common FSIGLT)
C     fOrogr  : orographic factor (used for surface drag)
C               (originally in com_sflcon.h, common SFLFIX)
C snLat,csLat : sin(Lat) & cos(Lat) ; 
C               (originally in com_physcon.h, common FSIGLT)
      COMMON /AIM_GRID_R/ fOrogr, WVSurf, snLat, csLat
      _RL fOrogr(NGP,MAX_NO_THREADS)
      _RL WVSurf(NGP,MAX_NO_THREADS)
      _RL snLat (NGP,MAX_NO_THREADS)
      _RL csLat (NGP,MAX_NO_THREADS)

#endif /* ALLOW_AIM */ 
