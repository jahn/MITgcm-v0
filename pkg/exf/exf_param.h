c $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exf/Attic/exf_param.h,v 1.3 2002/11/12 20:34:41 heimbach Exp $
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
      character*(128) precipfile
      character*(128) sfluxfile
      character*(128) runofffile
      character*(128) ustressfile
      character*(128) vstressfile
      character*(128) uwindfile
      character*(128) vwindfile
      character*(128) swfluxfile
      character*(128) lwfluxfile
      character*(128) apressurefile

      common /exf_param_i/
     &                          hfluxstartdate1,   hfluxstartdate2,
     &                          atempstartdate1,   atempstartdate2,
     &                          aqhstartdate1,     aqhstartdate2,
     &                          sfluxstartdate1,   sfluxstartdate2,
     &                          runoffstartdate1,  runoffstartdate2,
     &                          precipstartdate1,  precipstartdate2,
     &                          ustressstartdate1, ustressstartdate2,
     &                          vstressstartdate1, vstressstartdate2,
     &                          uwindstartdate1,   uwindstartdate2,
     &                          vwindstartdate1,   vwindstartdate2,
     &                          swfluxstartdate1,  swfluxstartdate2,
     &                          lwfluxstartdate1,  lwfluxstartdate2,
     &                          obcsNstartdate1,   obcsNstartdate2,
     &                          obcsSstartdate1,   obcsSstartdate2,
     &                          obcsEstartdate1,   obcsEstartdate2,
     &                          obcsWstartdate1,   obcsWstartdate2,
     &                          apressurestartdate1,apressurestartdate2,
     &                          hfluxstartdate,
     &                          atempstartdate,
     &                          aqhstartdate,
     &                          sfluxstartdate,
     &                          precipstartdate,
     &                          runoffstartdate,
     &                          ustressstartdate,
     &                          vstressstartdate,
     &                          uwindstartdate,
     &                          vwindstartdate,
     &                          swfluxstartdate,
     &                          lwfluxstartdate,
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
     &                          precipperiod,
     &                          runoffperiod,
     &                          ustressperiod,
     &                          vstressperiod,
     &                          uwindperiod,
     &                          vwindperiod,
     &                          swfluxperiod,
     &                          lwfluxperiod,
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
     &                          precipfile,
     &                          runofffile,
     &                          ustressfile,
     &                          vstressfile,
     &                          uwindfile,
     &                          vwindfile,
     &                          swfluxfile,
     &                          lwfluxfile,
     &                          apressurefile

c     file precision and field type

      common /exf_param_type/ 
     &                        exf_iprec,
     &                        exf_yftype

      integer exf_iprec
      character*(2) exf_yftype

c     scaling between exf units and MITgcm units

      _RL     scal_hfl
      _RL     scal_ust
      _RL     scal_vst
      _RL     scal_swf
      _RL     scal_sst
      _RL     scal_sss
      _RL     scal_apressure
      _RL     scal_prc
      _RL     scal_sfl

      common /exf_param_scal/
     &                      scal_hfl
     &                    , scal_ust
     &                    , scal_vst
     &                    , scal_swf
     &                    , scal_sst
     &                    , scal_sss
     &                    , scal_apressure
     &                    , scal_prc
     &                    , scal_sfl
