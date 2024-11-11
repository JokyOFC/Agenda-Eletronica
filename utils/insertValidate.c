#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "insertValidate.h"

void sendMessageValid(char *message){
	printf("-----------------------------------------------------------\n");
    printf("%s\n", message);
	printf("-----------------------------------------------------------\n");
}

int *insertValidate(int option, int type, char input[]){
	int *returnValid;
	char *message = NULL;
	char *characterInput = input;
	int lengthInput = strlen(characterInput);
		
	char *emailValid = strchr(input, '@');			
	char *emailValidPoint = NULL;
	
	if(type == 1){		
		//Nome		
		if(lengthInput < 1){
			message = "Nome obrigatório!";
		}else if(lengthInput < 2){
			if(option == 1){
				message = "Contato não pode ter Nome ou Sobrenome com menos de dois caracteres!";
			}else if(option == 2){
				message = "Dependente não pode ter Nome ou Sobrenome com menos de dois caracteres!";					
			}
		}			
	}else if(type == 2){
		//CPF
    	if(lengthInput < 1){
			message = "CPF obrigatório!";
		}else if(lengthInput != 11){
			message = "CPF inválido. Favor inserir um CPF sem pontos e sem traços.";			
		}
			
	}else if(type == 3){
		//Número de Telefone    		
    	if(lengthInput < 1){
			message = "Telefone obrigatório!";
		}else if(lengthInput < 10 || lengthInput > 11){
			message = "Número de telefone inválido! Informe o DDD sem o zero. Caso seja celular informe o dígito adicional.";			
		}
	}else if(type == 4){
		//Email	
		if(lengthInput < 1){
			message = "Email obrigatório!";
		}else{
			emailValidPoint = strchr(emailValid + 1, '.');
			if(emailValid == NULL || emailValidPoint == NULL){
    			message = "Email inválido!";
			}						
		}		
    		
	}else if(type == 5){
    	//Vizinho    		
    	if(lengthInput < 1){
			message = "Bairro obrigatório!";
		}else if(lengthInput < 4){
			message = "Bairro inválido!";
		}
	}	
	
	if(message != NULL){
        sendMessageValid(message);	
		returnValid = 1;	
	}else{
		returnValid = 0;
	}
		
	return returnValid;	    	
}





