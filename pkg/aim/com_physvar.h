C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/com_physvar.h,v 1.4 2002/09/27 20:01:57 jmc Exp $
C $Name:  $

#ifdef ALLOW_AIM

C--   COMMON /PHYGR1/ : Model variables on gaussian grid
C      UG1     = u-wind
C      VG1     = v-wind
C      TG1     = abs. temperature
C      QG1     = specific humidity (g/kg)
C      PHIG1   = geopotential
C      PSLG1   = log. of surface pressure
C      Vsurfsq = Square of surface wind speed (grid position = as T,Q)
      COMMON /PHYGR1/ UG1, VG1, TG1, QG1, PHIG1, PSLG1, Vsurfsq
      _RL UG1(NGP,NLEV,MAX_NO_THREADS)
      _RL VG1(NGP,NLEV,MAX_NO_THREADS)
      _RL TG1(NGP,NLEV,MAX_NO_THREADS)
      _RL QG1(NGP,NLEV,MAX_NO_THREADS)
      _RL PHIG1(NGP,NLEV,MAX_NO_THREADS)
      _RL PSLG1(NGP,MAX_NO_THREADS)
      _RL Vsurfsq(NGP,MAX_NO_THREADS) 

C--   COMMON /PHYGR2/ : Diagnosed upper-air variables
C      SE     = dry static energy
C      RH     = relative humidity
C      QSAT   = saturation specific humidity (g/kg)
      COMMON /PHYGR2/ SE, RH, QSAT
      _RL SE(NGP,NLEV,MAX_NO_THREADS)
      _RL RH(NGP,NLEV,MAX_NO_THREADS)
      _RL QSAT(NGP,NLEV,MAX_NO_THREADS)
      

C--   COMMON /PHYGR3/ : Diagnosed surface variables 
C      PSG    = surface pressure
C      TS     = surface temperature
C      TSKIN  = skin temperature (not yet implemented)
C      CLOUDC = total cloud cover (fraction)
C      PNLEVW = Surface pressure for the computation of the surface fluxes
      COMMON /PHYGR3/ PSG, TS, TSKIN, CLOUDC, PNLEVW
      _RL PSG   (NGP,MAX_NO_THREADS)
      _RL TS    (NGP,MAX_NO_THREADS)
      _RL TSKIN (NGP,MAX_NO_THREADS)
      _RL CLOUDC(NGP,MAX_NO_THREADS)
      _RL PNLEVW(NGP,MAX_NO_THREADS)

C--   COMMON /PHYTEN/ : Physical param. tendencies
C      TT_CNV  =  temperature tendency due to convection
C      QT_CNV  = sp. humidity tendency due to convection
C      TT_LSC  =  temperature tendency due to large-scale condensation
C      QT_LSC  = sp. humidity tendency due to large-scale condensation
C      TT_RSW  =  temperature tendency due to short-wave radiation
C      TT_RLW  =  temperature tendency due to long-wave radiation
C      UT_PBL  =       u-wind tendency due to PBL and diffusive processes
C      VT_PBL  =       v-wind tendency due to PBL and diffusive processes
C      TT_PBL  =  temperature tendency due to PBL and diffusive processes
C      QT_PBL  = sp. humidity tendency due to PBL and diffusive processes
      COMMON /PHYTEN/ TT_CNV, QT_CNV, TT_LSC, QT_LSC, 
     &        TT_RSW, TT_RLW, UT_PBL, VT_PBL, TT_PBL, QT_PBL
      _RL TT_CNV(NGP,NLEV,MAX_NO_THREADS)
      _RL QT_CNV(NGP,NLEV,MAX_NO_THREADS)
      _RL TT_LSC(NGP,NLEV,MAX_NO_THREADS)
      _RL QT_LSC(NGP,NLEV,MAX_NO_THREADS)
      _RL TT_RSW(NGP,NLEV,MAX_NO_THREADS)
      _RL TT_RLW(NGP,NLEV,MAX_NO_THREADS)
      _RL UT_PBL(NGP,NLEV,MAX_NO_THREADS)
      _RL VT_PBL(NGP,NLEV,MAX_NO_THREADS)
      _RL TT_PBL(NGP,NLEV,MAX_NO_THREADS)
      _RL QT_PBL(NGP,NLEV,MAX_NO_THREADS)

C--
C--   COMMON /FLUXES/ : Surface and upper boundary fluxes
C      PRECNV = convective precipitation  [g/(m^2 s)]
C      PRECLS = large-scale precipitation [g/(m^2 s)]
C      CBMF   = cloud-base mass flux 
C      TSR    = top-of-atm. shortwave radiation (downward)
C      SSR    = surface shortwave radiation (downward)
C      SLR    = surface longwave radiation (upward) 
C      OLR    = outgoing longwave radiation (upward)
C      USTR   = u-stress (1: land, 2: sea, 3: weighted average)
C      VSTR   = v-stress (1: land, 2: sea, 3: weighted average)
C      SHF    = sensible heat flux (1: land, 2: sea, 3: w. average)
C      EVAP   = evaporation [g/(m^2 s)] (1: land, 2: sea, 3: w. average)
C      DRAG   = surface Drag term (= Cd*Rho*|V|)
      COMMON /FLUXES/ PRECNV, PRECLS, CBMF, TSR, SSR, SLR, OLR,
     &                USTR, VSTR, SHF, EVAP, T0, Q0, QSAT0,
     &                SLR_DOWN, ST4S, SPEED0, DRAG
      _RL PRECNV  (NGP,MAX_NO_THREADS)
      _RL PRECLS  (NGP,MAX_NO_THREADS)
      _RL CBMF    (NGP,MAX_NO_THREADS)
      _RL TSR     (NGP,MAX_NO_THREADS)
      _RL SSR     (NGP,MAX_NO_THREADS)
      _RL SLR     (NGP,MAX_NO_THREADS)
      _RL OLR     (NGP,MAX_NO_THREADS)
      _RL USTR    (NGP,3,MAX_NO_THREADS)
      _RL VSTR    (NGP,3,MAX_NO_THREADS)
      _RL SHF     (NGP,3,MAX_NO_THREADS)
      _RL EVAP    (NGP,3,MAX_NO_THREADS)
      _RL T0      (NGP,2,MAX_NO_THREADS)
      _RL Q0      (NGP,MAX_NO_THREADS)
      _RL QSAT0   (NGP,2,MAX_NO_THREADS)
      _RL SLR_DOWN(NGP,MAX_NO_THREADS)
      _RL ST4S    (NGP,MAX_NO_THREADS)
      _RL SPEED0  (NGP,MAX_NO_THREADS)
      _RL DRAG    (NGP,MAX_NO_THREADS)

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
#endif /* ALLOW_AIM */ 
