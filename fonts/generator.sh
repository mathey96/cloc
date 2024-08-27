#!/bin/bash

export LISTOFFILES="standard
lean
mini
mono9
mono12
smmono12
smscript
smshadow
smslant"

echo -e "$LISTOFFILES" | parallel 'seq 0 9 | figlet -f {} > {}.h' &&
echo -e "$LISTOFFILES" | parallel 'echo ":" | figlet -f {} >> {}.h' &&
echo -e "$LISTOFFILES" | sed 's/$/.h/' | xargs sed -i "s/^ *$//g"
echo -e "$LISTOFFILES" | parallel 'awk -v var1={} -f generate_font.awk {}.h > {}.temp && mv {}.temp {}.h'

