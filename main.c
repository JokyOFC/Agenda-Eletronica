#include "datasources/datasource.h"
#include "entities/entitie.h"
#include "menu/menu.h"
#include <stdio.h>
#ifdef _WIN32  // Apenas para Windows
    #include <windows.h>
#endif

int main() {
  #ifdef _WIN32  // Para Windows, definir o console como UTF-8
    SetConsoleOutputCP(CP_UTF8);
  #endif
  Node *contact_list = NULL;

  createMockContacts(&contact_list);
  createMockContactWithDependent(&contact_list);
  displayMenu(contact_list);

  return 0;
}
