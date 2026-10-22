#include <stdio.h>

int main() {
    int choice;
    do {
        printf("\n1. Greet\n2. Say Goodbye\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Hello! Welcome.\n");
                break;
            case 2:
                printf("Goodbye! Have a nice day.\n");
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 3);

    return 0;
}
