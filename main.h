#ifndef MAIN_H
#define MAIN_H
#define MAX 1024
#define fileName "data.txt"
#include <stdio.h>
#include <stdlib.h>


typedef struct produit
{
    int code;
    char name[MAX];
    int quantite;
    float price;
} Produit_t;

// Product Operations
void addProduct(void);
void addProducts(int limit);
void readProducts(void);
void deleteProduct(int targetcode);
void searchProduct(int identifier);

// Search types
void searchByCode(int target_code);
void searchByquantite(int targetquantity);
void searchBystock(void);

// File operations
FILE *openFile(char *filename, char *mode);

// Auxlarry Function;
void Welcome(void);
float CalcTTC(float price);


#endif /* MAIN_H */