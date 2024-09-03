#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#include "utility.h"


void measure_qs_best(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("quick_best.txt", "w");
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
                    v[k] = k;
                }
                best(v, 0, i - 1);
            clock_gettime(CLOCK_MONOTONIC, &b);
            quick_sort(v, 0, i - 1);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void measure_qs_average(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("quick_average.txt", "w");
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
            quick_sort(v, 0, i - 1);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void measure_qs_worst(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("quick_worst.txt", "w");
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
            quick_sort(v, 0, i - 1);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

int partition (int *v, int s, int e) 
{
    int k, i;

    k = v[e];
    i = (s - 1);

    for (int j = s; j <= e - 1; j++) 
    {
        if (v[j] <= k) 
        {
            i = i + 1;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[e]);
    return (i + 1);
}

void quick_sort(int *v, int s, int e) 
{
    if (s < e) 
    {
        int p;
        p = partition(v, s, e);
        quick_sort(v, s, p - 1);
        quick_sort(v, p + 1, e);
    }
}

void best(int *v, int s, int e) 
{
    if (s < e) 
    {
        int m;
        m = (s+e)/2;
        best(v, s, m - 1);
        best(v, m + 1, e);
        swap(&v[m], &v[e]);
    }
}