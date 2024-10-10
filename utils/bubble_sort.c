#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../entities/entitie.h"

void bubbleSort(Node** head) {
    if (*head == NULL) {
        return; // Retorna se a lista estiver vazia
    }

    int hasSwapped; // Indica se houve trocas na passagem
    Node* currentNode; // Ponteiro para percorrer a lista
    Node* lastSortedNode = NULL; // Marca a última posição ordenada

    do {
        hasSwapped = 0; // Reinicia a flag de troca
        currentNode = *head; // Começa do início da lista

        while (currentNode->next != lastSortedNode) {
            // Compara os nomes dos contatos
            if (strcmp(currentNode->contact.name, currentNode->next->contact.name) > 0) {
                // Troca os contatos se necessário
                Contact tempContact = currentNode->contact; 
                currentNode->contact = currentNode->next->contact; 
                currentNode->next->contact = tempContact; 
                hasSwapped = 1; // Indica que uma troca ocorreu
            }
            currentNode = currentNode->next; // Move para o próximo contato
        }
        lastSortedNode = currentNode; // Atualiza a última posição ordenada
    } while (hasSwapped); // Repete se houve trocas
}
