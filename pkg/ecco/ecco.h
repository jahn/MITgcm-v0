C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/ecco/ecco.h,v 1.6 2014/10/03 15:01:07 gforget Exp $
C $Name:  $

c     ==================================================================
c     HEADER ECCO
c     ==================================================================
c
c     o Header for the ECCO project.
c
c     started: Christian Eckert eckert@mit.edu  23-Feb-1999
c
c     changed: Christian Eckert eckert@mit.edu
c
c
c     ==================================================================
c     HEADER ECCO
c     ==================================================================

c     Version of the release and versions of used packages:
c     =====================================================
c
c     eccoVersion                - ecco release version.
c     usesCalendarVersion        - version of the calendar that has to
c                                  be used.
c     usesExternalForcingVersion - version of the external forcing that
c                                  has to be used.
c     usesAdjointSupportVersion  - version of the adjoint support routines
c                                  that have to be used.
c     usesOptimizationVersion    - version of the oof-line optimization
c                                  that has to be used.

      character*(5) eccoVersion
      character*(5) eccoUsesCalVersion
      character*(5) eccoUsesExfVersion
      character*(5) eccoUsesAdsuppVersion
      character*(5) eccoUsesOptimVersion

      parameter(    eccoVersion           = '0.1.0' )
      parameter(    eccoUsesCalVersion    = '0.1.4' )
      parameter(    eccoUsesExfVersion    = '0.1.1' )
      parameter(    eccoUsesAdsuppVersion = '0.1.0' )
      parameter(    eccoUsesOptimVersion  = '2.1.0' )


c     Experiment name:
c     ================

      common /ecco_c/
     &                expId
      character*(10)  expId


c     Integration information:
c     ========================
c
c     nyears - number of calendar years that are affected by the
c              current integration.

      common /ecco_i/
     &                nyears, nmonths, ndays, numsteps,
     &                eccoiter, ecco_prevcall
      integer nyears
      integer nmonths
      integer ndays
      integer numsteps
      integer eccoiter
      integer ecco_prevcall

c     Averaging counters:
c     ===================
c
c     sum1day - counter for the daily averaging
c     sum1mon - counter for the monthly averaging
c     dayrec  - number of averaged surface pressure records.
c     monrec  - number of averaged theta and salinity records.

      common /average_i/
     &                   sum1day,sum1mon,sum1year,
     &                   dayrec,monrec,yearrec
      integer sum1day
      integer sum1mon
      integer sum1year
      integer dayrec
      integer monrec
      integer yearrec

c     Flags used in the model-data comparison:
c     ========================================
c
c     using_ers - flag that indicates the use of ERS data

      common /ecco_cost_data_flags/
     &                         using_mdt,
     &                         using_tpj,
     &                         using_topex,
     &                         using_ers,
     &                         using_gfo,
     &                         using_cost_altim,
     &                         using_cost_bp,
     &                         using_cost_sst,
     &                         using_cost_scat,
     &                         using_cost_seaice
      logical using_mdt
      logical using_tpj
      logical using_topex
      logical using_ers
      logical using_gfo
      logical using_cost_altim
      logical using_cost_bp
      logical using_cost_sst
      logical using_cost_scat
      logical using_cost_seaice

c     Record counters relevant for the cost function evaluation.
c     ==========================================================
c
c     nyearsrec - number of yearly records that will be generated by
c                 the current model integration.
c     nmonsrec  - number of monthly records that will be generated by
c                 the current model integration.
c     ndaysrec  - number of  daily  records that will be generated by
c                 the current model integration.

      common /ecco_i/
     &                nyearsrec,
     &                nmonsrec,
     &                ndaysrec
      integer nyearsrec
      integer nmonsrec
      integer ndaysrec

      common /ecco_r/
     &                    etanFull,
     &                    VOLsumGlob_0,
     &                    VOLsumGlob,
     &                    RHOsumGlob_0,
     &                    RHOsumGlob

      _RL VOLsumGlob_0, VOLsumGlob, RHOsumGlob_0, RHOsumGlob
      _RL etanFull       (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)

c     file precision and field type
      common /prec_type_cost/
     &                        cost_iprec,
     &                        cost_yftype

      integer cost_iprec
      character*(2) cost_yftype

c     empty preprocessing name:
c     =========================
      character*(16) no_preproc,no_posproc
      PARAMETER ( no_preproc='        ' )
      PARAMETER ( no_posproc='        ' )
      character*(MAX_LEN_FNAM) no_scalefile
      PARAMETER ( no_scalefile=' ' )

c     Number of User Cost terms:
c     =============================
      INTEGER NUSERCOST
      PARAMETER ( NUSERCOST=10 )

c     Number of Generic Cost terms:
c     =============================
      INTEGER NGENCOST
      PARAMETER ( NGENCOST=20 )

      INTEGER NGENCOST3D
