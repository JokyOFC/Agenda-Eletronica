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
        printf("4. Adicionar Novo Contato\n");
        printf("0. Fechar Agenda\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                clearScreen();
                displayReports(head);
                notClean = 0;
            break;
            case '2':
                clearScreen();
                displayRemove(head);
                notClean = 0;
            break;
            case '3':
                // Chamar função para editar contato
                    break;
            case '4':
                clearScreen();
                displayInclude(head);
                notClean = 0;
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
        printf("1. Listar Contatos\n");
        printf("2. Listar Contatos de um Bairro Específico\n");
        printf("3. Buscar Contato em Específico e Seus Dependentes\n");
        printf("4. Listar Dependentes Menores de 18 Anos\n");
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
                // Chamar função para Listar Contatos de um Bairro Específico
            break;
            case '3':
                // Chamar função para Buscar Contato em Específico e Seus Dependentes
                clearScreen();
                char name[45];
                printf("Insira o nome do contato que deseja buscar:\n");
                scanf("%44s", name);
                getContactsByName(head, name);
                notClean = 1;                    
            break;
            case '4':
                // Chamar função para Listar Dependentes Menores de 18 Anos
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

void displayRemove(Node *head) {
    char option;
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Remover ------\n");
        printf("1. Contato\n");
        printf("2. Dependete\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                // Remover Contato
                    break;
            case '2':
                // Remover Dependente
                    break;            
            case '0':
                return;
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != '0');
}

void displayInclude(Node *head) {
    char option;
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Incluir ------\n");
        printf("1. Contato\n");
        printf("2. Dependete\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                // Adicionar Contato
                    break;
            case '2':
                // Adicionar Dependente
                    break;            
            case '0':
                return;
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != '0');
}