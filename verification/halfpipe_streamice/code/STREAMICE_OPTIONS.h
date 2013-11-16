C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/halfpipe_streamice/code/STREAMICE_OPTIONS.h,v 1.2 2013/11/16 12:03:33 dgoldberg Exp $
C $Name:  $

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|

C CPP options file for MYPACKAGE
C
C Use this file for selecting options within package "streamice"

#ifndef STREAMICE_OPTIONS_H
#define STREAMICE_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_STREAMICE

#include "CPP_OPTIONS.h"

C Place CPP define/undef flag here

#define STREAMICE_CONSTRUCT_MATRIX
#define STREAMICE_HYBRID_STRESS
#define USE_ALT_RLOW
#undef STREAMICE_GEOM_FILE_SETUP
#define STREAMICE_SMOOTH_FLOATATION
#undef ALLOW_PETSC
#undef ALLOW_STREAMICE_2DTRACER
#undef STREAMICE_TRACER_AB
#undef STREAMICE_SERIAL_TRISOLVE

#endif /* ALLOW_MYPACKAGE */
#endif /* MYPACKAGE_OPTIONS_H */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
