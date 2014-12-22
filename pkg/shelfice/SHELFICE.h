C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/shelfice/SHELFICE.h,v 1.15 2014/12/22 22:51:57 jmc Exp $
C $Name:  $

#ifdef ALLOW_SHELFICE

CBOP
C !ROUTINE: SHELFICE.h

C !DESCRIPTION: \bv
C     *==========================================================*
C     | SHELFICE.h
C     | o Basic header thermodnynamic shelf ice package.
C     |   Contains all SHELFICE field declarations.
C     *==========================================================*

C-----------------------------------------------------------------------
C
C--   Constants that can be set in data.shelfice
C     SHELFICEtopoFile         :: File containing the topography of the
C                                 shelfice draught (unit=m)
C     SHELFICEmassFile         :: name of shelfice Mass file
C     SHELFICEloadAnomalyFile  :: name of shelfice load anomaly file
C     SHELFICEMassDynTendFile  :: file name for other mass tendency (e.g. dynamics)
C     SHELFICEDragLinear       :: linear drag at bottom shelfice (1/s)
C     SHELFICEDragQuadratic    :: quadratic drag at bottom shelfice (1/m)
C     SHELFICEheatTransCoeff   :: heat transfer coefficient that determines
C                                 heat flux into shelfice (m/s)
C     SHELFICEsaltTransCoeff   :: salinity transfer coefficient that determines
C                                 salt flux into shelfice (m/s)
C     SHELFICElatentHeat       :: latent heat of fusion (J/kg)
C     useISOMIPTD              :: use simple ISOMIP thermodynamics
C     SHELFICEconserve         :: use conservative form of H&O-thermodynamics
C                                 following Jenkins et al. (2001, JPO)
C     SHELFICEMassStepping     :: flag to step forward ice shelf mass/thickness
C                                 accounts for melting/freezing & dynamics (from
C                                 file or from coupling)
C     SHELFICEboundaryLayer    :: turn on vertical merging of cells to for a
C                                 boundary layer of drF thickness
C     SHELFICEadvDiffHeatFlux  :: use advective-diffusive heat flux into the ice shelf
C                                 instead of diffusive heat flux (default), see Holland
C                                 and Jenkins (1999), eq.21,22,26,31
C     SHELFICEuseGammaFrict    :: use velocity dependent exchange coefficients,
C                                 see Holland and Jenkins (1999), eq.11-18
C     no_slip_shelfice         :: set slip conditions for shelfice separately,
C                                 (by default the same as no_slip_bottom)
C     SHELFICEwriteState       :: enable output
C     SHELFICE_dump_mnc        :: use netcdf for snapshot output
C     SHELFICE_tave_mnc        :: use netcdf for time-averaged output
C     SHELFICE_dumpFreq        :: analoguous to dumpFreq (= default)
C     SHELFICE_taveFreq        :: analoguous to taveFreq (= default)
C
C--   Fields
C     ktopC                  :: index of the top "wet cell" (2D)
C     R_shelfIce             :: shelfice topography [m]
C     shelficeMassInit       :: ice-shelf mass (per unit area) [kg/m^2]
C     shelficeMass           :: ice-shelf mass (per unit area) [kg/m^2]
C     shelfIceMassDynTendency :: other mass balance tendency (e.g., from dynamics)
C     shelficeLoadAnomaly    :: pressure load anomaly of shelfice [Pa]
C     shelficeHeatFlux       :: upward heat flux [W/m^2]
C     shelficeFreshWaterFlux :: upward fresh water flux (virt. salt flux) [kg/m^2/s]
C     shelficeForcingT       :: analogue of surfaceForcingT
C                               units are  r_unit.Kelvin/s (=Kelvin.m/s if r=z)
C     shelficeForcingS       :: analogue of surfaceForcingS
C                               units are  r_unit.psu/s (=psu.m/s if r=z)
C-----------------------------------------------------------------------
C \ev
CEOP

      COMMON /SHELFICE_PARMS_I/  kTopC
      INTEGER kTopC (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON /SHELFICE_PARMS_R/
     &     SHELFICE_dumpFreq, SHELFICE_taveFreq,
     &     SHELFICEheatTransCoeff, SHELFICEsaltTransCoeff,
     &     rhoShelfice, SHELFICEkappa,
     &     SHELFICElatentHeat, recip_SHELFICElatentHeat,
     &     SHELFICEheatCapacity_Cp,
     &     SHELFICEthetaSurface,
     &     SHELFICEDragLinear, SHELFICEDragQuadratic,
     &     shiCdrag, shiZetaN, shiRc,
     &     shiPrandtl, shiSchmidt, shiKinVisc

      _RL SHELFICE_dumpFreq, SHELFICE_taveFreq
      _RL SHELFICEheatTransCoeff
      _RL SHELFICEsaltTransCoeff
      _RL SHELFICElatentHeat
      _RL SHELFICEheatCapacity_Cp
      _RL rhoShelfice
      _RL SHELFICEkappa
      _RL recip_SHELFICElatentHeat
      _RL SHELFICEDragLinear
      _RL SHELFICEDragQuadratic
      _RL SHELFICEthetaSurface
      _RL shiCdrag, shiZetaN, shiRc
      _RL shiPrandtl, shiSchmidt, shiKinVisc

      COMMON /SHELFICE_FIELDS_RL/
     &     shelficeForcingT, shelficeForcingS,
     &     shiTransCoeffT, shiTransCoeffS
      _RL shelficeForcingT      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL shelficeForcingS      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL shiTransCoeffT        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL shiTransCoeffS        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON /SHELFICE_FIELDS_RS/
     &     R_shelfIce,
     &     shelficeMassInit,
     &     shelficeMass,
     &     shelficeLoadAnomaly,
     &     shelficeHeatFlux,
     &     shelfIceFreshWaterFlux,
     &     shelfIceMassDynTendency
      _RS R_shelfIce            (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS shelficeMass          (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS shelficeMassInit      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS shelficeLoadAnomaly   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS shelficeHeatFlux      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS shelficeFreshWaterFlux(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RS
     &   shelfIceMassDynTendency(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

#ifdef ALLOW_SHIFWFLX_CONTROL
      COMMON /SHELFICE_MASKS_CTRL/ maskSHI
      _RS maskSHI  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy)
#endif /* ALLOW_SHIFWFLX_CONTROL */

      LOGICAL SHELFICEisOn
      LOGICAL useISOMIPTD
      LOGICAL SHELFICEconserve
      LOGICAL SHELFICEboundaryLayer
      LOGICAL no_slip_shelfice
      LOGICAL SHELFICEwriteState
      LOGICAL SHELFICE_dump_mdsio
      LOGICAL SHELFICE_tave_mdsio
      LOGICAL SHELFICE_dump_mnc
      LOGICAL SHELFICE_tave_mnc
      LOGICAL SHELFICEadvDiffHeatFlux
      LOGICAL SHELFICEuseGammaFrict
      LOGICAL SHELFICEMassStepping
      COMMON /SHELFICE_PARMS_L/
     &     SHELFICEisOn,
     &     useISOMIPTD,
     &     SHELFICEconserve,
     &     SHELFICEboundaryLayer,
     &     no_slip_shelfice,
     &     SHELFICEwriteState,
     &     SHELFICE_dump_mdsio,
     &     SHELFICE_tave_mdsio,
     &     SHELFICE_dump_mnc,
     &     SHELFICE_tave_mnc,
     &     SHELFICEadvDiffHeatFlux,
     &     SHELFICEuseGammaFrict,
     &     SHELFICEMassStepping

      CHARACTER*(MAX_LEN_FNAM) SHELFICEloadAnomalyFile
      CHARACTER*(MAX_LEN_FNAM) SHELFICEmassFile
      CHARACTER*(MAX_LEN_FNAM) SHELFICEtopoFile
      CHARACTER*(MAX_LEN_FNAM) SHELFICEMassDynTendFile
      COMMON /SHELFICE_PARM_C/
     &     SHELFICEloadAnomalyFile,
     &     SHELFICEmassFile,
     &     SHELFICEtopoFile,
     &     SHELFICEMassDynTendFile

#endif /* ALLOW_SHELFICE */
