#include "../datasources/datasource.h"
#include "../entities/entitie.h"
#include "../utils/clearScreen.h"
#include "../utils/stringCreate.h"
#include "../utils/insertValidate.h"
#include "../utils/listUtils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"


int notClean = 0;

void displayAsciiArt() {
    printf("      _.--._  _.--._\n");
    printf(",-=.-\":;:;:;\\':;:;:;\"-._\n");
    printf("\\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
    printf(" \\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
    printf("  \\\\:;:;:;:;:;\\:;:;:;:;:;\\\n");
    printf("   \\\\:;:;:;:;:;\\:;::;:;:;:\\\n");
    printf("    \\\\:;:;::;:;:\\:;:;:;::;:\\\n");
    printf("     \\\\;;:;:_:--:\\:_:--:_;:;\\\n");
    printf("      \\\\_.-\"      :      \"-._\\\n");
    printf("       \\`_..--\"\"--.;.--\"\"--.._=>\n");
}

void displayMenu(Node *head) {	
    char option;
    srand(time(NULL));
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }        
        displayAsciiArt();
                        
        printf("\n------ Menu ------\n");
        printf("1. Relatórios/Buscas\n");
        printf("2. Remover Contato/Dependente\n");
        printf("3. Editar Contato/Dependente\n");
        printf("4. Adicionar Novo Contato/Dependente\n");
        printf("0. Fechar Agenda\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                clearScreen();
                displayReports(head);
                notClean = 0;
            break;
            case '2':
                clearScreen();
                displayRemove(head);
                notClean = 0;
            break;
            case '3':
                clearScreen();
                displayEdit(head);
                notClean = 0;
            break;
            case '4':
                clearScreen();
                displayInclude(&head);
                notClean = 0;
            break;           
            case '0':
                clearScreen();
                saveContactsToFile(head);
                printf("Saindo...\n");
            break;
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
                notClean = 1;
            break;
        }
    } while (option != '0');
}

void displayReports(Node *head) {
     
    char option;
    char *dynamicStringInput = NULL;
    
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Relatórios/Buscas ------\n");
        printf("1. Listar Contatos\n");
        printf("2. Listar Contatos de um Bairro Específico\n");
        printf("3. Buscar Contato em Específico e Seus Dependentes\n");
        printf("4. Listar Dependentes Menores de 18 Anos\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                clearScreen();
                getContacts(head);
                notClean = 1;
            break;
            case '2':                
                // Chamar função para Buscar Contatos de um Bairro em Específico
                clearScreen();
                printf("Insira o bairro que deseja buscar:\n");

                dynamicStringInput = stringCreateInput();

                if(dynamicStringInput != NULL) {
                    getContacByNeighborhood(head, dynamicStringInput);
                } else {
                    printf("Erro ao capturar o bairro.\n");
                }
                
                free(dynamicStringInput);
                dynamicStringInput = NULL;
                notClean = 1;
            break;
            case '3':
                // Chamar função para Buscar Contato em Específico e Seus Dependentes
                clearScreen();
                
                printf("Insira o nome do contato que deseja buscar:\n");
                
                dynamicStringInput = stringCreateInput();
                
                if(dynamicStringInput != NULL){
                     getContactsByName(head, dynamicStringInput);
                     
                } else {
                     printf("Erro ao capturar o contato.\n"); 
                }
                
                free(dynamicStringInput);
                dynamicStringInput = NULL;
                notClean = 1;                    
            break;
            case '4':
            	// Chamar função para Listar Dependentes Menores de 18 Anos
            	clearScreen();
                getAllDependentsByAgeAndContactName(head);
                notClean = 1;                
            break;
            case '0':
                return;  // Volta para o menu anterior
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != '0');
}

