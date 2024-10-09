#ifndef DATASOURCE_H
#define DATASOURCE_H

#include "entitie.h"

void getContacts(Contact contacts[]);
void getContacByNeighborhood(Contact contacts[], char neighborhood[]);
void getContactsByName(Contact contacts[], char name[]);
void getAllDependentsByAgeAndContactName(Contact contacts[], char dependentAge, char contactName[]);

#endif