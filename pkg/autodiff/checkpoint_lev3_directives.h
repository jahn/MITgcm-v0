C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/autodiff/checkpoint_lev3_directives.h,v 1.22 2004/09/17 23:02:01 heimbach Exp $
C $Name:  $
c
c     store directives for checkpoint level 3
c
c     created: heimbach@mit.edu 10-Jan-2002
c
CADJ STORE gs        = tapelev3, key = ilev_3
CADJ STORE gt        = tapelev3, key = ilev_3
CADJ STORE gtnm1     = tapelev3, key = ilev_3
CADJ STORE gsnm1     = tapelev3, key = ilev_3
CADJ STORE gunm1     = tapelev3, key = ilev_3
CADJ STORE gvnm1     = tapelev3, key = ilev_3
CADJ STORE theta     = tapelev3, key = ilev_3
CADJ STORE salt      = tapelev3, key = ilev_3
CADJ STORE uvel      = tapelev3, key = ilev_3
CADJ STORE vvel      = tapelev3, key = ilev_3
CADJ STORE wvel      = tapelev3, key = ilev_3
CADJ STORE etan      = tapelev3, key = ilev_3
CADJ STORE totphihyd = tapelev3, key = ilev_3
CADJ STORE surfaceforcingTice = tapelev3, key = ilev_3
cnewCADJ STORE ivdconvcount       = tapelev3, key = ilev_3

#ifdef EXACT_CONSERV
CADJ STORE etaH      = tapelev3, key = ilev_3
CADJ STORE dEtaHdt   = tapelev3, key = ilev_3
CADJ STORE PmEpR     = tapelev3, key = ilev_3
cphCADJ STORE hDivFlow  = tapelev3, key = ilev_3
#endif /* EXACT_CONSERV */

#ifdef ALLOW_PASSIVE_TRACER
CADJ STORE tr1       = tapelev3, key = ilev_3
CADJ STORE gtr1nm1   = tapelev3, key = ilev_3
#endif /* ALLOW_PASSIVE_TRACER */

#ifdef ALLOW_CD_CODE
# include "cd_code_ad_check_lev3_dir.h"
#endif /* ALLOW_CD_CODE */

#ifdef ALLOW_EXF
# include "exf_ad_check_lev3_dir.h"
#else /* ALLOW_EXF undef */

CADJ STORE taux0   = tapelev3, key = ilev_3
CADJ STORE taux1   = tapelev3, key = ilev_3
CADJ STORE tauy0   = tapelev3, key = ilev_3
CADJ STORE tauy1   = tapelev3, key = ilev_3
CADJ STORE Qnet0   = tapelev3, key = ilev_3
CADJ STORE Qnet1   = tapelev3, key = ilev_3
CADJ STORE EmPmR0  = tapelev3, key = ilev_3
CADJ STORE EmPmR1  = tapelev3, key = ilev_3
CADJ STORE SST0    = tapelev3, key = ilev_3
CADJ STORE SST1    = tapelev3, key = ilev_3
CADJ STORE SSS0    = tapelev3, key = ilev_3
CADJ STORE SSS1    = tapelev3, key = ilev_3
#ifdef SHORTWAVE_HEATING
CADJ STORE Qsw0    = tapelev3, key = ilev_3
CADJ STORE Qsw1    = tapelev3, key = ilev_3
#endif
#ifdef ATMOSPHERIC_LOADING
CADJ STORE pload0  = tapelev3, key = ilev_3
CADJ STORE pload1  = tapelev3, key = ilev_3
#endif

#endif /* ALLOW_EXF */

#ifdef ALLOW_PTRACERS
# include "ptracers_ad_check_lev3_dir.h"
#endif

#ifdef ALLOW_OBCS
# include "obcs_ad_check_lev3_dir.h"
#endif  /* ALLOW_OBCS */

#ifdef ALLOW_SEAICE
# include "seaice_ad_check_lev3_dir.h"
#endif /* ALLOW_SEAICE */

#ifdef ALLOW_EBM
CADJ STORE fu    = tapelev3, key = ilev_3
CADJ STORE fv    = tapelev3, key = ilev_3
CADJ STORE qnet  = tapelev3, key = ilev_3
CADJ STORE qsw   = tapelev3, key = ilev_3
CADJ STORE sss   = tapelev3, key = ilev_3
CADJ STORE empmr = tapelev3, key = ilev_3
# include "ebm_ad_check_lev3_dir.h"
#endif /* ALLOW_EBM */
