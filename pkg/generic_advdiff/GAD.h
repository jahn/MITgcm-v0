C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/generic_advdiff/GAD.h,v 1.8.4.1 2002/11/07 17:03:41 heimbach Exp $
C $Name:  $

CBOP
C !ROUTINE: GAD.h

C !INTERFACE:
C #include "GAD.h"

C !DESCRIPTION:
C Contains enumerated constants for distinguishing between different
C advection schemes and tracers.
C
C Unfortunately, there is no easy way to make use of the
C tokens in namelist input so for now we have to enter the
C tokens value into "data" (ie. 2 for 2nd order etc.)

C !USES:
#include "GAD_OPTIONS.h"

C !DEFINED PARAMETERS:

C ENUM_CENTERED_2ND :: Centered 2nd order
      INTEGER ENUM_CENTERED_2ND
      PARAMETER(ENUM_CENTERED_2ND=2)

C ENUM_UPWIND_3RD :: 3rd order upwind 
      INTEGER ENUM_UPWIND_3RD
      PARAMETER(ENUM_UPWIND_3RD=3)

C ENUM_CENTERED_4TH :: Centered 4th order
      INTEGER ENUM_CENTERED_4TH
      PARAMETER(ENUM_CENTERED_4TH=4)

C ENUM_FLUX_LIMIT :: Non-linear flux limiter
      INTEGER ENUM_FLUX_LIMIT
      PARAMETER(ENUM_FLUX_LIMIT=77)

C ENUM_DST3 :: 3-DST 
      INTEGER ENUM_DST3
      PARAMETER(ENUM_DST3=30)

C ENUM_DST3_FLUX_LIMIT :: 3-DST flux limited
      INTEGER ENUM_DST3_FLUX_LIMIT
      PARAMETER(ENUM_DST3_FLUX_LIMIT=33)

C oneSixth :: Third/fourth order interpolation factor
      _RL oneSixth
      PARAMETER(oneSixth=1.D0/6.D0)

C Differentiate between tracers (only needed for KPP -  arrgh!!!)
cph                              and for GMRedi arrgh*arrgh!!!)
cph  indices are used for TAF key computations, so need to
cph  running from 1, 2, ...

C GAD_TEMPERATURE :: temperature
      INTEGER GAD_TEMPERATURE
      PARAMETER(GAD_TEMPERATURE=1)
C GAD_TEMPERATURE :: salinity
      INTEGER GAD_SALINITY
      PARAMETER(GAD_SALINITY=2)
C GAD_TR1 :: pssive tracer 1
      INTEGER GAD_TR1
      PARAMETER(GAD_TR1=3)
CEOP
