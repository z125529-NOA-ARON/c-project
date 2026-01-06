#include <stdio.h>
#include <string.h>
#include "system.h"

Item items[MAX];
int count = 0;

void welcomeScreen() {
    printf("*****************************\n");
    printf("* Welcome to coffee management system *\n");
    printf("*****************************\n");
}

/* Load CSV into array */
void loadData() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("CSV file not found.\n");
        return;
    }

    char line[200];
    fgets(line, sizeof(line), file); // skip header

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%49[^,],%f,%d",
               &items[count].id,
               items[count].product,
               &items[count].price,
               &items[count].quantity);
        count++;
    }

    fclose(file);
}

/* Save array back to CSV */
void saveData() {
    FILE *file = fopen(FILE_NAME, "w");
    fprintf(file, "id,product,price,quantity\n");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f,%d\n",
                items[i].id,
                items[i].product,
                items[i].price,
                items[i].quantity);
    }

    fclose(file);
}

/* VIEW */
void viewData() {
    printf("\nID | Product | Price | Quantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d | %s | %.2f | %d\n",
               items[i].id,
               items[i].product,
               items[i].price,
               items[i].quantity);
    }

    printf("\nPress 0 to go back: ");
    int back;
    scanf("%d", &back);
}

/* ADD */
void addData() {
    Item temp;
    temp.id = count + 1;

    printf("Product name: ");
    scanf(" %[^\n]", temp.product);
    printf("Price: ");
    scanf("%f", &temp.price);
    printf("Quantity: ");
    scanf("%d", &temp.quantity);

    char confirm;
    printf("Confirm (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y') {
        items[count++] = temp;
        saveData();
        printf("Data added successfully.\n");
    } else {
        printf("Cancelled.\n");
    }

    printf("Press 0 to go back: ");
    int back;
    scanf("%d", &back);
}

/* EDIT */
void editData() {
    int id;
    printf("Enter ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("New price: ");
            scanf("%f", &items[i].price);
            printf("New quantity: ");
            scanf("%d", &items[i].quantity);
            saveData();
            printf("Data updated.\n");
            return;
        }
    }

    printf("ID not found.\n");
}

/* DELETE */
void deleteData() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                items[j] = items[j + 1];
            }
            count--;
            saveData();
            printf("Data deleted.\n");
            return;
        }
    }

    printf("ID not found.\n");
}