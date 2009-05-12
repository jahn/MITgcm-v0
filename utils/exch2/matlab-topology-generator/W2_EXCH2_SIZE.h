C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/utils/exch2/matlab-topology-generator/Attic/W2_EXCH2_SIZE.h,v 1.1 2009/05/12 19:12:16 jmc Exp $
C $Name:  $

C      *** THIS FILE IS AUTOMATICALLY GENERATED ***
C---   Size of Tiling topology structures
C  W2_maxNbFacets   :: Maximum number of Facets (also and formerly called
C                   :: "domains" or "sub-domains") of this topology
C  W2_maxNeighbours :: Maximum number of neighbours any tile has.
C  W2_maxNbTiles    :: Maximum number of tiles (active+blank) in this topology
C  W2_ioBufferSize  :: Maximum size of Single-CPU IO buffer
       INTEGER W2_maxNbFacets
       INTEGER W2_maxNeighbours
       INTEGER W2_maxNbTiles
       INTEGER W2_ioBufferSize

C---   Default values : 6-face Cube-Sphere topology
       PARAMETER ( W2_maxNbFacets = 6 )
       PARAMETER ( W2_maxNeighbours = 5 )
       PARAMETER ( W2_maxNbTiles = 12 )
       PARAMETER ( W2_ioBufferSize = 6144 )

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
