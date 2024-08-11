#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

// TODO: Define product Struct
// TODO: Define product Operations
// TODO: Define File Operations
// TODO: Define Memory Operations
// TODO: Define Auxillary Functions

typedef struct produit
{
    int code;
    char *name;
    int quatite;
    float price;
} Produit_t;

// Product Operations
void addProduct(Produit_t *newProduct);
// void readProducts(void);
// void updateProduct(void);
// void deleteProduct(void);

// File operations
int openWrite(Produit_t *newProduct);
// void Update(void);
// void Read(void);
// void Delete(void);

// Memory Operations
Produit_t allocateMemory(void);
void freeMemory(Produit_t *product);

// Auxlarry Function;
void Welcome(void);
float CalcTTC(float price);


#endif /* MAIN_H */