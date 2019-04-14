#!/bin/sh

for file in $(ls *.cpp)
do
   filePreix=`echo $file| awk -F"." '{printf("%04d", $1)}'`
   mv $file $filePreix".cpp"
done
