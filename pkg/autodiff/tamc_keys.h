C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/autodiff/tamc_keys.h,v 1.3 2006/06/07 01:55:13 heimbach Exp $
C
C     /==========================================================\
C     | tamc_keys.h keys required by TAMC for record computation |
C     |==========================================================|
C     \==========================================================/
      integer           key, ikey
      common /tamckeys/ key, ikey
#ifdef ALLOW_CG2D_NSA
      integer           icg2dkey
      common /tamckeys_cg2d/ icg2dkey
#endif /* ALLOW_CG2D_NSA */
