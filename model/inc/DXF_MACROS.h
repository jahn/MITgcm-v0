C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/DXF_MACROS.h,v 1.1 1998/05/26 21:29:44 cnh Exp $
C
C     /==========================================================\
C     | DXF_MACROS.h                                             |
C     |==========================================================|
C     | These macros are used to reduce memory requirement and/or|
C     | memory references when variables are fixed along a given |
C     | axis or axes.                                            |
C     \==========================================================/

#ifdef DXF_CONST
#define  _dxF(i,j,bi,bj) dxF(1,1,1,1)
#endif

#ifdef DXF_FX_ONLY
#define  _dxF(i,j,bi,bj) dxF(i,1,bi,1)
#endif

#ifdef DXF_FY_ONLY
#define  _dxF(i,j,bi,bj) dxF(1,j,1,bj)
#endif

#ifndef _dxF
#define  _dxF(i,j,bi,bj) dxF(i,j,bi,bj)
#endif
