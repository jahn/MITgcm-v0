C--
C--   /FORCON/: Constants for forcing fields (initial. in INPHYS)
C--    SOLC   = Solar constant (area averaged) in W/m^2
C--    ALBSEA = Albedo over sea 
C--    ALBICE = Albedo over sea ice (for ice fraction = 1)
C--    ALBSN  = Albedo over snow (for snow depth > SDALB)
C--    SDALB  = Snow depth corresponding to maximum albedo
C--    SWCAP  = Soil wetness capacity
C--    SWWIL  = Soil wetness at wilting point

      COMMON /FORCON/ SOLC, ALBSEA, ALBICE, ALBSN, SDALB,
     &                SWCAP, SWWIl

 
C      $Id: com_forcon.h,v 1.1.2.1 2001/01/26 00:14:32 cnh Exp $
