#include <stdio.h> // pour scanf printf
#include <stdlib.h> // pour malloc, calloc, EXIT_SUCESS

int *allouerTableauEntiersV1(int const taille) {
    int *tab = calloc(taille, sizeof(int));
    return tab;
}

void allouerTableauEntiersV2(int **pTab, int const taille) {
    *pTab = calloc(taille, sizeof(int));
}

void allouerTableauEntiersV3(int** pTab, int* pTaille) {
    *pTab = calloc(*pTaille, sizeof(int));
}

int main() {
    // variables
    int taille;
    int *tab = NULL;

    // input
    do {
        printf("Donnez la taille du tableau : ");
        scanf("%d", &taille);
    } while (taille <= 0);

    // Creation dynamique
    // tab = allouerTableauEntiersV1(taille); // version 1
    // allouerTableauEntiersV2(&tab, taille); // version 2
    allouerTableauEntiersV3(&tab, &taille); // version 3

    // affichage tableau
    for (int i = 0; i < taille; ++i) {
        printf("tab[%d] = %d \n", i, tab[i]);
    }

    // libération mémoire
    free(tab);

    return EXIT_SUCCESS;
}
