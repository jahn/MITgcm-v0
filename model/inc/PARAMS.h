C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/PARAMS.h,v 1.36 1998/12/15 00:20:34 adcroft Exp $
C
C     /==========================================================\
C     | PARAMS.h                                                 |
C     | o Header file defining model "parameters".               |
C     |==========================================================|
C     | The values from the model standard input file are        |
C     | stored into the variables held here. Notes describing    |
C     | the parameters can also be found here.                   |
C     \==========================================================/

C     Macros for special grid options
#include "PARAMS_MACROS.h"

C--   Contants
C     Useful physical values
      Real*8 PI
      PARAMETER ( PI    = 3.14159265358979323844D0   )
      Real*8 deg2rad
      PARAMETER ( deg2rad = 2.D0*PI/360.D0           )

C     Symbolic values
C     precXXXX - Used to indicate what precision to use for
C                dumping model state.
      INTEGER precFloat32
      PARAMETER ( precFloat32 = 32 )
      INTEGER precFloat64
      PARAMETER ( precFloat64 = 64 )
C     UNSET_xxx - Used to indicate variables that have not been given a value
      Real*8 UNSET_FLOAT8
      PARAMETER ( UNSET_FLOAT8 = 1.234567D5 )
      Real*4 UNSET_FLOAT4
      PARAMETER ( UNSET_FLOAT4 = 1.234567E5 )
      _RL    UNSET_RL    
      PARAMETER ( UNSET_RL     = 1.234567D5 )
      _RS    UNSET_RS     
      PARAMETER ( UNSET_RS     = 1.234567E5 )
      INTEGER UNSET_I
      PARAMETER ( UNSET_I      = 123456789  )

C     Checkpoint data
      INTEGER maxNoChkptLev
      PARAMETER ( maxNoChkptLev = 2 )

C--   COMMON /PARM_C/ Character valued parameters used by the model.
C     checkPtSuff - List of checkpoint file suffices
C     bathyFile   - File containing bathymetry. If not defined bathymetry
C                   is taken from inline function.
C     hydrogThetaFile - File containing initial hydrographic data for potential
C                       temperature.
C     hydrogSaltFile  - File containing initial hydrographic data for salinity.
C     zonalWindFile   - File containing zonal wind data
C     meridWindFile   - File containing meridional wind data
C     thetaClimFile   - File containing theta climataology used
C                       in relaxation term -lambda(theta-theta*)
C     saltClimFile    - File containing salt climataology used
C                       in relaxation term -lambda(salt-salt*)
C     buoyancyRelation - Flag used to indicate which relation to use to
C                        get buoyancy.
      COMMON /PARM_C/ checkPtSuff,
     &                bathyFile, hydrogThetaFile, hydrogSaltFile,
     &                zonalWindFile, meridWindFile, thetaClimFile,
     &                saltClimFile, buoyancyRelation
      CHARACTER*(5) checkPtSuff(maxNoChkptLev)
      CHARACTER*(MAX_LEN_FNAM) bathyFile
      CHARACTER*(MAX_LEN_FNAM) hydrogThetaFile
      CHARACTER*(MAX_LEN_FNAM) hydrogSaltFile
      CHARACTER*(MAX_LEN_FNAM) zonalWindFile
      CHARACTER*(MAX_LEN_FNAM) meridWindFile
      CHARACTER*(MAX_LEN_FNAM) thetaClimFile
      CHARACTER*(MAX_LEN_FNAM) saltClimFile
      CHARACTER*(MAX_LEN_FNAM) buoyancyRelation

C--   COMMON /PARM_I/ Integer valued parameters used by the model.
C     cg2dMaxIters        - Maximum number of iterations in the
C                           two-dimensional con. grad solver.
C     cg2dChkResFreq      - Frequency with which to check residual
C                           in con. grad solver.
C     cg3dMaxIters        - Maximum number of iterations in the
C                           three-dimensional con. grad solver.
C     cg3dChkResFreq      - Frequency with which to check residual
C                           in con. grad solver.
C     nIter0              - Start time-step number of for this run
C     nTimeSteps          - Number of timesteps to execute
C     numStepsPerPickup   - For offline setup. Frequency of pickup
C                           of flow fields.
C     writeStatePrec      - Precision used for writing model state.
C     writeBinaryPrec     - Precision used for writing binary files
C     readBinaryPrec      - Precision used for reading binary files
C     nCheckLev           - Holds current checkpoint level
C     nShap               - "Order" of shapiro filter to apply to
C                           model prognositic fields.
C                           nShap == 1 => del2
C                           nShap == 2 => del4
C                           nShap == 3 => del6
C                           etc...

      COMMON /PARM_I/
     &        cg2dMaxIters,
     &        cg2dChkResFreq,
     &        cg3dMaxIters,
     &        cg3dChkResFreq,
     &        nIter0, nTimeSteps,
     &        numStepsPerPickup,
     &        writeStatePrec, nCheckLev,
     &        writeBinaryPrec, readBinaryPrec,
     &        nShap
      INTEGER cg2dMaxIters
      INTEGER cg2dChkResFreq
      INTEGER cg3dMaxIters
      INTEGER cg3dChkResFreq
      INTEGER nIter0
      INTEGER nTimeSteps
      INTEGER numStepsPerPickup
      INTEGER writeStatePrec
      INTEGER writeBinaryPrec
      INTEGER readBinaryPrec
      INTEGER nCheckLev
      INTEGER nShap

