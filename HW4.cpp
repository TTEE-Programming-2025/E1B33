#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �� 1 �D�G�n�J�禡
int login() {
    char password[10];
    int attempts = 0;
    const char correct_password[] = "2025";

    while (attempts < 3) {
        system("cls"); // �M���e��
        // �ӤH����e�� (�ܤ�20��)
        printf("=====================================\n");
        printf("*                                   *\n");
        printf("*     Welcome to Grade System       *\n");
        printf("*                                   *\n");
        printf("*     Designed by YOU (2025)        *\n");
        printf("*                                   *\n");
        printf("*     -------------------------     *\n");
        printf("*     |     Secure Login      |     *\n");
        printf("*     -------------------------     *\n");
        for (int i = 0; i < 10; i++) {
            printf("*                                   *\n");
        }
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

// �� 2 �D�G�D���禡
void showMenu() {
    system("cls"); // �M���e��
    printf("------------[Grade System]------------\n");
    printf("| a. Enter student grades             |\n");
    printf("| b. Display student grades           |\n");
    printf("| c. Search for student grades        |\n");
    printf("| d. Grade ranking                    |\n");
    printf("| e. Exit system                      |\n");
    printf("--------------------------------------\n");
    printf("Please enter your choice: ");
}

int main() {
    char choice;

    if (!login()) {
        return 0; // �n�J���Ѫ�������
    }

    while (1) {
        showMenu();
        scanf(" %c", &choice); // �Ů��קKŪ��e����J��d�������

        switch (choice) {
            case 'a':
                printf("�z��ܡG��J�ǥͦ��Z\n");
                system("pause");
                break;
            case 'b':
                printf("�z��ܡG��ܾǥͦ��Z\n");
                system("pause");
                break;
            case 'c':
                printf("�z��ܡG�j�M�ǥͦ��Z\n");
                system("pause");
                break;
            case 'd':
                printf("�z��ܤF�G�~�űƦW\n");
                system("pause");
                break;
            case 'e':
                printf("�z��ܡG�h�X�t��\n");
                system("pause");
                return 0;
            default:
                printf("�L�Ŀ�ܡC�A�դ@���C\n");
                system("pause");
        }
    }

    return 0;
}

