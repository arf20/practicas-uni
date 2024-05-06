#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 4. */
double minimo(double *v, int n) {
    double min = 10.0f;
    for (int i = 0; i < n; i++)
        if (v[i] < min) min = v[i];
    return min;
}

double maximo(double *v, int n) {
    double max = -10.0f;
    for (int i = 0; i < n; i++)
        if (v[i] > max) max = v[i];
    return max;
}

/* 7. */
struct Estructura_s {
    int e;
    struct Estructura_s *next;
};
typedef struct Estructura_s *Estructura;

/* 8. */
Estructura crear_estructura(int n, int a, int b) {
    if (n < 0 || (a > b)) return NULL;

    Estructura l = NULL, prev = NULL, new = NULL;
    l = prev  = malloc(sizeof(struct Estructura_s));

    for (int i = 0; i < n; i++) {
        new = malloc(sizeof(struct Estructura_s));

        new->e = a + (rand() % ((b-a)+1));

        a = new->e; /* new->next->e >= new->e */
        prev->next = new;
        prev = new;
    }
    prev->next = NULL;
    return l;
}

/* 12. */
struct ArbolBinario_s {
    int e;
    struct ArbolBinario_s *l, *r;
};
typedef struct ArbolBinario_s *ArbolBinario;

/* 13.a. */
ArbolBinario crea_arbol(int elem) {
    ArbolBinario a = malloc(sizeof(struct ArbolBinario_s));
    a->e = elem;
    a->l = a->r = NULL;
    return a;
}

/* 14. */
void preorden(ArbolBinario a) {
    if (!a) return;
    printf("%d ", a->e);
    preorden(a->l);
    preorden(a->r);
}

int producto(ArbolBinario a) {
    if (!a) return 1;
    return producto(a->l) * producto(a->r) * a->e;
}

void liberar(ArbolBinario a) {
    if (!a) return;
    liberar(a->l);
    liberar(a->r);
    free(a);
}

int main() {
    /* Bloque I */
    /* 1. */
    int n = 0;
    printf("1. n> ");
    do {
        scanf("%d", &n);
    } while (n < 1);

    double *arr = malloc(sizeof(double) * n);

    /* 2. */
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = -10.0 + (20.0*((double)rand() / (double)RAND_MAX));

    /* 3. */
    printf("3. elems de array: ");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");

    /* 5. */
    printf("5. min: %.2f, max = %.2f\n", minimo(arr, n), maximo(arr, n));

    /* 6. */
    free(arr);


    /* Bloque II */
    /* 9. */
    Estructura e = crear_estructura(5, 0, 100);

    /* 10. */
    printf("10. elems de lista enlazada: ");
    for (Estructura i = e->next; i != NULL; i = i->next)
        printf("%d ", i->e);
    printf("\n");

    /* 11. */
    for (Estructura i = e; i != NULL;) {
        Estructura t = i;
        i = i->next;
        free(t);
    }


    /* Bloque III */
    /* 13.b. */
    ArbolBinario arbol = crea_arbol(1);
    arbol->l = crea_arbol(2);
    arbol->r = crea_arbol(3);
    arbol->r->l = crea_arbol(4);

    /* 15.a. */
    printf("15.a. preorden: ");
    preorden(arbol);
    printf("\n");
    /* 15.b. */
    printf("15.b. producto: %d\n", producto(arbol));
    /* 15.c. */
    liberar(arbol);

    return 0;
}
