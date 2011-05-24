C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/grdchk/GRDCHK_OPTIONS.h,v 1.1 2011/05/24 17:09:19 jmc Exp $
C $Name:  $

CBOP
C !ROUTINE: GRDCHK_OPTIONS.h
C !INTERFACE:
C #include "GRDCHK_OPTIONS.h"

C !DESCRIPTION:
C *==================================================================*
C | CPP options file for Gradient-Check (grdchk) package:
C | Control which optional features to compile in this package code.
C *==================================================================*
CEOP

#ifndef GRDCHK_OPTIONS_H
#define GRDCHK_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "AD_CONFIG.h"
#ifdef ALLOW_GRDCHK

#include "CPP_OPTIONS.h"

C-- Package-specific options go here
C   Note: most of these options have been shifted to the common header
C         file ECCO_CPPOPTIONS.h

#endif /* ALLOW_GRDCHK */
#endif /* GRDCHK_OPTIONS_H */
