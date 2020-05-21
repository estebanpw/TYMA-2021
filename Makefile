CC=gcc
CFLAGS=-O3 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE -Wall #-DVERBOSE
BIN=./bin
SRC=./src

all: generate_dotplot generate_dotplot_word_thresh dictionary sort_words hits

generate_dotplot: $(SRC)/generate_dotplot.c
	$(CC) $(CFLAGS) $(SRC)/generate_dotplot.c $(SRC)/common.c -o $(BIN)/generate_dotplot

generate_dotplot_word_thresh: $(SRC)/generate_dotplot_word_thresh.c
	$(CC) $(CFLAGS) $(SRC)/generate_dotplot_word_thresh.c $(SRC)/common.c -o $(BIN)/generate_dotplot_word_thresh

dictionary: $(SRC)/dictionary.c
	$(CC) $(CFLAGS) $(SRC)/dictionary.c $(SRC)/common.c -o $(BIN)/dictionary

sort_words: $(SRC)/sort_words.c
	$(CC) $(CFLAGS) $(SRC)/sort_words.c $(SRC)/common.c -o $(BIN)/sort_words

hits: $(SRC)/hits.c
	$(CC) $(CFLAGS) $(SRC)/hits.c $(SRC)/common.c -o $(BIN)/hits
