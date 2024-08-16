#include "main.h"



void Welcome(void) {
    printf("\nChoisie Votre Operation par numbre: \n"
           "0: Exit le Program\n"
           "1: Ajouter Un Produit\n"
           "2: Ajouter des Produits\n"
           "3: Lister tous les Produits\n"
           "4: Supprimer un Produit\n"
           "5: Operation de Recherche\n"
           "6: Alimenter le Stock\n"
           "7: Acheter Un Produit\n"
           "8: Lister les Statistique de vente\n");
}


float CalcTTC(float price) {
    float new = (price * 15) / 100 ;
    return new + price;
}


int countLines(FILE *fp) {
    int count = 0;
    char buffer[MAX];

    while(fgets(buffer, sizeof(buffer), fp)) {
        count++;
    }
    rewind(fp);
    return count;
}

struct tm *timeNow(void) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);
    return tm_info;
}

int monthEvaluation(char *month) {
    char *months[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            return i + 1;
        }
    }

    return -1;
}