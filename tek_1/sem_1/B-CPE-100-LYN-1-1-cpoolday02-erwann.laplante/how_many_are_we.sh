#!/bin/bash
if [ -z $1]
then
	wc -l
else
	cut -d\; -f3 |grep -i "$1" | wc -l
fi
