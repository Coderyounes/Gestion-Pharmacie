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

void readProducts(void) {
    // TODO: Sort the data based on alphabitiques &  based on Prices from High to Low
    char buffer[MAX];
    int code;
    char name[MAX];
    int quantite;
    float price;

    FILE *fp = openRead();

    while(fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%d %s %d %f", &code, name, &quantite, &price);
        printf("Product %d: %s, Price: %.2f DH, Price TTC:  %.2f DH, Etat De Stock: %d\n", code,
                                                                                            name,
                                                                                            price,
                                                                                            CalcTTC(price),
                                                                                            quantite);
    }

    fclose(fp);
}