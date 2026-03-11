#include <stdio.h> // scanf, printf, fgets
#include <stdlib.h> // malloc, calloc, realloc, rand, srand
#include <time.h>  // pour time

int main() {
    srand(time(NULL));

    // variables
    int ** tab = NULL;
    int col =0, lin =0;

    // input
    printf("Donnez le nb des lignes et des colonnes : ");
    scanf("%d %d", &lin, &col);

    // allocation dynamique
    tab  =  calloc(lin, sizeof(int *));
    for (int i = 0; i < lin; ++i) {
        tab[i] =calloc(col, sizeof(int));
    }

    // matrice aleatoire
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            // i,j
            tab[i][j] = rand()%256;
        }
    }

    // afficher
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
           printf("%d ", tab[i][j]);
        }

        printf("\n");
    }

    // la liberation se fait dans
    // le sense inverse que l'allocation
    for (int i = 0; i < lin; ++i) {
        free(tab[i]);
    }
    free(tab);

    return 0;
}