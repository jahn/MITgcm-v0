C
C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/global_ocean.90x40x15/code_ad_vecinv/Attic/CPP_OPTIONS.h,v 1.5 2003/10/26 01:22:24 heimbach Exp $
C $Name:  $

C CPP flags controlling which code in included in the files that
C will be compiled.

#ifndef CPP_OPTIONS_H
#define CPP_OPTIONS_H

#include "PACKAGES_CONFIG.h"
#include "AD_CONFIG.h"

C o Shortwave heating as extra term in external_forcing.F
#ifdef ALLOW_KPP
#define  SHORTWAVE_HEATING
#endif

C o Include/exclude code for C-D grid method of integrating the 
C   coriolis terms
#undef  INCLUDE_CD_CODE

C o Include/exclude momentum eqn metric terms code
#define INCLUDE_MOMENTUM_METRIC_TERM_CODE

C o Include/exclude phi_hyd calculation code
#define INCLUDE_PHIHYD_CALCULATION_CODE

C o Include/exclude call to S/R CONVECT
#define INCLUDE_CONVECT_CALL

C o Include/exclude call to S/R CALC_DIFFUSIVITY
#define INCLUDE_CALC_DIFFUSIVITY_CALL

C o Allow nonHydrostatic code
#undef  ALLOW_NONHYDROSTATIC

C o Use "natural" boundary conditions for salinity
C   instead of the "virtual salt flux"
#undef  USE_NATURAL_BCS

C o Read/write of checkpoint files for restarting.
#undef OLD_STYLE_WITH_MANY_FILES

C o Exact volume conservation
#define EXACT_CONSERV

C o Include/exclude monitor package
#define EXCLUDE_MONITOR

C o Execution environment support options
#include "CPP_EEOPTIONS.h"

C o Include/exclude code specific to the ECCO/SEALION version.
#define ALLOW_GRADIENT_CHECK

#if (defined (INCLUDE_ECCO_PACKAGE) || \
     defined (ALLOW_ADJOINT_RUN) || \
     defined (ALLOW_TANGENTLINEAR_RUN))
#include "ECCO_CPPOPTIONS.h"
#endif

#endif /* CPP_OPTIONS_H */

