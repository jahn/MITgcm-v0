
c     ==================================================================
c     HEADER CONTROLVARS
c     ==================================================================
c
c     o Control variables of the ECCO state estimation tool.
c
c     Depending on the specific problem to be studied users will have to
c     modify this header file.
c
c     started: Christian Eckert eckert@mit.edu  30-Jun-1999
c
c     changed: Christian Eckert eckert@mit.edu
c
c
c     ==================================================================
c     HEADER CONTROLVARS
c     ==================================================================
c
c     nwet[c/s/w]tile - Number of wet points in a tile for center (c),
c                       south (s), and western (w) mask, resp. .

      integer     maxcvars
      parameter ( maxcvars = 20 )

      integer     ctrlprec
      parameter ( ctrlprec = 64 )

      common /controlvars_i/
     &                       nvartype,
     &                       nvarlength,
     &                       ncvarindex,
     &                       ncvarrecs,
     &                       ncvarrecstart,
     &                       ncvarrecsend,
     &                       ncvarxmax,
     &                       ncvarymax,
     &                       ncvarnrmax,
     &                       nwetctile,
     &                       nwetstile,
     &                       nwetwtile
      integer nvartype
      integer nvarlength
      integer ncvarindex    ( maxcvars )
      integer ncvarrecs     ( maxcvars )
      integer ncvarrecstart ( maxcvars )
      integer ncvarrecsend  ( maxcvars )
      integer ncvarxmax     ( maxcvars )
      integer ncvarymax     ( maxcvars )
      integer ncvarnrmax    ( maxcvars )
      integer nwetctile     ( nsx,nsy,nr )
      integer nwetstile     ( nsx,nsy,nr )
      integer nwetwtile     ( nsx,nsy,nr )

#ifdef ALLOW_OBCSN_CONTROL
      common /controlvars_i_obcsn/
     &                       nwetobcsn
      integer nwetobcsn     ( nsx,nsy,nr,nobcs )
#endif
#ifdef ALLOW_OBCSS_CONTROL
      common /controlvars_i_obcss/
     &                       nwetobcss
      integer nwetobcss     ( nsx,nsy,nr,nobcs )
#endif
#ifdef ALLOW_OBCSW_CONTROL
      common /controlvars_i_obcsw/
     &                       nwetobcsw
      integer nwetobcsw     ( nsx,nsy,nr,nobcs )
#endif
#ifdef ALLOW_OBCSE_CONTROL
      common /controlvars_i_obcse/
     &                       nwetobcse
      integer nwetobcse     ( nsx,nsy,nr,nobcs )
#endif

      common /controlvars_c/
     &                       ncvargrd
      character*(1) ncvargrd(maxcvars)

