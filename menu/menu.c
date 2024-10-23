#include "../datasources/datasource.h"
#include "../entities/entitie.h"
#include "../utils/clearScreen.h"
#include "../utils/stringCreate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    srand(time(NULL));
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
                displayInclude(&head);
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
                // Chamar função para Buscar Contatos de um Bairro em Específico
                clearScreen();
                printf("Insira o bairro que deseja buscar:\n");

                char *dynamicStringInput = stringCreateInput();

                if(dynamicStringInput != NULL) {
                    getContacByNeighborhood(head, dynamicStringInput);

                    free(dynamicStringInput);
                } else {
                    printf("Erro ao capturar o bairro.\n");
                }

                notClean = 1;
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

void displayInclude(Node **head) {
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
                clearScreen();
                // Adicionar Contato
                printf("Insira as informações do novo contato: \n");
                char id[10];
                char name[50];
                char lastName[50];
                int age;
                char taxNumber[14];
                char neighborhood[50];
                char email[100];
                char phone[20];
                printf("Nome: ");
                scanf("%49s", name);
                printf("Sobrenome: ");
                scanf("%49s", lastName);
                printf("Idade: ");
                scanf("%d", &age);
                printf("RG/CPF: ");
                scanf("%13s", taxNumber);
                printf("Bairro: ");
                scanf("%49s", neighborhood);
                printf("Email: ");
                scanf("%99s", email);
                printf("Telefone: ");
                scanf("%19s", phone);

                int haveDependents = 0;
                char nameDependent[50];
                int ageDependent = 0;
                //gera um número aleatório entre 1 e 1000 para colocar no id
                snprintf(id, sizeof(id), "%03d", rand() % 1000);
                clearScreen();
                Node *newContact = createContact(id, name, lastName, age, taxNumber, neighborhood, email, phone);
                printf("Possui dependentes? \n 1-SIM \n 0-NAO\n");

                scanf("%d", &haveDependents);

                if(haveDependents == 1) {
                    printf("Insira os dados do dependente:\n");
                    printf("Nome: ");
                    scanf("%49s", nameDependent);
                    printf("Idade: ");
                    scanf("%d", &ageDependent);
                    addDependent(&newContact->contact, nameDependent, ageDependent);
                }

                insertContact(head, newContact);
                notClean = 1;
                    break;
            case '2':
                // Adicionar Dependente
                    break;
            case '0':
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != '0');
}
