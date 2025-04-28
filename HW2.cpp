#include <iostream>
#include <conio.h>   // getch() �һ�
#include <cstdlib>   // system("cls")
#include <cctype>    // tolower()

using namespace std;

// ��ƫŧi
void welcomeScreen();
bool login();
void mainMenu();
void drawTriangle();
void multiplicationTable();
bool continuePrompt();

int main() {
    if (!login()) {
        printf("���~�T���A�t����w�A�{�������C\n");
        return 0;
    }

    bool keepRunning = true;
    while (keepRunning) {
        system("cls");
        mainMenu();
        char choice;
        scanf(" %c", &choice);  // �`�N�Ů��קKŪ�촫���

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
                printf("�L�Ŀﶵ�A�Э��s��J�C\n");
                system("pause");
        }
    }

    printf("�P�¨ϥΡA�A���I\n");
    return 0;
}

// ����w��e���]20 ��ӤH����^
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
    printf("-------------�G���--------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("------------�{���]�p-------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("----------github �@�~2-----------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("------------�w��ϥ�-------------\n");
    for (int i = 0; i < 2; i++) printLine();
    printf("*********************************\n");

    printf("\n[����] �K�X���G2025\n\n");
}


// �K�X�n�J�޿�A�̦h�T��
bool login() {
    const string PASSWORD = "2025";
    string input;
    int attempts = 0;

    while (attempts < 3) {
        welcomeScreen();
        printf("�п�J�|��ƱK�X�G");
        cin >> input;

        if (input == PASSWORD) {
            return true;
        } else {
            attempts++;
            printf("�K�X���~�A�Ѿl���ơG%d\n", 3 - attempts);
            system("pause");
        }
    }
    return false;
}

// �D���
void mainMenu() {
    printf("--------------------------\n");
    printf("| a. �e�X�����T����       |\n");
    printf("| b. ��ܭ��k��           |\n");
    printf("| c. ����                 |\n");
    printf("--------------------------\n");
    printf("�п�J�ﶵ�G");
}

// �e�X�����T����
void drawTriangle() {
    char ch;
    printf("�п�J�@�� 'a' �� 'n' ���r���G");
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
        printf("��J���~�A�п�J a ~ n ���r���C\n");
    }

    printf("\n�����N���^�D���...\n");
    getch();
}

// ��ܭ��k��
void multiplicationTable() {
    int n;
    printf("�п�J 1 �� 9 ����ơG");
    scanf("%d", &n);

    if (n < 1 || n > 9) {
        printf("��J���~�A�п�J 1~9 ����ơC\n");
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%2d ", i * j);
            }
            printf("\n");
        }
    }

    printf("\n�����N���^�D���...\n");
    getch();
}


// �����e�߰ݬO�_�~��
bool continuePrompt() {
    char ans;
    while (true) {
        printf("�O�_�n�����{���H(y/n)�G");
        scanf(" %c", &ans);
        ans = tolower(ans);
        if (ans == 'y') {
            return false;  
        } else if (ans == 'n') {
            return true;   
        } else {
            printf("��J���~�A�п�J y �� n�C\n");
        }
    }
}

