C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/thsice/thsice_ad_check_lev2_dir.h,v 1.4 2007/10/09 00:12:13 jmc Exp $
C $Name:  $

CADJ STORE iceMask   = tapelev2, key = ilev_2
CADJ STORE iceHeight  = tapelev2, key = ilev_2
CADJ STORE snowHeight = tapelev2, key = ilev_2
CADJ STORE snowAge  = tapelev2, key = ilev_2
CADJ STORE Tsrf     = tapelev2, key = ilev_2
CADJ STORE Qice1    = tapelev2, key = ilev_2
CADJ STORE Qice2    = tapelev2, key = ilev_2
CADJ STORE hOceMxL  = tapelev2, key = ilev_2
CADJ STORE ocefwfx = tapelev2, key = ilev_2
CADJ STORE oceqnet = tapelev2, key = ilev_2
CADJ STORE ocesflx = tapelev2, key = ilev_2

CADJ STORE saltflux = tapelev2, key = ilev_2

#ifdef ATMOSPHERIC_LOADING
CADJ STORE siceload = tapelev2, key = ilev_2
#endif
