C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/shap_filt/SHAP_FILT_OPTIONS.h,v 1.5 2003/10/09 04:19:20 edhill Exp $
C $Name:  $

C Header file for package pkg/shap_filt

#ifndef SHAP_FILT_OPTIONS_H
#define SHAP_FILT_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_SHAP_FILT

#include "CPP_OPTIONS.h"

C Use [1-d_yy^n)(1-d_xx^n] instead of [1-d_xx^n-d_yy^n]
C This changes the spectral response function dramatically.
C You need to do some analysis before changing this option. ;^)
#define SEQUENTIAL_2D_SHAP

C This invokes the older code which produces the same numbers
C and might even be faster because it does not do multiple
C exchanges within the filter. However, this requires the
C overlap to be sufficiently wide and also does not work
C for arbitrarily arranged tiles (ie. as in cubed-sphere).
C *DO NOT USE THIS OPTION UNLESS YOU REALLY WANT TO*  :-(
#undef  USE_OLD_SHAPIRO_FILTERS

#ifdef USE_OLD_SHAPIRO_FILTERS
C Boundary conditions for U,V Shapiro code
C Horizontal shear is calculated as if the boundaries are no-slip
C Note: option NO_SLIP_SHAP only used in OLD_SHAPIRO_FILTERS ;
C   it is replaced by parameter "Shap_noSlip=1." in new S/R.
#undef  NO_SLIP_SHAP
#endif

#endif /* ALLOW_SHAP_FILT */
#endif /* SHAP_FILT_OPTIONS_H */
