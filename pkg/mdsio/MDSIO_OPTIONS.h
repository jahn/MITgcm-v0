C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/mdsio/MDSIO_OPTIONS.h,v 1.3 2003/10/09 04:19:19 edhill Exp $
C $Name:  $

#ifndef MDSIO_OPTIONS_H
#define MDSIO_OPTIONS_H
#include "PACKAGES_CONFIG.h"
#ifdef ALLOW_MDSIO

#include "CPP_OPTIONS.h"

C Defining SAFE_IO stops the model from overwriting its own files
#undef  SAFE_IO

#ifdef SAFE_IO
#define _NEW_STATUS 'new'
#else
#define _NEW_STATUS 'unknown'
#endif

#ifdef ALLOW_AUTODIFF_TAMC
#define ALLOW_BROKEN_MDSIO_GL
#define _OLD_STATUS 'unknown'
#else
#undef  ALLOW_BROKEN_MDSIO_GL
#define _OLD_STATUS 'old'
#endif

#endif /* ALLOW_MDSIO */
#endif /* MDSIO_OPTIONS_H */
