
//////////////////////////////////////////////////////
//
//					hits.c
//
//		Generates the hits given two dictionaries
//
//
//			Author(s): estebanpw, ortrelles
//
//////////////////////////////////////////////////////

#include "common.h"

int main(int argc, char **av)
{

    // Check parameters
    if (argc != 5)
    {
        fprintf(stderr, "USE: hits dictionary1.sort dictionary2.sort hitsDictionary ksize\n");
        exit(-1);
    }

    // Open files for reading
    FILE *d1 = NULL;
    d1 = fopen(av[1], "rt");
    if (d1 == NULL)
    {
        fprintf(stderr, "Could not open input dictionary (1) file\n");
        exit(-1);
    }
    FILE *d2 = NULL;
    d2 = fopen(av[2], "rt");
    if (d2 == NULL)
    {
        fprintf(stderr, "Could not open input dictionary (2) file\n");
        exit(-1);
    }

    uint32_t k_size = (uint32_t)atoi(av[4]);

    // Load words
    uint32_t n_words_d1;
    Word *words1 = load_words(d1, &n_words_d1);
    uint32_t n_words_d2;
    Word *words2 = load_words(d2, &n_words_d2);

    // Close input dictionaries since it is already in memory
    fclose(d1);
    fclose(d2);

    // Output dictionary file
    FILE *hits_dictionary = fopen(av[3], "wt");
    if (hits_dictionary == NULL)
    {
        fprintf(stderr, "Could not open output hits dictionary file\n");
        exit(-1);
    }

    // Generate hits
    uint32_t n_hits = generate_hits(words1, words2, n_words_d1, n_words_d2, hits_dictionary, k_size);

    printf("Generated %u hits [TODO: Complete the exercise]\n", n_hits);

    // Free and close
    free(words1);
    free(words2);

    return 0;
}
