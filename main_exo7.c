#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int taille = 5;
    int *favori = NULL;
    int *tab = malloc(taille * sizeof(int));

    for (int i = 0; i < taille; i++) {
        tab[i] = i + 1;
    }

    favori = &tab[2];

    printf("Favori :\t%p\n", favori);
    printf("Case [2] :\t%p\n", &tab[2]);

    taille = rand() + 3;

    printf("Realloc...\n");

    tab = realloc(tab, taille * sizeof(int));

    printf("Favori :\t%p\n", favori);
    printf("Case [2] :\t%p\n", &tab[2]);

    free(tab);
    tab = NULL;

    return 0;
}
