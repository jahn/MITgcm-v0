C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/mnc/MNC_PARAMS.h,v 1.2 2004/09/29 03:45:14 heimbach Exp $
C $Name:  $
C

CBOP
C     !ROUTINE: PARAMS.h
C     !INTERFACE:
C     #include PARAMS.h

C     !DESCRIPTION:
C     Header file defining model "parameters".  The values from the
C     model standard input file are stored into the variables held
C     here. Notes describing the parameters can also be found here.
CEOP

C     ===  PARM_MNC_L Common Block  ===
C     useMNC           :: overall package run-time flag
C     mnc_use_indir    :: use "mnc_indir_str" as input filename prefix
C     mnc_use_outdir   :: use "mnc_outdir_str" as output filename prefix
C     mnc_outdir_date  :: use a date string within the output dir name
C     mnc_echo_gvtypes :: echo type names (fails on many platforms)
C     pickup_write_mnc :: use mnc to write pickups
C     pickup_read_mnc  :: use mnc to read  pickups
C     mon_write_mnc    :: use mnc to write monitor output
      COMMON /PARM_MNC_L/
     &     useMNC,
     &     mnc_use_indir, mnc_use_outdir, mnc_outdir_date,
     &     mnc_echo_gvtypes,
     &     pickup_write_mnc, pickup_read_mnc,
     &     timeave_mnc, snapshot_mnc, monitor_mnc, autodiff_mnc
      LOGICAL
     &     useMNC,
     &     mnc_use_indir, mnc_use_outdir, mnc_outdir_date,
     &     mnc_echo_gvtypes,
     &     pickup_write_mnc, pickup_read_mnc,
     &     timeave_mnc, snapshot_mnc, monitor_mnc, autodiff_mnc

C     ===  PARM_MNC_C Common Block  ===
C     mnc_outdir_str   :: name of the output directory
C     mnc_indir_str    :: name of the input directory
      COMMON /PARM_MNC_C/
     &     mnc_outdir_str,
     &     mnc_indir_str
      CHARACTER*(MAX_LEN_FNAM) mnc_outdir_str
      CHARACTER*(MAX_LEN_FNAM) mnc_indir_str


CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
