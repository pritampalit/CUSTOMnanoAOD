#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <filelist.txt>"
    exit 1
fi

FILELIST=$1

if [ ! -f "$FILELIST" ]; then
    echo "Error: filelist '$FILELIST' not found!"
    exit 2
fi

# Count number of lines = number of jobs
NJOBS=$(wc -l < "$FILELIST")

echo "Submitting $NJOBS jobs with filelist: $FILELIST"

condor_submit condorjob_customnano.jdl \
    -append "FILELIST=$FILELIST" \
    -append "NJOBS=$NJOBS"
