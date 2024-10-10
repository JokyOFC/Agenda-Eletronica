#include "../datasources/datasource.h"
#include "../entities/entitie.h"
#include <stdio.h>

void displayMenu(Node *head) {
  int option;
  do {
    printf("------ Menu ------\n");
    printf("1. Listar contatos\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
      getContacts(head);
      break;
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }
  } while (option != 0);
}
