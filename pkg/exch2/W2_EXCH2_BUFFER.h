C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exch2/W2_EXCH2_BUFFER.h,v 1.1 2009/05/12 19:44:59 jmc Exp $
C $Name:  $

CBOP
C     !ROUTINE: W2_EXCH2_BUFFER.h
C     !INTERFACE:
C     #include W2_EXCH2_BUFFER.h

C     !DESCRIPTION:
C     *==========================================================*
C     | W2_EXCH2_BUFFER.h
C     | o Definition of W2-EXCH2 Buffers
C     *==========================================================*
CEOP

C     e2BufrRecSize  :: Exch2 Buffer size
      INTEGER e2BufrRecSize
      PARAMETER ( e2BufrRecSize
     &            = ( (sNx+2*OLx)*2*OLy+(sNy+2*OLy)*2*OLx)*Nr
     &          )

C--   COMMON /W2_EXCH2_BUF_RX/ real type Buffer used by W2-EXCH2
      _RL E2BUFR1_RL( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      _RL E2BUFR2_RL( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      _RS E2BUFR1_RS( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      _RS E2BUFR2_RS( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      _R4 E2BUFR1_R4( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      _R4 E2BUFR2_R4( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      _R8 E2BUFR1_R8( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      _R8 E2BUFR2_R8( e2BufrRecSize, W2_maxNeighbours, nSx, 2 )
      COMMON /W2_EXCH2_BUF_RL/ E2BUFR1_RL, E2BUFR2_RL
      COMMON /W2_EXCH2_BUF_RS/ E2BUFR1_RS, E2BUFR2_RS
      COMMON /W2_EXCH2_BUF_R4/ E2BUFR1_R4, E2BUFR2_R4
      COMMON /W2_EXCH2_BUF_R8/ E2BUFR1_R8, E2BUFR2_R8

C--   COMMON /W2_EXCH2_COMMFLAG/ EXCH2 character Flag for type of communication
      CHARACTER W2_myCommFlag( W2_maxNeighbours, nSx )
      COMMON /W2_EXCH2_COMMFLAG/ W2_myCommFlag

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
