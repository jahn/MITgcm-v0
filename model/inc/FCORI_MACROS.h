C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/FCORI_MACROS.h,v 1.3 2001/05/29 14:01:36 adcroft Exp $
C $Name:  $
C
C     /==========================================================\
C     | FCORI_MACROS.h                                           |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef FCORI_CONST
#define  _fCori(i,j,bi,bj) fCori(1,1,1,1)
#define  _fCoriG(i,j,bi,bj) fCoriG(1,1,1,1)
#endif

#ifdef FCORI_FX
#define  _fCori(i,j,bi,bj) fCori(i,1,bi,1)
#define  _fCoriG(i,j,bi,bj) fCoriG(i,1,bi,1)
#endif

#ifdef FCORI_FY
#define  _fCori(i,j,bi,bj) fCori(1,j,1,bj)
#define  _fCoriG(i,j,bi,bj) fCoriG(1,j,1,bj)
#endif

#ifndef _fCori
#define  _fCori(i,j,bi,bj) fCori(i,j,bi,bj)
#define  _fCoriG(i,j,bi,bj) fCoriG(i,j,bi,bj)
#endif
