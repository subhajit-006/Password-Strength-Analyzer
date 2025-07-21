#include <stdio.h>
#include <string.h>
#include <ctype.h>

int has_uppercase(char *password) {
    for (int i = 0; password[i]; i++)
        if (isupper(password[i])) return 1;
    return 0;
}

int has_lowercase(char *password) {
    for (int i = 0; password[i]; i++)
        if (islower(password[i])) return 1;
    return 0;
}

int has_digit(char *password) {
    for (int i = 0; password[i]; i++)
        if (isdigit(password[i])) return 1;
    return 0;
}

int has_special_char(char *password) {
    for (int i = 0; password[i]; i++)
        if (ispunct(password[i])) return 1;
    return 0;
}

int main() {
    char password[100];
    int score = 0;

    printf("Enter password to analyze: ");
    scanf("%s", password);

    if (strlen(password) >= 8) score++;
    if (has_uppercase(password)) score++;
    if (has_lowercase(password)) score++;
    if (has_digit(password)) score++;
    if (has_special_char(password)) score++;

    printf("\nPassword Strength: ");
    switch (score) {
        case 5:
            printf("Very Strong\n");
            break;
        case 4:
            printf("Strong\n");
            break;
        case 3:
            printf("Moderate\n");
            break;
        case 2:
            printf("Weak\n");
            break;
        default:
            printf("Very Weak\n");
    }

    return 0;
}
