C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/natl_box_adjoint/code_seaice/Attic/OBCS_OPTIONS.h,v 1.1.2.1 2003/02/14 08:19:22 dimitri Exp $
C $Name:  $
 
C CPP options file for OBCS package
C
C Use this file for selecting options within the OBCS package
C
C OBCS is enabled with ALLOW_OBCS in CPP_OPTIONS.h

#include "CPP_OPTIONS.h"

#ifdef ALLOW_OBCS

C This include hooks to the Orlanski Open Boundary Radiation code
#undef ALLOW_ORLANSKI

C This includes hooks to sponge layer treatment of uvel, vvel
#define ALLOW_OBCS_SPONGE

C North/South/East/West open boundaries
 
#define ALLOW_OBCS_NORTH
#define ALLOW_OBCS_SOUTH
#define ALLOW_OBCS_EAST
#define ALLOW_OBCS_WEST

#endif /* ALLOW_OBCS */
