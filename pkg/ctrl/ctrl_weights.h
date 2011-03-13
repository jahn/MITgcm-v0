C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/ctrl/ctrl_weights.h,v 1.9 2011/03/13 22:25:56 heimbach Exp $
C $Name:  $

c     Define dummy weights as a placeholder
      common /ctrl_weights_dummy_r/
     &                        wtheta, wsalt,
     &                        wuvvel, wetan, wuvel, wvvel,
     &                        wdiffkr, wkapgm, wkapredi,
     &                        wedtaux, wedtauy

      _RL wtheta   ( nr,nsx,nsy )
      _RL wsalt    ( nr,nsx,nsy )
      _RL wuvvel   ( nr,nsx,nsy )
      _RL wuve l   ( nr,nsx,nsy )
      _RL wvvel    ( nr,nsx,nsy )
      _RL wetan    ( snx,sny,nsx,nsy )
      _RL wdiffkr  ( nr,nsx,nsy )
      _RL wkapgm   ( nr,nsx,nsy )
      _RL wkapredi ( nr,nsx,nsy )
      _RL wedtaux ( nr,nsx,nsy )
      _RL wedtauy ( nr,nsx,nsy )

#if (defined (ALLOW_OBCSN_COST_CONTRIBUTION) || defined (ALLOW_OBCSN_CONTROL))
      common /ctrl_cost_weights_obcsn/
     &                      wobcsn, wobcsnLev
      _RL wobcsn     (                      nr,nobcs)
      _RL wobcsnLev  (1-olx:snx+olx,nr,nsx,nsy,nobcs)
#endif
#if (defined (ALLOW_OBCSS_COST_CONTRIBUTION) || defined (ALLOW_OBCSS_CONTROL))
      common /ctrl_cost_weights_obcss/
     &                      wobcss, wobcssLev
      _RL wobcss     (                      nr,nobcs)
      _RL wobcssLev  (1-olx:snx+olx,nr,nsx,nsy,nobcs)
#endif
#if (defined (ALLOW_OBCSW_COST_CONTRIBUTION) || defined (ALLOW_OBCSW_CONTROL))
      common /ctrl_cost_weights_obcsw/
     &                      wobcsw, wobcswLev
      _RL wobcsw     (                      nr,nobcs)
      _RL wobcswLev  (1-oly:sny+oly,nr,nsx,nsy,nobcs)
#endif
#if (defined (ALLOW_OBCSE_COST_CONTRIBUTION) || defined (ALLOW_OBCSE_CONTROL))
      common /ctrl_cost_weights_obcse/
     &                      wobcse, wobcseLev
      _RL wobcse     (                      nr,nobcs)
      _RL wobcseLev  (1-oly:sny+oly,nr,nsx,nsy,nobcs)
#endif

#if (defined (ALLOW_COST_HFLUXM) || defined (ALLOW_HFLUXM_CONTROL))
c     whfluxm       - weight for heat flux.
      common /cost_weights_r/ whfluxm
      _RL whfluxm (1-olx:snx+olx,1-oly:sny+oly,   nsx,nsy)
#endif

