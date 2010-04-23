C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exch2/W2_OPTIONS.h,v 1.4 2010/04/23 20:21:06 jmc Exp $
C $Name:  $

C CPP options file for EXCH2 package

#ifndef W2_OPTIONS_H
#define W2_OPTIONS_H

C ... W2_USE_E2_SAFEMODE description ...
#define W2_USE_E2_SAFEMODE

C Debug mode option:
#undef  W2_E2_DEBUG_ON

C Use only exch2_R1_cube (and avoid calling exch2_R2_cube)
#undef W2_USE_R1_ONLY

C Fill null regions (face-corner halo regions) with e2FillValue_RX (=0)
C notes: for testing (allow to check that results are not affected)
#undef W2_FILL_NULL_REGIONS

#endif /* W2_OPTIONS_H */
