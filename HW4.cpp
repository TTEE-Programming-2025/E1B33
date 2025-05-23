#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login() {
    char password[10];
    int attempts = 0;
    const char correct_password[] = "2025";

    while (attempts < 3) {
        system("cls"); // �M���e��
        // �ӤH����e�� (�ܤ�20��)
        printf("=====================================\n");
        printf("*                                   *\n");
        printf("*              E1B                  *\n");
        printf("*                                   *\n");
        printf("*               33                  *\n");
        printf("*                                   *\n");
        printf("*             �G���                *\n");
		printf("*                                   *\n");
        printf("*             Github                *\n");
        printf("*                                   *\n");
        printf("*              HW4                  *\n");
        printf("*                                   *\n");
        printf("*     Welcome to Grade System       *\n");
        printf("*                                   *\n");
        printf("*                                   *\n");
		printf("*     -------------------------     *\n");
        printf("*     |     Secure Login      |     *\n");
        printf("*     -------------------------     *\n");
        printf("*                                   *\n");
        printf("*                                   *\n");
        printf("=====================================\n");

        printf("Please enter your 4-digit password: ");
        scanf("%s", password);

        if (strcmp(password, correct_password) == 0) {
            printf("Login successful!\n");
            system("pause");
            return 1;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
            system("pause");
        }
    }

    printf("Too many incorrect attempts. Exiting...\n");
    return 0;
}

int main() {
    if (login()) {
        printf("Welcome to the system.\n");
    } else {
        printf("Program terminated.\n");
    }
    return 0;
}

