#ifndef ENTITIE_H 	//Verificação da definição das Entidades
#define ENTITIE_H	//Definindo dados e tipagem para as entidade se ainda não foi definido

//Definição de estrutura dos dependentes
typedef struct { 
  char name[50];
  int age;
} Dependent;

//Definição do No da estrutura dos dependentes
typedef struct DependentNode {
  Dependent dependent;
  struct DependentNode *next;
} DependentNode;

//Definição dos contatos
typedef struct {
  char id[10];
  char name[50];
  char lastName[50];
  int age;
  char taxNumber[14];
  char neighborhood[50];
  char email[100];
  char phone[20];
  DependentNode *dependents;
} Contact;

//Definição do No da testrutura dos contatos
typedef struct Node {
  Contact contact;
  struct Node *next;
} Node;

#endif

