// extra features modified
#include <stdio.h>

int main(void) {
    int n; 
    char choice; 

    do {
        printf("Enter an integer: "); 
        if (scanf("%d", &n) != 1) { 
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        
        if (n % 2 == 0) {
            printf("%d is an even number!\n", n);
        } else {
            printf("%d is an odd number!\n", n);
        }

    
        printf("Do you want to check another number? (y/n): ");
        while (getchar() != '\n'); 
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    return 0; 
}
