C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/Attic/PARAMS_MACROS.h,v 1.2 2001/02/04 14:38:45 cnh Exp $
C $Name:  $
C
C     /==========================================================\
C     | PARAMS_MACROS.h                                          |
C     |==========================================================|
C     | These macros are used to substitute definitions for      |
C     | PARAMS.h variables for particular configurations.        |
C     | In setting these variables the following convention      |
C     | applies.                                                 |
C     | define phi_CONST   - Indicates the variable phi is fixed |
C     |                      in X, Y and Z.                      |
C     | define phi_FX      - Indicates the variable phi only     |  
C     |                      varies in X (i.e.not in X or Z).    |
C     | define phi_FY      - Indicates the variable phi only     |  
C     |                      varies in Y (i.e.not in X or Z).    |
C     | define phi_FXY     - Indicates the variable phi only     |  
C     |                      varies in X and Y ( i.e. not Z).    |
C     \==========================================================/

#undef    FCORI_CONST   
#undef    FCORI_FX
#undef    FCORI_FY
#include "FCORI_MACROS.h"
