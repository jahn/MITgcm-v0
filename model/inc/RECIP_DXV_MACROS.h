C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/RECIP_DXV_MACROS.h,v 1.1 1998/08/15 16:55:48 cnh Exp $
C
C     /==========================================================\
C     | RECIP_DXV_MACROS.h                                       |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef RECIP_DXV_CONST
#define  _recip_dxV(i,j,bi,bj) recip_dxV(1,1,1,1)
#endif

#ifdef RECIP_DXV_FX
#define  _recip_dxV(i,j,bi,bj) recip_dxV(i,1,bi,1)
#endif

#ifdef RECIP_DXV_FY
#define  _recip_dxV(i,j,bi,bj) recip_dxV(1,j,1,bj)
#endif

#ifndef _recip_dxV
#define  _recip_dxV(i,j,bi,bj) recip_dxV(i,j,bi,bj)
#endif
