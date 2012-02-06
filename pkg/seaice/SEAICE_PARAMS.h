C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/seaice/SEAICE_PARAMS.h,v 1.81 2012/02/06 19:19:58 jmc Exp $
C $Name:  $

C     *==========================================================*
C     | SEAICE_PARAMS.h
C     | o Basic parameter header for sea ice model.
C     *==========================================================*

C--   COMMON /SEAICE_PARM_L/ Logical parameters of sea ice model.
C
C     SEAICEwriteState  :: If true, write sea ice state to file;
C                          default is false.
C     SEAICEuseDYNAMICS :: If false, do not use dynamics;
C                          default is to use dynamics.
C     SEAICEuseTEM      :: to use truncated ellipse method (see Geiger et al.
C                          1998) set this parameter to true, default is false
C     SEAICEuseEVP      :: If false, use Zhangs LSR solver for VP equations
C                          if true use elastic viscous plastic solver
C     SEAICEuseFREEDRIFT :: If True use free drift velocity instead of EVP or LSR
C     SEAICEuseEVPpickup :: Set to false in order to start EVP solver with
C                          non-EVP pickup files.  Default is true.
C                          Applied only if SEAICEuseEVP=.TRUE.
C     SEAICEuseFluxForm :: use flux form for advection and diffusion
C                          of seaice
C     SEAICEuseMetricTerms :: use metric terms for dynamics solver
C                          (default = .true. )
C     SEAICEuseFlooding :: turn on scheme to convert submerged snow into ice
C     SEAICEadvHeff     :: turn on advection of effective thickness
C                          (default = .true.)
C     SEAICEadvArea     :: turn on advection of fraction area
C                          (default = .true.)
C     SEAICEadvSnow     :: turn on advection of snow (does not work with
C                          non-default Leap-frog scheme for advection)
C     SEAICEadvSalt     :: turn on advection of salt (does not work with
C                          non-default Leap-frog scheme for advection)
C     useHB87stressCoupling :: use an intergral over ice and ocean surface
C                          layer to define surface stresses on ocean
C                          following Hibler and Bryan (1987, JPO)
C     usePW79thermodynamics :: use "0-layer" thermodynamics as described in
C                           Parkinson and Washington (1979) and Hibler (1979)
C     useMaykutSatVapPoly :: use Maykut Polynomial for saturation vapor pressure
C                         instead of extended temp-range exponential law; def=F.
C     SEAICErestoreUnderIce :: restore surface T/S also underneath ice
C                          ( default is false )
C     SEAICE_no_slip    :: apply no slip boundary conditions to seaice velocity
C     SEAICE_clipVelocities :: clip velocities to +/- 40cm/s
C     SEAICE_maskRHS    :: mask the RHS of the solver where there is no ice
C     SEAICE_tave_mdsio :: write TimeAverage output using MDSIO
C     SEAICE_dump_mdsio :: write snap-shot output   using MDSIO
C     SEAICE_mon_stdio  :: write monitor to std-outp
C     SEAICE_tave_mnc   :: write TimeAverage output using MNC
C     SEAICE_dump_mnc   :: write snap-shot output   using MNC
C     SEAICE_mon_mnc    :: write monitor to netcdf file
      LOGICAL
     &     SEAICEwriteState, SEAICEuseDYNAMICS, SEAICEuseEVP,
     &     SEAICEuseFREEDRIFT, SEAICEuseTEM,
     &     SEAICEuseMetricTerms,
     &     SEAICEuseEVPpickup, SEAICEuseFlooding,
     &     SEAICEadvHeff, SEAICEadvArea,
     &     SEAICEadvSnow, SEAICEadvSalt,
     &     SEAICEuseFluxForm, useHB87stressCoupling,
     &     usePW79thermodynamics, useMaykutSatVapPoly,
     &     SEAICErestoreUnderIce,
     &     SEAICE_no_slip, SEAICE_clipVelocities, SEAICE_maskRHS,
     &     SEAICE_tave_mdsio, SEAICE_dump_mdsio, SEAICE_mon_stdio,
     &     SEAICE_tave_mnc,   SEAICE_dump_mnc,   SEAICE_mon_mnc
      COMMON /SEAICE_PARM_L/
     &     SEAICEwriteState, SEAICEuseDYNAMICS, SEAICEuseEVP,
     &     SEAICEuseFREEDRIFT, SEAICEuseTEM,
     &     SEAICEuseMetricTerms,
     &     SEAICEuseEVPpickup, SEAICEuseFlooding,
     &     SEAICEadvHeff, SEAICEadvArea,
     &     SEAICEadvSnow, SEAICEadvSalt,
     &     SEAICEuseFluxForm, useHB87stressCoupling,
     &     usePW79thermodynamics, useMaykutSatVapPoly,
     &     SEAICErestoreUnderIce,
     &     SEAICE_no_slip, SEAICE_clipVelocities, SEAICE_maskRHS,
     &     SEAICE_tave_mdsio, SEAICE_dump_mdsio, SEAICE_mon_stdio,
     &     SEAICE_tave_mnc,   SEAICE_dump_mnc,   SEAICE_mon_mnc

