#include "datasource.h"
#include "../entities/entitie.h"
#include "../utils/bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getContacts(Node *head) {
  Node *current = head;

  printf("\n------ Lista de Contatos ------\n");

  if (current == NULL) {
    printf("Nenhum contato encontrado.\n\n");
    return;
  }

  while (current != NULL) {
    printf("ID: %s\n", current->contact.id);
    printf("Name: %s %s\n", current->contact.name, current->contact.lastName);
    printf("Age: %d\n", current->contact.age);
    printf("Tax Number: %s\n", current->contact.taxNumber);
    printf("Neighborhood: %s\n", current->contact.neighborhood);
    printf("Email: %s\n", current->contact.email);
    printf("Phone: %s\n", current->contact.phone);

    if (current->contact.dependents != NULL) {
      printf("Dependentes:\n");
      DependentNode *depCurrent = current->contact.dependents;
      while (depCurrent != NULL) {
        printf("\t- Nome: %s, Idade: %d\n", depCurrent->dependent.name,
               depCurrent->dependent.age);
        depCurrent = depCurrent->next;
      }
    } else {
      printf("Nenhum dependente cadastrado.\n");
    }

    printf("----------------------------\n");
    current = current->next;
  }
  printf("\n");
}

void getContactsWhithoutDependents(Node *head) {
  Node *current = head;

  printf("\n------ Lista de Contatos ------\n");

  if (current == NULL) {
    printf("Nenhum contato encontrado.\n\n");
    return;
  }

  while (current != NULL) {
    printf("ID: %s\n", current->contact.id);
    printf("Name: %s %s\n", current->contact.name, current->contact.lastName);
    printf("Age: %d\n", current->contact.age);
    printf("Tax Number: %s\n", current->contact.taxNumber);
    printf("Neighborhood: %s\n", current->contact.neighborhood);
    printf("Email: %s\n", current->contact.email);
    printf("Phone: %s\n", current->contact.phone);
    printf("n");
    current = current->next;
  }
  printf("\n");
}

void getContacByNeighborhood(Node *head, char neighborhood[]) {
  Node *current = head;
  int foundContact = 0;

  printf("\n------Contato(s) no bairro: %s------\n", neighborhood);

  while (current != NULL) {
    if (strcmp(current->contact.neighborhood, neighborhood) == 0) {
      printf("ID: %s\n", current->contact.id);
      printf("Name: %s %s\n", current->contact.name, current->contact.lastName);
      printf("Age: %d\n", current->contact.age);
      printf("Tax Number: %s\n", current->contact.taxNumber);
      printf("Neighborhood: %s\n", current->contact.neighborhood);
      printf("Email: %s\n", current->contact.email);
      printf("Phone: %s\n", current->contact.phone);

      if (current->contact.dependents != NULL) {
        printf("Dependentes:\n");
        DependentNode *depCurrent = current->contact.dependents;
        while (depCurrent != NULL) {
          printf("\t- Nome: %s, Idade: %d\n", depCurrent->dependent.name, depCurrent->dependent.age);
          depCurrent = depCurrent->next;
        }
      }
      printf("----------------------------\n");
      foundContact = 1;
    }
    current = current->next;
  }

  if (!foundContact) {
    printf("\nNenhum contato encontrado no bairro: %s.\n", neighborhood);
    printf("----------------------------\n");
  }
  printf("\n");
}

