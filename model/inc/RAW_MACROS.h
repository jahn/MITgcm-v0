C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/RAW_MACROS.h,v 1.2 2001/02/04 14:38:45 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | RAW_MACROS.h                                             |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef RA_CONST
#define  _rAw(i,j,bi,bj) rAw(1,1,1,1)
#endif

#ifdef RA_FX
#define  _rAw(i,j,bi,bj) rAw(i,1,bi,1)
#endif

#ifdef RA_FY
#define  _rAw(i,j,bi,bj) rAw(1,j,1,bj)
#endif

#ifndef _rAw
#define  _rAw(i,j,bi,bj) rAw(i,j,bi,bj)
#endif
