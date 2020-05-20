#include "common.h"


int main(int argc, char ** av){
    
    if(argc != 6) {
        fprintf(stderr, "USE: generate_dotplot s1 s2 W T output\n"); 
        exit(-1);
    }
    
    
    // Open files for reading
    FILE * query = NULL, * ref = NULL;
    query = fopen(av[1], "rt"); if(query == NULL) { fprintf(stderr, "Could not open input query file\n"); exit(-1);}
    ref   = fopen(av[2], "rt"); if(ref   == NULL) { fprintf(stderr, "Could not open input ref   file\n"); exit(-1);}

    // Use word size, threshold and keep scoring values
    uint32_t W, T, score;

    W = (uint32_t) atoi(av[3]);
    T = (uint32_t) atoi(av[4]);
    
    // Output dotplot file
    FILE * dotplot = fopen(av[5], "wt"); if(dotplot == NULL) { fprintf(stderr, "Could not open output dotplot file\n"); exit(-1);}
    
    // Load sequences
    uint32_t l_query;
    char * s_query = load_seq(query, &l_query);
    
    uint32_t l_ref;
    char * s_ref = load_seq(ref, &l_ref);
    
    // Close input sequences since they are already in memory
    fclose(query);
    fclose(ref);
    
    // Generate dotplot
    
    uint32_t i, j, k;
    for(i=0; i<l_query; i++){
        for(j=0; j<l_ref; j++){ 

            score = 0;
            for (k=0; k<W; k++) 
            {
                // Compare nucleotides
                if(s_query[i+k] == s_ref[j+k]) ++score;
            }

            // Only write results if the score is higher than the threshold
            if (score >= T) fprintf(dotplot, "1"); else  fprintf(dotplot, "0");
            
            // Add space if not in last, breakline otherwise
            if(j < (l_ref-1)) fprintf(dotplot, " "); else fprintf(dotplot, "\n");
            
        }
    }
    
    
    // Close and exit
    free(s_query);
    free(s_ref);
    fclose(dotplot);

    return 0;
    
}
