//
// Created by Shift on 11/10/2024.
//

#include "clearScreen.h"
#include <stdlib.h>
#include <stdio.h>
#ifdef _WIN32  // Apenas para Windows
    #include <windows.h>
#endif

// Função para limpar a tela de forma portátil
void clearScreen() {
    printf("Chamando clearScreen()...\n");
    #ifdef _WIN32  // Se estiver compilando no Windows
        system("cls");
    #elif __linux__ || __APPLE__  // Se estiver compilando no Linux ou MacOS
        system("clear");
    #else
        printf("Não foi possível limpar a tela. Sistema não suportado.\n");
    #endif
}
