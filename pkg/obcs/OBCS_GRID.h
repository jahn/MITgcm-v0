C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/obcs/OBCS_GRID.h,v 1.4 2012/09/17 21:47:33 jmc Exp $
C $Name:  $

#ifdef ALLOW_OBCS

CBOP
C     !ROUTINE: OBCS_GRID.h
C     !INTERFACE:
C     #include "OBCS_GRID.h"

C     !DESCRIPTION:
C     *==========================================================*
C     | OBCS_GRID.h
C     | o Header file containing OBCS location on the grid
C     *==========================================================*
C     | o Note: does not (and should not) contain any conditional
C     |   statement that depends on OBCS options ; therefore
C     |   can be safely included without OBCS_OPTIONS.h
C     *==========================================================*
CEOP

C tileHasOB[N,S,E,W] :: this tile has OB at Northern/Southern/Eastern/Western edge
C   OB_Jn, OB_Js     :: indices of Northern & Southern OB location (cell center pt)
C   OB_Ie, OB_Iw     :: indices of  Eastern & Western  OB location (cell center pt)
C   OB_indexNone     :: null value for OB index (if row or column without OB)
C OBCS_indexStatus   :: track status of OB indices setting
C OBCS_insideMask    :: Inside OB region mask (zero beyond OB).

      COMMON /OBCS_ACTIVE_TILES/
     &  tileHasOBN, tileHasOBS, tileHasOBE, tileHasOBW
      LOGICAL tileHasOBN(nSx,nSy)
      LOGICAL tileHasOBS(nSx,nSy)
      LOGICAL tileHasOBE(nSx,nSy)
      LOGICAL tileHasOBW(nSx,nSy)

      COMMON /OBCS_GRID_INDICES/
     &  OB_Jn, OB_Js, OB_Ie, OB_Iw,
     &  OB_indexNone, OBCS_indexStatus
      INTEGER OB_Jn(1-OLx:sNx+OLx,nSx,nSy)
      INTEGER OB_Js(1-OLx:sNx+OLx,nSx,nSy)
      INTEGER OB_Ie(1-OLy:sNy+OLy,nSx,nSy)
      INTEGER OB_Iw(1-OLy:sNy+OLy,nSx,nSy)
      INTEGER OB_indexNone
      INTEGER OBCS_indexStatus

      COMMON /OBCS_MASK_RS/
     &  OBCS_insideMask
      _RS OBCS_insideMask(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

#endif /* ALLOW_OBCS */