void displayEdit(Node *head) {
     
     char *dynamicStringInput = NULL;
     char option;
     
     do{
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Editar ------\n");
        printf("1. Contato\n");
        printf("2. Dependente\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);
        
        switch(option){
           case '1':
                clearScreen();
                printf("Digite o nome do contato que deseja editar: \n");

                dynamicStringInput = stringCreateInput();
                
                Node * findContact = searchContactAndReturn(&head, dynamicStringInput);
                
                if (findContact != NULL) {
                	printf("%s ", findContact->contact.name);
                    displayEditContact(findContact);
                } else {
                    printf("Contato nao encontrado.\n");
                }
                
                free(dynamicStringInput);
              
                notClean = 1;
           break;
           case '2':
                clearScreen();
                printf("Digite o nome do contato que possui o dependente que deseja editar: \n");

                dynamicStringInput = stringCreateInput();
            	findContact = searchContactAndReturn(&head, dynamicStringInput);
                if (findContact) {
                    displayEditDependent(findContact);
                } else {
                    printf("Contato nao encontrado.\n");
                }
                
                free(dynamicStringInput);
                notClean = 1;
           break;
           case '0':
                return;
           default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
           break;       
        }  
        
     } while(option != '0');
     
}

void displayEditContact(Node *head){
     
     char *dynamicStringInput = NULL;
     char secondOption;
     
     do{
       if(!notClean) {
           clearScreen();
           notClean = 0;
       }
       printf("\n------ Contato Encontrado ------\n");
       printContact(&head->contact);
       printf("\n--------------------------------\n");
       printf("1. Nome\n");
       printf("2. Sobrenome\n");
       printf("3. Idade\n");
       printf("4. CPF\n");
       printf("5. Bairro\n");
       printf("6. Email\n");
       printf("7. Telefone\n");
       printf("0. Voltar\n");
       printf("Digite qual informação deseja alterar no contato: ");
       scanf(" %c", &secondOption);
                        
       switch(secondOption){
            case '1':
                 printf("Digite o novo Nome do contato: ");
                 dynamicStringInput = stringCreateInput();
                 clearScreen();
                 
                 if(dynamicStringInput != NULL && dynamicStringInput != "") {
                 
                     editContact(head, dynamicStringInput,NULL, NULL, NULL,NULL, NULL,NULL);
                     
                 } else {
                        
                     printf("Nome inválido");
                 
                 }
                 
                 notClean = 1;
                 break;
            case '2':
                 printf("Digite o novo Sobrenome do contato: ");
                 dynamicStringInput = stringCreateInput();
                 clearScreen();
                 
                 if(dynamicStringInput != NULL && dynamicStringInput != "") {
                 
                     editContact(head, NULL,dynamicStringInput, NULL, NULL,NULL, NULL,NULL);
                     
                 } else {
                        
                     printf("Sobrenome inválido");
                 
                 }
                 
                 notClean = 1;
                 break;
            case '3':
                 printf("Digite a nova Idade do contato: ");
                 dynamicStringInput = stringCreateInput();
                 clearScreen();
                 
                 if(dynamicStringInput != NULL && dynamicStringInput != "" && dynamicStringInput != "0") {
                     
                     int age = atoi(dynamicStringInput);
                     editContact(head, NULL, NULL, age, NULL,NULL, NULL,NULL);
                     
                 } else {
                        
                     printf("Idade inválido");
                 
                 }
                 
                 notClean = 1;
                 break;
            case '4':
                 printf("Digite o novo CPF do contato: ");
                 dynamicStringInput = stringCreateInput();
                 clearScreen();
                 
                 if(dynamicStringInput != NULL && dynamicStringInput != "" && dynamicStringInput != "0") {
                     
                     editContact(head, NULL, NULL, NULL, dynamicStringInput,NULL, NULL,NULL);
                     
                 } else {
                        
                     printf("CPF inválido");
                 
                 }
                 
                 notClean = 1;
                 break;
            case '5':
                 printf("Digite o novo Bairro do contato: ");
                 dynamicStringInput = stringCreateInput();
                 clearScreen();
                 
                 if(dynamicStringInput != NULL && dynamicStringInput != "") {
                     
                     editContact(head, NULL, NULL, NULL, NULL,dynamicStringInput, NULL,NULL);
                     
                 } else {
                        
                     printf("Bairro inválido");
                 
                 }
                 
                 notClean = 1;
                 break;
            case '6':
                 printf("Digite o novo Email do contato: ");
                 dynamicStringInput = stringCreateInput();
                 clearScreen();
                 
                 if(dynamicStringInput != NULL && dynamicStringInput != "") {
                     
                     editContact(head, NULL, NULL, NULL, NULL, NULL, dynamicStringInput,NULL);
                     
                 } else {
                        
                     printf("Email inválido");
                 
                 }
                 
                 notClean = 1;
                 break;
            case '7':
                 printf("Digite o novo Telefone do contato: ");
                 dynamicStringInput = stringCreateInput();
                 clearScreen();
                 
                 if(dynamicStringInput != NULL && dynamicStringInput != "") {
                     
                     editContact(head, NULL, NULL, NULL, NULL, NULL, NULL, dynamicStringInput);
                     
                 } else {
                        
                     printf("Telefone inválido");
                 
                 }
                 
                 notClean = 1;
                 break;
            case '0':
                clearScreen();
                return;
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
             break;      
                                 
         }
                    
       } while(secondOption !='0');
       
       free(secondOption);
     
}

void displayEditDependent(Node *head) {
    int dependentIndex, editChoice;
    char *dynamicStringInput = NULL;
    int newAge;
    
    DependentNode *current = head->contact.dependents;

    if (current == NULL) {
        printf("Este contato não tem dependentes.\n");
        return;
    }

    printf("\n------ Dependentes ------\n");

    int i = 1;
    DependentNode *start = current;  
    do {
        printf("%d. %s\n", i, current->dependent.name);
        current = current->next;
        i++;
    } while (current != start); 

    printf("\nEscolha o número do dependente que deseja editar: ");
    scanf("%d", &dependentIndex);

    if (dependentIndex < 1 || dependentIndex >= i) {
        printf("Índice inválido.\n");
        return;
    }

    current = head->contact.dependents;
    for (i = 1; i < dependentIndex; i++) {
        current = current->next;
    }

    printf("\nO que deseja editar?\n1. Nome\n2. Idade\nEscolha: ");
    scanf("%d", &editChoice);
    if (editChoice == 1) {
        // Editar o nome
        printf("Digite o novo nome do dependente: ");
        dynamicStringInput = stringCreateInput();
        
        if (dynamicStringInput != NULL && strlen(dynamicStringInput) > 0) {
            editDependent(current, dynamicStringInput, -1);
        } else {
            printf("Nome inválido.\n");
        }
        free(dynamicStringInput);
    } else if (editChoice == 2) {
        // Editar a idade
        printf("Digite a nova idade do dependente: ");
        if (scanf("%d", &newAge) == 1 && newAge > 0) {
            editDependent(current, NULL, newAge);
        } else {
            printf("Idade inválida.\n");
        }
    } else {
        printf("Opção inválida.\n");
    }
}



void displayRemove(Node *head) {
    char option;
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Remover ------\n");
        printf("1. Contato\n");
        printf("2. Dependete\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':{
				clearScreen();
                char contactName[50];
                printf("Insira o nome do contato que deseja remover: ");
                scanf("%49s", contactName);
                removeContact(&head, contactName);
                notClean = 1;
			}   
            break;
            
            case '2':{	
            	clearScreen();
				char contactName[50];
				char dependentName[50];
				printf("Insira o nome do contato do dependente: ");
				scanf("%49s",contactName);
				printf("Insira o nome do dependente que deseja remover: ");
				scanf("%49s",dependentName);
				removeDependent(&head, contactName, dependentName);
				notClean = 1;    	
				}
            break;
			        
            case '0':
                return;
            default:
                clearScreen();
                printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != '0');
}

