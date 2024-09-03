#include <stdio.h>
#include <stdlib.h>
#include "utility.h"


void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int b_search (int *v, int s, int e, int k)
{
    int m;
    if (s <= e)
    {
        m = (s + e)/2;
        if (k == v[m])
        {
            return m;
        }
        if (k < v[m])
        {
            return b_search(v, s, m - 1, k);
        }
        return b_search(v, m + 1, e, k);
    }
    return 0;
}