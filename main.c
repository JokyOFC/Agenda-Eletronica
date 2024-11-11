#include "datasources/datasource.h"
#include "entities/entitie.h"
#include "menu/menu.h"
#include <stdio.h>
#include <locale.h>

#ifdef _WIN32  // Apenas para Windows - Caracteres UTF8
    #include <windows.h>
#endif


int main(){
	//Definindo idioma da aplicação para utilização de acentuação
	setlocale(LC_ALL, "Portuguese");
	
	/*#ifdef _WIN32  // Para Windows, definir o console como UTF-8
    	SetConsoleOutputCP(CP_UTF8);
	#endif*/
	Node *contact_list = NULL;
	
	
	createMockContacts(&contact_list); 	//Cria a lista de contatos em Entidades
	createMockContactWithDependent(&contact_list); //Cria a lista dos dependentes dos contatos em Entidades
	displayMenu(contact_list);	//Chama o Menu (Inicio) do programa
	
		
	return 0; //Retorno de compilação sucesso do programa
}
