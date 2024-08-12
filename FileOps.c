#include "main.h"


FILE *openFile(void) {
    return fopen("data.txt", "a");
}

int openWrite(Produit_t *newProduct) {

    FILE *fp = openFile();
    if (fp == NULL) {
        printf("something Wrong with Write in the file!!");
        return(1);
    }
    fprintf(fp,"%d %s %d %.2f\n", newProduct->code,
                              newProduct->name,
                              newProduct->quantite,
                              newProduct->price);
    fclose(fp);
    return (0);
}