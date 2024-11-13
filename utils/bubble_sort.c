#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../entities/entitie.h"


void bubbleSort(Node **head) {
  if (*head == NULL) {
    return; 
  }

  int hasSwapped;             
  Node *currentNode;           
  Node *lastSortedNode = NULL; 

  do {
    hasSwapped = 0;      
    currentNode = *head; 

    while (currentNode->next != lastSortedNode) {
     
      if (strcmp(currentNode->contact.name, currentNode->next->contact.name) >
          0) {
        
        Contact tempContact = currentNode->contact;
        currentNode->contact = currentNode->next->contact;
        currentNode->next->contact = tempContact;
        hasSwapped = 1; 
      }
      currentNode = currentNode->next; 
    }
    lastSortedNode = currentNode; 
  } while (hasSwapped);           
}

