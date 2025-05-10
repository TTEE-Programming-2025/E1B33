#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for system("cls")

int main() {
    char password[10];
    int attempts = 0;

    // personal style
    printf("*********************\n");
    printf("*                   *\n");
    printf("*      WELCOME      *\n");
    printf("*                   *\n");
    printf("*         I         *\n");
    printf("*        AM         *\n");
    printf("*        E1B        *\n");
    printf("*        33         *\n");
    printf("*                   *\n");
    printf("*********************\n");
    printf("*                   *\n");
    printf("*   Enter Password  *\n");
    printf("*                   *\n");
    printf("* You have 3 times  *\n");
    printf("*                   *\n");
    printf("*********************\n");
    printf("*                   *\n");
    printf("*      github       *\n");
    printf("*                   *\n");
    printf("*       HW3         *\n");
    printf("*                   *\n");
    printf("*********************\n");

    while (attempts < 3) {
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(password, "2025") == 0) {
            printf("Password correct! Welcome!\n");

            // clear screen
            #ifdef _WIN32
                system("cls");  // Windows
            #else
                system("clear"); // Linux/macOS
            #endif

            // Show main menu
            char choice;
            do {
                printf("----------[Booking System]----------\n");
                printf("| a. Available seats               |\n");
                printf("| b. Arrange for you              |\n");
                printf("| c. Choose by yourself           |\n");
                printf("| d. Exit                         |\n");
                printf("------------------------------------\n");
                printf("Please select (a/b/c/d): ");
                scanf(" %c", &choice);

                switch (choice) {
                    case 'a':
                        printf("還未作\n");
                        break;
                    case 'b':
                        printf("還未作\n");
                        break;
                    case 'c':
                        printf("還未作\n");
                        break;
                    case 'd':
                        printf("Goodbye!\n");
                        break;
                    default:
                        printf("Invalid choice, please try again.\n");
                        break;
                }
            } while (choice != 'd');

            break; // Exit while loop
        } else {
            printf("Wrong password!\n");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("Too many attempts. Program ends.\n");
    }

    return 0;
}

