#!/bin/bash

#test for runlist
if [ $# -ge 1 ] 
then
    runlist=$1
else
    echo "Error: please provide a run list!"
    exit 1
fi 

if [ $# -ge 2 ]
then
    nsegs=$2
else
    nsegs=1
fi

if [ $# -ge 3 ]
then
    nevents=$3
else
    nevents=50000
fi

echo "Submitting jobs for $runlist, $nsegs segment per run, $nevents events per segment/"
   
#get the files from the list
runs=`cat $runlist`

export NEVENTS=$nevents

#submit a job for each file in filelist
for run in $runs
do
    export RUN_NUMBER=$run
    if (( $nsegs < 0 ))
    then
	export nsegs=`ls $VOL_DATA_DIR/*$RUN_NUMBER* | wc -l`
    fi
    echo "Submitting $nsegs jobs for run $RUN_NUMBER for GEn Replay"
    for (( seg=0; seg<$nsegs; seg++))
    do
	echo Job: $seg
	export SEG=$seg
	#qsub Replay.sh
	Replay.sh &
	sleep 5
    done
done
