c $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exf/Attic/exf_param.h,v 1.1.4.8 2003/05/01 06:10:19 dimitri Exp $
c
c
c     ==================================================================
c     HEADER exf_param
c     ==================================================================
c
c     o Header file for the surface flux data. Used by the external
c       forcing package.
c
c     started: Christian Eckert eckert@mit.edu  30-Jun-1999
c
c     changed: Christian Eckert eckert@mit.edu  14-Jan-2000
c              - Restructured the original version in order to have a
c                better interface to the MITgcmUV.
c
c              Christian Eckert eckert@mit.edu  12-Feb-2000
c              - Changed some variables names (package prefix: exf_)
c
c              Patrick Heimbach, heimbach@mit.edu  04-May-2000
c              - included exf_iprec, exf_yftype to enable easy
c                switch between 32bit/64 bit data format
c
c              Patrick Heimbach, heimbach@mit.edu  01-May-2001
c              - added obcs parameters
c
c     mods for pkg/seaice: menemenlis@jpl.nasa.gov 20-Dec-2002
c
c     ==================================================================
c     HEADER exf_param
c     ==================================================================

c     Calendar data.
      integer hfluxstartdate1
      integer hfluxstartdate2
      integer hfluxstartdate(4)
      _RL     hfluxperiod
      character*1 hfluxmask
      parameter(  hfluxmask = 's' )

      integer atempstartdate1
      integer atempstartdate2
      integer atempstartdate(4)
      _RL     atempperiod
      character*1 atempmask
      parameter(  atempmask = 's' )

      integer aqhstartdate1
      integer aqhstartdate2
      integer aqhstartdate(4)
      _RL     aqhperiod
      character*1 aqhmask
      parameter(  aqhmask = 's' )

      integer sfluxstartdate1
      integer sfluxstartdate2
      integer sfluxstartdate(4)
      _RL     sfluxperiod
      character*1 sfluxmask
      parameter(  sfluxmask = 's' )

      integer evapstartdate1
      integer evapstartdate2
      integer evapstartdate(4)
      _RL     evapperiod
      character*1 evapmask
      parameter(  evapmask = 's' )

      integer precipstartdate1
      integer precipstartdate2
      integer precipstartdate(4)
      _RL     precipperiod
      character*1 precipmask
      parameter(  precipmask = 's' )

      integer runoffstartdate1
      integer runoffstartdate2
      integer runoffstartdate(4)
      _RL     runoffperiod
      character*1 runoffmask
      parameter(  runoffmask = 's' )

      integer ustressstartdate1
      integer ustressstartdate2
      integer ustressstartdate(4)
      _RL     ustressperiod
      character*1 ustressmask
      parameter(  ustressmask = 'u' )

      integer vstressstartdate1
      integer vstressstartdate2
      integer vstressstartdate(4)
      _RL     vstressperiod
      character*1 vstressmask
      parameter(  vstressmask = 'v' )

      integer uwindstartdate1
      integer uwindstartdate2
      integer uwindstartdate(4)
      _RL     uwindperiod
      character*1 uwindmask
      parameter(  uwindmask = 'u' )

      integer vwindstartdate1
      integer vwindstartdate2
      integer vwindstartdate(4)
      _RL     vwindperiod
      character*1 vwindmask
      parameter(  vwindmask = 'v' )

      integer swfluxstartdate1
      integer swfluxstartdate2
      integer swfluxstartdate(4)
      _RL     swfluxperiod
      character*1 swfluxmask
      parameter(  swfluxmask = 's' )

      integer lwfluxstartdate1
      integer lwfluxstartdate2
      integer lwfluxstartdate(4)
      _RL     lwfluxperiod
      character*1 lwfluxmask
      parameter(  lwfluxmask = 's' )

      integer swdownstartdate1
      integer swdownstartdate2
      integer swdownstartdate(4)
      _RL     swdownperiod
      character*1 swdownmask
      parameter(  swdownmask = 's' )

      integer lwdownstartdate1
      integer lwdownstartdate2
      integer lwdownstartdate(4)
      _RL     lwdownperiod
      character*1 lwdownmask
      parameter(  lwdownmask = 's' )

      integer obcsNstartdate1
      integer obcsNstartdate2
      integer obcsNstartdate(4)
      _RL     obcsNperiod

      integer obcsSstartdate1
      integer obcsSstartdate2
      integer obcsSstartdate(4)
      _RL     obcsSperiod

      integer obcsEstartdate1
      integer obcsEstartdate2
      integer obcsEstartdate(4)
      _RL     obcsEperiod

      integer obcsWstartdate1
      integer obcsWstartdate2
      integer obcsWstartdate(4)
      _RL     obcsWperiod

      integer apressurestartdate1
      integer apressurestartdate2
      integer apressurestartdate(4)
      _RL     apressureperiod
      character*1 apressuremask
      parameter(  apressuremask = 's' )

