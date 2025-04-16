#include <stdio.h>
#define SIZE 15

int buffer[SIZE];
int start = -1, end = -1;

void insert(int value) {
    if ((end + 1) % SIZE == start) {
        printf(" is full\n");
        return;
    } else if (start == -1 && end == -1) {
        start = end = 0;
        buffer[end] = value;
    } else {
        end = (end + 1) % SIZE;
        buffer[end] = value;
    }
}

void remove_element() {
    if (start == -1 && end == -1) return;

    if (start == end) {
        start = -1;
        end = -1;
    } else {
        start = (start + 1) % SIZE;
    }
}

void show() {
    if (start == -1 && end == -1) return;

    int i = start;
    while (1) {
        printf("%d ", buffer[i]);
        if (i == end) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int value, num;
    printf("Enter the number of elements to insert (1-15): ");
    scanf("%d", &num);

    printf("Enter values: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &value);
        insert(value);
    }

    printf("\nBuffer: ");
    show();

    int rem_count;
    printf("\nNumber of elements to remove: ");
    scanf("%d", &rem_count);

    for (int i = 0; i < rem_count; i++) remove_element();

    printf("After Removal: ");
    show();

    int add_count;
    printf("\nNumber of elements to insert: ");
    scanf("%d", &add_count);

    printf("Enter values: ");
    for (int i = 0; i < add_count; i++) {
        scanf("%d", &value);
        insert(value);
    }

    show();

    return 0;
}