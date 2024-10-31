#include "datasources/datasource.h"
#include "entities/entitie.h"
#include "menu/menu.h"
#include <stdio.h>
#include <locale.h>

#ifdef _WIN64
    #include <windows.h>
#elif _WIN32  // Apenas para Windows
    #include <windows.h>
#endif

int main() {
  
  #ifdef _WIN64  // Para Windows, definir o console como UTF-8
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Portuguese");
  #elif _WIN32
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "Portuguese");
  #else
    setlocale(LC_CTYPE, "pt_BR.UTF-8");
  #endif
  
  Node *contact_list = NULL;

  createMockContacts(&contact_list);
  createMockContactWithDependent(&contact_list);
  displayMenu(contact_list);

  return  0;
}
