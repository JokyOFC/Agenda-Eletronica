#ifndef MENU_H 	//Verificando definição de cabeçalho
#define MENU_H	//Se não for definido, passa a definir

#include "../entities/entitie.h" 	//Inclui o arquivo de cabeçalho

void displayMenu(Node *head);
void displayReports(Node *head);
void displayRemove(Node *head);
void displayInclude(Node **head);
void displayEdit(Node *head);
void displayEditContact(Node *head);

#endif	//Finalizar o processo de inclusão do cabeçalho

