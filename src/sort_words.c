#include "common.h"

int main(int argc, char ** av){
   
    // Check parameters 
    if(argc != 2) {
        fprintf(stderr, "USE: sort_words dictionary\n"); 
        exit(-1);
    }
    
    
    // Open files for reading
    FILE * d = NULL;
    d = fopen(av[1], "rt"); if(d == NULL) { fprintf(stderr, "Could not open input dictionary file\n"); exit(-1);}  

    // Load words
    uint32_t n_words;
    Word * words = load_words(d, &n_words);

    // Close input dictionary since it is already in memory
    fclose(d);

    // Sort words
    quick_sort_words_inplace(words, 0, n_words-1, KSIZE);

 

    // Output dictionary file
    char output_name[MAX_NAME];
    strcpy(output_name, av[1]);
    strcat(output_name, ".sort");
    FILE * sorted_dictionary = fopen(output_name, "wt"); if(sorted_dictionary == NULL) { fprintf(stderr, "Could not open output dictionary file\n"); exit(-1);}


    // Write to dictionary
    uint32_t i; 
    for(i=0; i<n_words; i++)
    {
        fprintf(sorted_dictionary, "%.32s %u\n", words[i].kmer, words[i].pos); 
    }


    // Close and exit
    fclose(sorted_dictionary);

    return 0;
    
}
