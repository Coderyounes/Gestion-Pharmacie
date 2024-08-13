#include "main.h"



void addStock(int target_code, int aliment) {
    char buffer[MAX];
    Produit_t *tempProduct;
    FILE *fp, *temp;

    tempProduct = malloc(sizeof(Produit_t));
    if (!tempProduct) {
        perror(FMEMO);
        exit(1);
    }
    fp = openFile(fileName, "r");
    temp = openFile("temp.txt", "w+");

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %d %f", &tempProduct->code,
                                      tempProduct->name,
                                      &tempProduct->quantite,
                                      &tempProduct->price);
        if (tempProduct->code == target_code) {
            tempProduct->quantite += aliment;
        }

        fprintf(temp, "%d %s %d %.2f\n", tempProduct->code,
                                      tempProduct->name,
                                      tempProduct->quantite,
                                      tempProduct->price);
    }

    fclose(fp);
    fclose(temp);
    remove(fileName);
    rename("temp.txt", fileName);
    free(tempProduct);
}

void sellProduct(int target_code, int quantity) {
    char buffer[MAX];
    Produit_t *tempProduct;
    FILE *fp, *temp, *fsell;
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    tempProduct = malloc(sizeof(Produit_t));
    if (!tempProduct) {
        perror(FMEMO);
        exit(1);
    }
    fp = openFile(fileName, "r");
    temp = openFile("temp.txt", "w+");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %d %f", &tempProduct->code,
                                      tempProduct->name,
                                      &tempProduct->quantite,
                                      &tempProduct->price);
        if (tempProduct->code == target_code) {
            fsell = openFile(sellFile, "a+");
            printf("%.2f %s", CalcTTC(tempProduct->price) * quantity, asctime(tm_info));
            fprintf(fsell, "%.2f %s", CalcTTC(tempProduct->price) * quantity, asctime(tm_info));
            tempProduct->quantite -= quantity;
        }

        fprintf(temp, "%d %s %d %.2f\n", tempProduct->code,
                                      tempProduct->name,
                                      tempProduct->quantite,
                                      tempProduct->price);
    }

    fclose(fp);
    fclose(temp);
    fclose(fsell);
    remove(fileName);
    rename("temp.txt", fileName);
    free(tempProduct);
}