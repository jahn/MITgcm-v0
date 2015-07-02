C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/OpenAD/code_oad/GGL90_OPTIONS.h,v 1.1 2015/07/02 15:57:20 heimbach Exp $
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
#define ALLOW_GGL90_SMOOTH

C     allow IDEMIX model
#undef ALLOW_GGL90_IDEMIX

#endif /* ALLOW_GGL90 */
#endif /* GGL90_OPTIONS_H */
