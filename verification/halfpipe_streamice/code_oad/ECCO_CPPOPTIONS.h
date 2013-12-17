C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/halfpipe_streamice/code_oad/ECCO_CPPOPTIONS.h,v 1.1 2013/12/17 19:08:33 heimbach Exp $
C $Name:  $

#ifndef ECCO_CPPOPTIONS_H
#define ECCO_CPPOPTIONS_H

C
C CPP flags controlling which code is included in the files that
C will be compiled.

C ********************************************************************
C ***                  Adjoint Support Package                     ***
C ********************************************************************

C o Include/exclude code in order to be able to automatically
C   differentiate the MITgcmUV by using the Tangent Linear and
C   Adjoint Model Compiler (TAMC).
C
#define ALLOW_AUTODIFF_TAMC
C       >>> Checkpointing as handled by TAMC
#define ALLOW_TAMC_CHECKPOINTING
C
#define ALLOW_AUTODIFF_OPENAD
C       >>> Extract adjoint state
#undef ALLOW_AUTODIFF_MONITOR
C
C       >>> DO 2-level checkpointing instead of 3-level
#undef AUTODIFF_2_LEVEL_CHECKPOINT
C
C o use divided adjoint to split adjoint computations
#undef ALLOW_DIVIDED_ADJOINT
#undef ALLOW_DIVIDED_ADJOINT_MPI

C ********************************************************************
C ***                Cost function Package                         ***
C ********************************************************************
C
C       >>> Cost function contributions
#define ALLOW_COST_TEST

C ********************************************************************
C ***               Control vector Package                         ***
C ********************************************************************
C
#undef EXCLUDE_CTRL_PACK
#undef  ALLOW_NONDIMENSIONAL_CONTROL_IO
C
C       >>> Initial values.
#define ALLOW_GENARR2D_CONTROL

#endif /* ECCO_CPPOPTIONS_H */