#ifdef ALLOW_GENCOST3D
      PARAMETER ( NGENCOST3D=2 )
#else
      PARAMETER ( NGENCOST3D=0 )
#endif

#ifdef ALLOW_GENCOST_CONTRIBUTION
c     objf_gencost - gencost user defined contribution
      common /ecco_gencost_ctrl/
     &       gencost_dummy
      _RL  gencost_dummy(NGENCOST)

      common /ecco_gencost_r_1/
     &       objf_gencost, num_gencost, mult_gencost,
     &       gencost_barfld, gencost_modfld, gencost_weight,
#ifdef ALLOW_GENCOST3D
     &       gencost_bar3d, gencost_mod3d, gencost_wei3d,
#endif
     &       gencost_spmin, gencost_spmax, gencost_spzero
      _RL  objf_gencost(nsx,nsy,NGENCOST)
      _RL  num_gencost(nsx,nsy,NGENCOST)
      _RL  mult_gencost(NGENCOST)
      _RL  gencost_spmin(NGENCOST)
      _RL  gencost_spmax(NGENCOST)
      _RL  gencost_spzero(NGENCOST)
      _RL  gencost_barfld(1-olx:snx+olx,1-oly:sny+oly,
     &       nsx,nsy,NGENCOST)
      _RL  gencost_modfld(1-olx:snx+olx,1-oly:sny+oly,
     &       nsx,nsy,NGENCOST)
      _RL  gencost_weight(1-olx:snx+olx,1-oly:sny+oly,
     &       nsx,nsy,NGENCOST)
#ifdef ALLOW_GENCOST3D
      _RL  gencost_bar3d(1-olx:snx+olx,1-oly:sny+oly,
     &       nr,nsx,nsy,NGENCOST3D)
      _RL  gencost_mod3d(1-olx:snx+olx,1-oly:sny+oly,
     &       nr,nsx,nsy,NGENCOST3D)
      _RL  gencost_wei3d(1-olx:snx+olx,1-oly:sny+oly,
     &       nr,nsx,nsy,NGENCOST3D)
#endif

      common /ecco_gencost_r_2/
     &       gencost_period
      _RL     gencost_period(NGENCOST)

      common /ecco_gencost_i_1/
     &       gencost_nrec, gencost_nrecperiod,
     &       gencost_flag, gencost_outputlevel,
     &       gencost_startdate1, gencost_startdate2,
     &       gencost_enddate1, gencost_enddate2,
     &       gencost_startdate, gencost_enddate,
     &       gencost_pointer3d, gencost_smooth2Ddiffnbt

      integer gencost_nrec(NGENCOST)
      integer gencost_nrecperiod(NGENCOST)
      integer gencost_flag(NGENCOST)
      integer gencost_outputlevel(NGENCOST)
      integer gencost_startdate1(NGENCOST)
      integer gencost_startdate2(NGENCOST)
      integer gencost_startdate(4,NGENCOST)
      integer gencost_enddate1(NGENCOST)
      integer gencost_enddate2(NGENCOST)
      integer gencost_enddate(4,NGENCOST)
      integer gencost_pointer3d(NGENCOST)
      integer  gencost_smooth2Ddiffnbt(NGENCOST)

      common /ecco_gencost_l_1/
     &       gencost_timevaryweight, gencost_barskip,
     &       using_gencost, gencost_is3d
      LOGICAL using_gencost(NGENCOST)
      LOGICAL gencost_is3d(NGENCOST)
      LOGICAL gencost_timevaryweight(NGENCOST)
      LOGICAL gencost_barskip(NGENCOST)

      common /ecco_gencost_c/
     &       gencost_name,
     &       gencost_scalefile,
     &       gencost_errfile,
     &       gencost_datafile,
     &       gencost_barfile,
     &       gencost_avgperiod,
     &       gencost_preproc,
     &       gencost_posproc,
     &       gencost_mask
      character*(MAX_LEN_FNAM) gencost_name(NGENCOST)
      character*(MAX_LEN_FNAM) gencost_scalefile(NGENCOST)
      character*(MAX_LEN_FNAM) gencost_errfile(NGENCOST)
      character*(MAX_LEN_FNAM) gencost_datafile(NGENCOST)
      character*(MAX_LEN_FNAM) gencost_barfile(NGENCOST)
      character*(5)            gencost_avgperiod(NGENCOST)
      character*(16)           gencost_preproc(NGENCOST)
      character*(16)           gencost_posproc(NGENCOST)
      character*(1)            gencost_mask(NGENCOST)

#endif /* ALLOW_GENCOST_CONTRIBUTION */

c     ==================================================================
c     END OF HEADER ECCO
c     ==================================================================


