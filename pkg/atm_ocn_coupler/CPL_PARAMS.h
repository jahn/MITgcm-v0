C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/atm_ocn_coupler/CPL_PARAMS.h,v 1.3 2006/06/15 23:29:17 jmc Exp $
C $Name:  $

C     *==========================================================*
C     | CPL_PARAMS.h
C     |  - parameter for the Coupler, holds in common block
C     *==========================================================*
      
C--   COMMON /CPL_PAR_I/: Integer parameters
C     nCouplingSteps   :: Number of coupling steps
      COMMON /CPL_PAR_I/
     &     nCouplingSteps
      INTEGER nCouplingSteps
