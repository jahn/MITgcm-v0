C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/shelfice/SHELFICE.h,v 1.1 2006/02/07 11:45:21 mlosch Exp $
C $Name:  $

#ifdef ALLOW_SHELFICE

CBOP
C !ROUTINE: SHELFICE.h

C !DESCRIPTION: \bv
C     /==========================================================\
C     | SHELFICE.h                                               |
C     | o Basic header thermodnynamic shelf ice package.         |
C     |   Contains all SHELFICE field declarations.              |
C     \==========================================================/

C-----------------------------------------------------------------------
C
C--   Constants that can be set in data.shelfice
C     SHELFICEDragLinear       - linear drag at bottom shelfice (1/s)
C     SHELFICEDragQuadratic    - quadratic drag at bottom shelfice (1/m)
C     SHELFICEexchangeVelocity - scale parameter that determines heat flux
C                                into shelfice (m/s)
C     SHELFICElatentHeat       - latent heat of fusion (J/kg)
C     useISOMIPTD              - use simple ISOMIP thermodynamics
C     no_slip_shelfice         - set slip conditions for shelfice separately,
C                                (by default the same as no_slip_bottom) 
C     SHELFICEwriteState       - enable output
C     SHELFICE_dump_mnc        - use netcdf for snapshot output
C     SHELFICE_tave_mnc        - use netcdf for time-averaged output
C     SHELFICE_dumpFreq        - analoguous to dumpFreq (= default)
C     SHELFICE_taveFreq        - analoguous to taveFreq (= default)
C
C--   Fields
C     ktopC    - index of the top "wet cell" (2D)
C-----------------------------------------------------------------------
C \ev
CEOP

      COMMON /SHELFICE_PARMS_I/  kTopC
      INTEGER kTopC (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON /SHELFICE_PARMS_R/ 
     &     SHELFICE_dumpFreq, SHELFICE_taveFreq,
     &     SHELFICEexchangeVelocity,
     &     SHELFICElatentHeat, recip_SHELFICElatentHeat,
     &     SHELFICEDragLinear, SHELFICEDragQuadratic
      _RL SHELFICE_dumpFreq, SHELFICE_taveFreq
      _RL SHELFICEexchangeVelocity
      _RL SHELFICElatentHeat
      _RL recip_SHELFICElatentHeat
      _RL SHELFICEDragLinear
      _RL SHELFICEDragQuadratic

      COMMON /SHELFICE_FIELDS_RL/ 
     &     shelficeForcingT,
     &     shelficeForcingS
      _RL shelficeForcingT      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL shelficeForcingS      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON /SHELFICE_FIELDS_RS/ 
     &     R_shelfIce,
     &     shelficeHeatFlux,
     &     shelfIceFreshWaterFlux
      _RS R_shelfIce            (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS shelficeHeatFlux      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS shelficeFreshWaterFlux(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      
      LOGICAL SHELFICEisOn
      LOGICAL useISOMIPTD
      LOGICAL no_slip_shelfice
      LOGICAL SHELFICEwriteState
      LOGICAL SHELFICE_dump_mdsio
      LOGICAL SHELFICE_tave_mdsio
      LOGICAL SHELFICE_dump_mnc
      LOGICAL SHELFICE_tave_mnc
      COMMON /SHELFICE_PARMS_L/
     &     SHELFICEisOn,
     &     useISOMIPTD,
     &     no_slip_shelfice,
     &     SHELFICEwriteState,
     &     SHELFICE_dump_mdsio,
     &     SHELFICE_tave_mdsio,
     &     SHELFICE_dump_mnc,
     &     SHELFICE_tave_mnc

#endif /* ALLOW_SHELFICE */
