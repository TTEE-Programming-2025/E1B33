#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

// ���c�w�q�G�ǥ͸��
struct Student {
    char name[20];
    int id;
    int math;
    int physics;
    int english;
    float average;
};

// �����ܼ�
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// �� 1 �D�G�n�J�e��
int login() {
    char password[10];
    int attempts = 0;
    const char correct_password[] = "2025";

    while (attempts < 3) {
        system("cls"); // �M���e��

        // �ӤH����e�� 
        printf("=====================================\n");
        printf("*                                   *\n");
        printf("*              E1B                  *\n");
        printf("*                                   *\n");
        printf("*               33                  *\n");
        printf("*                                   *\n");
        printf("*             �G���                *\n");
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

        printf("�п�J4��ƱK�X�G");
        scanf("%s", password);

        if (strcmp(password, correct_password) == 0) {
            printf("�n�J���\�I\n");
            system("pause");
            return 1;
        } else {
            printf("�K�X���~�A�ЦA�դ@���C\n");
            attempts++;
            system("pause");
        }
    }

    printf("���~�W�L�T���A�t�ε����I\n");
    return 0;
}

// �� 2 �D�G�D���
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

// �� 3 �D�G��J�ǥͦ��Z
void inputStudents() {
    system("cls");
    int n;

    printf("�п�J�ǥͤH�� (5~10): ");
    scanf("%d", &n);

    while (n < 5 || n > 10) {
        printf("���~�I�п�J 5~10 �������H��: ");
        scanf("%d", &n);
    }

    studentCount = n;

    for (int i = 0; i < n; i++) {
        printf("\n��J�� %d ��ǥ͸�ơG\n", i + 1);

        printf("�m�W�G");
        scanf("%s", students[i].name);

        printf("�Ǹ��]6���ơ^�G");
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("���~�I�п�J6���ƾǸ��G");
            scanf("%d", &students[i].id);
        }

        printf("�ƾǦ��Z�]0~100�^�G");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("���~�I�Э��s��J�G");
            scanf("%d", &students[i].math);
        }

        printf("���z���Z�]0~100�^�G");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("���~�I�Э��s��J�G");
            scanf("%d", &students[i].physics);
        }

        printf("�^�妨�Z�]0~100�^�G");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("���~�I�Э��s��J�G");
            scanf("%d", &students[i].english);
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }

    printf("\n��ƿ�J�����I\n");
    system("pause");
}

// �� 4 �D�G��ܩҦ��ǥ͸��
void displayStudents() {
    system("cls");
    printf("%-10s %-10s %-6s %-6s %-6s %-7s\n", "�m�W", "�Ǹ�", "�ƾ�", "���z", "�^��", "����");
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

// �� 5 �D�G�j�M�S�w�ǥ͸��
void searchStudent() {
    char searchName[20];
    int found = 0;
    system("cls");

    printf("�п�J�n�d�ߪ��ǥͩm�W�G");
    scanf("%s", searchName);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("%-10s %-10s %-6s %-6s %-6s %-7s\n", "�m�W", "�Ǹ�", "�ƾ�", "���z", "�^��", "����");
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
        printf("�d�L���ǥ͸�ơC\n");
    }

    system("pause");
}

// �� 6 �D�G���Z�Ƨ�
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

    printf("%-10s %-10s %-7s\n", "�m�W", "�Ǹ�", "����");
    printf("--------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s %-10d %-7.1f\n",
               students[i].name,
               students[i].id,
               students[i].average);
    }
    system("pause");
}

// �D�{��
int main() {
    char choice;

    if (!login()) {
        return 0; // �n�J����
    }

    while (1) {
        showMenu();
        scanf(" %c", &choice); // �`�N�e���Ů�

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
                printf("�z������}�t��\n");
                system("pause");
                return 0;
            default:
                printf("��J���~�A�Э��s���\n");
                system("pause");
        }
    }

    return 0;
}

