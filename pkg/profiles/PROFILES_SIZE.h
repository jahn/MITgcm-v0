C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/profiles/PROFILES_SIZE.h,v 1.3 2017/04/03 23:16:38 ou.wang Exp $
C $Name:  $

C============================================================
C NOBSGLOB            :: maximum number of profiles per file and tile
C NFILESPROFMAX       :: maximum number of files
C NVARMAX             :: maximum number of variables 
C NLEVELMAX           :: maximum number of vertical levels 
C NUM_INTERP_POINTS   :: number of points used in horizontal averaging
C============================================================

      INTEGER  NOBSGLOB
      PARAMETER ( NOBSGLOB = 500  )
      INTEGER NFILESPROFMAX
      PARAMETER ( NFILESPROFMAX=20 )
      INTEGER NVARMAX
      PARAMETER ( NVARMAX=6 )
      INTEGER NLEVELMAX
      PARAMETER ( NLEVELMAX=110 )
      INTEGER NUM_INTERP_POINTS
      PARAMETER (NUM_INTERP_POINTS = 4)
#ifdef ALLOW_PROFILES_SAMPLESPLIT_COST
      INTEGER NLEVELCOMBMAX
      PARAMETER ( NLEVELCOMBMAX=50 )
      INTEGER NAVGBINMAX
      PARAMETER ( NAVGBINMAX=2500 )
#endif
