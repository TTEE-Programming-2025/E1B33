#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 第 1 題：登入函式
int login() {
    char password[10];
    int attempts = 0;
    const char correct_password[] = "2025";

    while (attempts < 3) {
        system("cls"); // 清除畫面
        // 個人風格畫面 (至少20行)
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

// 第 2 題：主選單函式
void showMenu() {
    system("cls"); // 清除畫面
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
        return 0; // 登入失敗直接結束
    }

    while (1) {
        showMenu();
        scanf(" %c", &choice); // 空格避免讀到前面輸入遺留的換行符

        switch (choice) {
            case 'a':
                printf("您選擇：輸入學生成績\n");
                system("pause");
                break;
            case 'b':
                printf("您選擇：顯示學生成績\n");
                system("pause");
                break;
            case 'c':
                printf("您選擇：搜尋學生成績\n");
                system("pause");
                break;
            case 'd':
                printf("您選擇了：年級排名\n");
                system("pause");
                break;
            case 'e':
                printf("您選擇：退出系統\n");
                system("pause");
                return 0;
            default:
                printf("無效選擇。再試一次。\n");
                system("pause");
        }
    }

    return 0;
}

