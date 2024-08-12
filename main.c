#include "main.h"

/**
*
*/

int main(void) {
    int Ops;
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
                // TODO: call AddProducts function
                break;
            case 3:
                readProducts();
                break;
            case 4:
                // TODO: Call DeleteProduct Function
                break;
            case 5:
                // TODO: call Search function
                break;
            case 6:
                // TODO: call addStock function
                break;
            case 7:
                // TODO: call buyProduct function
                break;
            case 8:
                // TODO: call DisplayStats function
                break;
            default:
                printf("Error: Enter number from 0 to 8\n");
        }
    }
    return (0);
}