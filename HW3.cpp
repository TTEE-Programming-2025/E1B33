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

// 心得:
// 這次製作「座位訂票系統」的過程，
// 我不只複習了 C 語言的基本語法，
// 也深入了解了條件判斷、迴圈控制、
// 陣列操作以及使用者輸入驗證等重要概念。 
// 在功能設計上，我做了隨機初始化座位、
// 顯示座位表、密碼登入驗證等基本功能。
// 接著，根據題目需求加入了「自動安排座位」
// 與「自行選擇座位」兩種選位方式。
// 這次的程式對我而言是一次非常實用且具挑戰性的學習經驗。 
