#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int age;
    char name[60];
    int waiting_number;
    struct node *next;
} patient;

patient *front = NULL, *rear = NULL;
int patient_count = 0;

void enque(char name[], int age) {
    patient *new_patient = (patient *)malloc(sizeof(patient));
    new_patient->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = new_patient;
        new_patient->age = age;
        new_patient->waiting_number = ++patient_count;
        strcpy(new_patient->name, name);
    } else {
        rear->next = new_patient;
        new_patient->age = age;
        new_patient->waiting_number = ++patient_count;
        strcpy(new_patient->name, name);
        rear = new_patient;
    }
}

void deque() {
    if (front == NULL && rear == NULL) return;

    patient *del = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;

        patient *t = front;
        while (t != rear) {
            t->waiting_number--;
            t = t->next;
        }
        rear->waiting_number--;
        patient_count--;
    }
    free(del);
}

void print_detail() {
    if (front == NULL && rear == NULL) return;

    patient *t = front;

    while (t != rear) {
        printf(" %s | %d | %d\n", t->name, t->age, t->waiting_number);
        t = t->next;
    }

    printf(" %s | %d | %d\n", rear->name, rear->age, rear->waiting_number);
}

int main() {
    enque("Aarav", 21);
    enque("Anant", 17);
    enque("Mihir", 22);
    enque("Tanvi", 25);


    printf(" Name  | Age | Number\n");
    Display();
    printf("\n");

    deque();
    deque();

    enque("Neha", 19);
    deque();
    deque();

    enque("Vivaan", 24);
    printf("\n");
    printf(" Name  | Age | Number\n");
    print_detail();
    printf("\n");

    return 0;
}