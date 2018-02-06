#include <stdlib.h>
#include <stdio.h>
#include "POLYNOMIALS.h"
#include <unistd.h>

struct poly { int N; int* a; };

Poly POLYterm(int coeff, int exp) {
    int i; Poly t = malloc(sizeof(*t));
    t->a = malloc((exp+1) * sizeof(int));
    t->N = exp + 1; t->a[exp] = coeff;
    for (i = 0; i < exp; i++) t->a[i] = 0;
    return t;
}

Poly POLYadd(Poly p, Poly q) {
    int i; Poly temp;
    if (p->N < q->N) {
        temp = p; p = q; q = temp;
    }
    for (i = 0; i < q->N; i++) p->a[i] += q->a[i];
    return p;
}

Poly POLYmult(Poly p, Poly q) {
    int i, j; Poly t = POLYterm(0, (p->N-1)+(q->N-1));
    for (i = 0; i < p->N; i++)
        for (j = 0; j < q->N; j++) 
            t->a[i+j] += p->a[i] * q->a[j];
    return t;
}

float POLYeval(Poly p, float x) {
    int i; float res = 0;
    for (i = p->N-1; i >= 0; i--) {
        res = res * x + p->a[i]; 
    }
    return res;
}

void showPOLY(Poly p) {
    int i;
    for (i = p->N-1; i >= 0; i-- ) {
        if (i != 0)
            printf("%d * x^%d +  ", p->a[i], i);
        else 
            printf("%d\n", p->a[i]);
    }
}
