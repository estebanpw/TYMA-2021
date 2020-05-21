#!/bin/bash

# Pipeline to run the sequence comparison algorithm

if [ $# -lt 3 ]; then
	echo "***ERROR*** Use: $0 <fastax> <fastay> <kmer>"
	exit -1
fi

BINDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

FASTAX=$1
FASTAY=$2
KSIZE=$3

NAMEX=$(basename $FASTAX)
NAMEY=$(basename $FASTAY)

$BINDIR/dictionary $FASTAX $NAMEX.dict $KSIZE
$BINDIR/dictionary $FASTAY $NAMEY.dict $KSIZE

$BINDIR/sort_words $NAMEX.dict $NAMEX.dict.sort $KSIZE
$BINDIR/sort_words $NAMEY.dict $NAMEY.dict.sort $KSIZE

$BINDIR/hits $NAMEX.dict.sort $NAMEY.dict.sort $NAMEX-$NAMEY.hits $KSIZE

