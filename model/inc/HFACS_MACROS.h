C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/HFACS_MACROS.h,v 1.2 2001/02/04 14:38:44 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | HFACS_MACROS.h                                           |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef HFACS_CONST
#define  _hFacS(i,j,k,bi,bj) hFacS(1,1,1,1,1)
#endif

#ifdef HFACS_FX
#define  _hFacS(i,j,k,bi,bj) hFacS(i,1,1,bi,1)
#endif

#ifdef HFACS_FY
#define  _hFacS(i,j,k,bi,bj) hFacS(1,j,1,1,bj)
#endif

#ifdef HFACS_FXY
#define  _hFacS(i,j,k,bi,bj) hFacS(i,j,1,bi,bj)
#endif

#ifndef _hFacS
#define  _hFacS(i,j,k,bi,bj) hFacS(i,j,k,bi,bj)
#endif
