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