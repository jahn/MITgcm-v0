C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/dic/DIC_VARS.h,v 1.1 2008/04/04 21:38:56 dfer Exp $
C $Name:  $

C     /==========================================================\
C     | DIC_VARS.h
C     | o Carbon Variables
C     |==========================================================|

       COMMON /CARBON_NEEDS/
     &              AtmospCO2, AtmosP, pH, pCO2, FluxCO2,
     &              wind, FIce, Silica, Kwexch_Pre
      _RL  AtmospCO2(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  AtmosP(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  pH(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  pCO2(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  FluxCO2(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  wind(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  FIce(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  Silica(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  Kwexch_Pre(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

       COMMON /CARBON_CHEM/
     &                     ak0,ak1,ak2,akw,akb,aks,akf,
     &                     ak1p,ak2p,ak3p,aksi,
     &                     ff,ft,st,bt, Ksp_TP_Calc
      _RL  ak0(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  ak1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  ak2(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  akw(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  akb(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  aks(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  akf(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  ak1p(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  ak2p(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  ak3p(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  aksi(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  ff(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  ft(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  st(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  bt(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL  Ksp_TP_Calc(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

       COMMON /OXYGEN_CHEM/
     &              oA0,oA1,oA2,oA3,oA4,oA5,
     &              oB0,oB1,oB2,oB3,
     &              oC0       
      _RL oA0,oA1,oA2,oA3,oA4,oA5
      _RL oB0,oB1,oB2,oB3
      _RL oC0

C permil : is conversion factor for mol/m3 to mol/kg
C          assumes uniform (surface) density
C Pa2Atm : for conversion of atmospheric pressure
C          when coming from atmospheric model 
       COMMON /GLOBAL_SURF_MEAN/
     &                          gsm_alk,gsm_s,gsm_t,gsm_dic,
     &                          gsm_c14,permil,Pa2Atm
      _RL  gsm_alk
      _RL  gsm_s
      _RL  gsm_t
      _RL  gsm_DIC
      _RL  gsm_C14
      _RL  permil
      _RL  Pa2Atm

C schmidt number coefficients
      COMMON /SCHMIDT_NO/
     &                    sca1, sca2, sca3, sca4,
     &                    sox1, sox2, sox3, sox4
      _RL  sca1
      _RL  sca2
      _RL  sca3
      _RL  sca4
      _RL  sox1
      _RL  sox2
      _RL  sox3
      _RL  sox4

#ifdef DIC_BIOTIC
C     /==========================================================\
C     | o Biological Carbon Variables
C     |==========================================================|

      COMMON /BIOTIC_NEEDS/
     &     BIOave, CARave, SURave, SUROave, pCO2ave, pHave, 
     &     fluxCO2ave, omegaCave, pfluxave, epfluxave, cfluxave, 
     &     dic_timeave,
     &     alpha, rain_ratio, InputFe, omegaC,
     &     Kpo4, DOPfraction, zcrit, KRemin,
     &     KDOPremin,zca,R_op,R_cp,R_NP, R_FeP,
     &     O2crit, alpfe, KScav, ligand_stab, ligand_tot, KFE,
     &     freefemax, par,
     &     parfrac, k0, lit0,
     &     nlev, QSW_underice

      integer nlev

C     For averages
      _RL BIOave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nR,nSx,nSy)
      _RL CARave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nR,nSx,nSy)
      _RL SURave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL SUROave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL pCO2ave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL pHave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL fluxCO2ave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL OmegaCave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nR,nSx,nSy)
      _RL pfluxave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nR,nSx,nSy)
      _RL epfluxave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nR,nSx,nSy)
      _RL cfluxave(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nR,nSx,nSy)
      _RL DIC_timeave(nSx,nSy,nR)

C     values for biogeochemistry
      _RL par(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL alpha(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL rain_ratio(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL InputFe(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL omegaC(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nR,nSx,nSy)
      _RL Kpo4            
      _RL DOPfraction   
      _RL zcrit
      _RL KRemin
      _RL KDOPremin
      _RL zca
      _RL R_op
      _RL R_cp
      _RL R_NP
      _RL R_FeP
      _RL O2crit
      _RL alpfe
      _RL KScav
      _RL ligand_stab
      _RL ligand_tot
      _RL  KFe
      _RL freefemax
C     values for light limited bio activity
      _RL k0, parfrac, lit0

      LOGICAL QSW_underice
#endif

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
