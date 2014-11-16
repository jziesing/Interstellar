#!/bin/sh

filePrefix="$1"
sequence=0

for file in $(ls -tr *.jpg) ; do
    renamedFile="$filePrefix$sequence.png"
    echo $renamedFile
    currentFile="$(echo $file)"
    echo "renaming \"$currentFile\" to $renamedFile"
    mv "$currentFile" "$renamedFile"
    sequence=$(($sequence+1))
done
exit 0