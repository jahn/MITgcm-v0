C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/tutorial_tracer_adjsens/code_ad/Attic/ECCO_CPPOPTIONS.h,v 1.4 2011/03/24 12:13:56 heimbach Exp $
C $Name:  $

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
C       >>> Extract adjoint state
#define ALLOW_AUTODIFF_MONITOR
C
C       >>> DO 2-level checkpointing instead of 3-level
#define AUTODIFF_2_LEVEL_CHECKPOINT
C
C o use divided adjoint to split adjoint computations
#undef ALLOW_DIVIDED_ADJOINT
#undef ALLOW_DIVIDED_ADJOINT_MPI
C
C o write separate tape files for each ptracer
#define AUTODIFF_PTRACERS_SPLIT_FILES

C ********************************************************************
C ***                     Calender Package                         ***
C ********************************************************************
C
C CPP flags controlling which code is included in the files that
C will be compiled.

CPH >>>>>> THERE ARE NO MORE CAL OPTIONS TO BE SET <<<<<<

C ********************************************************************
C ***                Cost function Package                         ***
C ********************************************************************
C
C       >>> Cost function contributions
#define ALLOW_COST
#undef ALLOW_COST_TEST
#define ALLOW_COST_TRACER
#undef ALLOW_COST_ATLANTIC_HEAT

C ********************************************************************
C ***               Control vector Package                         ***
C ********************************************************************
C
#define EXCLUDE_CTRL_PACK
#undef  ALLOW_NONDIMENSIONAL_CONTROL_IO
C
C       >>> Initial values.
#define ALLOW_THETA0_CONTROL
#define ALLOW_SALT0_CONTROL
#define ALLOW_TR10_CONTROL
#define ALLOW_TAUU0_CONTROL
#define ALLOW_TAUV0_CONTROL
#define ALLOW_SFLUX0_CONTROL
#define ALLOW_HFLUX0_CONTROL
#undef ALLOW_SSS0_CONTROL
#undef ALLOW_SST0_CONTROL
#define ALLOW_DIFFKR_CONTROL
#undef ALLOW_KAPGM_CONTROL

