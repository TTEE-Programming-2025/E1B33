#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

// 結構定義：學生資料
struct Student {
    char name[20];
    int id;
    int math;
    int physics;
    int english;
    float average;
};

// 全域變數
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// 第 1 題：登入畫面
int login() {
    char password[10];
    int attempts = 0;
    const char correct_password[] = "2025";

    while (attempts < 3) {
        system("cls"); // 清除畫面

        // 個人風格畫面 
        printf("=====================================\n");
        printf("*                                   *\n");
        printf("*              E1B                  *\n");
        printf("*                                   *\n");
        printf("*               33                  *\n");
        printf("*                                   *\n");
        printf("*             鄭丞佑                *\n");
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

        printf("請輸入4位數密碼：");
        scanf("%s", password);

        if (strcmp(password, correct_password) == 0) {
            printf("登入成功！\n");
            system("pause");
            return 1;
        } else {
            printf("密碼錯誤，請再試一次。\n");
            attempts++;
            system("pause");
        }
    }

    printf("錯誤超過三次，系統結束！\n");
    return 0;
}

// 第 2 題：主選單
void showMenu() {
    system("cls");
    printf("------------[Grade System]------------\n");
    printf("| a. Enter student grades             |\n");
    printf("| b. Display student grades           |\n");
    printf("| c. Search for student grades        |\n");
    printf("| d. Grade ranking                    |\n");
    printf("| e. Exit system                      |\n");
    printf("--------------------------------------\n");
    printf("Please enter your choice: ");
}

// 第 3 題：輸入學生成績
void inputStudents() {
    system("cls");
    int n;

    printf("請輸入學生人數 (5~10): ");
    scanf("%d", &n);

    while (n < 5 || n > 10) {
        printf("錯誤！請輸入 5~10 之間的人數: ");
        scanf("%d", &n);
    }

    studentCount = n;

    for (int i = 0; i < n; i++) {
        printf("\n輸入第 %d 位學生資料：\n", i + 1);

        printf("姓名：");
        scanf("%s", students[i].name);

        printf("學號（6位整數）：");
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("錯誤！請輸入6位整數學號：");
            scanf("%d", &students[i].id);
        }

        printf("數學成績（0~100）：");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("錯誤！請重新輸入：");
            scanf("%d", &students[i].math);
        }

        printf("物理成績（0~100）：");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("錯誤！請重新輸入：");
            scanf("%d", &students[i].physics);
        }

        printf("英文成績（0~100）：");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("錯誤！請重新輸入：");
            scanf("%d", &students[i].english);
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }

    printf("\n資料輸入完成！\n");
    system("pause");
}

// 第 4 題：顯示所有學生資料
void displayStudents() {
    system("cls");
    printf("%-10s %-10s %-6s %-6s %-6s %-7s\n", "姓名", "學號", "數學", "物理", "英文", "平均");
    printf("------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%-10s %-10d %-6d %-6d %-6d %-7.1f\n",
               students[i].name,
               students[i].id,
               students[i].math,
               students[i].physics,
               students[i].english,
               students[i].average);
    }

    system("pause");
}

// 第 5 題：搜尋特定學生資料
void searchStudent() {
    char searchName[20];
    int found = 0;
    system("cls");

    printf("請輸入要查詢的學生姓名：");
    scanf("%s", searchName);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("%-10s %-10s %-6s %-6s %-6s %-7s\n", "姓名", "學號", "數學", "物理", "英文", "平均");
            printf("------------------------------------------------\n");
            printf("%-10s %-10d %-6d %-6d %-6d %-7.1f\n",
                   students[i].name,
                   students[i].id,
                   students[i].math,
                   students[i].physics,
                   students[i].english,
                   students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("查無此學生資料。\n");
    }

    system("pause");
}

// 第 6 題：成績排序
void rankStudents() {
    system("cls");
    struct Student temp;
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].average < students[j].average) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("%-10s %-10s %-7s\n", "姓名", "學號", "平均");
    printf("--------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s %-10d %-7.1f\n",
               students[i].name,
               students[i].id,
               students[i].average);
    }
    system("pause");
}

// 主程式
int main() {
    char choice;

    if (!login()) {
        return 0; // 登入失敗
    }

    while (1) {
        showMenu();
        scanf(" %c", &choice); // 注意前面空格

        switch (choice) {
            case 'a':
                inputStudents();
                break;
            case 'b':
                displayStudents();
                break;
            case 'c':
                searchStudent();
                break;
            case 'd':
                rankStudents();
                break;
            case 'e':
                printf("您選擇離開系統\n");
                system("pause");
                return 0;
            default:
                printf("輸入錯誤，請重新選擇\n");
                system("pause");
        }
    }

    return 0;
}

