C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/bling/bling_ad_check_lev2_dir.h,v 1.3 2016/09/12 20:00:27 mmazloff Exp $
C $Name:  $

#ifdef ALLOW_BLING

C common CARBON_NEEDS
CADJ STORE pH                = tapelev2, key = ilev_2
CADJ STORE fice              = tapelev2, key = ilev_2
CADJ STORE silica            = tapelev2, key = ilev_2

CADJ STORE irr_mem           = tapelev2, key = ilev_2
CADJ STORE phyto_sm          = tapelev2, key = ilev_2 
CADJ STORE phyto_lg          = tapelev2, key = ilev_2 
CADJ STORE phyto_diaz        = tapelev2, key = ilev_2
CADJ STORE chl               = tapelev2, key = ilev_2

CADJ STORE atmosp0        = tapelev2, key = ilev_2
CADJ STORE atmosp1        = tapelev2, key = ilev_2
CADJ STORE feinput0       = tapelev2, key = ilev_2
CADJ STORE feinput1       = tapelev2, key = ilev_2
CADJ STORE ice0           = tapelev2, key = ilev_2
CADJ STORE ice1           = tapelev2, key = ilev_2
CADJ STORE silica0        = tapelev2, key = ilev_2
CADJ STORE silica1        = tapelev2, key = ilev_2
CADJ STORE dicwind0       = tapelev2, key = ilev_2
CADJ STORE dicwind1       = tapelev2, key = ilev_2

#ifdef ALLOW_BLING_COST
CADJ STORE totcost  = tapelev2, key = ilev_2
#endif

#endif /* ALLOW_BLING */