C--   COMMON /SEAICE_PARM_I/ Integer valued parameters of sea ice model.
C     IMAX_TICE         :: number of iterations for ice surface temp (default=10)
C     postSolvTempIter :: select flux calculation after surf. temp solver iteration
C                         0 = none, i.e., from last iter ; 2 = full non-lin form
C                         1 = use linearized approx (consistent with tsurf finding)
C     SOLV_MAX_ITERS    :: maximum number of allowed LSR-solver iterations
C     SOLV_NCHECK       :: iteration interval for solver convergence test
C     NPSEUDOTIMESTEPS  :: number of extra pseudo time steps (>= 2)
C     LSR_mixIniGuess   :: control mixing of free-drift sol. into LSR initial guess
C                       :: =0 : no mix ; =2,4 : mix with (1/err)^2,4 factor
C     SEAICEadvScheme   :: sets the advection scheme for thickness and area
C     SEAICEadvSchArea  :: sets the advection scheme for area
C     SEAICEadvSchHeff  :: sets the advection scheme for effective thickness
C                         (=volume), snow thickness, and salt if available
C     SEAICEadvSchSnow  :: sets the advection scheme for snow on sea-ice
C     SEAICEadvSchSalt  :: sets the advection scheme for sea ice salinity
C     SEAICEadvSchSnow  :: sets the advection scheme for snow on sea-ice
C     SEAICEareaFormula :: sets the formula used to increment area as
C                          a function of heff increment
C     SEAICE_debugPointI :: I,J index for seaice-specific debuggin
C     SEAICE_debugPointJ
C
      INTEGER IMAX_TICE, postSolvTempIter
      INTEGER SOLV_MAX_ITERS, SOLV_NCHECK
      INTEGER NPSEUDOTIMESTEPS
      INTEGER LSR_mixIniGuess
      INTEGER SEAICEadvScheme
      INTEGER SEAICEadvSchArea
      INTEGER SEAICEadvSchHeff
      INTEGER SEAICEadvSchSnow
      INTEGER SEAICEadvSchSalt
      INTEGER SEAICEadjMODE
      INTEGER SEAICEareaFormula
      INTEGER SEAICE_debugPointI
      INTEGER SEAICE_debugPointJ
      COMMON /SEAICE_PARM_I/
     &     IMAX_TICE, postSolvTempIter,
     &     SOLV_MAX_ITERS, SOLV_NCHECK,
     &     NPSEUDOTIMESTEPS,
     &     LSR_mixIniGuess,
     &     SEAICEadvScheme,
     &     SEAICEadvSchArea,
     &     SEAICEadvSchHeff,
     &     SEAICEadvSchSnow,
     &     SEAICEadvSchSalt,
     &     SEAICEadjMODE,
     &     SEAICEareaFormula,
     &     SEAICE_debugPointI,
     &     SEAICE_debugPointJ

C--   COMMON /SEAICE_PARM_C/ Character valued sea ice model parameters.
C     AreaFile          :: File containing initial sea-ice concentration
C     HsnowFile         :: File containing initial snow thickness
C     HsaltFile         :: File containing initial sea ice salt content
C     HeffFile          :: File containing initial sea-ice thickness
C     uIceFile          :: File containing initial sea-ice U comp. velocity
C     vIceFile          :: File containing initial sea-ice V comp. velocity
C        !!! NOTE !!! Initial sea-ice thickness can also be set using
C        SEAICE_initialHEFF below.  But a constant initial condition
C        can mean large artificial fluxes of heat and freshwater in
C        the surface layer during the first model time step.
C
      CHARACTER*(MAX_LEN_FNAM) AreaFile
      CHARACTER*(MAX_LEN_FNAM) HsnowFile
      CHARACTER*(MAX_LEN_FNAM) HsaltFile
      CHARACTER*(MAX_LEN_FNAM) HeffFile
      CHARACTER*(MAX_LEN_FNAM) uIceFile
      CHARACTER*(MAX_LEN_FNAM) vIceFile
      COMMON /SEAICE_PARM_C/
     &   AreaFile, HsnowFile, HsaltFile, HeffFile,
     &   uIceFile, vIceFile

