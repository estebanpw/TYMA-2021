//////////////////////////////////////////////////////
//
//                  common.c
//
//	Implementation of the methods for sorting, matching, etc.
//
//
//          Author(s): estebanpw, ortrelles
//
//////////////////////////////////////////////////////


#include "common.h"

uint32_t estimate_seq_size(FILE * f)
{

    if(f == NULL) {fprintf(stderr, "File is null. Check inputs.\n"); exit(-1);}
    
    fseek(f, 0L, SEEK_END);
    uint32_t l = (uint32_t) ftell(f);
    rewind(f);
    return l;

}

char * allocate_memory_for_sequence(FILE * f)
{

    uint32_t l = estimate_seq_size(f);
    if(l == 0) {fprintf(stderr, "Sequence is 0-sized. Check inputs.\n"); exit(-1);}
    char * s = NULL;
    s = (char *) malloc(l * sizeof(char));
    if(s == NULL) {fprintf(stderr, "Could not allocate memory for sequence.\n"); exit(-1);}

    return s;

}

char * load_seq(FILE * f, uint32_t * l)
{

    char c = '\0';
    *l = 0;
    char * s = allocate_memory_for_sequence(f);    

    while(!feof(f))
    {
        c = getc(f);
        if(c == '>')
        {
            while(c != '\n') c = getc(f);
        }
        c = toupper(c);
        if(c >= 'A' && c <= 'Z')
        {
            s[*l] = c;
            *l = *l + 1;
        }
    }
    rewind(f);

    return s;

}

uint32_t get_seq_len(FILE * f) 
{

    char c = '\0';
    uint32_t l = 0;
    while(!feof(f))
    {
        c = getc(f);
        if(c == '>')
        {
            while(c != '\n') c = getc(f);
        }
        c = toupper(c);
        if(c >= 'A' && c <= 'Z') ++l;
    }
    rewind(f);

    return l;

}

void generate_kmer_dictionary(char * s, uint32_t l, FILE * dictionary, uint32_t k_size)
{

    uint32_t i;

	if(l < k_size) return;

    for(i=0; i<l - k_size + 1; i++)
    {

        fprintf(dictionary, "%.*s %u\n", k_size, &s[i], i);

    }

}


Word * load_words(FILE * f, uint32_t * n)
{
    
    uint32_t i = 0;
    char buffer[MAX_LINE];

    Word * words = (Word *) malloc(BATCH_SIZE * sizeof(Word));
    if(words == NULL) {fprintf(stderr, "No memory for allocating words.\n"); exit(-1);}


    while(!feof(f))
    {

        if(fgets(buffer, MAX_LINE, f) != NULL)
        {

            sscanf(buffer, "%s %u", words[i].kmer, &words[i].pos);
            ++i;

            // Progressive allocation of memory every BATCH_SIZE words
            if(i % BATCH_SIZE == 0) words = (Word *) realloc(words, (i/BATCH_SIZE + 1) * BATCH_SIZE * sizeof(Word));

        }

    }

    rewind(f);

    // Reallocate to real size
    words = (Word *) realloc(words, i * sizeof(Word));

    *n = i;
    return words;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Notice: this quicksort operates on the range [0, n) so remember to subtract -1 from the total elements to be sorted! //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void quick_sort_words_inplace(Word * words, uint32_t x, uint32_t y, uint32_t k_size)
{
    Word pivot, aux;
    uint32_t x1, y1;

    strncpy(pivot.kmer, words[(x+y)/2].kmer, k_size);
    pivot.pos = words[(x+y)/2].pos;

    x1 = x;
    y1 = y;

    do
    { 
        while ( strncmp(pivot.kmer, words[x1].kmer, k_size) >0 ) x1++;
        while ( strncmp(pivot.kmer, words[y1].kmer, k_size) <0 ) y1--;

        if (x1 < y1) {

            aux.pos = words[x1].pos;
            words[x1].pos = words[y1].pos;
            words[y1].pos = aux.pos;

            strncpy(aux.kmer, words[x1].kmer, k_size);
            strncpy(words[x1].kmer, words[y1].kmer, k_size);
            strncpy(words[y1].kmer, aux.kmer, k_size);

            x1++;
            y1--;
        }
        else if (x1 == y1) x1++;

    } while (x1 <= y1);

    if (x < y1) quick_sort_words_inplace(words, x, y1, k_size);
    if (x1 < y) quick_sort_words_inplace(words, x1, y, k_size);
}


uint32_t generate_hits(Word * d1, Word * d2, uint32_t n_words_d1, uint32_t n_words_d2, FILE * hits_dictionary, uint32_t k_size)
{
	uint32_t n_hits = 0, pos_d1 = 0, pos_d2 = 0;
	char * kmer = NULL;


	// TODO
	// Complete the method so that every match pair is written to the file

	// ... code to match hits

	fprintf(hits_dictionary, "%.*s %u %u\n", k_size, kmer, pos_d1, pos_d2);

	return n_hits;

}





