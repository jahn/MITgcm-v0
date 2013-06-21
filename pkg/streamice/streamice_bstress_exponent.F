C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/streamice/streamice_bstress_exponent.F,v 1.3 2013/06/21 20:49:50 jmc Exp $
C $Name:  $

#include "CPP_OPTIONS.h"

      _RL FUNCTION STREAMICE_BSTRESS_EXP (speed,m)

       _RL speed, m
!       _RL SLOPE_LIMITER

        STREAMICE_BSTRESS_EXP = speed**(m-1)

       RETURN
       END
