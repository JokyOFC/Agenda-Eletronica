#include <stdio.h>
#include "menu/menu.h" 
#include "datasources/datasource.h"
#include "entities/entitie.h"

int main() {
    Node* contact_list = NULL;

    createMockContacts(&contact_list);
    createMockContactWithDependent(&contact_list);
    display_menu(contact_list);

    return 0;
}
