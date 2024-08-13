#include "main.h"



void Welcome(void) {
    printf("\nChoisie Votre Operation par numbre: \n"
           "0: Exit le Program\n"
           "1: Ajouter Un Produit\n"
           "2: Ajouter des Produits\n"
           "3: Lister tous les Produits\n"
           "4: Supprimer un Produit\n"
           "5: Operation de Recherche\n"
           "6: Alimenter le Stock\n"
           "7: Acheter Un Produit\n"
           "8: Lister les Statistique de vente\n");
}


float CalcTTC(float price) {
    float new = (price * 15) / 100 ;
    return new + price;
}

void defaultSort(FILE *fp) {
    char buffer[MAX];
    Produit_t *tempProduct = malloc(sizeof(Produit_t));
    if (tempProduct == NULL) {
        perror(FMEMO);
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%d %s %d %f", &tempProduct->code,
                                      tempProduct->name,
                                      &tempProduct->quantite,
                                      &tempProduct->price);
        printf("Product %d: %s, Price: %.2f DH, Price TTC: %.2f DH, Etat De Stock: %d\n",
               tempProduct->code,
               tempProduct->name,
               tempProduct->price,
               CalcTTC(tempProduct->price),
               tempProduct->quantite);
    }
    free(tempProduct);
}

void sortByprice(void) {}
void sortByAlphbet(void) {}