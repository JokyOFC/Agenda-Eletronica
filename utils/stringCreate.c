#include "stringCreate.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char *stringCreateInput() {
    size_t bufferSize = 32; 
    size_t length = 0;
    char *dynamicStringInput = malloc(bufferSize * sizeof(char));

    if (dynamicStringInput == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }

    
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        dynamicStringInput[length++] = ch;

       
        if (length >= bufferSize) {
            bufferSize *= 2; 
            dynamicStringInput = realloc(dynamicStringInput, bufferSize * sizeof(char));
            if (dynamicStringInput == NULL) {
                printf("Erro de alocação de memória!\n");
                return NULL;
            }
        }
    }
    
    dynamicStringInput[length] = '\0';

    return dynamicStringInput;
}

