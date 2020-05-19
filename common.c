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

    while(!feof(f)){
        c = getc(f);
        if(c == '>'){
            while(c != '\n') c = getc(f);
        }
        c = toupper(c);
        if(c >= 'A' && c <= 'Z'){
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
