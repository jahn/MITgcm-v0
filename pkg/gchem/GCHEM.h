C $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/pkg/gchem/GCHEM.h,v 1.5 2004/01/28 18:49:05 stephd Exp $
C $Name:  $

#ifdef ALLOW_PTRACERS
#ifdef ALLOW_GCHEM

CBOP
C    !ROUTINE: GCHEM.h
C    !INTERFACE:
 
C    !DESCRIPTION:
C Contains tracer parameters and input files for chemical tracers.
C These can be read in from data.gchem
C
C  tIter0     : : timestep when tracer is initialized (default 0)
C  nsubtime   : : number of chemistry timesteps per deltaTtracer
C                 (default 1) 
C  WindFile   : : file name of wind speeds that may be needed for
C                 biogeochemical experiments
C  AtmospFile : : file name of atmospheric pressure that may be needed for
C                 biogeochemical experiments
C  IceFile    : : file name of seaice fraction that may be needed for
C                 biogeochemical experiments
C  IronFile   : : file name of aeolian iron flux that may be needed for
C                 biogeochemical experiments
C  SilicaFile : : file name of surface silica that may be needed for
C                 biogeochemical experiments

C  
      INTEGER tIter0
      INTEGER nsubtime
      CHARACTER*(MAX_LEN_FNAM) WindFile
      CHARACTER*(MAX_LEN_FNAM) AtmospFile
      CHARACTER*(MAX_LEN_FNAM) IceFile
      CHARACTER*(MAX_LEN_FNAM) IronFile
      CHARACTER*(MAX_LEN_FNAM) SilicaFile

      COMMON /GCHEM_PARAMS/
     &                   tIter0,
     &                   WindFile,
     &                   AtmospFile,
     &                   IceFile,
     &                   IronFile,
     &                   SilicaFile,
     &                   nsubtime
      NAMELIST /GCHEM_PARM01/
     &                   tIter0,
     &                   WindFile,
     &                   IceFile,
     &                   AtmospFile,
     &                   IronFile,
     &                   SilicaFile,
     &                   nsubtime
CEOP

#endif
#endif /* ALLOW_PTRACERS */
