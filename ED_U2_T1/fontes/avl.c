#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


unsigned int height(struct node_avl *n) 
{
    if (n == NULL) 
    {
        return 0;
    }

    if ((n->r != NULL) && (n->l != NULL)) 
    {
        if ((n->r->h) > (n->l->h)) 
        {
            return (n->r->h) + 1;
        }
        else
        {
            return (n->l->h) + 1;
        }
    }

    if ((n->r != NULL) && ((n->l == NULL))) 
    {
        return n->r->h + 1;
    }

    if ((n->r == NULL) && ((n->l != NULL))) 
    {
        return n->l->h + 1;
    }
    else
    {
        return 1;
    }
}

struct node_avl* new_node_avl(int value) 
{
    struct node_avl* n = (struct node_avl*) malloc(sizeof(struct node_avl));
    n->v = value;
    n->l = NULL;
    n->r = NULL;
    n->p = NULL;
    n->h = 1;
    return n;
}

int balance_factor(struct node_avl *n) 
{
    if (n == NULL) 
    {
        return 0;
    }
    else
    {
        return height(n->l) - height(n->r);
    }
}

void update_height(struct node_avl **n) 
{
    if (*n != NULL) 
    {
        (*n)->h = height(*n);
    }
}

void rotate_left(struct node_avl**r) 
{
    struct node_avl *new_root = (*r)->r;
    (*r)->r = new_root->l;
    
    if (new_root->l != NULL) 
    {
        new_root->l->p = *r;
    }
    
    new_root->p = (*r)->p;
    new_root->l = *r;
    (*r)->p = new_root;

    update_height(r);
    update_height(&new_root);
    *r = new_root;
}

void rotate_right(struct node_avl **r) 
{
    struct node_avl *new_root = (*r)->l;
    (*r)->l = new_root->r;
    
    if (new_root->r != NULL) 
    {
        new_root->r->p = *r;
    }
    
    new_root->p = (*r)->p;
    new_root->r = *r;
    (*r)->p = new_root;

    update_height(r);
    update_height(&new_root);
    *r = new_root;
}

void balanceamento(struct node_avl **r) 
{
    if (*r != NULL) 
    {
        int bf = balance_factor(*r);
        
        if (bf > 1) 
        {
            if (balance_factor((*r)->l) < 0) 
            {
                rotate_left(&((*r)->l));
            }
            rotate_right(r);
        }
        
        else if (bf < -1) 
        {
            if (balance_factor((*r)->r) > 0) 
            {
                rotate_right(&((*r)->r));
            }
            rotate_left(r);
        }
    }
}

void btinsert_avl(struct node_avl** r, struct node_avl* n) 
{
    if ((*r) != NULL) 
    {
        if (((*r)->v) > (n->v)) 
        {
            btinsert_avl(&((*r)->l), n);
            (*r)->l->p = (*r);
        } 
        else 
        {
            btinsert_avl(&((*r)->r), n);
            (*r)->r->p = (*r);
        }
        update_height(r);
        balanceamento(r);
    } 
    else 
    {
        (*r) = n;
    }
}

struct node_avl* btsearch_avl(struct node_avl* r, int k) 
{
    if (r != NULL) 
    {
        if (r->v == k) 
        {
            return r;
        } 
        if (r->v > k) 
        {
            //print_avl(r->l);
            //printf("proximo ---\n");
            return btsearch_avl(r->l, k);
        } 
        else
        {
            //print_avl(r->r);
            //printf("proximo ---\n");
            return btsearch_avl(r->r, k);
        }
    }
    return NULL; 
}

void free_tree_avl(struct node_avl* n) 
{
    if (n != NULL) 
    {
        free_tree_avl(n->l);
        free_tree_avl(n->r);
        free(n);
    }
}


void print_tree(struct node_avl* r, int space, int height) 
{
    if (r != NULL)
    {
        // Aumenta a distância entre os níveis
        space += height;

        // Processa primeiro o nó da direita
        print_tree(r->r, space, height);

        // Imprime o nó atual após o espaço adequado
        printf("\n");
        for (int i = height; i < space; i++)
            printf(" ");
        printf("%d\n", r->v);

        // Processa o nó da esquerda
        print_tree(r->l, space, height);
    }
}

// Função para imprimir a árvore AVL
void print_avl(struct node_avl *r) 
{
    int height = 10;
    print_tree(r, 0, height);
}


void measure_avl_average(void)
{
    struct timespec a, b;
    double total_time;
    unsigned int t;
    FILE *file;
    struct node_avl *r = NULL;
    
    file = fopen("avl_average.txt", "w");
    if (file == NULL)
    {
        perror("Erro");
    }

    srand(time(NULL));
    for (int i = 1000; i <= 100000; i += 1000)
    {
        total_time = 0;
        int key = (rand() % i);
        for (int j = 0; j < 100; j++)
        {
            r = NULL;
            for (int k = 0; k < i; k++)
            {
                int random = rand() % i;
                int random_par = random + (random % 2);
                btinsert_avl(&r, new_node_avl(random_par));
            }
            clock_gettime(CLOCK_MONOTONIC, &b);
            btsearch_avl(r, key);
            clock_gettime(CLOCK_MONOTONIC, &a);

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
            total_time += t; 
            free_tree_avl(r);
        }
        double media = total_time/100;
        fprintf(file, "%d %lf\n", i, media);
    }
    fclose(file);
}

void measure_avl_worst(void)
{
    struct timespec a, b;
    double total_time;
    unsigned int t;
    FILE *file;
    struct node_avl *r = NULL;
    
    file = fopen("avl_worst.txt", "w");
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
                int random = rand() % i;
                random = random * 2;
                btinsert_avl(&r, new_node_avl(random));
            }
            clock_gettime(CLOCK_MONOTONIC, &b);
            btsearch_avl(r, (i + 1));
            clock_gettime(CLOCK_MONOTONIC, &a);
            

            t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
            total_time += t;
            free_tree_avl(r);
        }
        double media = total_time/100;
        fprintf(file, "%d %lf\n", i, media);
    }
    fclose(file);
}


void teste(void)
{
    struct node_avl *r = NULL;
    struct node_avl *result;

    srand(time(NULL));
    for (int i = 10; i <= 20; i += 10)
    {
        r = NULL;
        for (int k = 0; k < i; k++)
        {
            btinsert_avl(&r, new_node_avl(k));
        }
        printf("\n IMPRIMINDO ÁRVORE INSERIDA");
        print_avl(r);
        printf("\n");
        
        for (int j = 0; j < 10; j++)
        {
            int key = (i + j); //rand() % (i * 2);
            printf("\nProcurando por: %d", key);
            result = btsearch_avl(r, key);
            printf("\nRESULTADO DA BUSCA:\n");
            print_avl(result); 
            printf("\n"); 
        }
        free_tree_avl(r);
    }
}