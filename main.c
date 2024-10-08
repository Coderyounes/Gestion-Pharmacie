#include "main.h"

/**
*
*/

int main(void) {
    int Ops, limit, identifier, code, aliment, unit, mode, choice;
    FILE *fp;
    char *symbol = "*******";
    printf("%s Bienvenue!%s\n\n%sGestion Des Produits%s\n", symbol, symbol, symbol, symbol);

    while(1) {
        Welcome();
        printf("Enter the Operation Number: ");
        scanf("%d", &Ops);
        switch(Ops) {
            case 0:
                printf("Program is Closing....\n");
                exit(0);
            case 1:
                addProduct();
                break;
            case 2:
                printf("How many Product you want to Enter: ");
                scanf("%d", &limit);
                addProducts(limit);
                break;
            case 3:
                printf("Select the Sort Mode\n1: by Price\n2: By alphabet\n0: default\n");
                printf("enter your choice: ");
                scanf("%d", &mode);
                readProducts(mode);
                break;
            case 4:
                printf("Delete Operation, Enter Product Code: ");
                scanf("%d", &code);
                deleteProduct(code);
                break;
            case 5:
                printf("Select Search mode\n0: Break\n1: Search by Code\n2: Search By quantite\n3: Search By Stock\n");
                printf("Enter Your Choice: ");
                scanf("%d", &identifier);
                if (identifier == 0) {
                    break;
                }
                searchProduct(identifier);
                break;
            case 6:
                printf("Enter Product Code: ");
                scanf("%d", &code);
                printf("How much unit to add: ");
                scanf("%d", &unit);
                addStock(code, unit);
                break;
            case 7:
                printf("Enter Product Code: ");
                scanf("%d", &code);
                printf("How much unit to sell: ");
                scanf("%d", &aliment);
                sellProduct(code, aliment);
                break;
            case 8:
                printf("1: Show all the Sells\n2: Higher Sell of the day\n3: Cheapest Sell of the day\n4: average sells\n");
                printf("Enter your Choice: ");
                scanf("%d", &choice);
                getStat(choice);
                break;
            default:
                printf("Error: Enter number from 0 to 8\n");
        }
    }
    return (0);
}