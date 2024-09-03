#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"
#include "utility.h"

void measure_ss(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("selection.txt", "w");
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
            selection_sort(v,i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void selection_sort(int *v, unsigned int n)
{
    unsigned int i, j;
    int min;

    for (i = 0; i < (n - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < n; j++)
        {
            if (v[min] > v[j])
                min = j;
        }
        swap(&v[min], &v[i]);
    }
}