C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/AIM_OPTIONS.h,v 1.1.2.1 2001/01/26 00:14:31 cnh Exp $
C $Name:  $

C  CPP options file for AIM package 
C
#include "CPP_OPTIONS.h"

#ifdef ALLOW_AIM

C     Macro mapping dynamics vertical indexing (KD) to AIM vertical indexing (KA).
C     ( dynamics puts K=1 at bottom of atmos., AIM puts K=1 at top of atmos. )
#define _KD2KA( KD ) Nr-KD+1

#endif /* ALLOW_AIM */
