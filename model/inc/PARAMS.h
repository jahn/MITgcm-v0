C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/PARAMS.h,v 1.7 1998/05/21 18:28:50 cnh Exp $
C
C     /==========================================================\
C     | PARAMS.h                                                 |
C     | o Header file defining model "parameters".               |
C     |==========================================================|
C     | The values from the model's standard input file are      |
C     | stored into the variables held here. Notes describing    |
C     | the parameters can also be found here.                   |
C     \==========================================================/

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
      PARAMETER ( precFloat32 = 0 )
      INTEGER precFloat64
      PARAMETER ( precFloat64 = 1 )

C     Checkpoint data
      INTEGER maxNoChkptLev
      PARAMETER ( maxNoChkptLev = 2 )

C--   COMMON /PARM_C/ Character valued parameters used by the model.
C     checkPtSuff - List of checkpoint file suffices
      COMMON /PARM_C/ checkPtSuff
      CHARACTER*(5) checkPtSuff(maxNoChkptLev)

C--   COMMON /PARM_I/ Integer valued parameters used by the model.
C     cg2dMaxIters        - Maximum number of iterations in the
C                           two-dimensional con. grad solver.
C     cg2dChkResFreq      - Frequency with which to check residual
C                           in con. grad solver.
C     nIter0              - Start time-step number of for this run
C     nTimeSteps          - Number of timesteps to execute
C     numStepsPerPickup   - For offline setup. Frequency of pickup
C                           of flow fields.
C     writeStatePrec      - Precision used for writing model state.
C     writeBinaryPrec     - Precision used for writing binary files
C     readBinaryPrec      - Precision used for reading binary files
C     nCheckLev           - Holds current checkpoint level
      COMMON /PARM_I/
     &        cg2dMaxIters,
     &        cg2dChkResFreq,
     &        nIter0, nTimeSteps,
     &        numStepsPerPickup,
     &        writeStatePrec, nCheckLev,
     &        writeBinaryPrec, readBinaryPrec
      INTEGER cg2dMaxIters
      INTEGER cg2dChkResFreq
      INTEGER nIter0
      INTEGER nTimeSteps
      INTEGER numStepsPerPickup
      INTEGER writeStatePrec
      INTEGER writeBinaryPrec
      INTEGER readBinaryPrec
      INTEGER nCheckLev

C--   COMMON /PARM_L/ Logical valued parameters used by the model.
C     usingCartesianGrid - If TRUE grid generation will be in a cartesian
C                          coordinate frame.
C     usingSphericalPolarGrid - If TRUE grid generation will be in a 
C                               spherical polar frame.
C     momViscosity  - Flag which turns momentum friction terms on and off.
C     momAdvection  - Flag which turns advection of momentum on and off.
C     momForcing    - Flag which turns external forcing of momentum on
C                     and off.
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
      COMMON /PARM_L/ usingCartesianGrid, usingSphericalPolarGrid,
     & momViscosity, momAdvection, momForcing, useCoriolis,
     & tempDiffusion, tempAdvection, tempForcing,
     & saltDiffusion, saltAdvection, saltForcing
      LOGICAL usingCartesianGrid
      LOGICAL usingSphericalPolarGrid
      LOGICAL momViscosity
      LOGICAL momAdvection
      LOGICAL momForcing
      LOGICAL useCoriolis
      LOGICAL tempDiffusion
      LOGICAL tempAdvection
      LOGICAL tempForcing
      LOGICAL saltDiffusion
      LOGICAL saltAdvection
      LOGICAL saltForcing

