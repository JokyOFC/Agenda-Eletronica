#ifndef ENTITIE_H
#define ENTITIE_H

typedef struct {
    char name[50];
    int age;
} Dependent;

typedef struct DependentNode {
    Dependent dependent;
    struct DependentNode* next;
} DependentNode;

typedef struct {
    char id[10];
    char name[50];
    char lastName[50];
    int age;
    char taxNumber[14];
    char neighborhood[50];
    char email[100];
    char phone[20];
    DependentNode* dependents;  
} Contact;

typedef struct Node {
    Contact contact;
    struct Node* next;
} Node;

#endif
