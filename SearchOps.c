#include "main.h"


void searchByCode(int target_code) {
    char buffer[MAX];
    int code;
    char name[MAX];
    int quatity;
    float price;

    FILE *fp = openFile(fileName, "r");

    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%d %s %d %f", &code, name, &quatity, &price);
        if (code == target_code) {
            printf("Product found: %d %s %d %.2f\n", code, name, quatity, price);
        }
    }
}

void searchByquantite(void) {

}

void searchBystock(void) {

}