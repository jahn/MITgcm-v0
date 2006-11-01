C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/seaice/SEAICE_PARAMS.h,v 1.33 2006/11/01 09:49:37 mlosch Exp $
C $Name:  $

C     /==========================================================\
C     | SEAICE_PARAMS.h                                          |
C     | o Basic parameter header for sea ice model.              |
C     \==========================================================/

C--   COMMON /SEAICE_PARM_L/ Logical parameters of sea ice model.
C
C     SEAICEwriteState  - If true, write sea ice state to file;
C                         default is false.
C     SEAICEuseDYNAMICS - If false, do not use dynamics;
C                         default is to use dynamics.
C     SEAICEuseEVP      - If false, use Zhangs LSR solver for VP equations
C                         if true use elastic viscous plastic solver  
C     SEAICEuseEVPpickup - Set to false in order to start EVP solver with
C                          non-EVP pickup files.  Default is true.
C                          Applied only if SEAICEuseEVP=.TRUE.
C     SEAICEuseFluxForm :: use flux form for advection and diffusion
C                          of seaice
C     SEAICEuseFlooding :: turn on scheme to convert submerged snow into ice
C     SEAICEadvSnow     :: turn on advection of snow (does not work with
C                          non-default Leap-frog scheme for advection)
C     useHB87stressCoupling :: use an intergral over ice and ocean surface
C                          layer to define surface stresses on ocean
C                          following Hibler and Bryan (1987, JPO)
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
     &     SEAICEuseEVPpickup, SEAICEuseFlooding, SEAICEadvSnow, 
     &     SEAICEuseFluxForm, useHB87stressCoupling, 
     &     SEAICE_clipVelocities, SEAICE_maskRHS,
     &     SEAICE_tave_mdsio, SEAICE_dump_mdsio, SEAICE_mon_stdio,
     &     SEAICE_tave_mnc,   SEAICE_dump_mnc,   SEAICE_mon_mnc
      COMMON /SEAICE_PARM_L/
     &     SEAICEwriteState, SEAICEuseDYNAMICS, SEAICEuseEVP, 
     &     SEAICEuseEVPpickup, SEAICEuseFlooding, SEAICEadvSnow,
     &     SEAICEuseFluxForm, useHB87stressCoupling, 
     &     SEAICE_clipVelocities, SEAICE_maskRHS,
     &     SEAICE_tave_mdsio, SEAICE_dump_mdsio, SEAICE_mon_stdio,
     &     SEAICE_tave_mnc,   SEAICE_dump_mnc,   SEAICE_mon_mnc

C--   COMMON /SEAICE_PARM_I/ Integer valued parameters of sea ice model.
C     LAD        - time stepping used for sea-ice advection:
C                  1 = LEAPFROG,  2 = BACKWARD EULER.
C     IMAX_TICE  - number of iterations for ice heat budget   10
C     SEAICEadvScheme  - sets the advection scheme for thickness and area
C     SEAICEadvSchArea - sets the advection scheme for area
C     SEAICEadvSchHeff - sets the advection scheme for effective thickness 
C                        (=volume) and snow thickness if available
C     SEAICEadvSchEnth - sets the advection scheme for sea-ice enthalphy
C     SEAICEadvSchSnow - sets the advection scheme for snow on sea-ice
C
      INTEGER LAD, IMAX_TICE
      INTEGER SEAICEadvScheme
      INTEGER SEAICEadvSchArea
      INTEGER SEAICEadvSchHeff
      INTEGER SEAICEadvSchEnth
      INTEGER SEAICEadvSchSnow
      COMMON /SEAICE_PARM_I/ 
     &     LAD, IMAX_TICE,
     &     SEAICEadvScheme,
     &     SEAICEadvSchArea,
     &     SEAICEadvSchHeff,
     &     SEAICEadvSchEnth,
     &     SEAICEadvSchSnow

C--   COMMON /SEAICE_PARM_C/ Character valued sea ice model parameters.
C     uwindFile       - File containing uwind
C     vwindFile       - File containing vwind
C     atempFile       - File containing atemp
C     aqhFile         - File containing aqh
C     lwdownFile      - File containing lwdown
C     swdownFile      - File containing swdown
C     precipFile      - File containing precip
C     evapFile        - File containing evap
C     runoffFile      - File containing runoffF
C     HeffFile        - File containing initial sea-ice thickness
C        !!! NOTE !!! Initial sea-ice thickness can also be set using
C        SEAICE_initialHEFF below.  But a constant initial condition
C        can mean large artificial fluxes of heat and freshwater in
C        the surface layer during the first model time step.
C
      CHARACTER*(MAX_LEN_FNAM) uwindFile
      CHARACTER*(MAX_LEN_FNAM) vwindFile
      CHARACTER*(MAX_LEN_FNAM) atempFile
      CHARACTER*(MAX_LEN_FNAM) aqhFile
      CHARACTER*(MAX_LEN_FNAM) lwdownFile
      CHARACTER*(MAX_LEN_FNAM) swdownFile
      CHARACTER*(MAX_LEN_FNAM) precipFile
      CHARACTER*(MAX_LEN_FNAM) evapFile
      CHARACTER*(MAX_LEN_FNAM) runoffFile
      CHARACTER*(MAX_LEN_FNAM) HeffFile
      COMMON /SEAICE_PARM_C/ uwindFile, vwindFile, atempFile, aqhFile,
     &     lwdownFile, swdownFile, precipFile, evapFile, runoffFile,
     &	   HeffFile

