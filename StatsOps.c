#include "main.h"


float allSells(void) {
    char buffer[MAX];
    int lines;
    float total = 0;
    Log_t *tempSells;
    FILE *fp;

    fp = openFile(sellFile, "r");
    lines = countLines(fp);
    tempSells = malloc(sizeof(Produit_t));
    if (!tempSells) {
        perror(FMEMO);
        exit(1);
    }
    /*
    float price;
    char weekday[20];
    char month[20];
    int  monthday;
    char time[20];
    int year;*/
    // 25.30 Mon Aug 12 23:55:52 2024
    // TODO: find Solution to parse the day & Hour and use them to aggregate the total
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%f %s %d %s %d", &tempSells->price,
                                      tempSells->month,
                                      &tempSells->monthday,
                                      tempSells->time,
                                      &tempSells->year);
        total += tempSells->price;
    }
    fclose(fp);
    free(tempSells);
    return total;
}

//void highSell(void) {}

//void cheapSell(void) {}

//void averageSell(void) {}

void getStat(int choice) {
    switch(choice) {
        case 1:
            printf("the Total Sells: %.2f", allSells());
            break;
        case 2:
            //highSell();
            break;
        case 3:
            //cheapSell();
            break;
        case 4:
            //averageSell();
            break;
        default:
            printf("Enter a number from 1 to 3\n");
    }
}