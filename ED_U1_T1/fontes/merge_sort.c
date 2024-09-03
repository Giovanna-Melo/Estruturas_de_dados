#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"
#include "utility.h"

void measure_ms(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("merge.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    for (int i = 1000; i <= 10000; i += 100)
    {
        for (int j = 0; j < 100; j++)
        {
                v = (int *) malloc(i * sizeof(int));
                srand(time(NULL));
                for (int k = 0; k < i; k++)
                {
                    v[k] = rand();
                }
            clock_gettime(CLOCK_MONOTONIC, &b);
            merge_sort(v, 0, i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void merge(int *v, int s, int m, int e) 
{
    int i, j, k;
    int *v2 = (int *)malloc((e - s + 1) * sizeof(int));

    i = s;
    j = m + 1;
    for (k = 0; k < e - s + 1; k++) {
        if ((v[i] < v[j] && i <= m ) || j > e) 
        {
            v2[k] = v[i];
            i = i + 1;
        } else {
            v2[k] = v[j];
            j = j + 1;
        }
    }

    for (k = 0; k < e - s + 1; k++) 
    {
        v[s + k] = v2[k];
    }

    free(v2);
}

void merge_sort(int *v, int s, int e) 
{
    if (s < e) 
    {
        int m = (s + e) / 2;
        merge_sort(v, s, m);
        merge_sort(v, m + 1, e);
        merge(v, s, m, e);
    }
}