c     File names.
      character*(128) hfluxfile
      character*(128) atempfile
      character*(128) aqhfile
      character*(128) evapfile
      character*(128) precipfile
      character*(128) sfluxfile
      character*(128) runofffile
      character*(128) ustressfile
      character*(128) vstressfile
      character*(128) uwindfile
      character*(128) vwindfile
      character*(128) swfluxfile
      character*(128) lwfluxfile
      character*(128) swdownfile
      character*(128) lwdownfile
      character*(128) apressurefile

      common /exf_param_i/
     &                          hfluxstartdate1,   hfluxstartdate2,
     &                          atempstartdate1,   atempstartdate2,
     &                          aqhstartdate1,     aqhstartdate2,
     &                          sfluxstartdate1,   sfluxstartdate2,
     &                          evapstartdate1,    evapstartdate2,
     &                          runoffstartdate1,  runoffstartdate2,
     &                          precipstartdate1,  precipstartdate2,
     &                          ustressstartdate1, ustressstartdate2,
     &                          vstressstartdate1, vstressstartdate2,
     &                          uwindstartdate1,   uwindstartdate2,
     &                          vwindstartdate1,   vwindstartdate2,
     &                          swfluxstartdate1,  swfluxstartdate2,
     &                          lwfluxstartdate1,  lwfluxstartdate2,
     &                          swdownstartdate1,  swdownstartdate2,
     &                          lwdownstartdate1,  lwdownstartdate2,
     &                          obcsNstartdate1,   obcsNstartdate2,
     &                          obcsSstartdate1,   obcsSstartdate2,
     &                          obcsEstartdate1,   obcsEstartdate2,
     &                          obcsWstartdate1,   obcsWstartdate2,
     &                          apressurestartdate1,apressurestartdate2,
     &                          hfluxstartdate,
     &                          atempstartdate,
     &                          aqhstartdate,
     &                          sfluxstartdate,
     &                          evapstartdate,
     &                          precipstartdate,
     &                          runoffstartdate,
     &                          ustressstartdate,
     &                          vstressstartdate,
     &                          uwindstartdate,
     &                          vwindstartdate,
     &                          swfluxstartdate,
     &                          lwfluxstartdate,
     &                          swdownstartdate,
     &                          lwdownstartdate,
     &                          obcsNstartdate,
     &                          obcsSstartdate,
     &                          obcsEstartdate,
     &                          obcsWstartdate,
     &                          apressurestartdate

      common /exf_param_r/
     &                          hfluxperiod,
     &                          atempperiod,
     &                          aqhperiod,
     &                          sfluxperiod,
     &                          evapperiod,
     &                          precipperiod,
     &                          runoffperiod,
     &                          ustressperiod,
     &                          vstressperiod,
     &                          uwindperiod,
     &                          vwindperiod,
     &                          swfluxperiod,
     &                          lwfluxperiod,
     &                          swdownperiod,
     &                          lwdownperiod,
     &                          obcsNperiod,
     &                          obcsSperiod,
     &                          obcsEperiod,
     &                          obcsWperiod,
     &                          apressureperiod

      common /exf_param_c/
     &                          hfluxfile,
     &                          atempfile,
     &                          aqhfile,
     &                          sfluxfile,
     &                          evapfile,
     &                          precipfile,
     &                          runofffile,
     &                          ustressfile,
     &                          vstressfile,
     &                          uwindfile,
     &                          vwindfile,
     &                          swfluxfile,
     &                          lwfluxfile,
     &                          swdownfile,
     &                          lwdownfile,
     &                          apressurefile

