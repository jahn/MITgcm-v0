C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/obcs/OBCS_OPTIONS.h,v 1.2.8.2 2002/02/09 02:18:03 heimbach Exp $
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

C Enable OB values to be prescribed via EXF package
#define ALLOW_OBCS_PRESCRIBE

C This includes hooks to sponge layer treatment of uvel, vvel
#undef ALLOW_OBCS_SPONGE

C North/South/East/West open boundaries
 
#undef ALLOW_OBCS_NORTH
#undef ALLOW_OBCS_SOUTH
#undef ALLOW_OBCS_EAST
#undef ALLOW_OBCS_WEST

#endif /* ALLOW_OBCS */
