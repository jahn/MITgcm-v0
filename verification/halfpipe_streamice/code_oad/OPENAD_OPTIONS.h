C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/halfpipe_streamice/code_oad/OPENAD_OPTIONS.h,v 1.2 2015/02/19 16:52:03 heimbach Exp $
C $Name:  $

CBOP
C !ROUTINE: OPENAD_OPTIONS.h
C !INTERFACE:
C #include "OPENAD_OPTIONS.h"

C !DESCRIPTION:
C *==================================================================*
C | CPP options file for OpenAD (openad) package:
C | Control which optional features to compile in this package code.
C *==================================================================*
CEOP

#ifndef OPENAD_OPTIONS_H
#define OPENAD_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_OPENAD

#define ALLOW_OPENAD_ACTIVE_READ_XY
#define ALLOW_OPENAD_ACTIVE_WRITE

#endif /* ALLOW_OPENAD */
#endif /* OPENAD_OPTIONS_H */
