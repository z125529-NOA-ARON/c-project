#include <stdio.h>
#include "menu.h"
#include "system.h"

void menu() {
    int choice;

    do {
        printf("\nPlease choose menu 1, 2, 3, 4\n");
        printf("1. View data\n");
        printf("2. Add data\n");
        printf("3. Edit data\n");
        printf("4. Delete data\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewData(); break;
            case 2: addData(); break;
            case 3: editData(); break;
            case 4: deleteData(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 0);
}