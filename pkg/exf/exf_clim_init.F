c $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exf/Attic/exf_clim_init.F,v 1.1.4.2 2002/11/07 17:07:56 heimbach Exp $

#include "EXF_CPPOPTIONS.h"


      subroutine exf_clim_init(
     I                         mythid
     &                       )

c     ==================================================================
c     SUBROUTINE exf_clim_init
c     ==================================================================
c
c     o This routine initialises the climatologic forcing
c
c     started: Ralf.Giering@FastOpt.de 25-Mai-20000
c
c     ==================================================================
c     SUBROUTINE exf_clim_init
c     ==================================================================

      implicit none

c     == global variables ==

#include "EEPARAMS.h"
#include "SIZE.h"
#include "cal.h"
#include "exf.h"

#include "exf_clim_param.h"

c     == routine arguments ==

      integer mythid

c     == local variables ==

c     == end of interface ==

c     initialize climatology fields
      call exf_init_climtemp( mythid )
      call exf_init_climsalt( mythid )
      call exf_init_climsst(  mythid )
      call exf_init_climsss(  mythid )

      end
