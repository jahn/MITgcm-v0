C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/hs94.1x64x5/code_ad/tamc.h,v 1.4 2014/04/05 21:45:54 jmc Exp $
C $Name:  $

C     ================================================================
C     HEADER TAMC
C     ================================================================
C
C     o Header for the use of the Tangent Linear and Adjoint Model
C       Compiler (TAMC).
C
C     started: Christian Eckert eckert@mit.edu  04-Feb-1999
C     changed: Patrick Heimbach heimbach@mit.edu 06-Jun-2000
C              - New parameter nlevchk_0 for dimensionalising
C                common blocks in the undef ALLOW_TAMC_CHECKPOINTING case
C              - nhreads_chkpt was declared at the wrong place
C              - new keys, separate for different packages

C     ================================================================
C     HEADER TAMC
C     ================================================================
#ifdef ALLOW_AUTODIFF_TAMC

C     TAMC checkpointing parameters:
C     ==============================
C
C     The checkpointing parameters have to be consistent with other model
C     parameters and variables. This has to be checked before the model is
C     run.
C
C     nyears_chkpt   :: Number of calendar years affected by the assimilation
C                       experiment; nyears_chkpt has to be at least equal to
C                       the result of cal_IntYears(mythid).
C     nmonths_chkpt  :: Number of months per year; nmonth_chkpt has to be at
C                       least equal to nmonthyear.
C     ndays_chkpt    :: Number of days per month; nday_chkpt has to be at least
C                       equal to nmaxdaymonth.
C     nsteps_chkpt   :: Number of steps per day; nsteps_chkpt has to be at
C                       least equal to cal_nStepDay(mythid)
C     ncheck_chkpt   :: Number of innermost checkpoints.
C
C     ngeom_chkpt    :: Geometry factor.
C     nthreads_chkpt :: Number of threads to be used; nth_chkpt .eq. nTx*nTy

      integer nyears_chkpt
      integer nmonths_chkpt
      integer ndays_chkpt
      integer ngeom_chkpt
      integer ncheck_chkpt
      integer nthreads_chkpt

      parameter (nyears_chkpt   =          1 )
      parameter (nmonths_chkpt  =         12 )
      parameter (ndays_chkpt    =         31 )
      parameter (ngeom_chkpt    = nr*nsx*nsy )
      parameter (ncheck_chkpt   =          6 )
      parameter ( nthreads_chkpt = 1 )

#ifdef ALLOW_TAMC_CHECKPOINTING

      integer    nchklev_1
      parameter( nchklev_1      =  36 )
      integer    nchklev_2
      parameter( nchklev_2      =  30 )
      integer    nchklev_3
      parameter( nchklev_3      =  60 )

C--   Note always check for the correct sizes of the common blocks!

#else /* ALLOW_TAMC_CHECKPOINTING undefined */

      integer    nchklev_0
      parameter( nchklev_0      =  64800 )

#endif /* ALLOW_TAMC_CHECKPOINTING */

c     TAMC keys:
c     ==========
c
c     The keys are used for storing and reading data of the reference
c     trajectory.
c
c     The convention used here is:
c                                    ikey_<name>
c
c     which means that this key is used in routine <name> for reading
c     and writing data.

      common /tamc_keys_i/
     &                     ikey_dynamics,
     &                     ikey_yearly,
     &                     ikey_daily_1,
     &                     ikey_daily_2,
     &                     iloop_daily

      integer ikey_dynamics
      integer ikey_yearly
      integer ikey_daily_1
      integer ikey_daily_2
      integer iloop_daily

      INTEGER    isbyte
      PARAMETER( isbyte      = 8 )
      INTEGER    maximpl
      PARAMETER( maximpl     = 6 )
#ifndef ALLOW_PTRACERS
      INTEGER    maxpass
      PARAMETER( maxpass     = 2 )
#endif
      INTEGER    maxcube
      PARAMETER( maxcube     = 1 )

      INTEGER act0, act1, act2, act3, act4
      INTEGER max0, max1, max2, max3
      INTEGER iikey, kkey, passkey, igadkey,
     &        itdkey, idynkey, igmkey, ikppkey, iptrkey

#ifdef ALLOW_CG2D_NSA
C     Parameter that is needed for the tape complev_cg2d_iter
C     cannot be smaller than the allowed number of iterations in cg2d
C     (numItersMax >= cg2dMaxIters in data-file)
      INTEGER numItersMax
      PARAMETER ( numItersMax = 100 )
#endif

#endif /* ALLOW_AUTODIFF_TAMC */
C     ================================================================
C     END OF HEADER TAMC
C     ================================================================
