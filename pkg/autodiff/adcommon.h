
CBOP
C     !ROUTINE: adcommon.h 
C     !INTERFACE:
C     include "adcommon.h "
C     !DESCRIPTION: \bv
C     *==========================================================*
C     | CPP_EEMACROS.h                                            
C     *==========================================================*
C--   | common blocks of adjoint variables extracted from
C     | TAMC-/TAF- generated code for use in adjoint support;
C     | Make sure that adjoint common blocks below are up-to-date
C     | w.r.t. current adjoint code.
C     *==========================================================*
C     | CPP_EEMACROS.h                                            
C     *==========================================================*
C     \ev
CEOP

WARNING:
THESE LINES ARE MEANT TO PROVOKE A COMPILER CRASH.
THIS IS ONLY A TEMPLATE FILE.
YOU NEED TO CUSTOMIZE THIS TO YOUR RESPECTIVE SETUP,
E.G. BY PLACING A COPY IN YOUR VERIFICATION DIRECTORY.
IT IS IMPORTANT THAT YOU MAKE SURE THAT THE COMMON BLOCKS
BELOW CORRESPOND TO THE COMMON BLOCKS IN THE AUTOMATICALLY
CREATED ADJOINT CODE.

      common /addynvars_r/ 
     &                     adetan, adetanm1, 
     &                     aduvel, advvel, adwvel, 
     &                     adtheta, adsalt, 
     &                     adgu, adgv, adgt, adgs, 
     &                     adgunm1, adgvnm1, adgtnm1, adgsnm1
      _RL adetan(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL adetanm1(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL adgs(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgsnm1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgt(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgtnm1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgu(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgunm1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgv(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgvnm1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adsalt(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adtheta(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL aduvel(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL advvel(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adwvel(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)

      common /addynvars_cd/ 
     &                      aduveld, advveld,
     &                      adunm1, advnm1, 
     &                      adgucd, adgvcd
      _RL aduveld(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL advveld(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adunm1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL advnm1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgucd(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgvcd(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)

      common /adffields/
     &                   adfu, adfv, adqnet, adempmr, adsst, adsss
      _RL adfu(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL adfv(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL adqnet(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL adempmr(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL adsst(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)
      _RL adsss(1-olx:snx+olx,1-oly:sny+oly,nsx,nsy)

#ifdef ALLOW_TR10_CONTROL
      common /adtr1_r/ 
     &                 adtr1, adgtr1, adgtr1nm1
      _RL adgtr1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adgtr1nm1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
      _RL adtr1(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
#endif

#ifdef ALLOW_DIFFKR_CONTROL
      common /addynvars_diffkr/ 
     &                          addiffkr
      _RL addiffkr(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
#endif

#ifdef ALLOW_KAPGM_CONTROL
      common /addynvars_kapgm/ 
     &                          adkapgm
      _RL adkapgm(1-olx:snx+olx,1-oly:sny+oly,nr,nsx,nsy)
#endif