C--   COMMON /SEAICE_PARM_RL/ Real valued parameters of sea ice model.
C     SEAICE_deltaTtherm - Seaice timestep for thermodynamic equations (s)
C     SEAICE_deltaTdyn   - Seaice timestep for dynamic solver          (s)
C     SEAICE_deltaTevp   - Seaice timestep for EVP solver              (s)
C     SEAICE_elasticParm - parameter that sets relaxation timescale
C                          T = SEAICE_elasticParm * SEAICE_deltaTdyn
C     SEAICE_monFreq     - SEAICE monitor frequency.                   (s)
C     SEAICE_dumpFreq    - SEAICE dump frequency.                      (s)
C     SEAICE_taveFreq    - SEAICE time-averaging frequency.            (s)
C     SEAICE_initialHEFF - initial sea-ice thickness                   (m)
C     SEAICE_rhoAir      - density of air                              (kg/m^3)
C     SEAICE_rhoIce      - density of sea ice                          (kg/m^3)
C     SEAICE_drag        - air-ice drag coefficient
C     OCEAN_drag         - air-ocean drag coefficient
C     SEAICE_waterDrag   - water-ice drag coefficient * water density
C     SEAICE_dryIceAlb   - winter albedo
C     SEAICE_wetIceAlb   - summer albedo
C     SEAICE_drySnowAlb  - dry snow albedo
C     SEAICE_wetSnowAlb  - wet snow albedo
C     SEAICE_waterAlbedo - water albedo
C     SEAICE_strength    - sea-ice strength Pstar
C     SEAICE_eccen       - sea-ice eccentricity of the elliptical yield curve
C     SEAICE_sensHeat    - buld sensible heat transfer coefficient 
C                          = (sensible heat transfer coefficient)
C                          x (heat capacity of air) 
C                          x (density of air)
C     SEAICE_latentWater - bulk latent heat transfer coefficient for water
C                          = (latent heat transfer coefficient for water)
C                          x (specific latent heat water to water vapor)
C                          x (density of air)
C     SEAICE_latentIce   - bulk latent heat transfer coefficient for ice
C                          = (latent heat transfer coefficient for ice)
C                          x (latent heat ice to water vapor) 
C                          x (density of air)
C     SEAICE_iceConduct  - sea-ice conductivity
C     SEAICE_snowConduct - snow conductivity
C     SEAICE_emissivity  - Stefan-Boltzman constant * emissivity
C     SEAICE_snowThick   - cutoff snow thickness
C     SEAICE_shortwave   - penetration shortwave radiation factor
C     SEAICE_freeze      - FREEZING TEMP. OF SEA WATER
C     SEAICEstressFactor - factor by which ice affects wind stress (default=1)
C     LSR_ERROR          - sets accuracy of LSR solver
C     DIFF1              - parameter used in advect.F
C     A22                - parameter used in growth.F
C     HO                 - demarcation thickness between thin and
C                          thick ice: HO is a key ice-growth parameter
C     WindForcingStart   - Time of first  wind forcing record  (s)
C     WindForcingEnd     - Time of last   wind forcing record  (s)
C     WindForcingPeriod  - Period between wind forcing records (s)
C     FluxForcingStart   - Time of first  flux forcing record  (s)
C     FluxForcingEnd     - Time of last   flux forcing record  (s)
C     FluxForcingPeriod  - Period between flux forcing records (s)
C     SSTForcingStart    - Time of first  SST  forcing record  (s)
C     SSTForcingEnd      - Time of last   SST  forcing record  (s)
C     SSTForcingPeriod   - Period between SST  forcing records (s)
C     SSSForcingStart    - Time of first  SSS  forcing record  (s)
C     SSSForcingEnd      - Time of last   SSS  forcing record  (s)
C     SSSForcingPeriod   - Period between SSS  forcing records (s)
C     StartingYear       - Starting year of integration
C     EndingYear         - Ending year of integration
C     SEAICE_airTurnAngle   - turning angles of air-ice interfacial stress 
C     SEAICE_waterTurnAngle - and ice-water interfacial stress (in degrees)
C
      _RL SEAICE_deltaTtherm, SEAICE_deltaTdyn, SEAICE_deltaTevp
      _RL SEAICE_monFreq, SEAICE_dumpFreq, SEAICE_taveFreq
      _RL SEAICE_initialHEFF
      _RL SEAICE_rhoAir, SEAICE_rhoIce
      _RL SEAICE_drag, SEAICE_waterDrag,  SEAICE_dryIceAlb
      _RL SEAICE_wetIceAlb, SEAICE_drySnowAlb, SEAICE_wetSnowAlb
      _RL SEAICE_waterAlbedo, SEAICE_strength, SEAICE_eccen
      _RL SEAICE_sensHeat, SEAICE_latentWater, SEAICE_latentIce
      _RL SEAICE_iceConduct, SEAICE_snowConduct, SEAICE_emissivity
      _RL SEAICE_snowThick, SEAICE_shortwave, SEAICE_freeze
      _RL SEAICEstressFactor
      _RL OCEAN_drag, LSR_ERROR, DIFF1, A22, HO
      _RL WindForcingStart, WindForcingEnd, WindForcingPeriod
      _RL FluxForcingStart, FluxForcingEnd, FluxForcingPeriod
      _RL SSTForcingStart,  SSTForcingEnd,  SSTForcingPeriod
      _RL SSSForcingStart,  SSSForcingEnd,  SSSForcingPeriod
      _RL StartingYear,     EndingYear
      _RL SEAICE_airTurnAngle, SEAICE_waterTurnAngle
      _RL SEAICE_elasticParm
      COMMON /SEAICE_PARM_RL/
     &    SEAICE_deltaTtherm, SEAICE_deltaTdyn,
     &    SEAICE_deltaTevp, SEAICE_elasticParm,
     &    SEAICE_monFreq, SEAICE_dumpFreq, SEAICE_taveFreq,
     &    SEAICE_initialHEFF,
     &    SEAICE_rhoAir, SEAICE_rhoIce,
     &    SEAICE_drag, SEAICE_waterDrag, SEAICE_dryIceAlb,
     &    SEAICE_wetIceAlb, SEAICE_drySnowAlb, SEAICE_wetSnowAlb,
     &    SEAICE_waterAlbedo, SEAICE_strength, SEAICE_eccen,
     &    SEAICE_sensHeat, SEAICE_latentWater, SEAICE_latentIce,
     &    SEAICE_iceConduct, SEAICE_snowConduct, SEAICE_emissivity,
     &    SEAICE_snowThick, SEAICE_shortwave, SEAICE_freeze,
     &    SEAICEstressFactor,
     &    OCEAN_drag, LSR_ERROR, DIFF1, A22, HO,
     &    WindForcingStart, WindForcingEnd, WindForcingPeriod,
     &    FluxForcingStart, FluxForcingEnd, FluxForcingPeriod,
     &    SSTForcingStart,  SSTForcingEnd,  SSTForcingPeriod,
     &    SSSForcingStart,  SSSForcingEnd,  SSSForcingPeriod,
     &    StartingYear,     EndingYear,
     &    SEAICE_airTurnAngle, SEAICE_waterTurnAngle

