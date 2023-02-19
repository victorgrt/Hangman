#!/bin/bash
# 1. Create ProgressBar function
# 1.1 Input is currentState($1) and totalState($2)
function ProgressBar {
# Process data
    let progress=(${1}*100/${2}*100)/100
    let done=(${progress}*4)/10
    let left=40-$done
# Build progressbar string lengths
    fill=$(printf "\033[32m%${done}s\033[0m")
    empty=$(printf "%${left}s")

# 1.2 Build progressbar strings and print the ProgressBar line
# 1.2.1 Output example:                           
# 1.2.1.1 Progress : [########################################] 100%
printf "\r [${fill// /#}${empty// /-}] ${progress}%%"

}

# Variables
start=1

# This accounts as the "totalState" variable for the ProgressBar function
end=45

# Proof of concept
for number in $(seq ${start} ${end})
do
    sleep 0.01
    ProgressBar ${number} ${end}
done
    printf "\n"
