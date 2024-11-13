
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../entities/entitie.h"

Node **linkedListToArray(Node *head, int *size) {
    int count = 0;
    Node *current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }

    *size = count;
    Node **array = (Node**)malloc(count * sizeof(Contact));
    
    current = head;
    int i;
    for(i = 0; i < count; i++) {
        array[i] = current;
        //printf("Name at index %d: %s\n", i, array[i].name); // Check what is being copied
        current = current->next;
    }
    return array;
}

int binarySearch(Node **array, int size, const char *name) {
  int left = 0;
  int right = size - 1;

  char tempNameToLowerCase[45];
  char tempLastNameToLowerCase[45];
  char nameToLowerCase[45];

  // Converte `name` para minúsculas para comparação case-insensitive
  strncpy(nameToLowerCase, name, sizeof(nameToLowerCase) - 1);
  nameToLowerCase[sizeof(nameToLowerCase) - 1] = '\0';
  strlwr(nameToLowerCase);

  while (left <= right) {
    int mid = left + (right - left) / 2;

    // Converte `contact.name` para minúsculas
    strncpy(tempNameToLowerCase, array[mid]->contact.name, sizeof(tempNameToLowerCase) - 1);
    tempNameToLowerCase[sizeof(tempNameToLowerCase) - 1] = '\0';
    strlwr(tempNameToLowerCase);

    // Converte `contact.lastName` para minúsculas
    strncpy(tempLastNameToLowerCase, array[mid]->contact.lastName, sizeof(tempLastNameToLowerCase) - 1);
    tempLastNameToLowerCase[sizeof(tempLastNameToLowerCase) - 1] = '\0';
    strlwr(tempLastNameToLowerCase);

    int cmpName = strcmp(tempNameToLowerCase, nameToLowerCase);
    int cmpLastName = strcmp(tempLastNameToLowerCase, nameToLowerCase);

    // Debugging opcional
    printf("Left: %d, Right: %d, Mid: %d\n", left, right, mid);
    printf("Name at MID: %s, LastName at MID: %s\n", array[mid]->contact.name, array[mid]->contact.lastName);
    printf("CMP Name: %d, CMP LastName: %d\n", cmpName, cmpLastName);

    // Verifica se `name` corresponde ao `contact.name` ou ao `contact.lastName`
    if (cmpName == 0 || cmpLastName == 0) {
      return mid; // Contato encontrado
    } else if (cmpName < 0 && cmpLastName < 0) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1; // Contato não encontrado
}



void printContact(Node *node) {

    Contact *contact = &node->contact;

    printf("ID: %s\n", contact->id);
    printf("Name: %s\n", contact->name);
    printf("LastName: %s\n", contact->lastName);
    printf("Age: %d\n", contact->age);
    printf("Tax Number: %s\n", contact->taxNumber);
    printf("Neighborhood: %s\n", contact->neighborhood);
    printf("Email: %s\n", contact->email);
    printf("Phone: %s\n", contact->phone);

    if (contact->dependents != NULL) {
        printf("Dependentes:\n");
        DependentNode *currentDependent = contact->dependents;
        do {
            printf("\t- Nome: %s, Idade: %d\n", currentDependent->dependent.name, currentDependent->dependent.age);
            currentDependent = currentDependent->next;
        } while (currentDependent != contact->dependents);
    } else {
        printf("Nenhum dependente registrado.\n");
    }
}
