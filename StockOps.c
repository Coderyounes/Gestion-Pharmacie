#include "main.h"



void addStock(int target_code, int aliment) {
    char buffer[MAX];
    Produit_t *tempProduct;
    FILE *fp, *temp;

    tempProduct = malloc(sizeof(Produit_t));
    if (!tempProduct) {
        perror("Failed to Allocate Memory!");
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
// TODO: create a function to handle the selling Operations
// TODO: create a function to manage the Stock
// TODO: create a function to Display Selling Stats