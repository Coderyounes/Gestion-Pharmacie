#include "main.h"



void addProduct(void) {
    char buffer[MAX];
    int status;
    FILE *fp;
    Produit_t *newProduct = malloc(sizeof(Produit_t));

    if (!newProduct) {
        perror("Failed to Allocate Memory!");
        exit(1);
    }
    fp = openFile(fileName, "a");
    getchar();
    printf("Enter Code, Name, quantite, price (separated by spaces): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        sscanf(buffer,"%d %s %d %f", &newProduct->code,
                                     newProduct->name,
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
     char buffer[MAX];
     int count = 0;
     FILE *fp;
     fp = openFile(fileName, "a");
     while (count < limit) {
         Produit_t *newProduct = malloc(sizeof(Produit_t));
         if (!newProduct) {
             perror("Failed to Allocate Memory");
             exit(1);
         }
         printf("Enter Code, Name, quantite, price (separated by spaces):");
         getchar();
         if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
             sscanf(buffer,"%d %s %d %f", &newProduct->code,
                                          newProduct->name,
                                          &newProduct->quantite,
                                          &newProduct->price);
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

void readProducts(void) {
    // TODO: Sort the data based on alphabitiques &  based on Prices from High to Low
    char buffer[MAX];
    int code;
    char name[MAX];
    int quantite;
    float price;

    FILE *fp = openFile(fileName, "r");

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


void searchProduct(int identifier) {
    int code, quantity;
    switch(identifier) {
        case 1:
            printf("Enter Product Code: ");
            scanf("%d", &code);
            searchByCode(code);
            break;
        case 2:
            printf("Enter the Quantity: ");
            scanf("%d", &quantity);
            searchByquantite(quantity);
            break;
        case 3:
            searchBystock();
            break;
        default:
            printf("Error: no Search mode Exist");
    }

}

void deleteProduct(int targetcode) {
    char buffer[MAX];
    int code;
    char name[MAX];
    int quantity;
    float price;
    FILE *fp, *temp;
    fp = openFile(fileName, "r");
    temp = openFile("temp.txt", "w+");
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %d %f", &code, name, &quantity, &price);
        if (code != targetcode) {
            fprintf(temp,"%d %s %d %.2f\n", code, name, quantity, price);
        }
    }
    fclose(fp);
    fclose(temp);
    remove(fileName);
    rename("temp.txt", fileName);
}