void getContactsByName(Node *head, char name[]) {
  Node *current = head;
  int foundContact = 0;

  printf("\n------Contato(s) com o nome: %s------\n", name);

  while (current !=NULL) {

    if (strcmp(current->contact.name, name) == 0) {
      printf("ID: %s\n", current->contact.id);
      printf("Name: %s %s\n", current->contact.name, current->contact.lastName);
      printf("Age: %d\n", current->contact.age);
      printf("Tax Number: %s\n", current->contact.taxNumber);
      printf("Neighborhood: %s\n", current->contact.neighborhood);
      printf("Email: %s\n", current->contact.email);
      printf("Phone: %s\n", current->contact.phone);

      if (current->contact.dependents != NULL) {
      printf("Dependentes:\n");
      DependentNode *depCurrent = current->contact.dependents;
      while (depCurrent != NULL) {
        printf("\t- Nome: %s, Idade: %d\n", depCurrent->dependent.name,
               depCurrent->dependent.age);
        depCurrent = depCurrent->next;
      }
      } else {
        printf("Nenhum dependente cadastrado.\n");
      }

      printf("----------------------------\n");
      foundContact = 1;
    }
      current = current->next;
  }

  if(!foundContact) {
    printf("\nEsse contato não existe.\n");
    printf("----------------------------\n");
  }
    printf("\n");
}

void getAllDependentsByAgeAndContactName(Contact contacts[], int dependentAge,
                                         char contactName[]) {}

DependentNode *CreateDependent(const char *name, int age) {
  DependentNode *new_dependent = (DependentNode *)malloc(sizeof(DependentNode));
  strcpy(new_dependent->dependent.name, name);
  new_dependent->dependent.age = age;
  new_dependent->next = NULL;
  return new_dependent;
}

void addDependent(Contact *contact, const char *name, int age) {
  DependentNode *new_dependent = CreateDependent(name, age);
  if (contact->dependents == NULL) {
    contact->dependents = new_dependent;
  } else {
    DependentNode *current = contact->dependents;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_dependent;
  }
}

Node *createContact(const char *id, const char *name, const char *lastName,
                    int age, const char *taxNumber, const char *neighborhood,
                    const char *email, const char *phone) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  strcpy(new_node->contact.id, id);
  strcpy(new_node->contact.name, name);
  strcpy(new_node->contact.lastName, lastName);
  new_node->contact.age = age;
  strcpy(new_node->contact.taxNumber, taxNumber);
  strcpy(new_node->contact.neighborhood, neighborhood);
  strcpy(new_node->contact.email, email);
  strcpy(new_node->contact.phone, phone);
  new_node->next = NULL;
  return new_node;
}

void insertContact(Node **head, Node *new_contact) {
  Node *current = *head;
  int isExists = 0;
  while (current != NULL){
    if (strcmp(current->contact.name, new_contact->contact.name) == 0 && strcmp(current->contact.lastName, new_contact->contact.lastName)  == 0) {
      printf("Já existe um contato com esse nome: %s %s \n\n", new_contact->contact.name, new_contact->contact.lastName);
      isExists = 1;
    } 
    current = current->next;
  }
  
  if(isExists == 0) {
    new_contact->next = *head;
    *head = new_contact;
    bubbleSort(head);
    printf("Contato criado com sucesso.\n\n");
  }
  
}

void createMockContacts(Node **head) {
  insertContact(head, createContact("3", "Alice", "Johnsonnn", 42, "45678912300",
                                    "Midtown", "alice.johnson@example.com",
                                    "71982659845"));
  insertContact(head,
                createContact("1", "Alice", "Doe", 35, "12345678901", "Downtown",
                              "john.doe@example.com", "71982659845"));
  insertContact(head,
                createContact("2", "Jane", "Smith", 28, "98765432100", "Uptown",
                              "jane.smith@example.com", "71982659845"));
  insertContact(head,
                createContact("4", "Alex", "Rock", 30, "84738574938", "Midtown",
                              "alexrock@example.com", "71935478132"));
  insertContact(head,
                createContact("5", "Randvi", "Crow", 30, "95423915217", "Westonty",
                              "randvi@example.com", "71858421017"));
}

void createMockContactWithDependent(Node **head) {
  Node *contact =
      createContact("4", "Bob", "Builder", 50, "32165498700", "Hometown",
                    "bob.builder@example.com", "71982659845");
  addDependent(&contact->contact, "Alice", 25);
  addDependent(&contact->contact, "Tom", 15);
  insertContact(head, contact);
}
