#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"


struct node* new_node(int value) 
{
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->v = value;
    n->l = NULL;
    n->r = NULL;
    return n;
}

void btinsert(struct node** r, struct node* n) 
{
    if((*r)!=NULL) 
    {
        if(((*r)->v) > (n->v))
        {
            btinsert(&((*r)->l), n);
        }
        else
        {
            btinsert(&((*r)->r), n);
        } 
    } 
    else
    {
        (*r) = n;
    }
}

struct node* btsearch(struct node* r, int k) 
{
    if (r != NULL)
    {
        if (r->v == k)
        {
            return r;
        }
        if (r->v > k)
        {
            return btsearch(r->l, k);
        }
        return btsearch(r->r, k);
    }
    else 
    {
        return NULL;
    }
}

void free_tree(struct node* n) 
{
    if (n != NULL)
    {
        free_tree(n->l);
        free_tree(n->r);
        free(n);
    }
}


void measure_bta(void)
{
    struct timespec a, b;
    double total_time;
    unsigned int t;
    FILE *file;
    struct node *r = NULL;
    
    file = fopen("arvore_binaria_average.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    srand(time(NULL));
    for (int i = 1000; i <= 100000; i += 1000)
    {
        total_time = 0;
        for (int j = 0; j < 100; j++)
        {
            r = NULL;
            for (int k = 0; k < i; k++)
            {
                int value = rand() % i;
                btinsert(&r, new_node(value));
            }

            int key = rand() % i;
            clock_gettime(CLOCK_MONOTONIC, &b);
            btsearch(r, key);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
            total_time += t;

            free_tree(r);
        }
        double media = total_time/100;
        fprintf(file, "%d %lf\n", i, media);
    }
    fclose(file);
}

void measure_btw(void)
{
    struct timespec a, b;
    double total_time;
    unsigned int t;
    FILE *file;
    struct node *r = NULL;
    
    file = fopen("arvore_binaria_worst.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    srand(time(NULL));
    for (int i = 1000; i <= 100000; i += 1000)
    {
        r = NULL;
        for (int k = 0; k < i; k++)
        {
            btinsert(&r, new_node(k));
        }
        total_time = 0;
        for (int j = 0; j < 100; j++)
        {            
            clock_gettime(CLOCK_MONOTONIC, &b);
            btsearch(r, i + 1);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
            total_time += t;
        }
        
        free_tree(r);
        double media = total_time/100;
        fprintf(file, "%d %lf\n", i, media);
    }
    fclose(file);
}