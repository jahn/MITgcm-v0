C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/global2x2_tot/code/Attic/GAD_OPTIONS.h,v 1.1.2.1 2002/04/04 12:05:47 heimbach Exp $
C $Name:  $

CBOP
C !ROUTINE: GAD_OPTIONS.h

C !INTERFACE:
C #include "GAD_OPTIONS.h" 

C !DESCRIPTION:
C Contains CPP macros/flags for controlling optional features of package.
CEOP

C CPP options file for GAD (Generic Advection Diffusion) package
C
C Use this file for selecting options within the GAD package
C
C GAD is enabled with ALLOW_GAD in CPP_OPTIONS.h

#include "CPP_OPTIONS.h"

#ifndef __GAD_OPTIONS
#ifndef DISABLE_GENERIC_ADVDIFF

C The selects the form of COSINE(lat) scaling of bi-harmonic term.
C *only for use on a lat-lon grid*
#define COSINEMETH_III

C The selects isotropic scaling of bi-harmonic term when
C using the COSINE(lat) scaling.
#undef  ISOTROPIC_COS_SCALING

C As of checkpoint41, the inclusion of multi-dimensional advection
C introduces excessive recomputation/storage for the adjoint.
C We can disable it here using CPP because run-time flags are insufficient.
#define  DISABLE_MULTIDIM_ADVECTION

#else

C If GAD is disabled then so is multi-dimensional advection
#define DISABLE_MULTIDIM_ADVECTION

#endif /* DISABLE_GENERIC_ADVDIFF */
#define __GAD_OPTIONS
#endif /* __GAD_OPTIONS */
