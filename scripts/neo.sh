#!/bin/bash
#####################################################
# @author:alexeal									#
# @date:2017/03/05									#
# @shell:bin/bash									#
#####################################################
##### The Neo Trip #####
reset
neo="`whoami`"
# Wake up Neo...
message="Wake up $neo..."
for (( i=0; i<${#message}; i++ )); do
  echo -n "${message:$i:1}"
  sleep 0.25
done
reset
# The Matrix has you...
message="The Matrix has you..."
for (( i=0; i<${#message}; i++ )); do
  echo -n "${message:$i:1}"
  sleep 0.25
done
reset
# Follow the White Rabbit
message="Follow the White Rabbit"
for (( i=0; i<${#message}; i++ )); do
  echo -n "${message:$i:1}"
  sleep 0.25
done
reset
# Knock knock knock
echo Knock, knock $neo; sleep 3;
reset