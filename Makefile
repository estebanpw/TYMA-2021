CC=gcc
CFLAGS=-O3 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -Wall #-DVERBOSE
BIN=./bin
SRC=./src

all: generate_dotplot dictionary

generate_dotplot: $(SRC)/generate_dotplot.c
	$(CC) $(CFLAGS) $(SRC)/generate_dotplot.c $(SRC)/common.c -o $(BIN)/generate_dotplot

dictionary: $(SRC)/dictionary.c
	$(CC) $(CFLAGS) $(SRC)/dictionary.c $(SRC)/common.c -o $(BIN)/dictionary
