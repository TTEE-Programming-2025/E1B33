#include <stdio.h>
#include <ctype.h>

void task2();
void task3();
void task4();

int main() {
    printf("=========\n");
    printf("*程式設計 作業 1 *\n");
    printf("*姓名:E1B33鄭丞佑*\n"); 
    printf("*學號: 411302233*\n"); 
    printf("@@@@@@\n\n");
    
    task2();
    
    task3();
    
    task4();
    
    return 0;
}

void task2() {
    char password[5];
    printf("請輸入 4 個數字的密碼: ");
    scanf("%4s", password);
    
    int valid = 1;
    for (int i = 0; i < 4; i++) {
        if (!isdigit(password[i])) {
            valid = 0;
            break;
        }
    }
    
    if (valid) {
        printf("密碼設定成功！\n");
        printf("進入步驟 3...\n");
    } else {
        printf("密碼錯誤！請重新執行。\n");
        printf("密碼錯誤碼 2024\n");
    }
    printf("\n");
}

void task3() {
    printf("請選擇功能選單：\n");
    printf("--------------------------------\n");
    printf("| 'A'..'Z'  -> Uppercase      |\n");
    printf("| 'a'..'z'  -> Lowercase      |\n");
    printf("| '0'..'9'  -> Digit          |\n");
    printf("| 其他    -> Your name       |\n");
    printf("--------------------------------\n\n");
}

void task4() {
    char input;
    printf("請輸入 1 個字元: ");
    scanf(" %c", &input);
    
    if (input >= 'A' && input <= 'Z') {
        printf("Uppercase\n");
    } else if (input >= 'a' && input <= 'z') {
        printf("Lowercase\n");
    } else if (input >= '0' && input <= '9') {
        printf("Digit\n");
    } else {
        printf("Your name\n");
    }
}
GitHub 是一個強大的程式碼託管平台，
讓開發者能夠輕鬆進行版本控制、協作開發與專案管理。
我透過 GitHub 學習 Git 指令，如 commit、push、pull request 等，
使開發流程更順暢。
此外，它的開源社群提供許多學習機會，
讓我更快提升程式開發能力。
