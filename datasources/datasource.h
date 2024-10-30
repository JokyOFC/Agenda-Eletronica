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
void getAllDependentsByAgeAndContactName(Node *head);
void addDependent(Contact *contact, const char *name, int age);
void editContact(Node *head, const char *name, const char *newName,
                 const char *newLastName, int newAge, const char *newTaxNumber,
                 const char *newNeighborhood, const char *newEmail,
                 const char *newPhone);
void createMockContacts(Node **head);
void createMockContactWithDependent(Node **head);

#endif
