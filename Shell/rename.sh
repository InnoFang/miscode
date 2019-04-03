#!/bin/bash

# rename your files
# If your file contain a space, please remove it before you this script

for file in `ls | grep .txt`    
do
    newfile=`echo $file | sed 's/pattern/replace/g'`
    mv "$file" "${newfile}" 
done