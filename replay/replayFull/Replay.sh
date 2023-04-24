#!/bin/bash

##for command line testing (wont work with PBS)
if [ $# -eq 3 ]
then
    RUN_NUMBER=$1
    SEG=$2
    NEVENTS=$3
fi

#create necessary temporary directories on scratch
tempdir=/volatile/halla/sbs/gpenman/$RUN_NUMBER"_"$SEG
mkdir -p ${tempdir}

#check number of streams for run
#workdatafiles=$WORK_DATA_DIR/e1209016_$RUN_NUMBER.evio.*.$SEG
#export nstreams=`ls $workdatafiles | wc -l`

#check if files are already on scratch tempdir
#this is important for segment 0.0, which has prestart info and is therefore needed for EVERY job
#for ((i=0; i<nstreams; i++ ))
#do
#    if [ $SEG != 0 ] && [ ! -f $tempdir/e1209016_$RUN_NUMBER.evio.0.0 ]
#    then
#	cp $WORK_DATA_DIR/e1209016_$RUN_NUMBER.evio.0.0 $tempdir
#    fi
#    if [ ! -f $tempdir/e1209016_$RUN_NUMBER.evio.$i.$SEG ]
#    then
#	cp $WORK_DATA_DIR/e1209016_$RUN_NUMBER.evio.$i.$SEG $tempdir
#    fi
#done

#set strings for files on scratch and env variables for replay_gen.C
logfile=$tempdir"/"$RUN_NUMBER"_"$SEG".log"
#outfile=$tempdir"/*"$RUN_NUMBER"*.root"
#datafiles=$tempdir/e1209016_$RUN_NUMBER.evio.*

#export DATA_DIR=$tempdir
export DATA_DIR=$VOL_DATA_DIR
export OUT_DIR=$tempdir
export LOG_DIR=$tempdir

#do replay
echo $REPLAY_DIR
cd $REPLAY_DIR

nohup analyzer -b -q "replay_gen.C+("$RUN_NUMBER,$NEVENTS,1,'"e1209016"',$SEG,1,2,0,1,0")" > $logfile 2>&1
echo "****************** Hall A Analyzer Finished"

#tidy up
mv $tempdir/*.root  ${VOL_ROOT_DIR}
mv $tempdir/*.log ${VOL_LOG_DIR}
#rm -f $datafiles
rmdir $tempdir
