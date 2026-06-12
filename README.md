1. use script process_data.sh, which goes into datasets and removes whitespace, and replaces ',' with ' ' in a temporary file. Then counts events,
   and makes a file with the number of events per observation.
2. use bin/merge with the label file to get a file with events and the correct label beside it
3. do `bash scripts/get_accuracy.sh` to do a bunch of runs with thresholding
