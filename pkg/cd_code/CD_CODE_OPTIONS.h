C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/cd_code/CD_CODE_OPTIONS.h,v 1.2 2009/11/19 22:29:36 jmc Exp $
C $Name:  $

C CPP options file for CD_CODE package
C
C Use this file for selecting CPP options within the cd_code package

#ifndef CD_CODE_OPTIONS_H
#define CD_CODE_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_CD_CODE

#include "CPP_OPTIONS.h"

C Change defaut to get the same time-stepping for D-grid momentum and
C  C-grid momentum. D-grid velocity used to be stepped forward in time
C  with Adams-Bashforth only on surface pressure term. Tests show that
C  using AB on D-grid coriolis term improves stability (as expected from
C  CD-scheme paper). The following 2 options allow to reproduce old results.
#undef CD_CODE_NO_AB_MOMENTUM
#undef CD_CODE_NO_AB_CORIOLIS

C CPP macros go here

#endif /* ALLOW_CD_CODE */
#endif /* CD_CODE_OPTIONS_H */
