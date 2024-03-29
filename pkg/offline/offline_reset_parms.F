C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/offline/offline_reset_parms.F,v 1.4 2015/07/18 21:49:08 jmc Exp $
C $Name:  $

#include "OFFLINE_OPTIONS.h"

C !INTERFACE: ==========================================================
      SUBROUTINE OFFLINE_RESET_PARMS( myThid )

C !DESCRIPTION:
C reset some of the main-code parameters for offline calculation

C !USES: ===============================================================
      IMPLICIT NONE
#include "SIZE.h"
#include "EEPARAMS.h"
#include "PARAMS.h"
#include "OFFLINE.h"

C !INPUT PARAMETERS: ===================================================
C  myThid         :: my Thread Id. number
      INTEGER myThid
CEOP

C     !FUNCTIONS:
c     INTEGER  ILNBLNK
c     EXTERNAL ILNBLNK

C     !LOCAL VARIABLES:
C     msgBuf      :: Informational/error message buffer
      CHARACTER*(MAX_LEN_MBUF) msgBuf

      _BEGIN_MASTER(myThid)

C-    For off-line calculation, switch off Momentum and Active-tracers (=T,S):
      WRITE(msgBuf,'(A,A)') ' OFFLINE_RESET_PARMS: ',
     &    '=> turn off Temp,Salt & Mom_Stepping flags'
      CALL PRINT_MESSAGE( msgBuf, standardMessageUnit,
     &                    SQUEEZE_RIGHT, myThid )
      tempStepping = .FALSE.
      saltStepping = .FALSE.
      momStepping  = .FALSE.

C-    Switch off dynstat monitor (but keep one @ the end)
c     IF ( monitorFreq.GT.0. ) THEN
c       monitorFreq = endTime
c         WRITE(msgBuf,'(A,A,1PE18.10)') ' OFFLINE_RESET_PARMS: ',
c    &    '=> reset monitorFreq to:', monitorFreq
c         CALL PRINT_MESSAGE( msgBuf, standardMessageUnit,
c    &                        SQUEEZE_RIGHT, myThid )
c     ENDIF

      IF ( Wvelfile .EQ. ' '  ) THEN
C--   Make sure we compute vertical velocity since it is not read from a file
        IF ( .NOT.exactConserv ) THEN
          WRITE(msgBuf,'(A,A)') '** WARNING ** OFFLINE_RESET_PARMS: ',
     &    '=> turn on exactConserv to compute wVel'
          CALL PRINT_MESSAGE( msgBuf, standardMessageUnit,
     &                        SQUEEZE_RIGHT, myThid )
          CALL PRINT_MESSAGE( msgBuf, errorMessageUnit,
     &                        SQUEEZE_RIGHT, myThid )
          exactConserv = .TRUE.
        ENDIF
      ELSE
C--   Vertical velocity is read from a file: make sure it is not re-computed
        IF ( exactConserv ) THEN
          WRITE(msgBuf,'(A,A)') '** WARNING ** OFFLINE_RESET_PARMS: ',
     &    '=> turn off exactConserv to skip wVel calc'
          CALL PRINT_MESSAGE( msgBuf, standardMessageUnit,
     &                        SQUEEZE_RIGHT, myThid )
          CALL PRINT_MESSAGE( msgBuf, errorMessageUnit,
     &                        SQUEEZE_RIGHT, myThid )
          exactConserv = .FALSE.
        ENDIF
      ENDIF

      _END_MASTER(myThid)

      RETURN
      END
