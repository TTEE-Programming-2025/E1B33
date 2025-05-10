#include <stdio.h>
#include <string.h>
#include <stdlib.h>// for system("cls")
#include <time.h>

#define SIZE 9

char seats[SIZE][SIZE];

// Initialize seats
void initSeats() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seats[i][j] = '-';

    // Randomly book 10 seats for '*'
    srand(time(NULL));
    int count = 0;
    while (count < 10) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }
}

// Show seating chart
void showSeats() {
    printf(" \\123456789\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", SIZE - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// Automatically arrange seats: Return the number of seats found
int autoArrange(int needed) {
    int found = 0;

    // Find consecutive vacancies in the same column
    for (int i = 0; i < SIZE && found == 0; i++) {
        for (int j = 0; j <= SIZE - needed; j++) {
            int ok = 1;
            for (int k = 0; k < needed; k++) {
                if (seats[i][j + k] != '-') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < needed; k++) {
                    seats[i][j + k] = '@';
                }
                found = 1;
                break;
            }
        }
    }

    // If there are 4 people and no one in the same column is found, then find 2 people above and below.
    if (needed == 4 && found == 0) {
        for (int i = 0; i < SIZE - 1 && found == 0; i++) {
            for (int j = 0; j < SIZE - 1 && found == 0; j++) {
                if (seats[i][j] == '-' && seats[i][j + 1] == '-' &&
                    seats[i + 1][j] == '-' && seats[i + 1][j + 1] == '-') {
                    seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '@';
                    found = 1;
                }
            }
        }
    }

    return found;
}

// Convert '@' to '*'
void confirmSuggestion() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '*';
}

// Convert '@' to '-'
void cancelSuggestion() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '-';
}

int main() {
    char password[10];
    int attempts = 0;
    char choice;

    // Personal style
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

    while (attempts < 3) {
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(password, "2025") == 0) {
            printf("Password correct! Welcome!\n");
			
			// clear screen
            #ifdef _WIN32
                system("cls"); // Windows
            #else
                system("clear"); // Linux/macOS
            #endif

            initSeats();
			//Show main menu
            do {
                printf("----------[Booking System]----------\n");
                printf("| a. Available seats               |\n");
                printf("| b. Arrange for you              |\n");
                printf("| c. Choose by yourself           |\n");
                printf("| d. Exit                         |\n");
                printf("------------------------------------\n");
                printf("Please select (a/b/c/d): ");
                scanf(" %c", &choice);

                if (choice == 'a') {
                    showSeats();
                    printf("Press Enter to continue...");
                    getchar(); getchar(); // Clear newline and wait
                }
                else if (choice == 'b') {
                    int num;
                    printf("How many seats do you need (1~4)? ");
                    scanf("%d", &num);
                    if (num < 1 || num > 4) {
                        printf("Invalid number.\n");
                        continue;
                    }

                    int ok = autoArrange(num);
                    if (!ok) {
                        printf("No suitable seats found.\n");
                        continue;
                    }

                    showSeats();
                    printf("Are you satisfied with the suggestion? (y/n): ");
                    char yn;
                    scanf(" %c", &yn);
                    if (yn == 'y' || yn == 'Y') {
                        confirmSuggestion();
                    } else {
                        cancelSuggestion();
                    }
                }
                else if (choice == 'c') {
                    printf("功能尚未實作。\n");
                }
                else if (choice == 'd') {
                    printf("Continue? (y/n): ");
                    char yn;
                    scanf(" %c", &yn);
                    if (yn == 'n' || yn == 'N') {
                        printf("Goodbye!\n");
                        break;
                    }
                }
                else {
                    printf("Invalid choice.\n");
                }

            } while (1);

            break;
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


