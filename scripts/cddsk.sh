#!/usr/bin/env bash
#####################################################
# @author:alexeal                                   #
# @date:2024/05/11                                  #
# @shell:bin/bash                                   #
#####################################################
RED='\033[0;31m'
NC='\033[0m' 
diskPath=/Volumes/ # DEFAULT PATH (macOS PATH)
# Defines path accordingly to the OS
if [ "$(uname)" = "Darwin" ]; then
    diskPath=/Volumes/
elif [ "$(expr substr $(uname -s) 1 5)" = "Linux" ]; then
    diskPath=/run/media/$USER/ # be cautious: put the right path here
fi
# Change directory to mounted disk with the label
if [[ ! -z "$1"  ]]; then
    # is valid directory 
    if [[ -d $diskPath$1  ]]; then
        cd $diskPath$1
    elif [ "$1" = "--help" ]; then
            echo "Usage: cddsk <label> where label is the name of the partition"
            echo "Use cddsk --list to get the list of available disks"
    else
        echo -e "${RED}Error: Unknown disk${NC}"
        echo -e "Existing volumes:"
        ls -aF $diskPath
    fi
else 
    echo -e "${RED}Error: Unknown arg${NC}"
fi
