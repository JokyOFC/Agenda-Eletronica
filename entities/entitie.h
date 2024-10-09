#ifndef ENTITIE_H
#define ENTITIE_H

typedef struct {
    char name[50];
    int age;
} Dependent;

typedef struct {
    char name[50];
    char lastName[50];
    int age;
    char tax_number[14];
    char neighborhood[50];
    char email[100];
    char phone[20];
    Dependent dependent;  
} Contact;

#endif