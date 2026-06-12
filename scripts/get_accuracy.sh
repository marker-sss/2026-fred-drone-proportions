#!/bin/bash



for ((i=50; i<=1200; i+=50)); do
 echo "$i"
 ./bin/thresholding $1 $i
 echo ""
done
