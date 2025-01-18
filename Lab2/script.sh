#!/bin/bash

current_date=$(date)
echo "Date is: $current_date"

current_time=$(date +%s)
echo "Current time = $current_time"

let current_time=current_time*2
echo "Current time *2 = $current_time"

for i in {1..20}; do
	echo "Number: $i"
done



