#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for system("cls")
#include <time.h>

#define SIZE 9

char seats[SIZE][SIZE];

// Initialize seats
void initSeats() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seats[i][j] = '-';

    // Randomly book 10 seats
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

// Automatically arrange seats
int autoArrange(int needed) {
    int found = 0;

    // Try to find horizontal consecutive seats
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

    // Try 2x2 block for 4 people
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

// Confirm suggestion
void confirmSuggestion() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '*';
}

// Cancel suggestion
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

    // Welcome screen
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
                system("cls");
            #else
                system("clear");
            #endif

            initSeats();

            // Main menu
            do {
                printf("----------[Booking System]----------\n");
                printf("| a. Available seats               |\n");
                printf("| b. Arrange for you               |\n");
                printf("| c. Choose by yourself            |\n");
                printf("| d. Exit                          |\n");
                printf("------------------------------------\n");
                printf("Please select (a/b/c/d): ");
                scanf(" %c", &choice);

                if (choice == 'a') {
                    showSeats();
                    printf("Press Enter to continue...");
                    getchar(); getchar();
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
                    int num;
                    printf("How many seats do you want to choose (1~4)? ");
                    scanf("%d", &num);
                    if (num < 1 || num > 4) {
                        printf("Invalid number.\n");
                        continue;
                    }

                    int count = 0;
                    while (count < num) {
                        int row, col;
                        char input[10];
                        printf("Enter seat #%d (format: row-col): ", count + 1);
                        scanf("%s", input);

                        if (sscanf(input, "%d-%d", &row, &col) != 2 || row < 1 || row > 9 || col < 1 || col > 9) {
                            printf("Invalid format or out of range. Try again.\n");
                            continue;
                        }

                        int r = SIZE - row;
                        int c = col - 1;

                        if (seats[r][c] != '-') {
                            printf("Seat already taken. Choose another one.\n");
                            continue;
                        }

                        seats[r][c] = '@';
                        count++;
                    }

                    showSeats();
                    printf("Press Enter to confirm your selection...");
                    getchar(); getchar(); // Wait for Enter
                    confirmSuggestion();

                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif
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

// Program description
//
// This program uses a clear and interactive text-based menu to guide users
// Option a: Providesthe full seat layout
// Option b: Automatically arrange seats
// Option c: Choose by yourself
// Option d: Exits and asks if you want to continue(y/n)



// Experience:
// 
// The process of making the "seat reservation system" this time,
// I not only reviewed the basic grammar of C language,
// Also have a deep understanding of conditional judgment, loop control,
// Important concepts such as array operations and user input validation. 
// In terms of functional design, I randomly initialized seats,
// Display seating chart, password login verification and other basic functions.
// Then, according to the problem requirements, "Automatic Seating Arrangement" was added
// and "Select your own seat" are two options.
// For me, this course was a very practical and satisfying learning experience.