c     file precision and field type

      common /exf_param_type/ 
     &                        exf_iprec,
     &                        exf_yftype

      integer exf_iprec
      character*(2) exf_yftype

c     input and output scaling factors

      _RL     exf_inscal_hfl
      _RL     exf_inscal_ust
      _RL     exf_inscal_vst
      _RL     exf_inscal_swf
      _RL     exf_inscal_sst
      _RL     exf_inscal_sss
      _RL     exf_inscal_apressure
      _RL     exf_inscal_sfl
      _RL     exf_inscal_runoff
      _RL     exf_outscal_hfl
      _RL     exf_outscal_ust
      _RL     exf_outscal_vst
      _RL     exf_outscal_swf
      _RL     exf_outscal_sst
      _RL     exf_outscal_sss
      _RL     exf_outscal_apressure
      _RL     exf_outscal_sfl

      common /exf_param_scal/
     &                      exf_inscal_hfl
     &                    , exf_inscal_ust
     &                    , exf_inscal_vst
     &                    , exf_inscal_swf
     &                    , exf_inscal_sst
     &                    , exf_inscal_sss
     &                    , exf_inscal_apressure
     &                    , exf_inscal_sfl
     &                    , exf_inscal_runoff
     &                    , exf_outscal_hfl
     &                    , exf_outscal_ust
     &                    , exf_outscal_vst
     &                    , exf_outscal_swf
     &                    , exf_outscal_sst
     &                    , exf_outscal_sss
     &                    , exf_outscal_apressure
     &                    , exf_outscal_sfl

c     EXFwindOnBgrid - By default wind files, uwind and vwind,
c     are defined on Southwest C-grid U and V points.
c     When this flag is set, wind files are defined on
c     Southwest B-grid U and V points.
      LOGICAL             EXFwindOnBgrid
      COMMON /EXF_PARM_L/ EXFwindOnBgrid

