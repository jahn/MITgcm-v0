C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/halfpipe_streamice/code_ad/CTRL_SIZE.h,v 1.2 2014/11/13 17:02:13 gforget Exp $
C $Name:  $

c     ==================================================================
c     CTRL_SIZE.h
c     ==================================================================

C     Generic control variable array dimension
C     ----------------------------------------
C
C     maxCtrlArr2D :: number of 2-d generic init. ctrl variables
C     maxCtrlArr3D :: number of 3-d generic init. ctrl variables
C     maxCtrlTim2D :: number of 2-d generic tim-varying ctrl variables
C     maxCtrlProc  :: number of pre-processing options per ctrl variable

      integer     maxCtrlArr2D
      parameter ( maxCtrlArr2D = 2 )

      integer     maxCtrlArr3D
      parameter ( maxCtrlArr3D = 1 )

      integer     maxCtrlTim2D
      parameter ( maxCtrlTim2D = 1 )

      integer     maxCtrlProc
      parameter ( maxCtrlProc = 1 )

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