C--   COMMON /SEAICE_PARM_RL/ Real valued parameters of sea ice model.
C     SEAICE_deltaTtherm :: Seaice timestep for thermodynamic equations (s)
C     SEAICE_deltaTdyn   :: Seaice timestep for dynamic solver          (s)
C     SEAICE_deltaTevp   :: Seaice timestep for EVP solver              (s)
C     SEAICE_elasticParm :: parameter that sets relaxation timescale
C                           tau = SEAICE_elasticParm * SEAICE_deltaTdyn
C     SEAICE_evpTauRelax :: relaxation timescale tau                    (s)
C     SEAICE_evpDampC    :: evp damping constant (Hunke,JCP,2001)       (kg/m^2)
C     SEAICE_zetaMaxFac  :: factor determining the maximum viscosity    (s)
C                          (default = 5.e+12/2.e4 = 2.5e8)
C     SEAICE_zetaMin     :: lower bound for viscosity (default = 0)     (N s/m^2)
C     SEAICE_monFreq     :: SEAICE monitor frequency.                   (s)
C     SEAICE_dumpFreq    :: SEAICE dump frequency.                      (s)
C     SEAICE_taveFreq    :: SEAICE time-averaging frequency.            (s)
C     SEAICE_initialHEFF :: initial sea-ice thickness                   (m)
C     SEAICE_rhoAir      :: density of air                              (kg/m^3)
C     SEAICE_rhoIce      :: density of sea ice                          (kg/m^3)
C     SEAICE_rhoSnow     :: density of snow                             (kg/m^3)
C     ICE2WATR           :: ratio of sea ice density to water density
C     OCEAN_drag         :: air-ocean drag coefficient
C     SEAICE_cpAir       :: specific heat of air                        (J/kg/K)
C
C     SEAICE_drag        :: air-ice drag coefficient
C     SEAICE_waterDrag   :: water-ice drag coefficient * water density
C     SEAICE_dryIceAlb   :: winter albedo
C     SEAICE_wetIceAlb   :: summer albedo
C     SEAICE_drySnowAlb  :: dry snow albedo
C     SEAICE_wetSnowAlb  :: wet snow albedo
C     HO                 :: demarcation thickness between thin and
C                           thick ice: HO is a key ice-growth parameter
C
C     SEAICE_drag_south       :: Southern Ocean SEAICE_drag
C     SEAICE_waterDrag_south  :: Southern Ocean SEAICE_waterDrag
C     SEAICE_dryIceAlb_south  :: Southern Ocean SEAICE_dryIceAlb
C     SEAICE_wetIceAlb_south  :: Southern Ocean SEAICE_wetIceAlb
C     SEAICE_drySnowAlb_south :: Southern Ocean SEAICE_drySnowAlb
C     SEAICE_wetSnowAlb_south :: Southern Ocean SEAICE_wetSnowAlb
C     HO_south                :: Southern Ocean HO
C
C     SEAICE_wetAlbTemp  :: Temp (deg.C) above which wet-albedo values are used
C     SEAICE_waterAlbedo :: water albedo
C     SEAICE_strength    :: sea-ice strength Pstar
C     SEAICE_eccen       :: sea-ice eccentricity of the elliptical yield curve
C     SEAICE_lhFusion    :: latent heat of fusion for ice and snow (J/kg)
C     SEAICE_lhEvap      :: latent heat of evaporation for water (J/kg)
C     SEAICE_dalton      :: Dalton number (= sensible heat transfer coefficient)
C     SEAICE_iceConduct  :: sea-ice conductivity
C     SEAICE_snowConduct :: snow conductivity
C     SEAICE_emissivity  :: longwave ocean-surface emissivity (-)
C     SEAICE_ice_emiss   :: longwave ice-surface emissivity (-)
C     SEAICE_snow_emiss  :: longwave snow-surface emissivity (-)
C     SEAICE_boltzmann   :: Stefan-Boltzman constant (not a run time parameter)
C     SEAICE_snowThick   :: cutoff snow thickness (for snow-albedo)
C     SEAICE_shortwave   :: ice penetration shortwave radiation factor
C     SEAICE_freeze      :: FREEZING TEMP. OF SEA WATER
C     SIsalFRAC          :: salinity of newly formed sea ice defined as a fraction
C                           of the ocean surface salinity at the time of freezing
C     SIsal0             :: prescribed salinity of seaice (in g/kg).
C     SEAICE_gamma_t     :: timescale for melting ice from a warm mixed layer (s),
C                           3d = 259200s is a reasonable value, default=unset
C     SEAICE_gamma_t_frz :: timescale for freezing ice from a cold mixed layer (s),
C                           3h = 10800s is a reasonable value, default=SEAICE_gamma_t
C     SEAICE_availHeatFrac :: Fraction of surface level heat content used to
C                          melt ice; default=1 if SEAICE_gamma_t is unset, otherwise
C                          SEAICE_availHeatFrac=SEAICE_deltaTtherm/SEAICE_gamma_t
C     SEAICE_availHeatFracFrz :: Fraction of surface level heat content used to
C                          freeze ice; default=SEAICE_availHeatFrac
C                          if SEAICE_gamma_t_frz is unset, otherwise
C                          SEAICE_availHeatFrac=SEAICE_deltaTtherm/SEAICE_gamma_t_frz
C     SEAICEstressFactor :: factor by which ice affects wind stress (default=1)
C     LSR_ERROR          :: sets accuracy of LSR solver
C     DIFF1              :: parameter used in advect.F
C     SEAICE_area_max    :: usually set to 1. Seeting areaMax below 1. specifies
C                           the minimun amount of leads (1-areaMax) in the ice pack.
C     SEAICE_area_floor  :: usually set to 1x10^-5. Specifies a minimun
C                           ice fraction in the ice pack.
C     SEAICE_area_reg    :: usually set to 1x10^-5. Specifies a minimun
C                           ice fraction for the purposes of regularization
C     SEAICE_hice_reg    :: usually set to 5 cm. Specifies a minimun
C                           ice thickness for the purposes of regularization
C     SEAICEdiffKhArea   :: sets the diffusivity for area (m^2/s)
C     SEAICEdiffKhHeff   :: sets the diffusivity for effective thickness (m^2/s)
C     SEAICEdiffKhSnow   :: sets the diffusivity for snow on sea-ice (m^2/s)
C     SEAICEdiffKhSalt   :: sets the diffusivity for sea ice salinity (m^2/s)
C     SEAICE_airTurnAngle   :: turning angles of air-ice interfacial stress
C     SEAICE_waterTurnAngle :: and ice-water interfacial stress (in degrees)
C
      _RL SEAICE_deltaTtherm, SEAICE_deltaTdyn, SEAICE_deltaTevp
      _RL SEAICE_monFreq, SEAICE_dumpFreq, SEAICE_taveFreq
      _RL SEAICE_initialHEFF
      _RL SEAICE_rhoAir, SEAICE_rhoIce, SEAICE_rhoSnow, ICE2WATR
      _RL SEAICE_cpAir
      _RL SEAICE_drag, SEAICE_waterDrag, SEAICE_dryIceAlb
      _RL SEAICE_wetIceAlb, SEAICE_drySnowAlb, SEAICE_wetSnowAlb, HO
      _RL SEAICE_drag_south, SEAICE_waterDrag_south
      _RL SEAICE_dryIceAlb_south, SEAICE_wetIceAlb_south
      _RL SEAICE_drySnowAlb_south, SEAICE_wetSnowAlb_south, HO_south
      _RL SEAICE_wetAlbTemp, SEAICE_waterAlbedo
      _RL SEAICE_strength, SEAICE_eccen
      _RL SEAICE_lhFusion, SEAICE_lhEvap
      _RL SEAICE_dalton
      _RL SEAICE_iceConduct, SEAICE_snowConduct
      _RL SEAICE_emissivity, SEAICE_ice_emiss, SEAICE_snow_emiss
      _RL SEAICE_boltzmann
      _RL SEAICE_snowThick, SEAICE_shortwave, SEAICE_freeze
      _RL SIsalFRAC, SIsal0, SEAICEstressFactor
      _RL SEAICE_gamma_t, SEAICE_gamma_t_frz
      _RL SEAICE_availHeatFrac, SEAICE_availHeatFracFrz
      _RL OCEAN_drag, LSR_ERROR, DIFF1
      _RL SEAICE_area_reg, SEAICE_hice_reg
      _RL SEAICE_area_floor, SEAICE_area_max
      _RL SEAICE_airTurnAngle, SEAICE_waterTurnAngle
      _RL SEAICE_elasticParm, SEAICE_evpTauRelax
      _RL SEAICE_evpDampC, SEAICE_zetaMin, SEAICE_zetaMaxFac
      _RL SEAICEdiffKhArea, SEAICEdiffKhHeff, SEAICEdiffKhSnow
      _RL SEAICEdiffKhSalt

      COMMON /SEAICE_PARM_RL/
     &    SEAICE_deltaTtherm, SEAICE_deltaTdyn,
     &    SEAICE_deltaTevp, SEAICE_elasticParm, SEAICE_evpTauRelax,
     &    SEAICE_evpDampC, SEAICE_zetaMin, SEAICE_zetaMaxFac,
     &    SEAICE_monFreq, SEAICE_dumpFreq, SEAICE_taveFreq,
     &    SEAICE_initialHEFF,
     &    SEAICE_rhoAir, SEAICE_rhoIce, SEAICE_rhoSnow, ICE2WATR,
     &    SEAICE_drag, SEAICE_waterDrag, SEAICE_dryIceAlb,
     &    SEAICE_wetIceAlb, SEAICE_drySnowAlb, SEAICE_wetSnowAlb, HO,
     &    SEAICE_drag_south, SEAICE_waterDrag_south,
     &    SEAICE_dryIceAlb_south, SEAICE_wetIceAlb_south,
     &    SEAICE_drySnowAlb_south, SEAICE_wetSnowAlb_south, HO_south,
     &    SEAICE_wetAlbTemp, SEAICE_waterAlbedo,
     &    SEAICE_strength, SEAICE_eccen,
     &    SEAICE_lhFusion, SEAICE_lhEvap,
     &    SEAICE_dalton, SEAICE_cpAir,
     &    SEAICE_iceConduct, SEAICE_snowConduct,
     &    SEAICE_emissivity, SEAICE_ice_emiss, SEAICE_snow_emiss,
     &    SEAICE_boltzmann,
     &    SEAICE_snowThick, SEAICE_shortwave, SEAICE_freeze,
     &    SIsalFRAC, SIsal0, SEAICEstressFactor,
     &    SEAICE_gamma_t, SEAICE_gamma_t_frz,
     &    SEAICE_availHeatFrac, SEAICE_availHeatFracFrz,
     &    OCEAN_drag, LSR_ERROR, DIFF1,
     &    SEAICE_area_reg, SEAICE_hice_reg,
     &    SEAICE_area_floor, SEAICE_area_max,
     &    SEAICEdiffKhArea, SEAICEdiffKhHeff, SEAICEdiffKhSnow,
     &    SEAICEdiffKhSalt,
     &    SEAICE_airTurnAngle, SEAICE_waterTurnAngle

