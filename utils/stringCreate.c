//
// Created by Joaquim Esteves Filho on 20/10/24.
//

#include "stringCreate.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Função para criar um input de string dinamica ao invés de utilizar o scanf.
char *stringCreateInput() {
    size_t bufferSize = 32;  // Tamanho inicial da alocação
    size_t length = 0;
    char *dynamicStringInput = malloc(bufferSize * sizeof(char));

    if (dynamicStringInput == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }

    // Limpar o buffer de entrada após qualquer scanf anterior
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    // Lê os caracteres até encontrar um ENTER - Final da nossa string
    while ((ch = getchar()) != '\n' && ch != EOF) {
        dynamicStringInput[length++] = ch;

        // Se o tamanho atual atingir o tamanho do buffer, realocar
        if (length >= bufferSize) {
            bufferSize *= 2;  // Duplicar o tamanho do buffer
            dynamicStringInput = realloc(dynamicStringInput, bufferSize * sizeof(char));
            if (dynamicStringInput == NULL) {
                printf("Erro de alocação de memória!\n");
                return NULL;
            }
        }
    }

    return dynamicStringInput;
}
