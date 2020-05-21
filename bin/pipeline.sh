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

$BINDIR/dictionary $FASTAX $FASTAX.dict $KSIZE
$BINDIR/dictionary $FASTAY $FASTAY.dict $KSIZE

$BINDIR/sort_words $FASTAX.dict $FASTAX.dict.sort $KSIZE
$BINDIR/sort_words $FASTAY.dict $FASTAY.dict.sort $KSIZE

echo "Output files are"
echo "	$FASTAX.dict"
echo "	$FASTAY.dict"
echo "	$FASTAX.dict.sort"
echo "	$FASTAY.dict.sort"
