C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/icefront/ICEFRONT_OPTIONS.h,v 1.5 2011/12/24 01:04:48 jmc Exp $
C $Name:  $

C     *==========================================================*
C     | ICEFRONT_OPTIONS.h
C     | o CPP options file for ICEFRONT package.
C     *==========================================================*
C     | Use this file for selecting options within the ICEFRONT
C     | package.
C     *==========================================================*

#ifndef ICEFRONT_OPTIONS_H
#define ICEFRONT_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_ICEFRONT
C     Package-specific Options & Macros go here

C--   Allow code for specifying sub-glacial runoff.
C     Adds capability for time-evolving specification
C     of addmass array based on a 2D field, which is added
C     at bottommost wet level at each horizontal location.
#undef ALLOW_SUBGLACIAL_RUNOFF

#endif /* ALLOW_ICEFRONT */
#endif /* ICEFRONT_OPTIONS_H */
