#include "main.h"



void addProduct(void) {
    char buffer[MAX];
    int status;
    Produit_t *newProduct = malloc(sizeof(Produit_t));

    if (!newProduct) {
        perror("Failed to Allocate Memory!");
        exit(1);
    }
    getchar();
    printf("Enter Code, Name, quantite, price (separated by spaces): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        sscanf(buffer,"%d %s %d %f", &newProduct->code,
                                     newProduct->name,
                                     &newProduct->quantite,
                                     &newProduct->price);
    }
    status = openWrite(newProduct);
    if (status == 0) {
        printf("Data Sotred");
    } else {
        printf("Failed to Store Data!");
    }
}