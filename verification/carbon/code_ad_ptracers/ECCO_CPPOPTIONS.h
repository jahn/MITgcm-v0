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
#undef ALLOW_AUTODIFF_MONITOR
C
C o use divided adjoint to split adjoint computations
#undef ALLOW_DIVIDED_ADJOINT
#undef ALLOW_DIVIDED_ADJOINT_MPI

C ********************************************************************
C ***                     Calender Package                         ***
C ********************************************************************
C
C CPP flags controlling which code is included in the files that
C will be compiled.
C
C o Include the calendar tool.
#undef ALLOW_CALENDAR
#undef ALLOW_CAL_NENDITER

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

