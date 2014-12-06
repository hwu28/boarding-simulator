#!/bin/bash

for i in `ls *.c`
do
if [ "x$i" != "xfsim.c" ]; then
echo $i
gcc fsim.c $i -o `head -c-3 <<< $i`
fi
done
