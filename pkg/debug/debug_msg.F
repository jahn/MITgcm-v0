C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/debug/debug_msg.F,v 1.2.2.1 2003/06/24 23:07:32 heimbach Exp $
C $Name:  $

#include "CPP_OPTIONS.h"

      SUBROUTINE DEBUG_MSG(
     I                text,
     I                myThid )
C     /==========================================================\
C     | SUBROUTINE DEBUG_MSG                                     |
C     | o Prints to STDOUT the text argument                     |
C     |==========================================================|
C     \==========================================================/
      IMPLICIT NONE

C     === Global data ===
#include "SIZE.h"
#include "EEPARAMS.h"

C     === Routine arguments ===
      CHARACTER*(*) text
      INTEGER myThid

C     === Local variables ====
      CHARACTER*(MAX_LEN_MBUF) msgBuf

      _BEGIN_MASTER( myThid )
      WRITE(msgBuf,'(A11,A40)') 'DEBUG_MSG: ',text
      CALL PRINT_MESSAGE( msgBuf,
     &   standardMessageUnit, SQUEEZE_RIGHT, myThid )
      _END_MASTER( )

      RETURN
      END
