# Running environment (not for develping allpix-squared)

Geant4Bin=/opt/allpix/geant4.10.04/install/bin   
source ${Geant4Bin}/geant4.sh 
source /opt/allpix/root/install/bin/thisroot.sh

if [[ $# -eq 0 ]]; then
    printf "\nUsing default setup.\n"
else
    option=$1
fi


case $option in
    master) echo "Using master allpix2 ..."
    export ALLPIX=/home/shixin/allpix-squared
    ;;

    *) echo "Setting up allpix-squared v1.1.1 ..." 
    export ALLPIX=/opt/allpix/v1.1.1
    ;;     

esac

export PATH=$PATH:$ALLPIX/bin:$ALLPIX/bin/tcad_dfise_converter
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ALLPIX/lib

