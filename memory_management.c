#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 10;
    char **emails = (char **)malloc(n * sizeof(char *));
    char buffer[100];

    // Input emails
    printf("Enter %d email addresses:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        emails[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(emails[i], buffer);
    }

    // Shrink to 6 students
    n = 6;
    emails = (char **)realloc(emails, n * sizeof(char *));

    printf("\nStored emails:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", emails[i]);
        free(emails[i]);
    }

    free(emails);
    return 0;
}
