#!/bin/bash
cut -d: --output-delimiter="," -f 1 | sed -n 2~2p | rev | sort -r | awk -v line1="$MY_LINE1" -v line2="$MY_LINE2" "NR>=line1&&NR<=line2" | paste -s -d, | sed 's/,/, /g' | sed 's/$/.\n/'
