/*
 * Sorts a list of names in ascending or descending order using bubble sort.
 * Demonstrates function pointers with comparator functions.
 */

#include <stdio.h>
#include <string.h>

int ascending(char a[], char b[]) {
    return strcmp(a, b) > 0;
}

int descending(char a[], char b[]) {
    return strcmp(a, b) < 0;
}

void bubbleSort(char arr[][50], int n, int (*compare)(char[], char[])) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    char names[20][50];
    int n = 5; // for quick testing, you can make it 20
    char order[5];

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; // remove newline
    }

    printf("Enter sorting order (asc or desc): ");
    scanf("%s", order);

    if (strcmp(order, "asc") == 0)
        bubbleSort(names, n, ascending);
    else
        bubbleSort(names, n, descending);

    printf("\nSorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