C--   COMMON /SEAICE_BOUND_RL/ Various bounding values
C     MAX_HEFF          :: maximum ice thickness     (m)
C     MIN_ATEMP         :: minimum air temperature   (deg C)
C     MIN_LWDOWN        :: minimum downward longwave (W/m^2)
C     MIN_TICE          :: minimum ice temperature   (deg C)
C     SEAICE_EPS        :: small number used to reduce derivative singularities
C     SEAICE_EPS_SQ     :: small number square
C
      _RL MAX_HEFF, MIN_ATEMP, MIN_LWDOWN, MIN_TICE
      _RL SEAICE_EPS, SEAICE_EPS_SQ
      COMMON /SEAICE_BOUND_RL/
     &     MAX_HEFF, MIN_ATEMP, MIN_LWDOWN, MIN_TICE,
     &     SEAICE_EPS, SEAICE_EPS_SQ

C--   Constants used by sea-ice model
      _RL         ZERO           , ONE           , TWO
      PARAMETER ( ZERO = 0.0 _d 0, ONE = 1.0 _d 0, TWO = 2.0 _d 0 )
      _RL         QUART            , HALF
      PARAMETER ( QUART = 0.25 _d 0, HALF = 0.5 _d 0 )
      _RL siEps
      PARAMETER ( siEps = 1. _d -5 )
      INTEGER MPSEUDOTIMESTEPS
      PARAMETER (MPSEUDOTIMESTEPS=2)

C--   identifiers for advected properties
      INTEGER GAD_HEFF,GAD_AREA,GAD_QICE1,GAD_QICE2,GAD_SNOW
      INTEGER GAD_SALT,GAD_SITR
      PARAMETER ( GAD_HEFF  = 1,
     &            GAD_AREA  = 2,
     &            GAD_SNOW  = 3,
     &            GAD_SALT  = 4,
     &            GAD_QICE1 = 5,
     &            GAD_QICE2 = 6,
     &            GAD_SITR  = 7)

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
