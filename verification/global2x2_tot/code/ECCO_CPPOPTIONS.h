
C 
C CPP flags controlling which code is included in the files that
C will be compiled.
C
C ********************************************************************
C ***                         ECCO Package                         ***
C ********************************************************************
C
C o include dump of snap shots for checks
#define ALLOW_SNAPSHOTS

#undef  ALLOW_ECCO_FORWARD_RUN
#undef  ALLOW_ECCO_DIAGNOSTICS_RUN
#undef  ALLOW_ECCO_ADJOINT_RUN
#define  ALLOW_GRADIENT_CHECK
#define  ALLOW_ECCO_OPTIMIZATION

C       >>> Do a long protocol.
#undef ECCO_VERBOSE

C       >>> Just do a "dry" run ( useful for testing ).
#undef  ALLOW_NO_DYNAMICS
C       >>> Use the Yearly-Monthly-Daily-Stepping call tree.
#undef  ALLOW_YMDS_TREE
C       >>> Do not call stepping
#define ALLOW_STEPPING_CALL

C ********************************************************************
C ***                  Adjoint Support Package                     ***
C ********************************************************************

C o Include/exclude code in order to be able to automatically
C   differentiate the MITgcmUV by using the Tangent Linear and
C   Adjoint Model Compiler (TAMC).
#define INCLUDE_AUTODIFF_PACKAGE
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

C ********************************************************************
C ***                     Calender Package                         ***
C ********************************************************************
C 
C CPP flags controlling which code is included in the files that
C will be compiled.
C

C o Include the calendar tool.
#define ALLOW_CALENDAR
#define ALLOW_CAL_NENDITER

C ********************************************************************
C ***                Cost function Package                         ***
C ********************************************************************
C 
#define ALLOW_COST

#ifdef ALLOW_COST
C       >>> Use the EGM-96 geoid error covariance.
# define  ALLOW_EGM96_ERROR_DIAG
# undef  ALLOW_EGM96_ERROR_COV
# undef  ALLOW_SPH_PROJECTION

C       >>> Use NSCAT data.
# undef ALLOW_SCAT_COST_CONTRIBUTION

C       >>> Cost function contributions
# define ALLOW_HFLUX_COST_CONTRIBUTION
# define ALLOW_SFLUX_COST_CONTRIBUTION
# define ALLOW_MEAN_HFLUX_COST_CONTRIBUTION
# define ALLOW_MEAN_SFLUX_COST_CONTRIBUTION
# define ALLOW_USTRESS_COST_CONTRIBUTION
# define ALLOW_VSTRESS_COST_CONTRIBUTION
# define ALLOW_STRESS_MEAN_COST_CONTRIBUTION

# undef ALLOW_ATEMP_COST_CONTRIBUTION
# undef ALLOW_AQH_COST_CONTRIBUTION
# undef ALLOW_UWIND_COST_CONTRIBUTION
# undef ALLOW_VWIND_COST_CONTRIBUTION

# define ALLOW_THETA_COST_CONTRIBUTION
# define ALLOW_SALT_COST_CONTRIBUTION
# define ALLOW_THETA0_COST_CONTRIBUTION
# define ALLOW_SALT0_COST_CONTRIBUTION
# define ALLOW_SST_COST_CONTRIBUTION
# define ALLOW_SSS_COST_CONTRIBUTION

# define ALLOW_SSH_MEAN_COST_CONTRIBUTION
# define ALLOW_SSH_TPANOM_COST_CONTRIBUTION
# define ALLOW_SSH_ERSANOM_COST_CONTRIBUTION
# if (defined (ALLOW_SSH_MEAN_COST_CONTRIBUTION) || \
      defined (ALLOW_SSH_TPANOM_COST_CONTRIBUTION) || \
      defined (ALLOW_SSH_ERSANOM_COST_CONTRIBUTION))
#  define ALLOW_SSH_COST_CONTRIBUTION
# endif

# define ALLOW_XBT_COST_CONTRIBUTION
# define ALLOW_CTDT_COST_CONTRIBUTION
# define ALLOW_CTDS_COST_CONTRIBUTION
# undef ALLOW_DRIFTER_COST_CONTRIBUTION
# undef ALLOW_DRIFT_COST_CONTRIBUTION
# undef ALLOW_DRIFTW_COST_CONTRIBUTION
C
# define ALLOW_ARGO_THETA_COST_CONTRIBUTION
# define ALLOW_ARGO_SALT_COST_CONTRIBUTION
C
# undef ALLOW_COST_ATLANTIC
c
c       >>> Open boundaries
c       >>> Make sure that ALLOW_OBCS is defined!
# undef ALLOW_OBCSN_COST_CONTRIBUTION
# undef ALLOW_OBCSS_COST_CONTRIBUTION
# undef ALLOW_OBCSW_COST_CONTRIBUTION
# undef ALLOW_OBCSE_COST_CONTRIBUTION
# if (defined (ALLOW_OBCSN_COST_CONTRIBUTION) || \
      defined (ALLOW_OBCSS_COST_CONTRIBUTION) || \
      defined (ALLOW_OBCSW_COST_CONTRIBUTION) || \
      defined (ALLOW_OBCSE_COST_CONTRIBUTION))
#  define ALLOW_OBCS_COST_CONTRIBUTION
# endif

#endif /* ALLOW_COST */

C ********************************************************************
C ***               Control vector Package                         ***
C ********************************************************************
C 
#define  ALLOW_NONDIMENSIONAL_CONTROL_IO

C       >>> Initial values.
#define ALLOW_THETA0_CONTROL
#define ALLOW_SALT0_CONTROL

C       >>> Surface fluxes.
#define ALLOW_HFLUX_CONTROL
#define ALLOW_SFLUX_CONTROL
#define ALLOW_USTRESS_CONTROL
#define ALLOW_VSTRESS_CONTROL
#undef  ALLOW_SWFLUX_CONTROL
#undef  ALLOW_LWFLUX_CONTROL

C       >>> Atmospheric state.
#undef  ALLOW_ATEMP_CONTROL
#undef  ALLOW_AQH_CONTROL
#undef  ALLOW_UWIND_CONTROL
#undef  ALLOW_VWIND_CONTROL
#undef  ALLOW_PRECIP_CONTROL

C ********************************************************************
C ***             External forcing Package                         ***
C ********************************************************************
C 
C o Include/exclude the external forcing package. To use this package,
C   you have to include the calendar tool as well. KPP can be switched
C   on or off. The implementation automatically takes care of this.
#define INCLUDE_EXTERNAL_FORCING_PACKAGE

C   Do more printout for the protocol file than usual.
#undef EXF_VERBOSE

C   Bulk formulae related flags.
#undef  ALLOW_BULKFORMULAE
#undef  ALLOW_ATM_TEMP
#undef  ALLOW_ATM_WIND
#define ALLOW_RUNOFF

C   Relaxation to monthly climatologies.
#undef  ALLOW_CLIMTEMP_RELAXATION
#undef  ALLOW_CLIMSALT_RELAXATION
#undef  ALLOW_CLIMSST_RELAXATION
#undef  ALLOW_CLIMSSS_RELAXATION

C   Relaxation to constant surface fields.
#undef  ALLOW_CONST_SST_RELAXATION
#undef  ALLOW_CONST_SSS_RELAXATION
