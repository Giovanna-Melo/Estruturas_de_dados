#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "distribution_sort.h"
#include "utility.h"


void measure_ds_menor_k(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v, V_base[100];
    FILE *file;
    
    file = fopen("distribution_menor_k.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    for (int i = 1000; i <= 10000; i += 100)
    {
        for (int j = 0; j < 100; j++)
        {
                v = (int *) malloc(i * sizeof(int));
                for (int x = 0; x < 100; x++) 
                {
                    V_base[x] = x + 1;
                }

                int index = 0;
                for (int y = 0; y < i; y += 100) 
                {
                    for (int z = 0; z < 100 && index < i; z++) 
                    {
                        v[index] = V_base[z];
                        index++;
                    }
                }
                
            clock_gettime(CLOCK_MONOTONIC, &b);
            distribution_sort(v, i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void measure_ds_average(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v;
    FILE *file;
    
    file = fopen("distribution_average.txt", "w");
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
                    v[k] = rand() %10000;
                }
            clock_gettime(CLOCK_MONOTONIC, &b);
            distribution_sort(v, i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

void measure_ds_maior_k(void)
{
    struct timespec a, b;
    unsigned int t;
    int *v, V_base[20];
    FILE *file;
    
    file = fopen("distribution_maior_k.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    for (int i = 1000; i <= 10000; i += 100)
    {
        for (int j = 0; j < 100; j++)
        {
                v = (int *) malloc(i * sizeof(int));
                for (int x = 0; x < 20; x ++) 
                {
                    V_base[x] = x * 5000;
                }
                V_base[0] = 1;

                int index = 0;
                for (int y = 0; y < i; y += 20) 
                {
                    for (int z = 0; z < 20 && index < i; z++) 
                    {
                        v[index] = V_base[z];
                        index++;
                    }
                }

            clock_gettime(CLOCK_MONOTONIC, &b);
            distribution_sort(v, i);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

            fprintf(file, "%d %u\n", i, t);
            free(v);
        }
    }
    fclose(file);
}

int find_min(int *v, int n) 
{
    int min = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

int find_max(int *v, int n) 
{
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

void distribution_sort(int *v, int n) 
{
    int L = find_min(v, n);
    int b = find_max(v, n);
    int range = b - L + 1;

    int *w = (int *)malloc(range * sizeof(int));
    int *z = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < (range); i++) 
    {
        w[i] = 0;
    }

    for (int i = 0; i <= (n - 1); i++) 
    {
        int f = v[i] - L; 
        w[f] = w[f] + 1;
    }

    for (int i = 1; i < (range); i++) 
    {
        w[i] = w[i] + w[i - 1];
    }

    for (int i = 0; i <= (n - 1); i++)
    {
        int f = v[i] - L;
        z[w[f] - 1] = v[i];
        w[f] = w[f] - 1;
    }

    for (int i = 0; i < n; i++) 
    {
        v[i] = z[i];
    }

    free(w);
    free(z);
}