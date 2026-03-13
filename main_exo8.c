#include <stdio.h>
#include <stdlib.h>

struct c{
    int x, y;
};
typedef struct c Coord;

void ajouter(Coord* tab[6], int* tLog, int tPhy) {

    // on verifie si le tab est plein
    // cad si la taille logique >= à la taille physique
    if (*tLog >= tPhy) {
        printf("Désolé le tableau est plein");
        return;
    }
    // si non, on a assez de place, on rajoute une coordonnée
    // Demander les coordonnées x et y
    int x, y;
    printf("Donnez x et y");
    scanf("%d %d", &x, &y);

    // creation d'une structure Coord
    Coord* ptemp = calloc(1, sizeof(Coord));
    ptemp->x = x;
    ptemp->y= y;

    // Ajouter la nouvelle coordonnée dans le tableau
    tab[*tLog] = ptemp;

    // Modification de la taille logique (+1)
    (*tLog)++;
}

void afficher(Coord* tab[6], int tLog) {
    printf("\n----Liste de points----\n");
    for (int i = 0; i < tLog; ++i) {
        printf("Point %d (%d, %d)\n", i, tab[i]->x, tab[i]->y);
    }
    printf("\n----Fin de la liste----\n");
}

int main() {
    // Définition des variables
    Coord* tab[6] ={0}; // tableau de pointeurs de Coordonées

    int nbCoord = 0 ;   // c'est la taille logique
    int nbCoordMax = 6; // c'est la taille physique
    int choix =0;

    // Menu
    do {
        printf("\n-----Menu------\n");
        printf("1 : Ajouter une coordonée\n");
        printf("2 : Afficher les coordonées\n");
        printf("3 : Sortir\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter(tab,&nbCoord, 6);
                break;
            case 2:
                afficher(tab, nbCoord);
                break;
            default:
                break;
        }
    } while (choix !=3);

    // liberation
    for (int i = 0; i < nbCoord; ++i) {
        free(tab[i]);
    }


    return 0;
}