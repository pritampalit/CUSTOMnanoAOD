# CUSTOMnanoAOD

Custom NanoAOD production (with condor scripts) for displaced tau studies.

## Setup

```bash
cmsrel CMSSW_16_0_0_pre1
cd CMSSW_16_0_0_pre1/src
cmsenv

git clone https://github.com/pritampalit/CUSTOMnanoAOD.git PhysicsTools/CUSTOMnanoAOD

scram b

cd PhysicsTools/CUSTOMnanoAOD/test/

cmsRun Run3_2023_PAT_EXONANO_template.py # for local run

# change the $CMSDIR, $JOBDIR and $OUTDIR in run_job_customnano.sh
./submit_condor_customnano.sh filelist_stau_m100_ct100_2022_postEE_2file.txt # condor






