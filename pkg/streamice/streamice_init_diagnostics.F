C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/streamice/streamice_init_diagnostics.F,v 1.2 2014/04/24 12:02:41 dgoldberg Exp $
C $Name:  $

#include "STREAMICE_OPTIONS.h"

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
CBOP 0
C !ROUTINE: STREAMICE_INIT_FIXED

C !INTERFACE:
      SUBROUTINE STREAMICE_INIT_DIAGNOSTICS( myThid )

C     !DESCRIPTION:
C     Initialize STREAMICE variables that are kept fixed during the run.

C     !USES:
      IMPLICIT NONE
#include "EEPARAMS.h"
#include "SIZE.h"
#include "PARAMS.h"
#include "STREAMICE.h"
#include "STREAMICE_CG.h"
#include "STREAMICE_BDRY.h"
#include "GRID.h"

      INTEGER myThid

#ifdef ALLOW_STREAMICE

      CHARACTER*(MAX_LEN_MBUF) msgBuf
#ifdef ALLOW_DIAGNOSTICS

C     myThid ::  my Thread Id number

      INTEGER       diagNum
      INTEGER       diagMate
      CHARACTER*8   diagName
      CHARACTER*16  diagCode
      CHARACTER*16  diagUnits
      CHARACTER*(80) diagTitle

      diagName  = 'SI_Uvel '
      diagTitle = 'Ice stream x-velocity'
      diagUnits = 'm/a        '
      diagCode  = 'UZ      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_Vvel '
      diagTitle = 'Ice stream y-velocity'
      diagUnits = 'm/a        '
      diagCode  = 'VZ      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_Thick'
      diagTitle = 'Ice stream thickness'
      diagUnits = 'm          '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_area '
      diagTitle = 'Ice stream cell area coverage'
      diagUnits = 'm^2        '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_float'
      diagTitle = 'Ice stream grounding ind'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_hmask'
      diagTitle = 'Ice stream thickness mask'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_usurf'
      diagTitle = 'Ice stream surface x-vel'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_vsurf'
      diagTitle = 'Ice stream surface y-vel'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_ubase'
      diagTitle = 'Ice stream basal x-vel'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_vbase'
      diagTitle = 'Ice stream basal y-vel'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_taubx'
      diagTitle = 'Ice stream basal x-stress'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_tauby'
      diagTitle = 'Ice stream basal y-stress'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI_selev'
      diagTitle = 'Ice stream surface elev'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      diagName  = 'SI2Dtrac'
      diagTitle = 'Ice stream 2d tracer'
      diagUnits = 'none       '
      diagCode  = 'SM      L1      '
      CALL DIAGNOSTICS_ADDTOLIST( diagNum,
     I      diagName, diagCode, diagUnits, diagTitle, 0, myThid )

      WRITE(msgBuf,'(A)') 'ADDED DIAGS TO LIST'
       CALL PRINT_MESSAGE( msgBuf, standardMessageUnit,
     &                     SQUEEZE_RIGHT , 1)


#endif
#endif
      RETURN
      END
