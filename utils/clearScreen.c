#include <stdlib.h>
#include <stdio.h>

#include "clearScreen.h"

#ifdef _WIN32 
    #include <windows.h>
#endif


void clearScreen() {
    #ifdef _WIN32  
        system("cls");
    #elif __linux__ || __APPLE__ 
        system("clear");
    #else
        printf("Não foi possível limpar a tela. Sistema não suportado.\n");
    #endif
}

