#include "main.h"

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

void bubbleSortByPrice(Produit_t products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (products[j].price < products[j + 1].price) {
                Produit_t temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void bubbleSortByNames(Produit_t products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(products[j].name, products[j + 1].name) > 0) {
                Produit_t temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void sortByprice(FILE *fp) {
    char buffer[MAX];
    int i = 0, lines = countLines(fp);
    Produit_t products[lines];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %d %f", &products[i].code,
                                      products[i].name,
                                      &products[i].quantite,
                                      &products[i].price);
        i++;
    }
    bubbleSortByPrice(products, lines);
    for (i = 0; i < lines; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n",
               products[i].code,
               products[i].name,
               products[i].quantite,
               products[i].price);
    }
}

void sortByAlphbet(FILE *fp) {
    char buffer[MAX];
    int i = 0, lines = countLines(fp);
    Produit_t products[lines];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %d %f", &products[i].code,
                                      products[i].name,
                                      &products[i].quantite,
                                      &products[i].price);
        i++;
    }
    bubbleSortByNames(products, lines);
    for (i = 0; i < lines; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n",
               products[i].code,
               products[i].name,
               products[i].quantite,
               products[i].price);
    }
}