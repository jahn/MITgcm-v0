C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/dic/dic_ad_check_lev2_dir.h,v 1.1 2008/04/24 21:32:13 gforget Exp $
C $Name:  $

#ifdef ALLOW_DIC

C common CARBON_NEEDS
CADJ STORE pH                = tapelev2, key = ilev_2
CADJ STORE fice              = tapelev2, key = ilev_2
CADJ STORE silica            = tapelev2, key = ilev_2
CADJ STORE atmospco2         = tapelev2, key = ilev_2

C common dic_load
CADJ STORE dicwind0,dicwind1   = tapelev2, key = ilev_2
CADJ STORE ice0,ice1         = tapelev2, key = ilev_2
CADJ STORE atmosp0,atmosp1   = tapelev2, key = ilev_2
CADJ STORE silica0,silica1   = tapelev2, key = ilev_2
#ifdef ALLOW_FE
CADJ STORE feinput0,feinput1 = tapelev2, key = ilev_2
#endif

CADJ STORE gsm_s             = tapelev2, key = ilev_2
CADJ STORE co2atmos          = tapelev2, key = ilev_2
CADJ STORE total_atmos_carbon  = tapelev2, key = ilev_2

#endif /* ALLOW_DIC */

