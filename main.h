#ifndef MAIN_H
#define MAIN_H

#define MAX 1024
#define fileName "data.txt"
#define FMEMO "Failed to Allocate Memory!"
#define sellFile "sellLog.txt"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct produit
{
    int code;
    char name[MAX];
    int quantite;
    float price;
} Produit_t;

// TODO: new struct to handle the sell Stats

// Product Operations
void addProduct(void);
void addProducts(int limit);
void readProducts(int mode);
void deleteProduct(int targetcode);

// Search & their types
void searchProduct(int identifier);
void searchByCode(int target_code);
void searchByquantite(int targetquantity);
void searchBystock(void);

// File operations
FILE *openFile(char *filename, char *mode);

// Stock Operations
void addStock(int target_code, int aliment);
void displayStats(void);
void sellProduct(int code, int quantity);

// Auxlarry Function;
void Welcome(void);
float CalcTTC(float price);
int countLines(FILE *fp);

// Sort Operations
void bubbleSortByNames(Produit_t products[], int count);
void bubbleSortByPrice(Produit_t products[], int count);
void defaultSort(FILE *fp);
void sortByprice(FILE *fp);
void sortByAlphbet(FILE *fp);


#endif /* MAIN_H */