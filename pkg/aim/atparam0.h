C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/aim/Attic/atparam0.h,v 1.1.2.2 2001/01/26 17:54:24 adcroft Exp $
C $Namer: $

      INTEGER ISC
      PARAMETER (ISC=1)

      INTEGER NTRUN, MTRUN, IX
      PARAMETER ( NTRUN=21, MTRUN=21, IX=sNx )   

      INTEGER MX, MX2, IL, NTRUN1, MXP
      PARAMETER (MX=MTRUN+1 , MX2=2*MX)
      PARAMETER (IL=sNy, NTRUN1=NTRUN+1 )
      PARAMETER ( MXP=ISC*MTRUN+1 )
