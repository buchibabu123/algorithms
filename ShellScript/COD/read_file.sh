#! /bin/bash

while read line; do
	if echo $line | grep -q "password" ;
	then
		#echo "password line is"
		echo $line | awk -F':' '{print $2}'
	elif echo $line | grep -q "ssid" ;
	then
		#echo "ssid is"
		echo $line | awk -F':' '{print $2}'
	fi
done<txt
