#! /usr/bin/env bash

#  $Header: /home/jahn/src/cvs2git/MITgcm/20170915-2/gcmpack-all-patch/MITgcm/verification/lab_sea/input_ad/dorun.sh,v 1.3 2013/07/24 00:20:45 jmc Exp $
#  $Name:  $

#  number of additional executions to perform is given by "add_DIVA_runs"
#  and corresponds to "nchklev_3" value in file "code_ad/tamc.h"
add_DIVA_runs=4

if test $# = 0 ; then
    rm -f costfunction*0000 costfinal divided.ctrl snapshot*
#- not MPI run:
    echo "Run $add_DIVA_runs times + final run:"
    for ii in `seq 1 $add_DIVA_runs` ; do
      ./mitgcmuv_ad > output_adm.txt.diva_${ii}
      echo " additional DIVA run # $ii : done"
    done
    ./mitgcmuv_ad > output_adm.txt
else
  if [ $1 -ge 1 ] ; then
    rm -f costfunction*0000 costfinal divided.ctrl snapshot*
#- MPI run on $1 procs (note: may need to edit mpirun command):
    echo "Run $add_DIVA_runs times + final run (use 'mpirun -np $1' ):"
    for ii in `seq 1 $add_DIVA_runs` ; do
      mpirun -np $1 ./mitgcmuv_ad
      echo " additional DIVA run # $ii : done"
      mv -f STDOUT.0000 STDOUT.0000.diva_${ii}
    done
    mpirun -np $1 ./mitgcmuv_ad
  fi
fi
