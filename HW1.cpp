#include <stdio.h>
#include <ctype.h>

void task2();
void task3();
void task4();

int main() {
    printf("=========\n");
    printf("*�{���]�p �@�~ 1 *\n");
    printf("*�m�W:E1B33�G���*\n"); 
    printf("*�Ǹ�: 411302233*\n"); 
    printf("@@@@@@\n\n");
    
    task2();
    
    task3();
    
    task4();
    
    return 0;
}

void task2() {
    char password[5];
    printf("�п�J 4 �ӼƦr���K�X: ");
    scanf("%4s", password);
    
    int valid = 1;
    for (int i = 0; i < 4; i++) {
        if (!isdigit(password[i])) {
            valid = 0;
            break;
        }
    }
    
    if (valid) {
        printf("�K�X�]�w���\�I\n");
        printf("�i�J�B�J 3...\n");
    } else {
        printf("�K�X���~�I�Э��s����C\n");
        printf("�K�X���~�X 2024\n");
    }
    printf("\n");
}

void task3() {
    printf("�п�ܥ\����G\n");
    printf("--------------------------------\n");
    printf("| 'A'..'Z'  -> Uppercase      |\n");
    printf("| 'a'..'z'  -> Lowercase      |\n");
    printf("| '0'..'9'  -> Digit          |\n");
    printf("| ��L    -> Your name       |\n");
    printf("--------------------------------\n\n");
}

void task4() {
    char input;
    printf("�п�J 1 �Ӧr��: ");
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
GitHub �O�@�ӱj�j���{���X�U�ޥ��x�A
���}�o�̯�����P�i�檩������B��@�}�o�P�M�׺޲z�C
�ڳz�L GitHub �ǲ� Git ���O�A�p commit�Bpush�Bpull request ���A
�϶}�o�y�{�󶶺Z�C
���~�A�����}�����s���ѳ\�h�ǲ߾��|�A
���ڧ�ִ��ɵ{���}�o��O�C
