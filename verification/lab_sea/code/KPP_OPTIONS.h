C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/lab_sea/code/Attic/KPP_OPTIONS.h,v 1.1.2.1 2002/11/11 22:03:47 heimbach Exp $
C $Name:  $
C     /==========================================================\
C     | KPP_OPTIONS.h                                            |
C     | o CPP options file for KPP package.                      |
C     |==========================================================|
C     | Use this file for selecting options within the KPP       |
C     | package.  KPP is enabled with ALLOW_KPP in CPP_OPTIONS.h |
C     \==========================================================/

#include "CPP_OPTIONS.h"

C o Set precision for KPP variables (Real*4 or Real*8)
#define _KPP_RL Real*8

#ifdef ALLOW_KPP

C o When set, use exchange calls rather than recomputation
C   to obtain KPP parameters in overlap region.  This option
C   was added to reduce stack size requirements on the
C   Origin 2000.  It decreases memory and computation
C   requirements at the expense of increased communications.
C   For a 64-processor 360x224x46 MPI configuration on the
C   Exemplar or Origin 2000, wall clock time is about the
C   same whether FRUGAL_KPP is turned on or off.
#undef FRUGAL_KPP

C o When set, smooth zonal shear meridionally and
C   meridional shear zonally with 121 filters
#define KPP_SMOOTH_SHSQ
#undef KPP_SMOOTH_DVSQ

C o When set, smooth dbloc KPP variable horizontally
#define KPP_SMOOTH_DBLOC

C o When set, smooth all KPP density variables horizontally
#undef KPP_SMOOTH_DENS
#ifdef KPP_SMOOTH_DENS
#  define KPP_SMOOTH_DBLOC
#endif

C o When set, smooth vertical viscosity horizontally
#undef KPP_SMOOTH_VISC

C o When set, smooth vertical diffusivity horizontally
#undef KPP_SMOOTH_DIFF

C o Switch on vertical smoothing, the number of sweeps is set in the namelist
#undef ALLOW_KPP_VERTICALLY_SMOOTH

C o Get rid of vertical resolution dependence of dVsq term by
C   estimating a surface velocity that is independent of first
C   level thickness in the model.
#undef KPP_ESTIMATE_UREF

C o Include/exclude various time-averaged diagnostic output
C   for saving storage space
#ifdef  ALLOW_TIMEAVE
#define INCLUDE_DIAGNOSTICS_KPP
#undef  INCLUDE_DIAGNOSTICS_KPPDIFFKZSTAVE
#endif

C o Include/exclude KPP non/local transport terms
#define KPP_GHAT

#endif /* ALLOW_KPP */
