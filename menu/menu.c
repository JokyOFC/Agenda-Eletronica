#include "../datasources/datasource.h"
#include "../entities/entitie.h"
#include "../utils/clearScreen.h"
#include <stdio.h>
#include "menu.h"

int notClean = 0;

void displayAsciiArt() {
    printf("      _.--._  _.--._\n");
    printf(",-=.-\":;:;:;\\':;:;:;\"-._\n");
    printf("\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
    printf(" \\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
    printf("  \\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
    printf("   \\\\:;:;:;:;:;\\:;::;:;:;:\\\n");
    printf("    \\\\:;:;::;:;:\\:;:;:;::;:\\\n");
    printf("     \\\\;;:;:_:--:\\:_:--:_;:;\\\n");
    printf("      \\\\_.-\"      :      \"-._\\\n");
    printf("       \\`_..--\"\"--.;.--\"\"--.._=>\n");
}

void displayMenu(Node *head) {
    char option;
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Menu ------\n");
        printf("1. Relatórios/Buscas\n");
        printf("2. Remover Contato\n");
        printf("3. Editar Contato\n");
        printf("4. Adicionar novo contato\n");
        printf("5. Fechar agenda\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                clearScreen();
                displayReports(head);
                notClean = 0;
            break;
            case '2':
                // Chamar função para remover contato
                    break;
            case '3':
                // Chamar função para editar contato
                    break;
            case '4':
                // Chamar função para adicionar novo contato
                    break;
            case '5':
                // Função para fechar agenda
                    break;
            case '0':
                clearScreen();
                printf("Saindo...\n");
            break;
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
                notClean = 1;
            break;
        }
    } while (option != '0');
}

void displayReports(Node *head) {
    char option;
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Relatórios/Buscas ------\n");
        printf("1. Listar contatos\n");
        printf("2. Buscar contato pelo nome\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                clearScreen();
                getContacts(head);
                notClean = 1;
            break;
            case '2':
                clearScreen();
                char name[45];
                printf("Insira o nome do contato que deseja buscar:\n");
                scanf("%44s", name);
                getContactsByName(head, name);
                notClean = 1;
            break;
            case '0':
                return;  // Volta para o menu anterior
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != '0');

}
