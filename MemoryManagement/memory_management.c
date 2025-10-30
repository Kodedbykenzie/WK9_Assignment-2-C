/*
 * Stores email addresses dynamically using malloc, realloc, and free.
 * Demonstrates function pointers and duplicate removal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10
#define MAX_EMAIL_LEN 100

/* Function declarations */
void display_emails(char **emails, int count);
void remove_duplicates(char **emails, int *count);

int main(void) {
    int count = INITIAL_SIZE;
    char **emails = malloc(count * sizeof(char*));
    if (emails == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d email addresses:\n", count);
    for (int i = 0; i < count; i++) {
        char buffer[MAX_EMAIL_LEN];
        printf("Email %d: ", i + 1);
        if (scanf("%99s", buffer) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        emails[i] = malloc(strlen(buffer) + 1);
        if (emails[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        strcpy(emails[i], buffer);
    }

    /* Function pointers */
    void (*display_ptr)(char**, int) = display_emails;
    void (*remove_ptr)(char**, int*) = remove_duplicates;

    printf("\n--- Original List ---\n");
    display_ptr(emails, count);

    remove_ptr(emails, &count);
    printf("\n--- After Removing Duplicates ---\n");
    display_ptr(emails, count);

    /* Shrink to 6 students safely */
    int new_size = 6;
    if (count > new_size) {
        for (int i = new_size; i < count; i++) {
            free(emails[i]);
        }
        char **tmp = realloc(emails, new_size * sizeof(char*));
        if (tmp == NULL) {
            printf("Memory reallocation failed!\n");
            // keep using old emails safely
        } else {
            emails = tmp;
            count = new_size;
        }
    }

    printf("\n--- After Shrinking to %d Students ---\n", count);
    display_ptr(emails, count);

    /* Free all memory */
    for (int i = 0; i < count; i++)
        free(emails[i]);
    free(emails);

    return 0;
}

/* Display all emails */
void display_emails(char **emails, int count) {
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, emails[i]);
}

/* Remove duplicate email entries */
void remove_duplicates(char **emails, int *count) {
    for (int i = 0; i < *count; i++) {
        for (int j = i + 1; j < *count; ) {
            if (strcmp(emails[i], emails[j]) == 0) {
                free(emails[j]);
                for (int k = j; k < *count - 1; k++)
                    emails[k] = emails[k + 1];
                (*count)--;
            } else {
                j++;
            }
        }
    }
}
