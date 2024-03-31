#include <stdio.h>
#include <string.h>

int main() {
    char username[20], password[20];
    const char correct_username[] = "your_username";
    const char correct_password[] = "your_password";
    int max_attempts = 3;

    while (max_attempts > 0) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
            printf("Login successful!\n");
            return 0;
        }

        max_attempts--;
        printf("Incorrect username or password. Attempts remaining: %d\n", max_attempts);
    }

    printf("Too many failed attempts. Account locked.\n");
    return 0;
}