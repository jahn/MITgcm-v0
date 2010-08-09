C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/autodiff/AUTODIFF.h,v 1.7 2010/08/09 16:05:22 gforget Exp $
C $Name:  $

      integer ilev_1
      integer ilev_2
      integer ilev_3
      integer ilev_4
      integer max_lev2
      integer max_lev3
      integer max_lev4
      integer NDV3D, NDV2D, NEXF1, NEXF2, NCTRL1, NOB, NSI
#ifdef ALLOW_ADAMSBASHFORTH_3
      PARAMETER (NDV3D  = 16)
#else
      PARAMETER (NDV3D  = 12)
#endif
      PARAMETER (NDV2D  = 23)
      PARAMETER (NEXF1  = 21)
      PARAMETER (NEXF2  = 18)
      PARAMETER (NCTRL1 = 18)
      PARAMETER (NOB = 18)
      PARAMETER (NSI = 19)	
      _RL StoreDynVars3D
     &    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,Nr,nSx,nSy,NDV3D)
      _RL StoreDynVars2D
     &    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy,NDV2D)
      _RL StoreEXF1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy,NEXF1)
      _RL StoreEXF2(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy,NEXF2)
      _RL StoreCTRLS1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy,NCTRL1)
      _RL StoreOBCSN(1-Olx:sNx+Olx,Nr,nSx,nSy,NOB)
      _RL StoreOBCSS(1-Olx:sNx+Olx,Nr,nSx,nSy,NOB)
      _RL StoreOBCSE(1-OLy:sNy+OLy,Nr,nSx,nSy,NOB)
      _RL StoreOBCSW(1-OLy:sNy+OLy,Nr,nSx,nSy,NOB)
      _RL StoreSEAICE(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy,NSI)

      COMMON /AUTODIFF_STORE_DYN/
     &       StoreDynVars3D,
     &       StoreDynVars2D
      COMMON /AUTODIFF_STORE_EXF_FLUX/
     &       StoreEXF1
      COMMON /AUTODIFF_STORE_EXF_ATMOS/
     &       StoreEXF2
      COMMON /AUTODIFF_STORE_CTRL/
     &       StoreCTRLS1
      COMMON /AUTODIFF_STORE_OBCSN/
     &       StoreOBCSN
      COMMON /AUTODIFF_STORE_OBCSS/
     &       StoreOBCSS
      COMMON /AUTODIFF_STORE_OBCSE/
     &       StoreOBCSE
      COMMON /AUTODIFF_STORE_OBCSW/
     &       StoreOBCSW
      COMMON /AUTODIFF_STORE_SEAICE/
     &       StoreSEAICE

