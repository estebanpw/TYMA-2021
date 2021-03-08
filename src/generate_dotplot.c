//////////////////////////////////////////////////////
//
//                  generate_dotplot.c
//
//  Generates a dotplot file (coded with 0s and 1s) from two input fasta sequences
//
//
//          Author(s): estebanpw, ortrelles
//
//////////////////////////////////////////////////////

#include "common.h"
#include "time.h"

int main(int argc, char **av)
{

    // Start timestamp for benchmark purposes
    clock_t begin = clock();

    if (argc != 4)
    {
        fprintf(stderr, "USE: generate_dotplot s1 s2 output\n");
        exit(-1);
    }

    // Open files for reading
    FILE *query = NULL, *ref = NULL;
    query = fopen(av[1], "rt");
    if (query == NULL)
    {
        fprintf(stderr, "Could not open input query file\n");
        exit(-1);
    }
    ref = fopen(av[2], "rt");
    if (ref == NULL)
    {
        fprintf(stderr, "Could not open input ref   file\n");
        exit(-1);
    }

    // Output dotplot file
    FILE *dotplot = fopen(av[3], "wt");
    if (dotplot == NULL)
    {
        fprintf(stderr, "Could not open output dotplot file\n");
        exit(-1);
    }

    // Load sequences
    uint32_t l_query;
    char *s_query = load_seq(query, &l_query);

    uint32_t l_ref;
    char *s_ref = load_seq(ref, &l_ref);

    // Close input sequences since they are already in memory
    fclose(query);
    fclose(ref);

    // Generate dotplot

    uint32_t i, j;
    for (i = 0; i < l_query; i++)
    {
        for (j = 0; j < l_ref; j++)
        {

            // Compare nucleotides
            if (s_query[i] == s_ref[j])
                fprintf(dotplot, "1");
            else
                fprintf(dotplot, "0");

            // Add space if not in last, breakline otherwise
            if (j < (l_ref - 1))
                fprintf(dotplot, " ");
            else
                fprintf(dotplot, "\n");
        }
    }

    // Free memory
    free(s_query);
    free(s_ref);
    fclose(dotplot);

    // CPU time computing for benchmark purposes
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    // Output stats
    fprintf(stderr, " > generate_dotplot_word_thresh\n");
    fprintf(stderr, " > Input sizes: %d and %d\n", l_query, l_ref);
    fprintf(stderr, " > CPU time: %2.3lf s", time_spent);

    return 0;
}
