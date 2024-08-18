#include "main.h"

// TODO: Implement a method To Set the ID autoIncrement
// TODO: the IDeas is to generate the ID based on the File Lines
// TODO: After the Delete we should Have a function reOrganize the IDs again

void addProduct(void) {
    char buffer[MAX];
    int status;
    int lines;
    FILE *fp;
    Produit_t *newProduct = malloc(sizeof(Produit_t));
    if (!newProduct) {
        perror(FMEMO);
        exit(1);
    }
    fp = openFile(fileName, "a");
    lines = countLines(fp);
    newProduct->code = lines + 1;
    getchar();
    printf("Enter Name, quantite, price (separated by spaces): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        sscanf(buffer,"%s %d %f", newProduct->name,
                                     &newProduct->quantite,
                                     &newProduct->price);
    }

    fprintf(fp,"%d %s %d %.2f\n", newProduct->code,
                          newProduct->name,
                          newProduct->quantite,
                          newProduct->price);
    fclose(fp);
}

void addProducts(int limit) {
     char buffer[MAX], c;
     int count = 0;
     FILE *fp;
     int track;

     fp = openFile(fileName, "a");
     track = countLines(fp); // TODO: fix issue return 0 as lines Count
     //printf("Lines are: %d", track);
     getchar();
     while (count < limit) {
         Produit_t *newProduct = malloc(sizeof(Produit_t));
         if (!newProduct) {
             perror("Failed to Allocate Memory");
             exit(1);
         }
         printf("Enter Name, quantite, price (separated by spaces): ");
         if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
             sscanf(buffer, "%s %d %f", newProduct->name,
                                          &newProduct->quantite,
                                          &newProduct->price);
             newProduct->code = track++;
         }
         fprintf(fp,"\n%d %s %d %.2f", newProduct->code,
                               newProduct->name,
                               newProduct->quantite,
                               newProduct->price);
         count++;
         free(newProduct);
     }
     fclose(fp);
}

void readProducts(int mode) {
    FILE *fp = openFile(fileName, "r");
    switch(mode) {
        case 0:
            defaultSort(fp);
            break;
        case 1:
            sortByprice(fp);
            break;
        case 2:
            sortByAlphbet(fp);
            break;
        default:
            printf("Enter a Number From 0 to 2\n");
    }
    fclose(fp);
}

void deleteProduct(int targetcode) {
    char buffer[MAX];
    Produit_t *tempProduct = malloc(sizeof(Produit_t));
    if (tempProduct == NULL) {
        perror(FMEMO);
        exit(1);
    }
    FILE *fp, *temp;
    fp = openFile(fileName, "r");
    temp = openFile("temp.txt", "w+");
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %d %f", &tempProduct->code,
                                      tempProduct->name,
                                      &tempProduct->quantite,
                                      &tempProduct->price);
        if (tempProduct->code != targetcode) {
            fprintf(temp,"%d %s %d %.2f\n", tempProduct->code,
                                            tempProduct->name,
                                            tempProduct->quantite,
                                            tempProduct->price);
        }
        // TODO: Create a Logic to ReOgranize the Data IDs
    }
    fclose(fp);
    fclose(temp);
    remove(fileName);
    rename("temp.txt", fileName);
    free(tempProduct);
}