C--   COMMON /PARM_R/ "Real" valued parameters used by the model.
C     cg2dTargetResidual
C               - Target residual for cg2d solver.
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
C     delZ      - Vertical grid spacing ( m ) - delZ is the distance
C                 between "w" surfaces.
C     delX      - Separation between cell faces (m) or (deg), depending
C     delY        on input flags.
C     gravity   - Accel. due to gravity ( m/s^2 )
C     ronil     - Reference density
C     startTime - Start time for model ( s )
C     phiMin    - Latitude of southern most cell face.
C     thetaMin  - Longitude of western most cell face (this
C                 is an "inert" parameter but it is included
C                 to make geographical references simple.)
C     rSphere   - Radius of sphere for a spherical polar grid ( m ).
C     f0        - Reference coriolis parameter ( 1/s )
C                 ( Southern edge f for beta plane )
C     beta      - df/dy ( s^-1.m^-1 )
C     viscAh    - Eddy viscosity coeff. for mixing of
C                 momentum laterally ( m^2/s )
C     viscAz    - Eddy viscosity coeff. for mixing of
C                 momentum vertically ( m^2/s )
C     viscA4    - Biharmonic viscosity coeff. for mixing of
C                 momentum laterally ( m^4/s )
C     diffKhT   - Laplacian diffusion coeff. for mixing of
C                 heat laterally ( m^2/s )
C     diffKzT   - Laplacian diffusion coeff. for mixing of
C                 heat vertically ( m^2/s )
C     diffK4T   - Biharmonic diffusion coeff. for mixing of
C                 heat laterally ( m^4/s )
C     diffKhS  -  Laplacian diffusion coeff. for mixing of
C                 salt laterally ( m^2/s )
C     diffKzS   - Laplacian diffusion coeff. for mixing of
C                 salt vertically ( m^2/s )
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
C     tauCD     - CD scheme coupling timescale ( 1/s )
C     rCD       - CD scheme normalised coupling parameter ( 0-1 )
C     GMmaxslope  - max. slope allowed in GM/Redi tensor
C     GMlength  - Length to use in Visbeck et al. formula for K
C     GMalpha   - alpha to use in Visbeck et al. formula for K
C     GMdepth   - Depth over which to integrate Richardson # (Visbeck et al.)
C     GMbackground - background value of GM/Redi coefficient
C     startTime - Starting time for this integration ( s ).
C     endTime   - Ending time for this integration ( s ).
C     chkPtFreq  - Frequency of rolling check pointing ( s ).
C     pChkPtFreq - Frequency of permanent check pointing ( s ).
C     dumpFreq  - Frequency with which model state is written to
C                 post-processing files ( s ).
      COMMON /PARM_R/ cg2dTargetResidual, cg2dpcOffDFac, delZ, delX, delY, 
     & deltaT,deltaTmom, deltaTtracer, deltaTClock,abeps, startTime, phiMin, 
     & thetaMin, rSphere, f0, fCori, beta, viscAh, viscAz, viscA4, 
     & diffKhT, diffKzT, diffK4T, diffKhS, diffKzS, diffK4S, delT, 
     & tauCD, rCD, 
     & GMmaxslope,GMlength,GMalpha,GMdepth,GMkbackground,
     & gravity, rhonil, tRef, sRef,
     & endTime, chkPtFreq, pchkPtFreq, dumpFreq
      _RL cg2dTargetResidual
      _RL cg2dpcOffDFac
      _RL delZ(Nz)
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
      _RL f0
      _RL beta
      _RL viscAh
      _RL viscAz
      _RL viscA4 
      _RL diffKhT 
      _RL diffKzT
      _RL diffK4T 
      _RL diffKhS 
      _RL diffKzS
      _RL diffK4S 
      _RL delt
      _RL tauCD
      _RL rCD
      _RL GMmaxslope
      _RL GMlength
      _RL GMalpha
      _RL GMdepth
      _RL GMkbackground
      _RL gravity
      _RL rhonil
      _RL tRef(Nz)
      _RL sRef(Nz)
      _RL Fcori(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL startTime
      _RL endTime
      _RL chkPtFreq
      _RL pChkPtFreq
      _RL dumpFreq

      COMMON /PARM_A/ HeatCapacity_Cp,
     &                Lamba_theta
      _RL HeatCapacity_Cp
      _RL Lamba_theta

C Equation of State (polynomial coeffients)
      COMMON /PARM_EOS_NL/ eosC,eosSig0,eosRefT,eosRefS
      _RL eosC(Nz+1,9),eosSig0(Nz+1),eosRefT(Nz+1),eosRefS(Nz+1)
C Linear equation of state
C     tAlpha    - Linear EOS thermal expansion coefficient ( 1/degree ).
C     sBeta     - Linear EOS haline contraction coefficient.
      COMMON /PARM_EOS_LIN/ tAlpha,sBeta
      _RL tAlpha
      _RL sBeta

