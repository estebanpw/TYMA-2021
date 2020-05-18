#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>

uint32_t get_seq_len(FILE * f);
uint32_t load_seq(FILE * f, char * seq);
char * read_sequence(FILE * f, uint32_t * slen);

int main(int argc, char ** av){
    
    if(argc != 3) {
        fprintf(stderr, "USE: generate_dotplot s1 s2\n"); 
        exit(-1);
    }
    
    
    // Open files for reading
    FILE * query = NULL, * ref = NULL;
    query = fopen(av[1], "rt"); if(query == NULL) { fprintf(stderr, "Could not open input query file\n"); exit(-1);}
    ref   = fopen(av[2], "rt"); if(ref   == NULL) { fprintf(stderr, "Could not open input ref   file\n"); exit(-1);}
    
    // Output dotplot file
    FILE * dotplot = fopen("dotplot.txt", "wt"); if(dotplot == NULL) { fprintf(stderr, "Could not open output dotplot file\n"); exit(-1);}
    
    // Load sequences
    uint32_t l_query;
    char * s_query = read_sequence(query, &l_query);
    
    uint32_t l_ref;
    char * s_ref = read_sequence(ref, &l_ref);
    
    // Close input sequences since they are already in memory
    fclose(query);
    fclose(ref);
    
    // Generate dotplot
    
    uint32_t i, j;
    for(i=0; i<l_query; i++){
        for(j=0; j<l_ref; j++){ 
            
            // Compare nucleotides
            if(s_query[i] == s_ref[j]) fprintf(dotplot, "1"); else  fprintf(dotplot, "0");
            
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

char * read_sequence(FILE * f, uint32_t * slen){
    
    char * s = NULL;
    
    // Get sequence length and allocate memory
    uint32_t l = get_seq_len(f);
    s = (char *) malloc(l * sizeof(char));
    if(s == NULL) { fprintf(stderr, "Error allocating sequence memory\n"); exit(-1); } 
    
    // Load sequence into char array
    load_seq(f, s);
    
    // Return pointer to sequence
    *slen = l;
    return s;
    
}


uint32_t get_seq_len(FILE * f) {
    char c = '\0';
    uint32_t l = 0;
    while(!feof(f)){
        c = getc(f);
        if(c == '>'){
            while(c != '\n') c = getc(f);
        }
        c = toupper(c);
        if(c >= 'A' && c <= 'Z'){
            ++l;
        }
    }
    rewind(f);
    return l;
}

uint32_t load_seq(FILE * f, char * seq) {
    char c = '\0';
    uint32_t l = 0;
    while(!feof(f)){
        c = getc(f);
        if(c == '>'){
            while(c != '\n') c = getc(f);
        }
        c = toupper(c);
        if(c >= 'A' && c <= 'Z'){
            seq[l] = c;
            ++l;
        }
    }
    rewind(f);
    return l;
}
