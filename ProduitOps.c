#include "main.h"



void addProduct(void) {
    char buffer[MAX];
    Produit_t *newProduct = malloc(sizeof(Produit_t));
    if (!newProduct) {
        perror("Failed to Allocate Memory!");
        exit(1);
    }
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        sscanf(buffer,"%d %s %d %f", &newProduct->code,
                                     newProduct->name,
                                     &newProduct->quantite,
                                     &newProduct->price);
    }

}