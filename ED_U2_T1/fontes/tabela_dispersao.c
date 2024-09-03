#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tabela_dispersao.h"


int hash_function(int key, int table_size) 
{
    return key % table_size;
}

struct hash_table* create_table() 
{
    struct hash_table* t = (struct hash_table*)malloc(sizeof(struct hash_table));

    t->size = 1;  
    t->table = (struct item**)malloc(sizeof(struct item*) * t->size);

    for (int i = 0; i < t->size; i++) {
        t->table[i] = NULL;
    }
    
    t->last = 0;
    return t;
}

void hash_insert(struct hash_table* t, int value) 
{
    if (t->size <= t->last) 
    {
        rehash(t);
    }

    int index = hash_function(value, t->size);

    struct item* new_item = (struct item*)malloc(sizeof(struct item));
    new_item->v = value;
    new_item->n = t->table[index]; 
    t->table[index] = new_item;    
    t->last++;                    
}

void rehash(struct hash_table* t) 
{
    int old_size = t->size;            
    struct item** old_t = t->table;    

    int new_size = t->size * 2;        
    t->size = new_size;
    t->table = (struct item**)malloc(sizeof(struct item*) * new_size);

    for (int i = 0; i < new_size; i++) 
    {
        t->table[i] = NULL;
    }

    for (int i = 0; i < old_size; i++) 
    {
        struct item* item = old_t[i];
        while (item != NULL) 
        {
            struct item* next = item->n; 
            int index = hash_function(item->v, new_size);
            item->n = t->table[index];  
            t->table[index] = item;
            item = next;
        }
    }

    free(old_t);
}


int hash_search(struct hash_table* t, int key) 
{
    int index = hash_function(key, t->size); 

    struct item* item = t->table[index];
    while (item != NULL) 
    {
        if (item->v == key) 
        {
            return 1; 
        }
        item = item->n;
    }
    return 0;
}

void free_hash_table(struct hash_table* t) 
{
    for (unsigned int i = 0; i < t->size; i++) 
    {
        struct item *atual = t->table[i];
        while (atual != NULL) 
        {
            struct item *ant = atual;
            atual = atual->n;
            free(ant);
        }
    }
    free(t->table);
    free(t);
}

void print_hash_table(struct hash_table* t) 
{
    for (int i = 0; i < t->size; i++) 
    {
        printf("Index %d: ", i);

        struct item* item = t->table[i];
        while (item != NULL) 
        {
            printf("%d -> ", item->v);
            item = item->n;
        }

        printf("NULL\n");
    }
}


void measure_tda(void)
{
    struct timespec a, b;
    unsigned int t;
    int total_time;
    FILE *file;

    file = fopen("tabela_dispersao_average.txt", "w");
    if (file == NULL) {
        perror("Erro");
    }

    for (int i = 1000; i <= 100000; i += 1000) 
    {
        total_time = 0;
        int key = rand() % (i * 2);
        for (int j = 0; j < 100; j++) 
        {
            struct hash_table *ht = create_table();
            for (int k = 0; k < i; k++) 
            {
                int random = rand () % i;
                hash_insert(ht, random);
            }
            clock_gettime(CLOCK_MONOTONIC, &b);
            hash_search(ht, key);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
            total_time += t;
            free_hash_table(ht);
        }
        double media = total_time/100;
        fprintf(file, "%d %lf\n", i, media);
    }
    fclose(file);
}

void measure_tdw(void)
{
    struct timespec a, b;
    unsigned int t;
    int total_time;
    FILE *file; 
    
    file = fopen("tabela_dispersao_worst.txt", "w");
    if (file == NULL) {
        perror("Erro");
    }

    for (int i = 1000; i <= 100000; i += 1000) 
    {
        struct hash_table *ht = create_table();
        for (int k = 0; k < i; k++) 
        {
            hash_insert(ht, 0);
        }
        total_time = 0;
        for (int j = 0; j < 100; j++)
        {

            int tam = ht->size;
            clock_gettime(CLOCK_MONOTONIC, &b);
            hash_search(ht, tam);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
            total_time += t;
        }
        free_hash_table(ht);
        double media = total_time/100;
        fprintf(file, "%d %lf\n", i, media);
    }
    fclose(file);
}