c     Control variables:
c     ==================
c
c     xx_theta - control vector temperature part.
c     xx_salt  - control vector salt part.
c     xx_hflux   - control vector surface heat flux part.
c     xx_sflux   - control vector surface salt flux part.
c     xx_tauu  - control vector zonal wind stress part.
c     xx_tauv  - control vector meridional wind stress part.
cph(
c     xx_... are to be replaced by tmpfld2d/3d throughout the code; 
c     control variables are written to / read from active files
c     TAMC sees xx_..._dummy

      common /controlvars_r/
     &                        tmpfld2d
     &                      , tmpfld3d
      _RL tmpfld2d 
     &    (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL tmpfld3d 
     &    (1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)

#ifdef ALLOW_OBCS_CONTROL
      common /controlvars_r_obcs/
     &                        tmpfldxz
     &                      , tmpfldyz
      _RL tmpfldxz (1-olx:snx+olx,nr,nsx,nsy)
      _RL tmpfldyz (1-oly:sny+oly,nr,nsx,nsy)
#endif

c     Auxiliary storage arrays for the control variables:
c     ===================================================
c
c     xx_hflux0  - heat flux record before current date.
c     xx_hflux1  - heat flux record after  current date
c     xx_sflux0  - salt flux record before current date.
c     xx_sflux1  - salt flux record after  current date.
c     xx_tauu0 - zonal wind stress record before current date.
c     xx_tauu1 - zonal wind stress record after  current date.
c     xx_tauv0 - meridional wind stress record before current date.
c     xx_tauv1 - meridional wind stress record after  current date.

#if     (defined  (ALLOW_HFLUX_CONTROL))
      common /controlaux_1_r/
     &                      xx_hflux0,
     &                      xx_hflux1
#elif   (defined  (ALLOW_ATEMP_CONTROL))
      common /controlaux_1_r/
     &                      xx_atemp0,
     &                      xx_atemp1
#endif

#if     (defined  (ALLOW_SFLUX_CONTROL))
      common /controlaux_2_r/
     &                      xx_sflux0,
     &                      xx_sflux1
#elif   (defined  (ALLOW_AQH_CONTROL))
      common /controlaux_2_r/
     &                      xx_aqh0,
     &                      xx_aqh1
#endif

#if     (defined  (ALLOW_USTRESS_CONTROL))
      common /controlaux_3_r/
     &                      xx_tauu0,
     &                      xx_tauu1
#elif   (defined  (ALLOW_UWIND_CONTROL))
      common /controlaux_3_r/
     &                      xx_uwind0,
     &                      xx_uwind1
#endif

#if     (defined  (ALLOW_VSTRESS_CONTROL))
      common /controlaux_4_r/
     &                      xx_tauv0,
     &                      xx_tauv1
#elif   (defined  (ALLOW_VWIND_CONTROL))
      common /controlaux_4_r/
     &                      xx_vwind0,
     &                      xx_vwind1
#endif

#ifdef ALLOW_OBCS_CONTROL
      common /controlaux_5_r/
     &                      xz_obcs0,
     &                      xz_obcs1,
     &                      yz_obcs0,
     &                      yz_obcs1
#endif

#if     (defined  (ALLOW_HFLUX_CONTROL))
      _RL xx_hflux0 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_hflux1 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#elif   (defined  (ALLOW_ATEMP_CONTROL))
      _RL xx_atemp0 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_atemp1 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#endif
#if     (defined  (ALLOW_SFLUX_CONTROL))
      _RL xx_sflux0 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_sflux1 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#elif   (defined  (ALLOW_AQH_CONTROL))
      _RL xx_aqh0 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_aqh1 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#endif
#if     (defined  (ALLOW_USTRESS_CONTROL))
      _RL xx_tauu0(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_tauu1(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#elif   (defined  (ALLOW_UWIND_CONTROL))
      _RL xx_uwind0 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_uwind1 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#endif
#if     (defined  (ALLOW_VSTRESS_CONTROL))
      _RL xx_tauv0(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_tauv1(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#elif   (defined  (ALLOW_VWIND_CONTROL))
      _RL xx_vwind0 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL xx_vwind1 (1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
#endif

#ifdef ALLOW_OBCS_CONTROL
      _RL xz_obcs0 (1-Olx:sNx+Olx,Nr,nSx,nSy)
      _RL xz_obcs1 (1-Olx:sNx+Olx,Nr,nSx,nSy)
      _RL yz_obcs0 (1-Oly:sNy+Oly,Nr,nSx,nSy)
      _RL yz_obcs1 (1-Oly:sNy+Oly,Nr,nSx,nSy)
#endif

c     Files where the control variables are stored:
c     =============================================
c
c     xx_theta_file - control vector temperature part.
c     xx_salt_file  - control vector salinity part.
c     xx_hflux_file - control vector surface heat flux file.
c     xx_sflux_file - control vector surface salt flux file.
c     xx_tauu_file  - control vector zonal wind stress file.
c     xx_tauv_file  - control vector meridional wind stress file.
c     xx_obcsn_file - control vector Uvel at boundary
c     xx_obcss_file - control vector Vvel at boundary
c     xx_obcsw_file - control vector temp. at boundary
c     xx_obcse_file - control vector salin. at boundary 
      common /controlfiles_c/
     &                      xx_theta_file
     &                    , xx_salt_file
     &                    , xx_hflux_file
     &                    , xx_sflux_file
     &                    , xx_tauu_file
     &                    , xx_tauv_file
     &                    , xx_atemp_file
     &                    , xx_aqh_file
     &                    , xx_uwind_file
     &                    , xx_vwind_file
     &                    , xx_obcsn_file
     &                    , xx_obcss_file
     &                    , xx_obcsw_file
     &                    , xx_obcse_file
      character*(MAX_LEN_FNAM) xx_theta_file
      character*(MAX_LEN_FNAM) xx_salt_file
      character*(MAX_LEN_FNAM) xx_hflux_file
      character*(MAX_LEN_FNAM) xx_sflux_file
      character*(MAX_LEN_FNAM) xx_tauu_file
      character*(MAX_LEN_FNAM) xx_tauv_file
      character*(MAX_LEN_FNAM) xx_atemp_file
      character*(MAX_LEN_FNAM) xx_aqh_file
      character*(MAX_LEN_FNAM) xx_uwind_file
      character*(MAX_LEN_FNAM) xx_vwind_file
      character*(MAX_LEN_FNAM) xx_obcsn_file
      character*(MAX_LEN_FNAM) xx_obcss_file
      character*(MAX_LEN_FNAM) xx_obcsw_file
      character*(MAX_LEN_FNAM) xx_obcse_file

      common /packnames_c/
     &                      yadmark,
     &                      ctrlname, 
     &                      costname, 
     &                      scalname, 
     &                      maskname, 
     &                      metaname
      character*2 yadmark
      character*9 ctrlname
      character*9 costname
      character*9 scalname
      character*9 maskname
      character*9 metaname

c     Calendar information for the control variables:
c     ===============================================
c
c     xx_hfluxperiod - sampling interval for the heat flux control part.
c     xx_sfluxperiod - sampling interval for the salt flux control part.
c     xx_tauuperiod  - sampling interval for the zonal wind
c                      stress control part.
c     xx_tauvperiod  - sampling interval for the meridional wind
c                      stress control part.
c     xx_obcsuperiod - sampling interval
c     xx_obcsvperiod - sampling interval
c     xx_obcstperiod - sampling interval
c     xx_obcssperiod - sampling interval

      common /controltimes_r/
     &                        xx_hfluxperiod
     &                      , xx_sfluxperiod
     &                      , xx_tauuperiod
     &                      , xx_tauvperiod
     &                      , xx_atempperiod
     &                      , xx_aqhperiod
     &                      , xx_uwindperiod
     &                      , xx_vwindperiod
     &                      , xx_obcsnperiod
     &                      , xx_obcssperiod
     &                      , xx_obcswperiod
     &                      , xx_obcseperiod
      _RL     xx_hfluxperiod
      _RL     xx_sfluxperiod
      _RL     xx_tauuperiod
      _RL     xx_tauvperiod
      _RL     xx_atempperiod
      _RL     xx_aqhperiod
      _RL     xx_uwindperiod
      _RL     xx_vwindperiod
      _RL     xx_obcsnperiod
      _RL     xx_obcssperiod
      _RL     xx_obcswperiod
      _RL     xx_obcseperiod

c     xx_hfluxstartdate - start date for the heat flux control part.
c     xx_sfluxstartdate - start date for the salt flux control part.
c     xx_tauustartdate  - start date for the zonal wind stress
c                         control part.
c     xx_tauvstartdate  - start date for the meridional wind stress
c                         control part.

      common /controltimes_i/
     &                        xx_hfluxstartdate1
     &                      , xx_hfluxstartdate2
     &                      , xx_sfluxstartdate1
     &                      , xx_sfluxstartdate2
     &                      , xx_tauustartdate1
     &                      , xx_tauustartdate2
     &                      , xx_tauvstartdate1
     &                      , xx_tauvstartdate2
     &                      , xx_atempstartdate1
     &                      , xx_atempstartdate2
     &                      , xx_aqhstartdate1
     &                      , xx_aqhstartdate2
     &                      , xx_uwindstartdate1
     &                      , xx_uwindstartdate2
     &                      , xx_vwindstartdate1
     &                      , xx_vwindstartdate2
     &                      , xx_hfluxstartdate
     &                      , xx_sfluxstartdate
     &                      , xx_tauustartdate
     &                      , xx_tauvstartdate
     &                      , xx_atempstartdate
     &                      , xx_aqhstartdate
     &                      , xx_uwindstartdate
     &                      , xx_vwindstartdate
     &                      , xx_obcsnstartdate1
     &                      , xx_obcsnstartdate2
     &                      , xx_obcssstartdate1
     &                      , xx_obcssstartdate2
     &                      , xx_obcswstartdate1
     &                      , xx_obcswstartdate2
     &                      , xx_obcsestartdate1
     &                      , xx_obcsestartdate2
     &                      , xx_obcsnstartdate
     &                      , xx_obcssstartdate
     &                      , xx_obcswstartdate
     &                      , xx_obcsestartdate
      integer xx_hfluxstartdate1
      integer xx_hfluxstartdate2
      integer xx_sfluxstartdate1
      integer xx_sfluxstartdate2
      integer xx_tauustartdate1
      integer xx_tauustartdate2
      integer xx_tauvstartdate1
      integer xx_tauvstartdate2
      integer xx_atempstartdate1
      integer xx_atempstartdate2
      integer xx_aqhstartdate1
      integer xx_aqhstartdate2
      integer xx_uwindstartdate1
      integer xx_uwindstartdate2
      integer xx_vwindstartdate1
      integer xx_vwindstartdate2
      integer xx_obcsnstartdate1
      integer xx_obcsnstartdate2
      integer xx_obcssstartdate1
      integer xx_obcssstartdate2
      integer xx_obcswstartdate1
      integer xx_obcswstartdate2
      integer xx_obcsestartdate1
      integer xx_obcsestartdate2

      integer xx_hfluxstartdate(4)
      integer xx_sfluxstartdate(4)
      integer xx_tauustartdate(4)
      integer xx_tauvstartdate(4)
      integer xx_atempstartdate(4)
      integer xx_aqhstartdate(4)
      integer xx_uwindstartdate(4)
      integer xx_vwindstartdate(4)
      integer xx_obcsnstartdate(4)
      integer xx_obcssstartdate(4)
      integer xx_obcswstartdate(4)
      integer xx_obcsestartdate(4)

c     ==================================================================
c     END OF HEADER CONTROLVARS
c     ==================================================================


