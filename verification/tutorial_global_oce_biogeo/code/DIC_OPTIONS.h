C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/tutorial_global_oce_biogeo/code/Attic/DIC_OPTIONS.h,v 1.5 2011/04/20 20:44:53 jmc Exp $
C $Name:  $

#ifndef DIC_OPTIONS_H
#define DIC_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_DIC

#include "CPP_OPTIONS.h"

#define DIC_BIOTIC
#undef  ALLOW_FE
#define ALLOW_O2
#undef READ_PAR
#undef MINFE
c these all need to be defined for coupling to
c atmospheric model
#undef USE_QSW
#undef USE_ATMOSCO2
#undef USE_PLOAD

#undef ALLOW_OLD_VIRTUALFLUX

C put back bugs related to Water-Vapour in carbonate chemistry & air-sea fluxes
#undef WATERVAP_BUG

#endif /* ALLOW_DIC */
#endif /* DIC_OPTIONS_H */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
