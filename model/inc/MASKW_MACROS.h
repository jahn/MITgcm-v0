C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/MASKW_MACROS.h,v 1.2 2001/02/04 14:38:45 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | MASKW_MACROS.h                                           |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef MASKW_CONST
#define  _maskW(i,j,k,bi,bj) maskW(1,1,1,1,1)
#endif

#ifdef MASKW_FX
#define  _maskW(i,j,k,bi,bj) maskW(i,1,1,bi,1)
#endif

#ifdef MASKW_FY
#define  _maskW(i,j,k,bi,bj) maskW(1,j,1,1,bj)
#endif

#ifdef MASKW_FXY
#define  _maskW(i,j,k,bi,bj) maskW(i,j,1,bi,bj)
#endif

#ifndef _maskW
#define  _maskW(i,j,k,bi,bj) maskW(i,j,k,bi,bj)
#endif
