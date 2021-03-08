//////////////////////////////////////////////////////
//
//                  common.h
//
//      Definitions of structures and methods
//
//
//          Author(s): estebanpw, ortrelles
//
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

#define KSIZE 32               // Used for word size in dictionaries
#define MAX_NAME 1024          // Used for names of automatically generated files
#define MAX_LINE 1024          // Used for maximum length per break line in text files
#define BATCH_SIZE 1024 * 1024 // Used for progressively loading words into memory

typedef struct word
{

    char kmer[KSIZE];
    uint32_t pos;

} Word;

/////////////////////////////////////////////////////////////////////////////////////////////
//
//          Secret exercise
//
//  Look at the "Word" structure. Is this a good definition performance-wise?
//  Discuss if an Array of Structs (AoS) is better or worse than a Struct of Arrays (SoA).
//
//  https://en.wikipedia.org/wiki/AoS_and_SoA
//
/////////////////////////////////////////////////////////////////////////////////////////////

uint32_t estimate_seq_size(FILE *f);

char *allocate_memory_for_sequence(FILE *f);

char *load_seq(FILE *f, uint32_t *l);

uint32_t get_seq_len(FILE *f);

char *reverse_complement(char *in, uint32_t seq_size);

void generate_kmer_dictionary(char *s, uint32_t l, FILE *dictionary, uint32_t k_size);

Word *load_words(FILE *f, uint32_t *n);

void quick_sort_words_inplace(Word *words, uint32_t x, uint32_t y, uint32_t k_size);

uint32_t generate_hits(Word *d1, Word *d2, uint32_t n_words_d1, uint32_t n_words_d2, FILE *hits_dictionary, uint32_t k_size);
