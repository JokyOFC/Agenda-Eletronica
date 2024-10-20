#ifndef DATASOURCE_H
#define DATASOURCE_H

#include "../entities/entitie.h"

Node *createContact(const char *id, const char *name, const char *lastName,
                     int age, const char *taxNumber, const char *neighborhood,
                     const char *email, const char *phone);
void insertContact(Node **head, Node *new_contact);

void getContacts(Node *head);
void getContactsWhithoutDependents(Node *head);
void getContacByNeighborhood(Node *head, char neighborhood[]);
void getContactsByName(Node *head, char name[]);
void getAllDependentsByAgeAndContactName(Contact contacts[], int dependentAge,
                                         char contactName[]);
void addDependent(Contact *contact, const char *name, int age);
void createMockContacts(Node **head);
void createMockContactWithDependent(Node **head);

#endif
