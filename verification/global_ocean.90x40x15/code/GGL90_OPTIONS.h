C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/global_ocean.90x40x15/code/GGL90_OPTIONS.h,v 1.1 2015/02/19 16:00:45 mlosch Exp $
C $Name:  $

C     *=============================================================*
C     | GGL90_OPTIONS.h
C     | o CPP options file for GGL90 package.
C     *=============================================================*
C     | Use this file for selecting options within the GGL90
C     | package.
C     *=============================================================*

#ifndef GGL90_OPTIONS_H
#define GGL90_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_GGL90
C     Package-specific Options & Macros go here

C     Enable horizontal diffusion of TKE.
#undef ALLOW_GGL90_HORIZDIFF

C     Use horizontal averaging for viscosity and diffusivity as
C     originally implemented in OPA.
#undef ALLOW_GGL90_SMOOTH

c-----------------------------------------------------------------------
c       include IDEMIX model
c-----------------------------------------------------------------------
#define ALLOW_GGL90_IDEMIX


#endif /* ALLOW_GGL90 */
#endif /* GGL90_OPTIONS_H */