C--   COMMON /SEAICE_BOUND_RL/ Various bounding values
C     MAX_HEFF   - maximum ice thickness     (m)
C     MIN_ATEMP  - minimum air temperature   (deg C)
C     MIN_LWDOWN - minimum downward longwave (W/m^2)
C     MAX_TICE   - maximum ice temperature   (deg C)
C     MIN_TICE   - minimum ice temperature   (deg C)
C     SEAICE_EPS, SEAICE_EPS_SQ - used to reduce derivative singularities
C
      _RL MAX_HEFF, MIN_ATEMP, MIN_LWDOWN, MAX_TICE, MIN_TICE
      _RL SEAICE_EPS, SEAICE_EPS_SQ
      COMMON /SEAICE_BOUND_RL/
     &    MAX_HEFF, MIN_ATEMP, MIN_LWDOWN, MAX_TICE, MIN_TICE,
     &    SEAICE_EPS, SEAICE_EPS_SQ

C--   Constants used by sea-ice model
      _RL         ZERO           , ONE           , TWO
      parameter ( ZERO = 0.0 _d 0, ONE = 1.0 _d 0, TWO = 2.0 _d 0 )
      _RL         QUART            , HALF
      parameter ( QUART = 0.25 _d 0, HALF = 0.5 _d 0 ) 

C--   identifiers for advected properties
      INTEGER GAD_HEFF, GAD_AREA, GAD_QICE1, GAD_QICE2, GAD_SNOW
      PARAMETER ( GAD_HEFF  = 101, 
     &            GAD_AREA  = 102,
     &            GAD_QICE1 = 103,
     &            GAD_QICE2 = 104,
     &            GAD_SNOW  = 105 )


CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
