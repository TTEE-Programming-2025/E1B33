#include <iostream>
#include <conio.h>   // getch() 所需
#include <cstdlib>   // system("cls")
#include <cctype>    // tolower()
#include <cstring>  // 加這個提供 strcmp()

using namespace std;

// 函數宣告
void welcomeScreen();
bool login();
void mainMenu();
void drawTriangle();
void multiplicationTable();
bool continuePrompt();

int main() {
    if (!login()) {
        printf("錯誤三次，系統鎖定，程式結束。\n");
        return 0;
    }

    bool keepRunning = true;
    while (keepRunning) {
        system("cls");
        mainMenu();
        char choice;
        scanf(" %c", &choice);  // 注意空格避免讀到換行符

        switch (tolower(choice)) {
            case 'a':
                system("cls");
                drawTriangle();
                break;
            case 'b':
                system("cls");
                multiplicationTable();
                break;
            case 'c':
                if (!continuePrompt()) {
                    keepRunning = false;
                }
                break;
            default:
                printf("無效選項，請重新輸入。\n");
                system("pause");
        }
    }

    printf("感謝使用，再見！\n");
    return 0;
}

// 顯示歡迎畫面（20 行個人風格）
void printLine() {
    printf("---------------------------------\n");
}

void welcomeScreen() {
    system("cls");
    for (int i = 0; i < 2; i++) printLine();
    printf("---------------E1B---------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("---------------33----------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("-------------鄭丞佑--------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("------------程式設計-------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("----------github 作業2-----------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("------------歡迎使用-------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("*********************************\n");

    printf("\n[提示] 密碼為：2025\n\n");
}


// 密碼登入邏輯，最多三次
bool login() {
    const char PASSWORD[] = "2025";   // 用 C 字串
    char input[10];                   // 使用字元陣列
    int attempts = 0;

    while (attempts < 3) {
        welcomeScreen();
        printf("請輸入四位數密碼：");
        scanf("%s", input);  

        if (strcmp(input, PASSWORD) == 0) {  
            return true;
        } else {
            attempts++;
            printf("密碼錯誤，剩餘次數：%d\n", 3 - attempts);
            system("pause");
        }
    }
    return false;
}


// 主選單
void mainMenu() {
    printf("--------------------------\n");
    printf("| a. 畫出直角三角形       |\n");
    printf("| b. 顯示乘法表           |\n");
    printf("| c. 結束                 |\n");
    printf("--------------------------\n");
    printf("請輸入選項：");
}

// 畫出直角三角形
void drawTriangle() {
    char ch;
    printf("請輸入一個 'a' 到 'n' 的字元：");
    scanf(" %c", &ch);
    ch = tolower(ch);

    if (ch >= 'a' && ch <= 'n') {
        int lines = ch - 'a' + 1;
        for (int i = 1; i <= lines; i++) {
            for (int j = 0; j < i; j++) {
                printf("%c", 'a' + j);
            }
            printf("\n");
        }
    } else {
        printf("輸入錯誤，請輸入 a ~ n 的字元。\n");
    }

    printf("\n按任意鍵返回主選單...\n");
    getch();
}

// 顯示乘法表
void multiplicationTable() {
    int n;
    printf("請輸入 1 到 9 的整數：");
    scanf("%d", &n);

    if (n < 1 || n > 9) {
        printf("輸入錯誤，請輸入 1~9 的整數。\n");
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%2d ", i * j);
            }
            printf("\n");
        }
    }

    printf("\n按任意鍵返回主選單...\n");
    getch();
}


// 結束前詢問是否繼續
bool continuePrompt() {
    char ans;
    while (true) {
        printf("是否要結束程式？(y/n)：");
        scanf(" %c", &ans);
        ans = tolower(ans);
        if (ans == 'y') {
            return false;  
        } else if (ans == 'n') {
            return true;   
        } else {
            printf("輸入錯誤，請輸入 y 或 n。\n");
        }
    }
}



//HW2心得 
//這次作業讓我練習了的基本語法與功能拆分，
//像是登入系統、畫直角三角形和顯示乘法表。
//在製作過程中，我學到了如何正確讀取輸入、
//控制畫面清除，來改善使用體驗。

//遇到的困難包括輸入錯誤處理，
//以及忘記引入 cstring 導致 strcmp 錯誤，
//但在修正後更加了解標頭檔的重要性。
//這次經驗讓我認識到寫程式不只是把功能完成，
//也要注意程式的結構與使用者體驗。
//未來我會繼續加強這些能力。