void displayInclude(Node **head) {
    char option;
    do {
        if(!notClean) {
            clearScreen();
            notClean = 0;
        }
        displayAsciiArt();
        printf("\n------ Incluir ------\n");
        printf("1. Contato\n");
        printf("2. Dependete\n");
        printf("0. Voltar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                clearScreen();
                // Adicionar Contato
                printf("Insira as informações do novo contato: \n");
                char id[10];
                char name[50];
                char lastName[50];
                int age;
                char taxNumber[14];
                char neighborhood[50];
                char email[100];
                char phone[20];
                
                int *validMessage;
                
                printf("Nome: ");
                scanf("%49s", name);  
                validMessage = insertValidate(1, 1, name);								               
                if(validMessage == 1){
                	notClean = 1;
                	break;
				}		
								                              
                printf("Sobrenome: ");
                scanf("%49s", lastName);										          
                validMessage = insertValidate(1, 1, lastName);                
                if(validMessage == 1){
                	notClean = 1;             	
					break;    	
				}
                
                printf("Idade: ");
                scanf("%d", &age);        
                if(age < 1 || age > 102){                	 
                	sendMessageValid("Idade não pode ser menor ou igual a zero, ou maior que 102 anos.");
                	notClean = 1;             	
					break;
                }
                
                printf("CPF: ");
                scanf("%13s", taxNumber); 
				validMessage = insertValidate(1, 2, taxNumber);              
                if(validMessage == 1){
                	notClean = 1;             	
					break;
                }
                                  
                printf("Bairro: ");
                scanf("%49s", neighborhood);
                validMessage = insertValidate(1, 5, neighborhood);              
                if(validMessage == 1){
                	notClean = 1;             	
					break;
                }                
                
                printf("Email: ");
                scanf("%99s", email);
                validMessage = insertValidate(1, 4, email);              
                if(validMessage == 1){
                	notClean = 1;             	
					break;
                }
                
                printf("Telefone: ");
                scanf("%19s", phone);
                validMessage = insertValidate(1, 3, phone);              
                if(validMessage == 1){
                	notClean = 1;             	
					break;
                }

                int haveDependents = 0;
                char nameDependent[50];
                int ageDependent = 0;
                //gera um número aleatório entre 1 e 1000 para colocar no id
                snprintf(id, sizeof(id), "%03d", rand() % 1000); 
                clearScreen();
                Node *newContact = createContact(id, name, lastName, age, taxNumber, neighborhood, email, phone);
                printf("Possui dependentes? \n 1-SIM \n 0-NãO\n");

                scanf("%d", &haveDependents);
                
                if(haveDependents == 1) {
                    printf("Insira os dados do dependente:\n");
                    printf("Nome: ");
                    scanf("%49s", nameDependent);
                    validMessage = insertValidate(2, 1, nameDependent);              
	                if(validMessage == 1){
	                	notClean = 1;             	
						break;
	                }
	                
                    printf("Idade: ");    
					scanf("%d", &ageDependent);                           
	                if(ageDependent < 1 || ageDependent > 102){
                		sendMessageValid("Idade não pode ser menor ou igual a zero, ou maior que 102 anos.");
	                	notClean = 1;             	
						break;
	                }                    
                    
                    addDependent(&newContact->contact, nameDependent, ageDependent);
                }

                insertContact(head, newContact);
                notClean = 1;
                break;
            case '2':
                // Adicionar Dependente
                clearScreen();
                printf("Para qual contato deseja incluir dependente? \n");
                // char contactName[50];

                char *dynamicStringInput = stringCreateInput();
                Node * contactFound = searchContactAndReturn(head, dynamicStringInput);
                if(contactFound != NULL) {
                    char nameDependent[50];
                    int ageDependent = 0;
                    
                    bool *validMessage = 0;
                    
                    printf("Insira os dados do dependente:\n");
                    printf("Nome: ");                    
                    scanf("%49s", nameDependent);
                    validMessage = insertValidate(2, 1, nameDependent);              
	                if(validMessage == 1){
	                	notClean = 1;             	
						break;
	                }
                    
                    printf("Idade: ");
                    scanf("%d", &ageDependent);
                    if(ageDependent < 1 || ageDependent > 102){
                		sendMessageValid("Idade não pode ser menor ou igual a zero, ou maior que 102 anos.");
	                	notClean = 1;             	
						break;
	                }  	                
	                
                    addDependent(&contactFound->contact, nameDependent, ageDependent);
                    printf("\nDependente adicionado com sucesso!\n");
                } else {
                    printf("Contato com o nome: %s não encontrado\n", dynamicStringInput);
                }
                notClean = 1;
                break;            
            case '0':
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (option != '0');
}
