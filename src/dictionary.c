#include "common.h"


int main(int argc, char ** av){
   
    // Check parameters 
    if(argc != 3) {
        fprintf(stderr, "USE: dictionary sequence outputdictionary\n"); 
        exit(-1);
    }
    
    
    // Open files for reading
    FILE * query = NULL;
    query = fopen(av[1], "rt"); if(query == NULL) { fprintf(stderr, "Could not open input query file\n"); exit(-1);}  

    // Load sequence
    uint32_t l_query;
    char * s_query = load_seq(query, &l_query);

    // Close input sequences since they are already in memory
    fclose(query);


 
    // Output dictionary file
    FILE * dictionary = fopen(av[2], "wt"); if(dictionary == NULL) { fprintf(stderr, "Could not open output dictionary file\n"); exit(-1);}
    
    // Generate kmer dictionary 
    generate_kmer_dictionary(s_query, l_query, dictionary);

    // Close and exit
    free(s_query);
    fclose(dictionary);

    return 0;
    
}
