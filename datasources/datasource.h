#ifndef DATASOURCE_H 	//Verificação definição dos dados para criação dos dependentes e contatos
#define DATASOURCE_H 	//Definindo os dados e chamadas para criação dos dependentes e contatos

#include "../entities/entitie.h"

//Criando o No para criação de contato
Node *create_contact(const char *id, const char *name, const char *lastName,
                     int age, const char *taxNumber, const char *neighborhood,
                     const char *email, const char *phone); 

//Criando a chamada das função
void insert_contact(Node **head, Node *new_contact); 

void getContacts(Node *head);
void getContactsWhithoutDependents(Node *head);
void getContacByNeighborhood(Node *head, char neighborhood[]);
void getContactsByName(Node *head, char name[]);
void getAllDependentsByAgeAndContactName(Node *head);
void addDependent(Contact *contact, const char *name, int age);
void editContact(Node *head, const char *newName,const char *newLastName, int newAge, const char *newTaxNumber,const char *newNeighborhood, const char *newEmail,const char *newPhone);
void editDependent(DependentNode *dependent, const char *newName, int newAge);
void removeContact(Node **head, const char *contactName);
void removeDependent(Node **head, const char *contactName, const char *dependentName);


void createMockContacts(Node **head);
void createMockContactWithDependent(Node **head);

Node *searchContactAndReturn(Node **head, const char *name);
void saveContactsToFile(Node *head);

#endif
