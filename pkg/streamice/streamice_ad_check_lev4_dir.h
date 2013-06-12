C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/streamice/streamice_ad_check_lev4_dir.h,v 1.1 2013/06/12 21:30:22 dgoldberg Exp $
C $Name:  $

#ifdef ALLOW_STREAMICE

CADJ STORE area_shelf_streamice = tapelev4, key = ilev_4
CADJ STORE streamice_hmask = tapelev4, key = ilev_4
CADJ STORE u_streamice = tapelev4, key = ilev_4
CADJ STORE v_streamice = tapelev4, key = ilev_4
CADJ STORE h_streamice = tapelev4, key = ilev_4
CADJ STORE visc_streamice = tapelev4, key = ilev_4
CADJ STORE tau_beta_eff_streamice = tapelev4, key = ilev_4

#ifdef ALLOW_STREAMICE_2DTRACER
CADJ STORE trac2d
CADJ &     = tapelev4, key = ilev_4
#endif


CADJ STORE cost_func1_streamice
CADJ &     = tapelev4, key = ilev_4

CADJ STORE surf_el_streamice
CADJ &     = tapelev4, key=ilev_4
CADJ STORE float_frac_streamice
CADJ &     = tapelev4, key=ilev_4

CADJ STORE c_basal_friction
CADJ &     = tapelev4, key=ilev_4

# ifdef STREAMICE_HYBRID_STRESS
CADJ STORE visc_streamice_full
CADJ &     = tapelev4, key = ilev_4
# endif

# ifdef ALLOW_GENTIM2D_CONTROL
CADJ STORE bdot_streamice
CADJ &     = tapelev4, key = ilev_4
# endif

#ifdef STREAMICE_TRACER_AB
CADJ STORE GAD_trac_2d
CADJ &     = tapelev4, key = ilev_4
#endif

#endif /* ALLOW_STREAMICE */
