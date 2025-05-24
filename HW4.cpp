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

// 第 4 題：顯示學生成績
void displayStudents() {
    system("cls");

    if (studentCount == 0) {
        printf("尚未輸入任何學生資料，請先輸入資料！\n");
        system("pause");
        return;
    }

    printf("姓名\t學號\t數學\t物理\t英文\t平均\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
               students[i].name,
               students[i].id,
               students[i].math,
               students[i].physics,
               students[i].english,
               students[i].average);
    }

    system("pause");
}

// 第 5 題：搜尋學生
void searchStudent() {
    system("cls");

    if (studentCount == 0) {
        printf("尚未輸入任何學生資料，請先輸入資料！\n");
        system("pause");
        return;
    }

    char target[20];
    int found = 0;

    printf("請輸入要查詢的學生姓名：");
    scanf("%s", target);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, target) == 0) {
            printf("\n找到學生：\n");
            printf("姓名：%s\n", students[i].name);
            printf("學號：%d\n", students[i].id);
            printf("數學成績：%d\n", students[i].math);
            printf("物理成績：%d\n", students[i].physics);
            printf("英文成績：%d\n", students[i].english);
            printf("平均成績：%.1f\n", students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("查無此學生資料。\n");
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
                printf("功能尚未完成：排名功能\n");
                system("pause");
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

