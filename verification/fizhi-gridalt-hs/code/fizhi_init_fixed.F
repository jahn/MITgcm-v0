C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/fizhi-gridalt-hs/code/fizhi_init_fixed.F,v 1.4 2012/03/20 19:46:17 jmc Exp $
C $Name:  $

#include "FIZHI_OPTIONS.h"
       SUBROUTINE FIZHI_INIT_FIXED (myThid)
c-----------------------------------------------------------------------
c  Routine to initialise the fizhi package.
c
c  Input: myThid       - Process number calling this routine
c
c  Notes:
c   1) This routine is the interface to read input datasets and set
c      other fixed variables for fizhi
c      the datasets are:
c         vegetation (data for each tile at every grid point)
c         ozone (varies with lat, height and time - read it all in
c                   now and interpolate between values later)
c      the other fixed parameters are:
c         N2O, Methane (vary with space)
c         CO2, CFC11, CFC12, CFC22 (set to a global value)
c   3) For now, the fizhi package contains the alarms and clocks
c      routines, so this routine will also initialize the alarms.
c-----------------------------------------------------------------------
       IMPLICIT NONE
#include "SIZE.h"
#include "fizhi_SIZE.h"
#include "fizhi_land_SIZE.h"
#include "EEPARAMS.h"
#include "fizhi_chemistry_coms.h"
#include "fizhi_earth_coms.h"
#include "fizhi_land_coms.h"
#include "fizhi_ocean_coms.h"
#include "chronos.h"
#include "gridalt_mapping.h"
#include "GRID.h"
#include "PARAMS.h"

       INTEGER myThid

       INTEGER i,j,L,bi,bj
       INTEGER im1, im2, jm1, jm2, idim2, jdim2
       INTEGER nymdb,nhmsb
       CHARACTER*40 vegdata
       _RL pressure0(Nrphys+1)
       _RL pressure(Nrphys)
       _RL lats(sNx,sNy,nSx,nSy), lons(sNx,sNy,nSx,nSy)
       _RL fracland(sNx,sNy,nSx,nSy)

       idim2 = sNx+OLx
       jdim2 = sNy+OLy
       im1 = 1
       im2 = sNx
       jm1 = 1
       jm2 = sNy
       nymdb = nymd0
       nhmsb = nhms0

#ifdef ALLOW_MNC
       if (useMNC) then
        call fizhi_mnc_init(myThid)
       endif
#endif

#ifdef ALLOW_DIAGNOSTICS
       if ( useDiagnostics ) then
        call fizhi_diagnostics_init( myThid )
       endif
#endif

       call fizhi_alarms(nymdb,nhmsb,deltaTClock)

       do bj = myByLo(myThid), myByHi(myThid)
       do bi = myBxLo(myThid), myBxHi(myThid)
       do j = jm1,jm2
       do i = im1,im2
        lons(i,j,bi,bj) = xC(i,j,bi,bj)
        lats(i,j,bi,bj) = yC(i,j,bi,bj)
       enddo
       enddo
       enddo
       enddo
       vegdata = 'veg19232.data'
       call fizhi_init_veg ( myThid, vegdata,im2,jm2,nSx,nSy,
     &         nSx*nPx,nSy*nPy,maxtyp,nchp,nchptot,nchpland,lons,lats,
     &         surftype,tilefrac,igrd,ityp,chfr,chlt,chlon)

C And now fill the earth export landtype
       do bj = myByLo(myThid), myByHi(myThid)
       do bi = myBxLo(myThid), myBxHi(myThid)
        call get_landfrac(im2,jm2,nSx,nSy,bi,bj,maxtyp,
     &        surftype,tilefrac,fracland(1,1,bi,bj))
        do j=jm1,jm2
        do i=im1,im2
         landtype(i,j,bi,bj) = surftype(i,j,1,bi,bj)
         if(fracland(i,j,bi,bj).ge.0.3.and.surftype(i,j,1,bi,bj).ge.100)
     &            landtype(i,j,bi,bj) = surftype(i,j,2,bi,bj)
         if(sice(i,j,bi,bj).ne.0.0)landtype(i,j,bi,bj) = 101
        enddo
        enddo
       enddo
       enddo

C Compute pressure profile to get methane and n2o values
C     - First bottom-up (in mb)

       pressure0(1)=1000.
       do L = 2,Nrphys+1
        pressure0(L)=pressure0(L-1)-dpphys0(1,1,L-1,1,1)/100.
       enddo
C Now flip pressure to a top-down array and average to mid levels
C     to send to fizhi init chem
       do L = 1,Nrphys
        pressure(L)=(pressure0(Nrphys+2-L)+pressure0(Nrphys+1-L))/2.
       enddo

       call fizhi_init_chem(myThid,
     &      nlatsoz,nlevsoz,ntimesoz,latsoz,levsoz,ozone,
     &      nlatsq,nlevsq,ntimesq,latsq,levsq,stratq,
     &      Nrphys,pressure,n2o,methane,co2,cfc11,cfc12,cfc22)

       do bj = myByLo(myThid), myByHi(myThid)
       do bi = myBxLo(myThid), myBxHi(myThid)
        do j=jm1,jm2
        do i=im1,im2
         phis_var(i,j,bi,bj) = 0.
        enddo
        enddo
       enddo
       enddo

C Finally, grab unit numbers for reading sst and sea ice
C   (held in common block fizhi ocean coms)

c      call mdsfindunit( kice, myThid )
c      open(kice)
c      call mdsfindunit( ksst, myThid )
c      open(ksst)

       return
       end
