#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"
#include "utility.h"

void measure_is_best(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("insertion_best.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    for (int i = 1000; i <= 10000; i += 100)
    {
        for (int j = 0; j < 100; j++)
        {
                v = (int *) malloc(i * sizeof(int));
                for (int k = 0; k < i; k++)
                {
                    v[k] = k;
                }
            clock_gettime(CLOCK_MONOTONIC, &b);
            insertion_sort(v,i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void measure_is_average(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("insertion_average.txt", "w");
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
            insertion_sort(v,i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void measure_is_worst(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("insertion_worst.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    for (int i = 1000; i <= 10000; i += 100)
    {
        for (int j = 0; j < 100; j++)
        {
                v = (int *) malloc(i * sizeof(int));
                for (int k = i; k >= 0; k--)
                {
                    v[i - k] = k;
                }
            clock_gettime(CLOCK_MONOTONIC, &b);
            insertion_sort(v,i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void insertion_sort(int *v, unsigned int n)
{
    unsigned int i;
    int j, key;

    for (i = 1; i < n; i++) 
    {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key) 
        {
            swap(&v[j + 1], &v[j]);
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

