C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/model/inc/EOS.h,v 1.3 2003/02/18 15:12:17 jmc Exp $
C $Name:  $
CBOP
C    !ROUTINE: EOS.h
C    !INTERFACE:
C    include EOS.h
C    !DESCRIPTION: \bv
C     *==========================================================*
C     | EOS.h                                                  
C     | o Header file defining coefficients for equation of state.
C     *==========================================================*
C     | The values from the model standard input file are         
C     | stored into the variables held here.                   
C     *==========================================================*
C     \ev
CEOP

C     PARAMETER SItoBar
      _RL SItoBar, SItodBar
      PARAMETER ( SItoBar  = 1. _d -05 )
      PARAMETER ( SItodBar = 1. _d -04 )

C Linear equation of state
C     tAlpha    :: Linear EOS thermal expansion coefficient ( 1/degree ).
C     sBeta     :: Linear EOS haline contraction coefficient.
      COMMON /PARM_EOS_LIN/ tAlpha,sBeta,equationOfState
      _RL tAlpha
      _RL sBeta
      character*(6) equationOfState

C Equation of State (polynomial coeffients)
      COMMON /PARM_EOS_NL/ eosC,eosSig0,eosRefT,eosRefS
      _RL eosC(9,Nr+1),eosSig0(Nr+1),eosRefT(Nr+1),eosRefS(Nr+1)

C Full Equation of State
C     eosType = 'JMD95' (Jackett and McDougall 1995, JPO)
C     eosType = 'UNESCO' (Millero et al. 1980, DSR)
C     COMMON /PARM_EOS_JMD95/ 
C     eosJMDCFw  :: of fresh water at pressure 0
C     eosJMDCSw  :: of sea water at pressure 0
C     eosJMDCKFw :: of secant bulk modulus K of fresh water at pressure 0
C     eosJMDCKSw :: of secant bulk modulus K of sea water at pressure 0
C     eosJMDCKP  :: of secant bulk modulus K at pressure p
C     eosType = 'DJWF02' (McDougall et al. 2002, JAOT, submitted)
C     COMMON /PARM_EOS_MDJWF/ 
C     eosMDJWFnum :: coefficients of numerator
C     eosMDJWFden :: coefficients of denominator
C     end nonlinear equation of state
      _RL eosJMDCFw(6), eosJMDCSw(9)
      _RL eosJMDCKFw(5), eosJMDCKSw(7), eosJMDCKP(14)
      COMMON /PARM_EOS_JMD95/
     &     eosJMDCFw, eosJMDCSw, eosJMDCKFw, eosJMDCKSw, eosJMDCKP
      _RL eosMDJWFnum(0:11), eosMDJWFden(0:12)
      COMMON /PARM_EOS_MDJWF/ 
     &     eosMDJWFnum, eosMDJWFden

C     pressure :: global absolute pressure variable needed for the 
C                 nonlinear equation of state
c     _RL pressure(1-OLx:sNx+OLx,1-OLy:sNy+OLy,1:Nr,nSx,nSy)
c     COMMON /EOS_PRESSURE/ pressure
