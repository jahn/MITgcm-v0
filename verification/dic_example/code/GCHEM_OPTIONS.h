C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/dic_example/code/Attic/GCHEM_OPTIONS.h,v 1.6 2005/12/06 16:52:36 stephd Exp $
C $Name:  $

#ifndef GCHEM_OPTIONS_H
#define GCHEM_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_GCHEM

#include "CPP_OPTIONS.h"

CBOP
C    !ROUTINE: GCHEM_OPTIONS.h
C    !INTERFACE:

C    !DESCRIPTION:
c options for biogeochemistry package
CEOP

#define GCHEM_SEPARATE_FORCING

c------------------------------------
c specifics for dic pkg
#define DIC_BIOTIC
#undef  ALLOW_FE
#undef READ_PAR
#undef MINFE
c -------------------------------------

#undef  ALLOW_CFC

#endif /* ALLOW_GCHEM */
#endif /* GCHEM_OPTIONS_H */