C--   COMMON /PARM_L/ Logical valued parameters used by the model.
C     usingCartesianGrid - If TRUE grid generation will be in a cartesian
C                          coordinate frame.
C     usingSphericalPolarGrid - If TRUE grid generation will be in a 
C                               spherical polar frame.
C     no_slip_sides - Impose "no-slip" at lateral boundaries.
C     no_slip_bottom- Impose "no-slip" at bottom boundary.
C     momViscosity  - Flag which turns momentum friction terms on and off.
C     momAdvection  - Flag which turns advection of momentum on and off.
C     momForcing    - Flag which turns external forcing of momentum on
C                     and off.
C     momPressureForcing - Flag which turns pressure term in momentum equation
C                          on and off.
C     metricTerms   - Flag which turns metric terms on or off.
C     usingSphericalPolarMTerms - If TRUE use spherical polar metric terms.
C     useCoriolis   - Flag which turns the coriolis terms on and off.
C     tempDiffusion - Flag which turns diffusion of temperature on
C                     and off.
C     tempAdvection - Flag which turns advection of temperature on
C                     and off.
C     tempForcing   - Flag which turns external forcing of temperature on
C                     and off.
C     saltDiffusion - Flag which turns diffusion of salinit on
C                     and off.
C     saltAdvection - Flag which turns advection of salinit on
C                     and off.
C     saltForcing   - Flag which turns external forcing of salinit on
C                     and off.
C     implicitFreeSurface - Set to true to use implcit free surface
C     rigidLid            - Set to true to use rigid lid
C     momStepping   - Turns momentum equation time-stepping off
C     tempStepping  - Turns temperature equation time-stepping off
C     saltStepping  - Turns salinity equation time-stepping off
C     useConstantF  - Coriolis parameter set to f0
C     useBetaPlaneF - Coriolis parameter set to f0 + beta.y
C     useSphereF    - Coriolis parameter set to 2.omega.sin(phi)
C     implicitDiffusion - Turns implicit vertical diffusion on
C     doThetaClimRelax - Set true if relaxation to temperature
C                        climatology is required.
C     doSaltClimRelax  - Set true if relaxation to salinity
C                        climatology is required.
C     periodicExternalForcing - Set true if forcing is time-dependant
C     usingPCoords     - Set to indicate that we are working in pressure
C                        coords.
C     usingZCoords     - Set to indicate that we are working in height
C                        coords.
C     openBoundaries - Using open-boundaries
      COMMON /PARM_L/ usingCartesianGrid, usingSphericalPolarGrid,
     & no_slip_sides,no_slip_bottom,
     & momViscosity, momAdvection, momForcing, useCoriolis, 
     & momPressureForcing,tempDiffusion, tempAdvection, tempForcing,
     & saltDiffusion, saltAdvection, saltForcing,
     & implicitFreeSurface, rigidLid,
     & momStepping, tempStepping, saltStepping,
     & metricTerms, usingSphericalPolarMTerms,
     & useConstantF, useBetaPlaneF, useSphereF,
     & implicitDiffusion, doThetaClimRelax, doSaltClimRelax,
     & periodicExternalForcing, usingPCoords, usingZCoords,
     & openBoundaries
      LOGICAL usingCartesianGrid
      LOGICAL usingSphericalPolarGrid
      LOGICAL usingSphericalPolarMTerms
      LOGICAL no_slip_sides
      LOGICAL no_slip_bottom
      LOGICAL momViscosity
      LOGICAL momAdvection
      LOGICAL momForcing
      LOGICAL momPressureForcing
      LOGICAL useCoriolis
      LOGICAL tempDiffusion
      LOGICAL tempAdvection
      LOGICAL tempForcing
      LOGICAL saltDiffusion
      LOGICAL saltAdvection
      LOGICAL saltForcing
      LOGICAL implicitFreeSurface
      LOGICAL rigidLid
      LOGICAL momStepping
      LOGICAL tempStepping
      LOGICAL saltStepping
      LOGICAL metricTerms
      LOGICAL useConstantF
      LOGICAL useBetaPlaneF
      LOGICAL useSphereF
      LOGICAL implicitDiffusion
      LOGICAL doThetaClimRelax
      LOGICAL doSaltClimRelax
      LOGICAL periodicExternalForcing
      LOGICAL usingPCoords
      LOGICAL usingZCoords
      LOGICAL openBoundaries

