#!/bin/bash



for ((i=50; i<=1200; i+=50)); do

 echo "$i $((i + 50))"
 sed "s|XXX_data|datasets/data_${i}_$((i+50)).txt|g" network.txt > networks/network_${i}_$((i+50)).txt
 sed -i "s|XXX_label|datasets/labels_${i}_$((i+50)).txt|g" networks/network_${i}_$((i+50)).txt
 touch datasets/labels_${i}_$((i + 50)).txt
 ./bin/make_dataset data_easier_to_read.txt inputs/test_event_count.txt datasets/labels_${i}_$((i + 50)).txt $i $((i + 50)) \
	> datasets/data_${i}_$((i + 50)).txt
 echo ""
done
