#include "main.h"


float allSells(void) {
    char buffer[MAX];
    float total = 0;
    Log_t *tempSells;
    FILE *fp;

    fp = openFile(sellFile, "r");
    tempSells = malloc(sizeof(Log_t));
    if (!tempSells) {
        perror(FMEMO);
        exit(1);
    }
	struct tm *t = timeNow();
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%f %s %s %d %s %d", &tempSells->price,
                                      tempSells->weekday,
                                      tempSells->month,
                                      &tempSells->monthday,
									  tempSells->time,
                                      &tempSells->year);
		if ((t->tm_mday == tempSells->monthday)
            && (t->tm_year + 1900 == tempSells->year)
            && (t->tm_mon + 1 == monthEvaluation(tempSells->month))) {
			total += tempSells->price;
				}
    }
    fclose(fp);
    free(tempSells);
    return total;
}

float highSell(void) {
    char buffer[MAX];
    FILE *fp;
    Log_t *tempSells;
    float max = 0;

    tempSells = malloc(sizeof(Log_t));
    if (!tempSells) {
        perror(FMEMO);
        exit(1);
    }
    fp = openFile(sellFile, "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%f %s %s %d %s %d", &tempSells->price,
                          tempSells->weekday,
                          tempSells->month,
                          &tempSells->monthday,
						  tempSells->time,
                          &tempSells->year);
            // TODO: implement the dat CHeck
            if (max < tempSells->price) {
              max = tempSells->price;
            }
        }

    fclose(fp);
    free(tempSells);
    return max;
}

float cheapSell(void) {
    char buffer[MAX];
    FILE *fp;
    Log_t *tempSells;
    float min = highSell();

    tempSells = malloc(sizeof(Log_t));
    if (!tempSells) {
        perror(FMEMO);
        exit(1);
    }
    fp = openFile(sellFile, "r");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%f %s %s %d %s %d", &tempSells->price,
                          tempSells->weekday,
                          tempSells->month,
                          &tempSells->monthday,
						  tempSells->time,
                          &tempSells->year);
            // TODO: implement the dat CHeck
            if (tempSells->price < min) {
              min = tempSells->price;
            }
        }

    fclose(fp);
    free(tempSells);
    return min;
}

float averageSell(void) {
    char buffer[MAX];
    FILE *fp;
    Log_t *tempSells;
    int lines;
    float total;
    float min = highSell();

    tempSells = malloc(sizeof(Log_t));
    if (!tempSells) {
        perror(FMEMO);
        exit(1);
    }
    fp = openFile(sellFile, "r");
    lines = countLines(fp);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "%f %s %s %d %s %d", &tempSells->price,
                          tempSells->weekday,
                          tempSells->month,
                          &tempSells->monthday,
						  tempSells->time,
                          &tempSells->year);
            total += tempSells->price;
        }

    fclose(fp);
    free(tempSells);
    return total / lines;
}

void getStat(int choice) {
    switch(choice) {
        case 1:
            printf("the Total Sells: %.2f\n", allSells());
            break;
        case 2:
            printf("The High Product Sale today is %.2f\n", highSell());
            break;
        case 3:
            printf("The lowest Product sale today is %.2f\n", cheapSell());
            break;
        case 4:
            printf("The average Sale is %.2f\n", averageSell());
            break;
        default:
            printf("Enter a number from 1 to 3\n");
    }
}