C--   COMMON /PARM_R/ "Real" valued parameters used by the model.
C     cg2dTargetResidual
C               - Target residual for cg2d solver.
C     cg3dTargetResidual
C               - Target residual for cg3d solver.
C     cg2dpcOffDFac - Averaging weight for preconditioner off-diagonal.
C     Note. 20th May 1998
C           I made a weird discovery! In the model paper we argue
C           for the form of the preconditioner used here ( see
C           A Finite-volume, Incompressible Navier-Stokes Model
C           ...., Marshall et. al ). The algebra gives a simple
C           0.5 factor for the averaging of ac and aCw to get a
C           symmettric pre-conditioner. By using a factor of 0.51
C           i.e. scaling the off-diagonal terms in the
C           preconditioner down slightly I managed to get the
C           number of iterations for convergence in a test case to
C           drop form 192 -> 134! Need to investigate this further!
C           For now I have introduced a parameter cg2dpcOffDFac which
C           defaults to 0.51 but can be set at runtime.
C     delP      - Vertical grid spacing ( Pa ).
C     delZ      - Vertical grid spacing ( m  ).
C     delR      - Vertical grid spacing ( units of r ).
C     delX      - Separation between cell faces (m) or (deg), depending
C     delY        on input flags.
C     gravity   - Accel. due to gravity ( m/s^2 )
C     recip_gravity and its inverse
C     gBaro     - Accel. due to gravity used in barotropic equation ( m/s^2 )
C     ronil     - Reference density
C     rhoConst  - Vertically constant reference density 
C     startTime - Start time for model ( s )
C     phiMin    - Latitude of southern most cell face.
C     thetaMin  - Longitude of western most cell face (this
C                 is an "inert" parameter but it is included
C                 to make geographical references simple.)
C     rSphere   - Radius of sphere for a spherical polar grid ( m ).
C     recip_RSphere  - Reciprocal radius of sphere ( m ).
C     f0        - Reference coriolis parameter ( 1/s )
C                 ( Southern edge f for beta plane )
C     beta      - df/dy ( s^-1.m^-1 )
C     omega     - Angular velocity ( rad/s )
C     viscAh    - Eddy viscosity coeff. for mixing of
C                 momentum laterally ( m^2/s )
C     viscAz    - Eddy viscosity coeff. for mixing of
C                 momentum vertically ( m^2/s )
C     viscAp    - Eddy viscosity coeff. for mixing of
C                 momentum vertically ( Pa^2/s )
C     viscAr    - Eddy viscosity coeff. for mixing of
C                 momentum vertically ( units of r^2/s )
C     viscA4    - Biharmonic viscosity coeff. for mixing of
C                 momentum laterally ( m^4/s )
C     diffKhT   - Laplacian diffusion coeff. for mixing of
C                 heat laterally ( m^2/s )
C     diffKzT   - Laplacian diffusion coeff. for mixing of
C                 heat vertically ( m^2/s )
C     diffKpT   - Laplacian diffusion coeff. for mixing of
C                 heat vertically ( Pa^2/s )
C     diffKrT   - Laplacian diffusion coeff. for mixing of
C                 heat vertically ( units of r^2/s )
C     diffK4T   - Biharmonic diffusion coeff. for mixing of
C                 heat laterally ( m^4/s )
C     diffKhS  -  Laplacian diffusion coeff. for mixing of
C                 salt laterally ( m^2/s )
C     diffKzS   - Laplacian diffusion coeff. for mixing of
C                 salt vertically ( m^2/s )
C     diffKpS   - Laplacian diffusion coeff. for mixing of
C                 salt vertically ( Pa^2/s )
C     diffKrS   - Laplacian diffusion coeff. for mixing of
C                 salt vertically ( units of r^2/s )
C     diffK4S   - Biharmonic diffusion coeff. for mixing of
C                 salt laterally ( m^4/s )
C     deltaT    - Default timestep ( s )
C     deltaTClock  - Timestep used as model "clock". This determines the
C                    IO frequencies and is used in tagging output. It can
C                    be totally different to the dynamical time. Typically
C                    it will be the deep-water timestep for accelerated runs.
C                    Frequency of checkpointing and dumping of the model state
C                    are referenced to this clock. ( s )
C     deltaTMom    - Timestep for momemtum equations ( s )
C     deltaTtracer - Timestep for tracer equations ( s )
C     freesurfFac  - Parameter to turn implicit free surface term on or off
C                    freesurfac = 1. uses implicit free surface
C                    freesurfac = 0. uses rigid lid
C     hFacMin      - Minimum fraction size of a cell (affects hFacC etc...)
C     hFacMinDz    - Minimum dimesional size of a cell (affects hFacC etc..., m)
C     hFacMinDp    - Minimum dimesional size of a cell (affects hFacC etc..., Pa)
C     hFacMinDr    - Minimum dimesional size of a cell (affects hFacC etc..., units of r)
C     tauCD        - CD scheme coupling timescale ( 1/s )
C     rCD          - CD scheme normalised coupling parameter ( 0-1 )
C     GMmaxslope    - max. slope allowed in GM/Redi tensor
C     GMlength      - Length to use in Visbeck et al. formula for K (m)
C     GMalpha       - alpha to use in Visbeck et al. formula for K
C     GMdepth       - Depth over which to integrate Richardson # (Visbeck et al.)
C     GMkbackground - background value of GM/Redi diffusion coefficient ( m^2/s )
C     GMmaxval      - max. value of KapGM allowed in GM/Redi scheme ( m^2/s )
C     startTime     - Starting time for this integration ( s ).
C     endTime       - Ending time for this integration ( s ).
C     chkPtFreq     - Frequency of rolling check pointing ( s ).
C     pChkPtFreq    - Frequency of permanent check pointing ( s ).
C     dumpFreq      - Frequency with which model state is written to
C                     post-processing files ( s ).
C     afFacMom      - Advection of momentum term tracer parameter
C     vfFacMom      - Momentum viscosity tracer parameter
C     pfFacMom      - Momentum pressure forcing tracer parameter
C     cfFacMom      - Coriolis term tracer parameter
C     foFacMom      - Momentum forcing tracer parameter
C     mtFacMom      - Metric terms tracer parameter
C     cAdjFreq      - Frequency of convective adjustment
C
C     taveFreq      - Frequency with which time-averaged model state is written to
C                     post-processing files ( s ).
C     tauThetaClimRelax - Relaxation to climatology time scale ( s ).
C     lambdaThetaClimRelax - Inverse time scale for relaxation ( 1/s ).
C     tauSaltClimRelax - Relaxation to climatology time scale ( s ).
C     lambdaSaltClimRelax - Inverse time scale for relaxation ( 1/s ).
C     externForcingPeriod - Is the period of which forcing varies (eg. 1 month)
C     externForcingCycle - Is the repeat time of the forcing (eg. 1 year)
C                          (note: externForcingCycle must be an integer
C                           number times externForcingPeriod)
C     horiVertRatio      - Ratio on units in vertical to units in horizontal.
C     recip_horiVertRatio  ( 1 if horiz in m and vertical in m ).
C                          ( g*rho if horiz in m and vertical in Pa ).
C     latFFTFiltLo       - Low latitude for FFT filtering of latitude
C                          circles ( see filter*.F )
      COMMON /PARM_R/ cg2dTargetResidual, cg2dpcOffDFac, 
     & cg3dTargetResidual,
     & delP, delZ, delR, delX, delY, 
     & deltaT,deltaTmom, deltaTtracer, deltaTClock,abeps, startTime, 
     & phiMin, thetaMin, rSphere, recip_RSphere, f0, fCori, beta, 
     & viscAh,  viscAz,  viscA4,  viscAr,
     & diffKhT, diffKzT, diffK4T, diffKrT,
     & diffKhS, diffKzS, diffK4S, diffKrS,
     & delT, tauCD, rCD, freeSurfFac, hFacMin, hFacMinDz, 
     & GMmaxslope,GMlength,GMalpha,GMdepth,GMkbackground,GMmaxval,
     & gravity, recip_Gravity, gBaro, rhonil, recip_rhonil, 
     & recip_rhoConst, rhoConst, tRef, sRef,
     & endTime, chkPtFreq, pchkPtFreq, dumpFreq, taveFreq,
     & afFacMom, vfFacMom, pfFacMom, cfFacMom, foFacMom, mtFacMom,
     & cAdjFreq, omega, tauThetaClimRelax, lambdaThetaClimRelax,
     & tauSaltClimRelax, lambdaSaltClimRelax,
     & externForcingCycle, externForcingPeriod,
     & viscAp, diffKpT, diffKpS, hFacMinDr, hFacMinDp,
     & theta_S, specVol_S, horiVertRatio, recip_horiVertRatio,
     & latFFTFiltLo

      _RL cg2dTargetResidual
      _RL cg3dTargetResidual
      _RL cg2dpcOffDFac
      _RL delZ(Nr)
      _RL delP(Nr)
      _RL delR(Nr)
      _RL delX(Nx)
      _RL delY(Ny)
      _RL deltaT
      _RL deltaTClock
      _RL deltaTmom
      _RL deltaTtracer
      _RL abeps
      _RL phiMin
      _RL thetaMin
      _RL rSphere
      _RL recip_RSphere
      _RL f0
      _RL freeSurfFac
      _RL hFacMin
      _RL hFacMinDz
      _RL hFacMinDp
      _RL hFacMinDr
      _RL beta
      _RL viscAh
      _RL viscAz
      _RL viscAp
      _RL viscAr
      _RL viscA4 
      _RL diffKhT 
      _RL diffKrT
      _RL diffKzT
      _RL diffKpT
      _RL diffK4T 
      _RL diffKhS 
      _RL diffKrS
      _RL diffKzS
      _RL diffKpS
      _RL diffK4S 
      _RL delt
      _RL tauCD
      _RL rCD
      _RL GMmaxslope
      _RL GMlength
      _RL GMalpha
      _RL GMdepth
      _RL GMkbackground
      _RL GMmaxval
      _RL gravity
      _RL recip_gravity
      _RL gBaro
      _RL rhonil
      _RL recip_rhonil
      _RL rhoConst
      _RL recip_rhoConst
      _RL specVol_S(Nr)
      _RL tRef(Nr)
      _RL theta_S(Nr)
      _RL sRef(Nr)
      _RS Fcori(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL startTime
      _RL endTime
      _RL chkPtFreq
      _RL pChkPtFreq
      _RL dumpFreq
      _RL taveFreq
      _RL afFacMom
      _RL vfFacMom
      _RL pfFacMom
      _RL cfFacMom
      _RL foFacMom
      _RL mTFacMom
      _RL cAdjFreq
      _RL omega
      _RL tauThetaClimRelax
      _RL lambdaThetaClimRelax
      _RL tauSaltClimRelax
      _RL lambdaSaltClimRelax
      _RL externForcingCycle
      _RL externForcingPeriod
      _RL horiVertRatio
      _RL recip_horiVertRatio
      _RL latFFTFiltLo

      COMMON /PARM_A/ HeatCapacity_Cp,recip_Cp,
     &                Lamba_theta
      _RL HeatCapacity_Cp
      _RL Lamba_theta
      _RL recip_Cp

C Equation of State (polynomial coeffients)
      COMMON /PARM_EOS_NL/ eosC,eosSig0,eosRefT,eosRefS
      _RL eosC(9,Nr+1),eosSig0(Nr+1),eosRefT(Nr+1),eosRefS(Nr+1)
C Linear equation of state
C     tAlpha    - Linear EOS thermal expansion coefficient ( 1/degree ).
C     sBeta     - Linear EOS haline contraction coefficient.
      COMMON /PARM_EOS_LIN/ tAlpha,sBeta,eosType
      _RL tAlpha
      _RL sBeta
      character*(6) eosType

C These are input arrays (of integers) that contain the *absolute*
C computational index of an open-boundary (OB) point.
C A zero (0) element means there is no corresponding OB in that column/row.
C The computational coordinate refers to "tracer" cells.
C For a northern/southern OB, the OB V point is to the south/north.
C For an eastern/western OB, the OB U point is to the west/east.
C eg.
C     OB_Jnorth(3)=34  means that: 
C          T( 3 ,34) is a an OB point
C          U(3:4,34) is a an OB point
C          V( 4 ,34) is a an OB point
C while
C     OB_Jsouth(3)=1  means that:
C          T( 3 ,1) is a an OB point
C          U(3:4,1) is a an OB point
C          V( 4 ,2) is a an OB point
C 
C For convenience, negative values for Jnorth/Ieast refer to
C points relative to the Northern/Eastern edges of the model
C eg. OB_Jnorth(3)=-1  means that the point (3,Ny-1) is a northern O-B.
C
      COMMON /PARM_OB/
     & OB_Jnorth,OB_Jsouth,OB_Ieast,OB_Iwest
      INTEGER OB_Jnorth(Nx)
      INTEGER OB_Jsouth(Nx)
      INTEGER OB_Ieast(Ny)
      INTEGER OB_Iwest(Ny)
