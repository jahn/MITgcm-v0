c $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exf/Attic/exf.h,v 1.1.4.2 2003/01/12 08:20:10 dimitri Exp $
c
c
c     ==================================================================
c     HEADER EXF
c     ==================================================================
c
c     o Header for the external forcing package
c
c     started: Christian Eckert eckert@mit.edu  30-Jun-1999
c
c     changed: Christian Eckert eckert@mit.edu  14-Jan-2000
c              - restructured the original version in order to have a
c                better interface to the MITgcmUV.
c
c     mods for pkg/seaice: menemenlis@jpl.nasa.gov 20-Dec-2002
c
c     ==================================================================
c     HEADER EXF
c     ==================================================================

      character*(5) externalforcingversion
      character*(5) usescalendarversion

      parameter(    externalforcingversion = '0.2.2' )
      parameter(    usescalendarversion    = '0.2.0' )
