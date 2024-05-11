if [ "$(uname)" == "Darwin" ]; then
    dskpath=/Volumes/
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    dskpath=/run/media/$USER/ # be cautious: put the right path here
fi
if [ $# -ne 0 ];then
  if [ $# -ge 1 ];then
    if [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
        echo "Usage: cddsk <label> where label is the name of the partition"
        echo "Use cddsk --list to get the list of available disks"
        echo ""
        exit 1
    elif [[ "$1" == "--list" ]];then
        ls -Fa $dskpath
    elif [ -d $dskpath$1 ];then
            cd $dskpath$1
    else
        echo "An error happenned"
        echo "Check the command help to seek more informations"
    fi
  fi
else
  echo "Check the command help to seek more informations with the option --help"
fi
