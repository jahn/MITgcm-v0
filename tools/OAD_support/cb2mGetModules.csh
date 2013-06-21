#!/bin/csh -f
set fileName=${1:r}
set awkScript=${2}    
echo '      MODULE '${fileName}_mod   > ${fileName}_temp
echo '#include "CPP_OPTIONS.h"'      >> ${fileName}_temp
echo '#include "CPP_EEOPTIONS.h"'    >> ${fileName}_temp
if ( ${fileName} == 'DIC_LOAD' ) then
  echo '#include "DIC_OPTIONS.h"'    >> ${fileName}_temp
endif
if ( ${fileName} == 'GAD' ) then
  echo '#include "GAD_OPTIONS.h"'    >> ${fileName}_temp
endif
if ( ${fileName} == 'GMREDI' ) then
  echo '#include "GMREDI_OPTIONS.h"'    >> ${fileName}_temp
endif
if ( ${fileName} == 'MOM_VISC' ) then
  echo '#include "MOM_COMMON_OPTIONS.h"'    >> ${fileName}_temp
endif
if ( ${fileName} == 'SHAP_FILT' ) then
  echo '#include "SHAP_FILT_OPTIONS.h"'    >> ${fileName}_temp
endif
if ( ${fileName} == 'STREAMICE' ) then
  echo '#include "STREAMICE_OPTIONS.h"'    >> ${fileName}_temp
endif
if ( ${fileName} != 'SIZE' &&  ${fileName} != 'MNC_COMMON' &&  ${fileName} != 'EEPARAMS' ) then
  echo '      use SIZE_mod'          >> ${fileName}_temp
endif
if ( ${fileName} != 'EEPARAMS' &&  ${fileName} != 'SIZE' &&  ${fileName} != 'MNC_COMMON' ) then
  echo '      use EEPARAMS_mod'      >> ${fileName}_temp
endif
if ( ${fileName} != 'PARAMS' && ${fileName} != 'EEPARAMS' &&  ${fileName} != 'SIZE' &&  ${fileName} != 'MNC_COMMON' && ${fileName} != 'GAD' && ${fileName} != 'GRID' ) then
  echo '      use PARAMS_mod'	     >> ${fileName}_temp
endif
if ( ${fileName} == 'ctrl' || ${fileName} == 'ctrl_dummy' || ${fileName} == 'CTRL_GENARR' ) then
  echo '      use CTRL_SIZE_mod'     >> ${fileName}_temp
endif
if ( ${fileName} == 'PTRACERS_FIELDS' || ${fileName} == 'PTRACERS_PARAMS' || \
     ${fileName} == 'PTRACERS_START' || ${fileName} == 'PTRACERS_TAVE' || \
     ${fileName} == 'GCHEM_FIELDS' ) then
  echo '      use PTRACERS_SIZE_mod' >> ${fileName}_temp
endif
#echo awk -f ${awkScript} ${fileName}.h   
awk -f ${awkScript} ${fileName}.h | grep -v mpif.h   >> ${fileName}_temp
echo '      END MODULE' ${fileName}_mod   >> ${fileName}_temp
cp ${fileName}_temp ${fileName}_mod.FF90
\rm ${fileName}_temp
