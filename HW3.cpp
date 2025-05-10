#include <stdio.h>
#include <string.h>

int main() {
    char password[10];
    int attempts = 0;
    
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
    printf("*                   *\n");
	printf("*      github       *\n");
    printf("*                   *\n");
    printf("*       HW3         *\n");
    printf("*                   *\n");
    printf("*********************\n");

  
    while (attempts < 3) {
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(password, "2025") == 0) {
            printf("Password correct! Welcome!\n");
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
