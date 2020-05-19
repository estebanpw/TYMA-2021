CC=gcc
CFLAGS=-O3 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -Wall #-DVERBOSE
BIN=./

all: generate_dotplot

generate_dotplot: generate_dotplot.c
	$(CC) $(CFLAGS) generate_dotplot.c common.c -o $(BIN)/generate_dotplot
