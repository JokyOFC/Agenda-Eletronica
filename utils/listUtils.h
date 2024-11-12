#include "../entities/entitie.h"

#ifndef LISTUTILS_H
#define LISTUTILS_H

Node **linkedListToArray(Node *head, int *size);
int binarySearch(Node **array, int size, const char *name);
void printContact(Contact *contact);

#endif
