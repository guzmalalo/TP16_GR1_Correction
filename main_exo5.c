#include <stdio.h> // scanf, printf, fgets
#include <stdlib.h> // malloc, calloc, realloc, rand, srand
#include <time.h>  // pour time

// creation avec une procedure
void creerTab2DV1(int ***pTab, int *pNbLin, int * pNbCol) {
    printf("Donnez le nb des lignes et des colonnes : ");
    scanf("%d %d", pNbLin, pNbCol);

    *pTab = calloc(*pNbLin , sizeof(int *));

    for (int i = 0; i < *pNbLin; ++i) {
        (*pTab)[i] = calloc(*pNbCol, sizeof(int));
    }

}

// creation avec une fonction
int** creerTab2DV2(int *pNbLin, int * pNbCol) {
    int ** tab = NULL;

    printf("Donnez le nb des lignes et des colonnes : ");
    scanf("%d %d", pNbLin, pNbCol);

    tab = calloc(*pNbLin , sizeof(int *));
    for (int i = 0; i < *pNbLin; ++i) {
        tab[i] = calloc(*pNbCol, sizeof(int));
    }

    return tab;
}

void randTab(int **tab, const int lin, const int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            // i,j
            tab[i][j] = rand() % 256;
        }
    }
}

void afficherTab(int **tab, const int lin, const int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // variables
    int **tab = NULL;
    int col = 0, lin = 0;

    // Creation de matrice
    creerTab2DV1(&tab, &lin, &col);
    //tab = creerTab2DV2(&lin, &col); // version 2

    // matrice aleatoire
    randTab(tab, lin, col);

    // afficher
    afficherTab(tab, lin, col);

    // la liberation se fait dans
    // le sense inverse que l'allocation
    for (int i = 0; i < lin; ++i) {
        free(tab[i]);
    }
    free(tab);

    return 0;
}
