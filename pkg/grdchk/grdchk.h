
c     ==================================================================
c     HEADER GRADIENT_CHECK
c     ==================================================================
c
c     o Header for doing gradient checks with the ECCO ocean state
c       estimation tool.
c
c     started: Christian Eckert eckert@mit.edu  01-Mar-2000
c
c     changed: Christian Eckert eckert@mit.edu
c              heimbach@mit.edu 24-Feb-2003
c
c
c     ==================================================================
c     HEADER GRADIENT_CHECK
c     ==================================================================

c     maxgrdchecks - maximum number of gradient checks done per tile.

      integer     maxgrdchecks
      parameter ( maxgrdchecks = 4000 )

      common /grdchkparms_r/
     &                       grdchk_eps
      _RL     grdchk_eps

      common /grdchkparms_l/
     &                       useCentralDiff
      logical useCentralDiff

      common /grdchkparms_i/
     &                       nbeg,
     &                       nend,
     &                       nstep,
     &                       grdchkvarindex,
     &                       grdchkwhichproc
      integer nbeg
      integer nend
      integer nstep
      integer grdchkvarindex
      integer grdchkwhichproc

      common /grdchk_r/
     &                  fcrmem, fcppmem, fcpmmem,
     &                  xxmemref, xxmempert,
     &                  gfdmem, adxxmem, ftlxxmem,
     &                  ratioadmem, ratioftlmem
      _RL fcrmem      ( maxgrdchecks )
      _RL fcppmem     ( maxgrdchecks )
      _RL fcpmmem     ( maxgrdchecks )
      _RL xxmemref    ( maxgrdchecks )
      _RL xxmempert   ( maxgrdchecks )
      _RL gfdmem      ( maxgrdchecks )
      _RL adxxmem     ( maxgrdchecks )
      _RL ftlxxmem    ( maxgrdchecks )
      _RL ratioadmem  ( maxgrdchecks )
      _RL ratioftlmem ( maxgrdchecks )

      common /grdchk_i/
     &                  ncvarcomp, maxncvarcomps,
     &                  nwettile,
     &                  irecmem,
     &                  bimem, bjmem,
     &                  ilocmem,jlocmem,klocmem,
     &                  ichkmem, icompmem, itestmem, ierrmem
      integer ncvarcomp
      integer maxncvarcomps
      integer nwettile( nsx,nsy,nr )
      integer irecmem ( maxgrdchecks )
      integer bjmem   ( maxgrdchecks )
      integer bimem   ( maxgrdchecks )
      integer klocmem ( maxgrdchecks )
      integer jlocmem ( maxgrdchecks )
      integer ilocmem ( maxgrdchecks )
      integer ichkmem ( maxgrdchecks )
      integer icompmem( maxgrdchecks )
      integer itestmem( maxgrdchecks )
      integer ierrmem ( maxgrdchecks )

c     ==================================================================
c     END OF HEADER GRADIENT_CHECK
c     ==================================================================


