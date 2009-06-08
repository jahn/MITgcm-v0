C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/mdsio/MDSIO_BUFF_3D.h,v 1.1 2009/06/08 03:32:33 jmc Exp $
C $Name:  $

CBOP
C     !ROUTINE: MDSIO_BUFF_3D.h
C     !INTERFACE:
C     include "MDSIO_BUFF_3D.h"
C
C     !DESCRIPTION:
C     *==========================================================*
C     | MDSIO_BUFF_3D.h
C     | o Shared 3-D Buffers used for I/O
C     *==========================================================*
CEOP

C     size3dBuf  :: buffer 3rd dimension, corresponds to the maximum number
C                   of levels that can be read/written at a time.
C     Note: minimum value = Nr, but in few cases (vertical interpolation,
C           NrPhys from Fizhi, ...)  needs to be larger. Here we pick 2*Nr
C           which should be enough for most applications.
      INTEGER size3dBuf
      PARAMETER ( size3dBuf = 2*Nr )

C--   COMMON /MDS_3D_BUFFERS/  3-D Shared Local Buffers
C     Those buffers have be in common block to be shared by all threads
C shared3dBuf_rx :: Heap storage buffer to which master thread
C                   read-in/write-from data which all threads copy from
C                   (during read) or copy to (during write).
      COMMON /MDS_3D_BUFFERS/ shared3dBuf_r8, shared3dBuf_r4
      Real*8 shared3dBuf_r8( sNx*sNy*size3dBuf*nSx*nSy )
      Real*4 shared3dBuf_r4( sNx*sNy*size3dBuf*nSx*nSy )

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
