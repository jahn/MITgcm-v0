C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/diagnostics/DIAGNOSTICS_SIZE.h,v 1.1 2004/12/13 21:43:54 jmc Exp $
C $Name:  $


C     Diagnostics Array Dimension
C     ---------------------------
C     ndiagMax   :: maximum total number of available diagnostics
C     numlists   :: maximum number of diagnostics list (in data.diagnostics)
C     numperlist :: maximum number of active diagnostics per list (data.diagnostics)
C     numLevels  :: maximum number of levels to write    (data.diagnostics)
C     numfields  :: maximum number of active diagnostics (in data.diagnostics)
C     numdiags   :: maximum size of the storage array for active diagnostics
      INTEGER    ndiagMax
      INTEGER    numlists
      INTEGER    numperlist
      INTEGER    numLevels
      INTEGER    numfields
      INTEGER    numdiags
      PARAMETER( ndiagMax = 500 )
      PARAMETER( numlists = 10, numperlist = 50, numLevels=2*Nr )
      PARAMETER( numdiags = 10 )

      PARAMETER( numfields = numlists*numperlist )

CEH3 ;;; Local Variables: ***
CEH3 ;;; mode:fortran ***
CEH3 ;;; End: ***
