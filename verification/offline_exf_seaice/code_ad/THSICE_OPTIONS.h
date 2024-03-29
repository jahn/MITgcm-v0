C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/offline_exf_seaice/code_ad/THSICE_OPTIONS.h,v 1.1 2013/04/20 23:51:48 jmc Exp $
C $Name:  $

#ifndef THSICE_OPTIONS_H
#define THSICE_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_THSICE
C     Package-specific Options & Macros go here

C- use continuous power-law function for partition of energy between lateral
C  melting/freezing and thinning/thickening ; otherwise, use step function.
#define THSICE_FRACEN_POWERLAW

C- allow single grid-point debugging write to standard-output
#undef ALLOW_DBUG_THSICE

C- only to check conservation
C  (change content of ICE_qleft,fresh,salFx-T files)
#undef CHECK_ENERGY_CONSERV

C CPP Macros go here

#endif /* ALLOW_THSICE */
#endif /* THSICE_OPTIONS_H */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
