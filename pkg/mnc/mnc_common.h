C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/mnc/Attic/mnc_common.h,v 1.7 2004/01/27 05:47:32 edhill Exp $
C $Name:  $
C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
C
C     ==========================================
C     MNC : an MITgcm wrapper package for NetCDF
C     ==========================================
C
C     The following common block is the "state" for the MNC interface to
C     NetCDF.  The intent is to keep track of the associations between
C     files, attributes, variables, grids, and dimensions.  These
C     objects are roughly defined as:
C     
C     a dimension:
C     - contains: [ name, size ]
C     - exists per-NetCDF-file
C
C     a grid:
C     - contains *ORDERED* sets of dimensions: [ name, 1+ dim-refs ]
C     - exists per-NetCDF-file
C     - NOTE: when created, the name and dim-refs are embedded in 
C         the NetCDF file attributes for later retrieval
C     - NOTE: grid coordinates are implemented using variables with 
C         special names (eg. lat, lon) and special units 
C         (eg. degree_east)
C     
C     a variable:
C     - contains: [ name, units, 1 grid-ref, data ]
C     - exists per-NetCDF-file
C     - NOTE: is associated with *exactly* one grid
C     
C     an attribute:
C     - contains: [ name, units, data ]
C     - basically, a scalar (non-grid) variable
C     - exists per-NetCDF-file
C     
C     a NetCDF file:
C     - contains: [ name, 0+ attr, 0+ grid-ref, 0+ var-ref ]
C
C     ==================================================
C     MNC "Internals" Implemented using:
C
C     mnc_blank_name    : (convenience) just MNC_MAX_CHAR spaces
C
C     mnc_f_names (fi)  : file names
C     mnc_g_names (gi)  : grid names    <----+-----------+
C     .                                      |           |
C     mnc_f_info (fi,-) : isDEF, fID, Ngrid, g1,ds1,de1, g2,ds2,de2...
C     .                                         |   |       |   |
C     mnc_fd_ind (fi,-) : dim indicies  <-------+---+-------+---+
C     .                             |
C     mnc_d_names (di)  : names  <--+  <--+  |           |
C     mnc_d_ids   (di)  : IDs    <--+  <--+  +-----+-----+
C     mnc_d_size  (di)  : sizes  <--+  <--+        | starting
C     .                                   |        | indicies of
C     mnc_f_alld (fi,di): ndim, id1,id2,id3, ...   | grids in
C     .                                            | mnc_f_info
C     .                                +-----------+
C     .                                |           |
C     mnc_fv_ids (fi,-) : nVar, n1,ID1,ig1, n2,ID2,ig2, ...
C     .                         |           |
C     mnc_v_names (vi)  :   <---+-----------+
C
C     fi  :  file index
C     vi  :  variable index
C     di  :  dimension index
C
C     ==================================================
C     MNC "Convenience Wrapper" Implemented using:
C
C     mnc_cw_names (g)  : Gtype names
C     mnc_cw_ndim  (g)  : number of dimensions
C     mnc_cw_dn   (i,g) : dname1, dname2, ...
C     mnc_cw_dims (i,g) : d1, d2, d3, ...
C     mnc_cw_is   (i,g) : starting indicies: is1, is2, ...
C     mnc_cw_ie   (i,g) : ending indicies:   ie1, ie2, ...
C
C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|

      integer MNC_MAX_ID, MNC_MAX_CHAR, MNC_MAX_INFO
      integer MNC_CW_MAX_I
      parameter ( MNC_MAX_ID   = 1000 )
      parameter ( MNC_MAX_CHAR =  100 )
      parameter ( MNC_MAX_INFO =  100 )
      parameter ( MNC_CW_MAX_I =  100 )

      COMMON /MNC_VARS/
     &     mnc_blank_name, 
     &     mnc_f_names, mnc_g_names, mnc_v_names, 
     &     mnc_d_names, mnc_d_ids,   mnc_d_size, 
     &     mnc_f_info,  mnc_fd_ind,  mnc_fv_ids, 
     &     mnc_f_alld,
     &     mnc_cw_names, mnc_cw_ndim, mnc_cw_dims, 
     &     mnc_cw_dn, mnc_cw_is, mnc_cw_ie

      character*(MNC_MAX_CHAR) mnc_blank_name
      character*(MNC_MAX_CHAR) mnc_f_names(MNC_MAX_ID)
      character*(MNC_MAX_CHAR) mnc_g_names(MNC_MAX_ID)
      character*(MNC_MAX_CHAR) mnc_v_names(MNC_MAX_ID)
      character*(MNC_MAX_CHAR) mnc_d_names(MNC_MAX_ID)
      integer mnc_f_info(MNC_MAX_ID,MNC_MAX_INFO)
      integer mnc_fd_ind(MNC_MAX_ID,MNC_MAX_INFO)
      integer mnc_fv_ids(MNC_MAX_ID,MNC_MAX_INFO)
      integer mnc_f_alld(MNC_MAX_ID,MNC_MAX_INFO)
      integer mnc_d_size(MNC_MAX_ID)
      integer mnc_d_ids(MNC_MAX_ID)

      character*(MNC_MAX_CHAR) mnc_cw_names(MNC_MAX_ID)
      character*(MNC_MAX_CHAR) mnc_cw_dn(MNC_CW_MAX_I,MNC_MAX_ID)
      integer mnc_cw_ndim(MNC_MAX_ID)
      integer mnc_cw_dims(MNC_CW_MAX_I,MNC_MAX_ID)
      integer mnc_cw_is(MNC_CW_MAX_I,MNC_MAX_ID)
      integer mnc_cw_ie(MNC_CW_MAX_I,MNC_MAX_ID)

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
