C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/exf/exf_ad_check_lev3_dir.h,v 1.17 2012/03/22 04:13:18 heimbach Exp $
C $Name:  $

#ifdef ALLOW_EXF

CADJ STORE StoreEXF1    = tapelev3, key = ilev_3
CADJ STORE StoreEXF2    = tapelev3, key = ilev_3
CADJ STORE StoreCTRLS1  = tapelev3, key = ilev_3


# ifdef ALLOW_HFLUX_CONTROL
CADJ STORE xx_hflux0     = tapelev3, key = ilev_3
CADJ STORE xx_hflux1     = tapelev3, key = ilev_3
# endif
# ifdef ALLOW_SFLUX_CONTROL
CADJ STORE xx_sflux0     = tapelev3, key = ilev_3
CADJ STORE xx_sflux1     = tapelev3, key = ilev_3
# endif
# ifdef ALLOW_USTRESS_CONTROL
CADJ STORE xx_tauu0      = tapelev3, key = ilev_3
CADJ STORE xx_tauu1      = tapelev3, key = ilev_3
# endif
# ifdef ALLOW_VSTRESS_CONTROL
CADJ STORE xx_tauv0      = tapelev3, key = ilev_3
CADJ STORE xx_tauv1      = tapelev3, key = ilev_3
# endif
# ifdef ALLOW_SST_CONTROL
CADJ STORE xx_sst0      = tapelev3, key = ilev_3
CADJ STORE xx_sst1      = tapelev3, key = ilev_3
# endif
# ifdef ALLOW_SSS_CONTROL
CADJ STORE xx_sss0      = tapelev3, key = ilev_3
CADJ STORE xx_sss1      = tapelev3, key = ilev_3
# endif

#endif /* ALLOW_EXF */
