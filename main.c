#include "datasources/datasource.h"
#include "entities/entitie.h"
#include "menu/menu.h"
#include <stdio.h>

int main() {
  Node *contact_list = NULL;

  createMockContacts(&contact_list);
  createMockContactWithDependent(&contact_list);
  displayMenu(contact_list);

  return 0;
}
