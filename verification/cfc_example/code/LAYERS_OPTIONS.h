C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/cfc_example/code/LAYERS_OPTIONS.h,v 1.1 2015/06/10 20:54:32 jmc Exp $
C $Name:  $

C CPP options file for LAYERS package
C Use this file for selecting options within package "LAYERS"

#ifndef LAYERS_OPTIONS_H
#define LAYERS_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_LAYERS
C     Package-specific Options & Macros go here

C Compute isopycnal tranports in the U direction?
#define LAYERS_UFLUX
C Compute isopycnal tranports in the V direction?
#define LAYERS_VFLUX
C Keep track of layer thicknesses?
#define LAYERS_THICKNESS
C Do water mass thermodynamics?
#define LAYERS_THERMODYNAMICS
C Use refined grid for diapycnal terms? (gives worse results)
#undef LAYERS_FINEGRID_DIAPYCNAL

C The MNC stuff is too complicated
#undef LAYERS_MNC

C Allow use of potential density as a layering field.
#define LAYERS_PRHO_REF

#endif /* ALLOW_LAYERS */
#endif /* LAYERS_OPTIONS_H */
