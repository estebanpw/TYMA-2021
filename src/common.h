#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

#define KSIZE 32

uint32_t estimate_seq_size(FILE * f);

char * allocate_memory_for_sequence(FILE * f);

char * load_seq(FILE * f, uint32_t * l);

uint32_t get_seq_len(FILE * f);

void generate_kmer_dictionary(char * s, uint32_t l, FILE * dictionary);
