C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/ptracers/PTRACERS_SIZE.h,v 1.3 2004/09/17 23:02:01 heimbach Exp $
C $Name:  $

#ifdef ALLOW_PTRACERS

CBOP
C    !ROUTINE: PTRACERS_SIZE.h
C    !INTERFACE:
C #include PTRACERS_SIZE.h
 
C    !DESCRIPTION:
C Contains passive tracer array size (number of tracers).

C PTRACERS_num defines how many passive tracers are allocated/exist.
C  and is set here (default 1)
C
C     Number of tracers
      INTEGER PTRACERS_num
      PARAMETER(PTRACERS_num = 1 )

#ifdef ALLOW_AUTODIFF_TAMC
      INTEGER    maxpass
      PARAMETER( maxpass     = PTRACERS_num + 2 )
#endif

CEOP
#endif /* ALLOW_PTRACERS */

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
