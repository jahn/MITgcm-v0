C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/fizhi/fizhi_land_coms.h,v 1.1 2004/06/07 16:57:39 molod Exp $
C $Name:  $

c Land State Common
c -----------------
      common /land_state/ tcanopy, tdeep, ecanopy, 
     . swetshal, swetroot, swetdeep, snodep, capac
      _RL tcanopy(nchp), tdeep(nchp), ecanopy(nchp), swetshal(nchp)
      _RL swetroot(nchp), swetdeep(nchp), snodep(nchp), capac(nchp)

c Land Mapping Common
c -------------------
      common /land_mapping/ chlt, chlon, igrd
      _RL chlt(nchp), chlon(nchp)
      integer igrd(nchp) 
