C--   /LSMASK/ land-sea masks 
      common /LSMASK/ fmask1(ngp)	! fractional land-sea mask

C--   /FORFIX/ Time invariant forcing fields 
      common /FORFIX/ phi0(ngp),	! surface geopotential
     .                alb0(ngp)		! land-surface albedo

C--   /FORCIN/ Forcing fields 
      common /FORCIN/ sst1(ngp),	! SST
     .                oice1(ngp),	! sea ice fraction
     .                stl1(ngp),	! land-surface temperature
     .                snow1(ngp),	! snow depth (mm water)
     .                soilq1(ngp)	! soil wetness (mm water)

C      $Id: com_forcing1.h,v 1.1.2.1 2001/01/26 00:14:32 cnh Exp $