c for lat interpolation, arraysize currently set to 200 max data values
       integer MAX_LAT_INC
       parameter(MAX_LAT_INC = 200)
      _RL ustress_lon0, ustress_lon_inc
      _RL ustress_lat0, ustress_lat_inc(MAX_LAT_INC)
      INTEGER ustress_nlon, ustress_nlat
      _RL vstress_lon0, vstress_lon_inc
      _RL vstress_lat0, vstress_lat_inc(MAX_LAT_INC)
      INTEGER vstress_nlon, vstress_nlat
      _RL hflux_lon0, hflux_lon_inc
      _RL hflux_lat0, hflux_lat_inc(MAX_LAT_INC)
      INTEGER hflux_nlon, hflux_nlat
      _RL sflux_lon0, sflux_lon_inc
      _RL sflux_lat0, sflux_lat_inc(MAX_LAT_INC)
      INTEGER sflux_nlon, sflux_nlat
      _RL swflux_lon0, swflux_lon_inc
      _RL swflux_lat0, swflux_lat_inc(MAX_LAT_INC)
      INTEGER swflux_nlon, swflux_nlat
      _RL runoff_lon0, runoff_lon_inc
      _RL runoff_lat0, runoff_lat_inc(MAX_LAT_INC)
      INTEGER runoff_nlon, runoff_nlat
      _RL atemp_lon0, atemp_lon_inc
      _RL atemp_lat0, atemp_lat_inc
      INTEGER atemp_nlon, atemp_nlat
      _RL aqh_lon0, aqh_lon_inc
      _RL aqh_lat0, aqh_lat_inc
      INTEGER aqh_nlon, aqh_nlat
      _RL evap_lon0, evap_lon_inc
      _RL evap_lat0, evap_lat_inc
      INTEGER evap_nlon, evap_nlat
      _RL precip_lon0, precip_lon_inc
      _RL precip_lat0, precip_lat_inc
      INTEGER precip_nlon, precip_nlat
      _RL uwind_lon0, uwind_lon_inc
      _RL uwind_lat0, uwind_lat_inc
      INTEGER uwind_nlon, uwind_nlat
      _RL vwind_lon0, vwind_lon_inc
      _RL vwind_lat0, vwind_lat_inc
      INTEGER vwind_nlon, vwind_nlat
      _RL lwflux_lon0, lwflux_lon_inc
      _RL lwflux_lat0, lwflux_lat_inc
      INTEGER lwflux_nlon, lwflux_nlat
      _RL swdown_lon0, swdown_lon_inc
      _RL swdown_lat0, swdown_lat_inc
      INTEGER swdown_nlon, swdown_nlat
      _RL lwdown_lon0, lwdown_lon_inc
      _RL lwdown_lat0, lwdown_lat_inc
      INTEGER lwdown_nlon, lwdown_nlat
      _RL apressure_lon0,apressure_lon_inc
      _RL apressure_lat0,apressure_lat_inc
      INTEGER apressure_nlon,apressure_nlat

      common /exf_interp/
     & ustress_lon0, ustress_lon_inc,
     & ustress_lat0, ustress_lat_inc,
     & ustress_nlon, ustress_nlat,
     & vstress_lon0, vstress_lon_inc,
     & vstress_lat0, vstress_lat_inc,
     & vstress_nlon, vstress_nlat,
     & hflux_lon0, hflux_lon_inc,
     & hflux_lat0, hflux_lat_inc,
     & hflux_nlon, hflux_nlat,
     & sflux_lon0, sflux_lon_inc,
     & sflux_lat0, sflux_lat_inc,
     & sflux_nlon, sflux_nlat,
     & swflux_lon0, swflux_lon_inc,
     & swflux_lat0, swflux_lat_inc,
     & swflux_nlon, swflux_nlat,
     & runoff_lon0, runoff_lon_inc,
     & runoff_lat0, runoff_lat_inc,
     & runoff_nlon, runoff_nlat,
     & atemp_lat0, atemp_lat_inc,
     & atemp_nlon, atemp_nlat,
     & aqh_lon0, aqh_lon_inc,
     & aqh_lat0, aqh_lat_inc,
     & aqh_nlon, aqh_nlat,
     & evap_lon0, evap_lon_inc,
     & evap_lat0, evap_lat_inc,
     & evap_nlon, evap_nlat,
     & precip_lon0, precip_lon_inc,
     & precip_lat0, precip_lat_inc,
     & precip_nlon, precip_nlat,
     & uwind_lon0, uwind_lon_inc,
     & uwind_lat0, uwind_lat_inc,
     & uwind_nlon, uwind_nlat,
     & vwind_lon0, vwind_lon_inc,
     & vwind_lat0, vwind_lat_inc,
     & vwind_nlon, vwind_nlat,
     & lwflux_lon0, lwflux_lon_inc,
     & lwflux_lat0, lwflux_lat_inc,
     & lwflux_nlon, lwflux_nlat,
     & swdown_lon0, swdown_lon_inc,
     & swdown_lat0, swdown_lat_inc,
     & swdown_nlon, swdown_nlat,
     & lwdown_lon0, lwdown_lon_inc,
     & lwdown_lat0, lwdown_lat_inc,
     & lwdown_nlon, lwdown_nlat,
     & apressure_lon0,apressure_lon_inc,
     & apressure_lat0,apressure_lat_inc,
     & apressure_nlon,apressure_nlat
