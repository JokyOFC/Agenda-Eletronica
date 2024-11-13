#include "datasource.h"
#include "../entities/entitie.h"
#include "../utils/bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Arquivo de escreve e as fun��es e as definem
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
      do {
	    printf("\t- Nome: %s, Idade: %d\n", depCurrent->dependent.name,
	           depCurrent->dependent.age);
	    depCurrent = depCurrent->next;
	  } while (depCurrent != current->contact.dependents);
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
    if (strcmp(strlwr(current->contact.neighborhood), strlwr(neighborhood)) == 0) {
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
        do {
	    printf("\t- Nome: %s, Idade: %d\n", depCurrent->dependent.name,
	           depCurrent->dependent.age);
	    depCurrent = depCurrent->next;
	  } while (depCurrent != current->contact.dependents);
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
  char tempNameToLowerCase[45];
  char tempLastNameToLowerCase[45];

  printf("\n------Contato(s) com o nome: %s------\n", name);

  while (current !=NULL) {
    
    char fullName[100];
      strcpy(fullName, current->contact.name);
      strcat(fullName, " ");
      strcat(fullName, current->contact.lastName);
      
    if (strcmp(strlwr(current->contact.name), strlwr(name)) == 0 || 
         strcmp(strlwr(fullName), strlwr(name)) == 0) {
                                  
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
      do {
	    printf("\t- Nome: %s, Idade: %d\n", depCurrent->dependent.name,
	           depCurrent->dependent.age);
	    depCurrent = depCurrent->next;
	  } while (depCurrent != current->contact.dependents);
      } else {
        printf("Nenhum dependente cadastrado.\n");
      }

      printf("----------------------------\n");
      foundContact = 1;
    }
      current = current->next;
  }

  if(!foundContact) {
    printf("\nEsse contato n�o existe.\n");
    printf("----------------------------\n");
    return 0;
  }
    printf("\n");
    return 1;
}

void getAllDependentsByAgeAndContactName(Node *head) {
  Node *current = head;

  printf("\n------ Dependentes Menores de 18 Anos ------\n");

  if (current == NULL) {
    printf("Nenhum contato encontrado.\n\n");
    return;
  }

  int minorFound = 0;

  while (current != NULL) {
    DependentNode *depCurrent = current->contact.dependents;
    int contactHasMinors = 0;

    if (depCurrent != NULL) {
      do {
        if (depCurrent->dependent.age < 18) {
          if (!contactHasMinors) {
            printf("Contato: %s %s\n", current->contact.name, current->contact.lastName);
            contactHasMinors = 1;
          }
          printf("\t- Dependente: %s, Idade: %d\n", depCurrent->dependent.name, depCurrent->dependent.age);
          minorFound = 1;
        }
        depCurrent = depCurrent->next;
      } while (depCurrent != current->contact.dependents);
    }

    current = current->next;
  }

  if (!minorFound) {
    printf("Nenhum dependente menor de 18 anos encontrado.\n\n");
  }
  }

DependentNode *CreateDependent(const char *name, int age) {
  DependentNode *new_dependent = (DependentNode *)malloc(sizeof(DependentNode));
  strcpy(new_dependent->dependent.name, name);
  new_dependent->dependent.age = age;
  new_dependent->next = NULL;
  return new_dependent;
}

void editContact(Node *head, const char *newName,
                 const char *newLastName, int newAge, const char *newTaxNumber,
                 const char *newNeighborhood, const char *newEmail,
                 const char *newPhone) {
      
      if(newName != NULL && newName != ""){
      
         strcpy(head->contact.name, newName);  
           
      }
      
      if(newLastName != NULL && newLastName != ""){
      
         strcpy(head->contact.lastName, newLastName);
           
      }
      
      if(newAge != NULL && newAge != 0) {
      
         head->contact.age = newAge;
         
      }
      
      if(newTaxNumber != NULL && newTaxNumber != ""){
      
         strcpy(head->contact.taxNumber, newTaxNumber);  
           
      }
      
      if(newNeighborhood != NULL && newNeighborhood != ""){
           
         strcpy(head->contact.neighborhood, newNeighborhood);  
      
      }
      
      if(newEmail != NULL && newEmail != ""){
      
         strcpy(head->contact.email, newEmail);
           
      }
      
      if(newPhone != NULL && newPhone != ""){
      
         strcpy(head->contact.phone, newPhone);
           
      }
      
      printf("Contato editado com sucesso.\n");

}

void editDependent(DependentNode *dependent, const char *newName, int newAge) {
    if (newName != NULL && strlen(newName) > 0) {
        strcpy(dependent->dependent.name, newName);  
        printf("Nome do dependente editado com sucesso.\n");
    }

    if (newAge > 0) {
        dependent->dependent.age = newAge;
        printf("Idade do dependente editada com sucesso.\n");
    }
}

void addDependent(Contact *contact, const char *name, int age) {
  DependentNode *new_dependent = CreateDependent(name, age);
  if (contact->dependents == NULL) {
    contact->dependents = new_dependent;
    new_dependent->next = new_dependent;
  } else {
    DependentNode *current = contact->dependents;
    while (current->next != contact->dependents) {
      current = current->next;
    }
    current->next = new_dependent;
    new_dependent->next = contact->dependents;
  }
}

