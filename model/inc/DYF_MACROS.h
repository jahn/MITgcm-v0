C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/DYF_MACROS.h,v 1.2 2001/02/04 14:38:44 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | DYF_MACROS.h                                             |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef DYF_CONST
#define  _dyF(i,j,bi,bj) dyF(1,1,1,1)
#endif

#ifdef DYF_FX
#define  _dyF(i,j,bi,bj) dyF(i,1,bi,1)
#endif

#ifdef DYF_FY
#define  _dyF(i,j,bi,bj) dyF(1,j,1,bj)
#endif

#ifndef _dyF
#define  _dyF(i,j,bi,bj) dyF(i,j,bi,bj)
#endif
