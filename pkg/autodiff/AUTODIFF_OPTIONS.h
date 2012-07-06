C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/autodiff/AUTODIFF_OPTIONS.h,v 1.6 2012/07/06 23:12:45 jmc Exp $
C $Name:  $

CBOP
C !ROUTINE: AUTODIFF_OPTIONS.h
C !INTERFACE:
C #include "AUTODIFF_OPTIONS.h"

C !DESCRIPTION:
C *==================================================================*
C | CPP options file for AUTODIFF package:
C | Control which optional features to compile in this package code.
C *==================================================================*
CEOP

#ifndef AUTODIFF_OPTIONS_H
#define AUTODIFF_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#include "CPP_OPTIONS.h"

#ifdef ALLOW_AUTODIFF
C-- Package-specific options go here
C   Note: most of these options have been shifted to the common header
C         file ECCO_CPPOPTIONS.h

#endif /* ALLOW_AUTODIFF */
#endif /* AUTODIFF_OPTIONS_H */
