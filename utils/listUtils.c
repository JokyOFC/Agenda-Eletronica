
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

  //printf("Starting binary search for: %s\n", name);

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int cmp = strcmp(array[mid]->contact.name, name); // Access member using .
    int i =0;
    
    // Print statements for debugging (optional)
    //printf("Iteration: %d\n", i++); // Counter for iterations (optional)
    //printf("Left: %d, Right: %d, Mid: %d\n", left, right, mid);
    //printf("Comparison: %d\n", strcmp(array[mid]->contact.name, name));
    //printf("CMP: %d\n", cmp);
    //printf("Name at MID: %s\n", array[mid]->contact.name);  // Print full name for debugging

    if (cmp == 0) {
      return mid; // Contact found
    } else if (cmp < 0) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1; // Contact not found
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
