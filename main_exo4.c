#include <stdio.h>   // pour scanf, printf
#include <stdlib.h>  // pour malloc, calloc, EXIT_SUCCESS

void saisirNotes(float **pTabNotes, const int nbNotes) {
    *pTabNotes = malloc(nbNotes * sizeof(float));

    for (int i = 0; i < nbNotes; ++i) {
        printf("Donnez la note %d : ", i);
        scanf("%f", &((*pTabNotes)[i]));
    }
}

void affichageNotes(float *tabNotes, const int nbNotes) {
    for (int i = 0; i < nbNotes; ++i) {
        printf("Note %d = %.2f\n", i, tabNotes[i]);
    }
}

float moyenne(float *tabNotes, const int nbNotes) {
    float moy = 0.0f;

    for (int i = 0; i < nbNotes; ++i) {
        moy += tabNotes[i];
    }

    return moy / (float) nbNotes;
}

int main() {
    // variables
    float *tabNotes = NULL;
    int nbNotes = 0;

    // input
    printf("Combien de notes souhaitez-vous renseigner ? ");
    scanf("%d", &nbNotes);

    // remplissage du tableau
    saisirNotes(&tabNotes, nbNotes);

    // affichage des notes
    affichageNotes(tabNotes, nbNotes);

    // calcul de la moyenne
    printf("La moyenne est : %.2f\n", moyenne(tabNotes, nbNotes));

    // libération mémoire
    free(tabNotes);

    return EXIT_SUCCESS;
}
