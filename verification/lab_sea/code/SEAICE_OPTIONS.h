C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/lab_sea/code/SEAICE_OPTIONS.h,v 1.4 2003/10/09 04:19:31 edhill Exp $

C     /==========================================================\
C     | SEAICE_OPTIONS.h                                         |
C     | o CPP options file for sea ice package.                  |
C     |==========================================================|
C     | Use this file for selecting options within the sea ice   |
C     | package.  Sea ice model is enabled with ALLOW_SEAICE in  |
C     | CPP_OPTIONS.h                                            |
C     \==========================================================/

#ifndef SEAICE_OPTIONS_H
#define SEAICE_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_SEAICE

#include "CPP_OPTIONS.h"

C--   Write "text-plots" of certain fields in STDOUT for debugging.
#undef SEAICE_DEBUG

C--   Allow sea-ice dynamic code.
C     This option is provided to allow use of TAMC
C     on the thermodynamics component of the code only.
C     Sea-ice dynamics can also be turned off at runtime
C     using variable SEAICEuseDYNAMICS.
#define SEAICE_ALLOW_DYNAMICS

C--   By default, pkg/seaice defines forcing variable internally, in
C     SEAICE_FFIELDS.h, and reads them in from files.  When CPP option
C     SEAICE_EXTERNAL_FORCING is defined, the above forcing variables
C     are defined and provided by an external package.  At present this
C     option is hardwired for pkg/exf and the variables are passed using
C     include file exf_fields.h.
#define SEAICE_EXTERNAL_FORCING

C--   By default, the sea-ice package uses its own integrated bulk
C     formulae to compute fluxes (fu, fv, EmPmR, Qnet, and Qsw) over
C     open-ocean.  When this flag is set, these variables are computed
C     in a separate external package, for example, pkg/exf, and then
C     modified for sea-ice effects by pkg/seaice.
#undef SEAICE_EXTERNAL_FLUXES

C-- This include is necessary because of awkward dependancies with pkg/exf
#define INCLUDE_EXTERNAL_FORCING_PACKAGE
#include "EXF_OPTIONS.h"

#endif /* ALLOW_SEAICE */
#endif /* SEAICE_OPTIONS_H */