Node *searchContactAndReturn(Node **head, const char *name) {
    Node *current = *head;  
    char nameTemp[50];
    char lastNameTemp[50];
    
    while (current != NULL) { 	
		strncpy(nameTemp, current->contact.name, sizeof(nameTemp) - 1);
		nameTemp[sizeof(nameTemp) - 1] = '\0';
		
		strncpy(lastNameTemp, current->contact.lastName, sizeof(lastNameTemp) - 1);
		lastNameTemp[sizeof(lastNameTemp) - 1] = '\0';
				 	   	
        if (strcmp(strlwr(nameTemp), strlwr(name)) == 0 || 
			strcmp(strlwr(lastNameTemp), strlwr(name)) == 0) {
            return current;
        }
        current = current->next;
    }   
	    
    return NULL;
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
      printf("J� existe um contato com esse nome: %s %s \n\n", new_contact->contact.name, new_contact->contact.lastName);
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


void removeContact(Node **head, const char *contactName){
	
	Node *current = *head;
	Node *prev = NULL;
	
	while (current != NULL){
		
		if(strcmp(current->contact.name, contactName) == 0){
		
			if(prev==NULL){
			
				*head = current->next;
			} else {
				prev->next = current->next;
			}
			
			DependentNode *depCurrent = current->contact.dependents;
			while(depCurrent!=NULL){
				DependentNode *temp = depCurrent;
				depCurrent = depCurrent->next;
				free(temp);
			}
			
			free(current);
			
			printf("Contato '%s' removido com sucesso. \n", contactName);
			return;
		}
		
		prev = current;
		current = current->next;
		
	}
	
	printf("Contato '%s' n�o encontrado. \n", contactName);
}

void removeDependent(Node **head, const char *contactName, const char *dependentName){
	Node *current  = *head;
	while(current !=NULL){
		
		if(strcmp(current->contact.name,contactName)==0){
			DependentNode *depCurrent =  current->contact.dependents;
			DependentNode *prev = NULL;
			
			while(depCurrent!=NULL){
				if(strcmp(depCurrent->dependent.name, dependentName)==0){
					if(prev==NULL){
						current->contact.dependents = depCurrent->next;
					} else {
						prev->next = depCurrent->next;
					}
					free(depCurrent);
					printf("Dependente '%s' removido do contato '%s' com sucesso. \n",dependentName, contactName);
					return;
				}
				prev = depCurrent;
				depCurrent = depCurrent->next;
			}
			printf("Dependente '%s' n�o encontrado para o contato '%s'. \n", dependentName, contactName);
			return;
		}
		current = current->next;
	}
	printf("Contato '%s' n�o encontrado. \n", contactName);
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
                createContact("5", "Randvi", "Batista", 30, "95423915217", "Westonty",
                              "randvi@example.com", "71858421017"));
}

void createMockContactWithDependent(Node **head) {
  Node *contact =
      createContact("4", "Bob", "Builder", 50, "32165498700", "Hometown",
                    "bob.builder@example.com", "71982659845");
  Node *contact2 =
      createContact("4", "Renan", "Batista", 80, "32165498700", "Hometown",
                    "bob.builder@example.com", "71982659845");
  addDependent(&contact->contact, "Alice", 35);
  addDependent(&contact->contact, "Tom", 18);
  addDependent(&contact2->contact, "Renanzinho", 3);
  insertContact(head, contact);
  insertContact(head, contact2);
}


void saveContactsToFile(Node *head) {
  FILE *file = fopen("save_contacts.txt", "w");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo save_contacts.txt para escrita.\n");
    return;
  }

  Node *current = head;

  fprintf(file, "\n------ Lista de Contatos ------\n");

  if (current == NULL) {
    fprintf(file, "Nenhum contato encontrado.\n\n");
    fclose(file);
    return;
  }

  while (current != NULL) {
    fprintf(file, "ID: %s\n", current->contact.id);
    fprintf(file, "Nome: %s %s\n", current->contact.name, current->contact.lastName);
    fprintf(file, "Idade: %d\n", current->contact.age);
    fprintf(file, "N�mero de Contribuinte: %s\n", current->contact.taxNumber);
    fprintf(file, "Bairro: %s\n", current->contact.neighborhood);
    fprintf(file, "Email: %s\n", current->contact.email);
    fprintf(file, "Telefone: %s\n", current->contact.phone);

    if (current->contact.dependents != NULL) {
      fprintf(file, "Dependentes:\n");
      DependentNode *depCurrent = current->contact.dependents;
      do {
        fprintf(file, "\t- Nome: %s, Idade: %d\n", depCurrent->dependent.name,
                depCurrent->dependent.age);
        depCurrent = depCurrent->next;
      } while (depCurrent != current->contact.dependents);
    } else {
      fprintf(file, "Nenhum dependente cadastrado.\n");
    }

    fprintf(file, "----------------------------\n");
    current = current->next;
  }

  fprintf(file, "\n");
  fclose(file);
  printf("Contatos registrados com sucesso em save_contacts.txt.\n");
}
