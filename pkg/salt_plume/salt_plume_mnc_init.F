C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/salt_plume/salt_plume_mnc_init.F,v 1.2 2007/11/28 17:55:36 dimitri Exp $
C $Name:  $

#include "SALT_PLUME_OPTIONS.h"

CBOP 0
C     !ROUTINE: SALT_PLUME_MNC_INIT
C     !INTERFACE:
      SUBROUTINE SALT_PLUME_MNC_INIT( myThid )

C     !DESCRIPTION:
C     Initialize MNC lookup tables for Mypackage.

C     !USES:
      IMPLICIT NONE
#include "SIZE.h"
#include "EEPARAMS.h"
#include "PARAMS.h"
#include "SALT_PLUME.h"

C     !INPUT PARAMETERS:
      INTEGER myThid
CEOP

#ifdef ALLOW_SALT_PLUME
#ifdef ALLOW_MNC

      IF (useMNC) THEN

       CALL MNC_CW_ADD_VNAME('saltPlumeFlux', 'Cen_xy_Hn__-__t', 3,4,
     &                       myThid)
       CALL MNC_CW_ADD_VATTR_TEXT('saltPlumeFlux','units',
     &     'psu.kg/m^2/s', myThid)
       CALL MNC_CW_ADD_VATTR_TEXT('saltPlumeFlux','description',
     &     'Net downward salt flux rejected during freezing', myThid)

      ENDIF

#endif /* ALLOW_MNC */
#endif /* ALLOW_SALT_PLUME */

      RETURN
      END
