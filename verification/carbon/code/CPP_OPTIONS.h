C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/carbon/code/Attic/CPP_OPTIONS.h,v 1.11 2003/01/10 23:41:15 heimbach Exp $
C
C CPP flags controlling which code in included in the files that
C will be compiled.

C o Include/exclude code for AIM package
#undef  ALLOW_AIM

C o Include/exclude code for GM/Redi parameterization
#define  ALLOW_GMREDI

C o Include/exclude code for KPP mixing scheme
#undef  ALLOW_KPP

C o Shortwave heating as extra term in external_forcing.F
#ifdef ALLOW_KPP
#define  SHORTWAVE_HEATING
#endif

C o Include/exclude code for Shapiro filters
#undef  ALLOW_SHAP_FILT

C o Include/exclude code for C-D grid method of integrating the 
C   coriolis terms
#define  INCLUDE_CD_CODE

C o Include/exclude code for open-boundary conditions
#undef  ALLOW_OBCS

C o Include/exclude diagnostics package interface code
#define  ALLOW_TIMEAVE

C o Include/exclude latitude circle FFT filter
#undef  ALLOW_ZONAL_FILT

C o Include/exclude temperature advection code
cph
#define  INCLUDE_TR1_ADVECTION_CODE
#define  INCLUDE_T_ADVECTION_CODE
#ifdef   INCLUDE_T_ADVECTION_CODE
#define  _ADT(a)a
#endif
#ifndef  INCLUDE_T_ADVECTION_CODE
#define  _ADT(a)
#endif

C o Include/exclude temperature diffusion code
#define  INCLUDE_TR1_DIFFUSION_CODE
#define  INCLUDE_T_DIFFUSION_CODE
#ifdef   INCLUDE_T_DIFFUSION_CODE
#define  _LPT(a)a
#define  _BHT(a)a
#endif
#ifndef  INCLUDE_T_DIFFUSION_CODE
#define  _LPT(a)
#define  _BHT(a)
#endif

C o Include/exclude temperature forcing code
cph
#undef   INCLUDE_TR1_FORCING_CODE
#define  INCLUDE_T_FORCING_CODE

C o Include/exclude momentum advection code
cph
#define  INCLUDE_MOMENTUM_ADVECTION_CODE
#ifdef   INCLUDE_MOMENTUM_ADVECTION_CODE
#define  _ADM(a)a
#endif
#ifndef  INCLUDE_MOMENTUM_ADVECTION_CODE
#define  _ADM(a)
#endif

C o Include/exclude laplacian viscosity code
#define  INCLUDE_LP_MOMENTUM_DIFFUSION_CODE
#ifdef   INCLUDE_LP_MOMENTUM_DIFFUSION_CODE
#define  _LPM(a)a
#endif
#ifndef  INCLUDE_LP_MOMENTUM_DIFFUSION_CODE
#define  _LPM(a)
#endif

C o Include/exclude biharmonic viscosity code
#define  INCLUDE_BH_MOMENTUM_DIFFUSION_CODE
#ifdef   INCLUDE_BH_MOMENTUM_DIFFUSION_CODE
#define  _BHM(a)a
#else
#define  _BHM(a)
#endif

C o Include/exclude gradient of phy_hyd code
#define INCLUDE_GRADPH_CODE
#ifdef  INCLUDE_GRADPH_CODE
#define _PHM(a)a
#endif
#ifndef INCLUDE_GRADPH_CODE
#define _PHM(a)
#endif

C o Include/exclude momentum forcing code
cph
#define INCLUDE_MOMENTUM_FORCING_CODE

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

C o Use "OLD" UV discretisation near boundaries (*not* recommended)
C   Note - only works with  #undef NO_SLIP_LATERAL  in calc_mom_rhs.F
C          because the old code did not have no-slip BCs
#undef  OLD_ADV_BCS

C o Use "OLD" UV geometry on sphere (definately *NOT* recommended)
C   Note - only works with  #undef NO_SLIP_LATERAL  in calc_mom_rhs.F
C          because the old code did not have no-slip BCs
#undef  OLD_UV_GEOMETRY

C o Read/write of checkpoint files for restarting.
#undef OLD_STYLE_WITH_MANY_FILES

C o Exact volume conservation
#define EXACT_CONSERV

C o Add passive tracer advection routines
#define ALLOW_PASSIVE_TRACER

C o Include/exclude monitor package
#define EXCLUDE_MONITOR

C o Include/exclude code for sea-ice model
#undef  ALLOW_SEAICE

c o Allow atmospheric loading
#define ATMOSPHERIC_LOADING 

C o Execution environment support options
#include "CPP_EEOPTIONS.h"

C o Include/exclude code specific to the ECCO/SEALION version.
#undef INCLUDE_ECCO_PACKAGE
#define ALLOW_ADJOINT_RUN
#define ALLOW_GRADIENT_CHECK
#undef ALLOW_TANGENTLINEAR_RUN

#if (defined (INCLUDE_ECCO_PACKAGE) || \
     defined (ALLOW_ADJOINT_RUN) || \
     defined (ALLOW_TANGENTLINEAR_RUN))
#include "ECCO_CPPOPTIONS.h"
#endif



