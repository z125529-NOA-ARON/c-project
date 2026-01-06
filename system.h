#ifndef SYSTEM_H
#define SYSTEM_H

#define MAX 200
#define FILE_NAME "coffeeshopsales.csv"

typedef struct {
    int id;
    char product[50];
    float price;
    int quantity;
} Item;

/* global data */
extern Item items[MAX];
extern int count;

/* user-defined functions */
void welcomeScreen();
void loadData();
void saveData();

void viewData();
void addData();
void editData();
void deleteData();

#endif