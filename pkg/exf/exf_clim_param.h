c $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exf/Attic/exf_clim_param.h,v 1.4 2003/08/07 02:31:29 dimitri Exp $
c
c
c     ==================================================================
c     HEADER exf_clim_param
c     ==================================================================
c
c     o Header for the climatology part of the external forcing package.
c
c     started: Ralf Giering 15-Jan-2001
c
c     ==================================================================
c     HEADER exf_clim_param
c     ==================================================================

c     Calendar data.
      integer climtempstartdate1
      integer climtempstartdate2
      integer climtempstartdate(4)
      _RL     climtempperiod
      character*1 climtempmask
      parameter(  climtempmask = 's' )

      integer climsaltstartdate1
      integer climsaltstartdate2
      integer climsaltstartdate(4)
      _RL     climsaltperiod
      character*1 climsaltmask
      parameter(  climsaltmask = 's' )

      integer climsststartdate1
      integer climsststartdate2
      integer climsststartdate(4)
      _RL     climsstperiod
      character*1 climsstmask
      parameter(  climsstmask = 's' )

      integer climsssstartdate1
      integer climsssstartdate2
      integer climsssstartdate(4)
      _RL     climsssperiod
      character*1 climsssmask
      parameter(  climsssmask = 's' )

      _RL climsstconst
      _RL climsssconst

      common /exf_clim_i/
     &                        climtempstartdate1, climtempstartdate2,
     &                        climsaltstartdate1, climsaltstartdate2,
     &                        climsststartdate1,  climsststartdate2,
     &                        climsssstartdate1,  climsssstartdate2,
     &                        climtempstartdate,
     &                        climsaltstartdate,
     &                        climsststartdate,
     &                        climsssstartdate

      common /exf_clim_c/
     &                        climtempfile,
     &                        climsaltfile,
     &                        climsstfile,
     &                        climsssfile

      common /exf_clim_r/
     &                        climtempperiod,
     &                        climsaltperiod,
     &                        climsstperiod,
     &                        climsssperiod,
     &                        climsstconst,
     &                        climsssconst

c     File names.
      character*(128) climtempfile
      character*(128) climsaltfile
      character*(128) climsstfile
      character*(128) climsssfile

c     file precision and field type

      common /exf_clim_prec/ exf_clim_iprec
     &                     , exf_clim_yftype

      integer       exf_clim_iprec
      character*(2) exf_clim_yftype

#ifdef USE_EXF_INTERPOLATION
c for lat interpolation, arraysize currently set to 200 max data values
      _RL climsst_lon0, climsst_lon_inc
      _RL climsst_lat0, climsst_lat_inc(MAX_LAT_INC)
      INTEGER climsst_nlon, climsst_nlat
      _RL climsss_lon0, climsss_lon_inc
      _RL climsss_lat0, climsss_lat_inc(MAX_LAT_INC)
      INTEGER climsss_nlon, climsss_nlat
      common /exf_clim_interpolation/
     & climsst_lon0, climsst_lon_inc,
     & climsst_lat0, climsst_lat_inc,
     & climsst_nlon, climsst_nlat,
     & climsss_lon0, climsss_lon_inc,
     & climsss_lat0, climsss_lat_inc,
     & climsss_nlon, climsss_nlat
#endif
