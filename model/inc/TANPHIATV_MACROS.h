C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/TANPHIATV_MACROS.h,v 1.2 2001/02/04 14:38:45 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | TANPHIATV_MACROS.h                                       |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef TANPHIATV_CONST
#define  _tanPhiAtV(i,j,bi,bj) tanPhiAtV(1,1,1,1)
#endif

#ifdef TANPHIATV_FX
#define  _tanPhiAtV(i,j,bi,bj) tanPhiAtV(i,1,bi,1)
#endif

#ifdef TANPHIATV_FY
#define  _tanPhiAtV(i,j,bi,bj) tanPhiAtV(1,j,1,bj)
#endif

#ifndef _tanPhiAtV
#define  _tanPhiAtV(i,j,bi,bj) tanPhiAtV(i,j,bi,bj)
#endif
