C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/dic_example/code/Attic/CPP_OPTIONS.h,v 1.1 2004/09/01 03:44:40 edhill Exp $
C $Name:  $

#ifndef CPP_OPTIONS_H
#define CPP_OPTIONS_H

#include "PACKAGES_CONFIG.h"

C CPP flags controlling particular source code features

C o Include/exclude temperature forcing code
C#define  INCLUDE_T_FORCING_CODE

C o Shortwave heating as extra term in external_forcing.F
C Note: this should be a run-time option and not necessarily dependent on KPP
#ifdef ALLOW_KPP
#define  SHORTWAVE_HEATING
#endif

cswdptr --- add ---
#ifdef ALLOW_PTRACERS
#define NUMBER_OF_PTRACERS 5
#endif
cswdptr --- end add ----


C o Include/exclude momentum forcing code
#define INCLUDE_MOMENTUM_FORCING_CODE

C o Include/exclude momentum eqn metric terms code
#define INCLUDE_MOMENTUM_METRIC_TERM_CODE

C o Include/exclude phi_hyd calculation code
#define INCLUDE_PHIHYD_CALCULATION_CODE

C o Include/exclude call to S/R CONVECT
#undef  INCLUDE_CONVECT_CALL

C o Include/exclude call to S/R CALC_DIFFUSIVITY
#define INCLUDE_CALC_DIFFUSIVITY_CALL

C o Include/exclude nonHydrostatic code
#undef ALLOW_NONHYDROSTATIC

C o Include pressure loading code
#define ATMOSPHERIC_LOADING

C o Use "Exact Convervation" of fluid in Free-Surface formulation
C   so that d/dt(eta) is exactly equal to - Div.Transport
#undef  EXACT_CONSERV

C o Allow the use of Non-Linear Free-Surface formulation
C   this implies that surface thickness (hFactors) vary with time
#undef NONLIN_FRSURF

C o Use "OLD" UV discretisation near boundaries (*not* recommended)
C   Note - only works with  #undef NO_SLIP_LATERAL  in calc_mom_rhs.F
C          because the old code did not have no-slip BCs
#undef  OLD_ADV_BCS

C o Use "OLD" UV geometry on sphere (definately *NOT* recommended)
C   Note - only works with  #undef NO_SLIP_LATERAL  in calc_mom_rhs.F
C          because the old code did not have no-slip BCs
#undef  OLD_UV_GEOMETRY

C o Execution environment support options
#include "CPP_EEOPTIONS.h"

C o Include/exclude code specific to the ECCO/SEALION version.
#ifdef ALLOW_AUTODIFF
#include "ECCO_CPPOPTIONS.h"
#endif

#endif /* CPP_OPTIONS_H */

