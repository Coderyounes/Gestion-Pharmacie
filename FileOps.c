#include "main.h"


FILE *openFile(char *filename, char *mode) {

    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("something Wrong in the file!!");
        exit(1);
    }
    return fp;
}