#include "datasources/datasource.h"
#include "entities/entitie.h"
#include "menu/menu.h"
#include <stdio.h>
#include <locale.h>

#ifdef _WIN32  
    #include <windows.h>
#endif


int main(){
	
	setlocale(LC_ALL, "Portuguese");

	Node *contact_list = NULL;
	
	createMockContacts(&contact_list);
	createMockContactWithDependent(&contact_list); 
	displayMenu(contact_list);
		
	return 0; 
}
