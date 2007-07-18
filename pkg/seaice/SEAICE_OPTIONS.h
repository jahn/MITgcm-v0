C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/seaice/SEAICE_OPTIONS.h,v 1.24 2007/07/18 22:26:05 dimitri Exp $
C $Name:  $

C     /==========================================================\
C     | SEAICE_OPTIONS.h                                         |
C     | o CPP options file for sea ice package.                  |
C     |==========================================================|
C     | Use this file for selecting options within the sea ice   |
C     | package.                                                 |
C     \==========================================================/

#ifndef SEAICE_OPTIONS_H
#define SEAICE_OPTIONS_H
#include "PACKAGES_CONFIG.h"
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
C     include file EXF_FIELDS.h (=> cannot be defined without pkg/EXF )
#define SEAICE_EXTERNAL_FORCING
#ifndef ALLOW_EXF
# undef SEAICE_EXTERNAL_FORCING
#endif

#ifdef  SEAICE_EXTERNAL_FORCING
#  include "EXF_OPTIONS.h"
C--   By default, the sea-ice package uses its own integrated bulk
C     formulae to compute fluxes (fu, fv, EmPmR, Qnet, and Qsw) over
C     open-ocean.  When this flag is set, these variables are computed
C     in a separate external package, for example, pkg/exf, and then
C     modified for sea-ice effects by pkg/seaice.
# define SEAICE_EXTERNAL_FLUXES

#else  /* SEAICE_EXTERNAL_FORCING */
C-    current implementation requires those options to be set:
# undef  SEAICE_EXTERNAL_FLUXES
# define ALLOW_ATM_TEMP
# define ALLOW_DOWNWARD_RADIATION
# define ALLOW_RUNOFF

#endif /* SEAICE_EXTERNAL_FORCING */


C--   By default, the sea-ice package uses 2-category thermodynamics.
C     When this flag is set, an 8-category calculation of ice
C     thermodynamics is carried out in groatb.F
C     Note the pickup_seaice.* generated by this option differ
C     from those generated with the default 2-category model.
C     Therefore it is not possible to switch between the two
C     in the middle of an integration.
#undef SEAICE_MULTICATEGORY

C--   By default cdm wind stress under sea-ice is set to the
C     same value as it would be if there was no sea-ice.
C     This is a placeholder until a more physically-sensible
C     stable solution is developed.  Apparently ocean stress
C     that is based on sea-ice velocity can cause trouble in
C     Arctic Ocean configurations.  This temporary solution
C     also corresponds to that adopted by CCSM-2.  For the
C     adventurous user who requires ice-modified stress,
C     following options are available.
#undef SEAICE_ORIGINAL_BAD_ICE_STRESS
#undef SEAICE_TEST_ICE_STRESS_1

C--   By default the freezing point of water is set to the value of 
C     the parameter SEAICE_freeze (=-1.96 by default). To use a
C     simple linear dependence of the freezing point on salinity, 
C     set the following flag (pressure is assumed to have no effect,
C     which is a good assumption for the top 20 meters). With this
C     option defined the parameter SEAICE_freeze has no effect.
#undef SEAICE_VARIABLE_FREEZING_POINT

C--   Allow SEAICEuseFlooding, which converts snow to ice if submerged.
#undef ALLOW_SEAICE_FLOODING

C--   By default the seaice model is discretized on a B-Grid (for 
C     historical reasons). Define the following flag to use a new
C     (not thoroughly) test version on a C-grid
#define SEAICE_CGRID

C--   Only for the C-grid version it is possible to enable EVP code by
C     defining the following flag
#ifdef SEAICE_CGRID
#define SEAICE_ALLOW_EVP
#endif /* SEAICE_CGRID */

C--   When set use MAX_HEFF to cap sea ice thickness in seaice_growth
#undef SEAICE_CAP_HEFF

#endif /* SEAICE_OPTIONS_H */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
