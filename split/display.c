#include "header.h"

void viewData()
{
    FILE *file = fopen("coffeeshopsales.csv", "r") ;
    if (file == NULL)
    {
        printf("\033[31mERROR - Cannot open file\033[0m\n") ;
        return ;
    }

    char line[512] ;
    char id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    int choice ;

    do
    {
        system("CLS") ;
        printf("%-5s %-17s %-12s %-7s %-20s %-15s %-20s\n", "ID", "Store", "Product ID", "Price", "Category", "Type", "Detail") ;
        printf("-------------------------------------------------------------------------------------------------------------\n") ;

        fseek(file, 0, SEEK_SET) ;
        fgets(line, sizeof(line), file) ;

        while(fgets(line, sizeof(line), file))
        {
            if (strncmp(line, "transaction_id", 14) == 0) continue ;

            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, store, productID, price, category, type, detail) ;

            printf("%-5s %-17.17s %-12.12s %-7.7s %-20.20s %-15.15s %-20.20s\n", id, store, productID, price, category, type, detail) ;
        }

        printf("\nPress 0 to return to menu: ") ;
        scanf("%d", &choice) ;
    } while (choice != 0) ;

    fclose(file) ;
}

void displayAllData()
{
    FILE *file = fopen("coffeeshopsales.csv", "r") ;
    if (file == NULL)
    {
        printf("\033[31mERROR - Cannot open file\033[0m\n") ;
        return ;
    }

    char line[512] ;
    char id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    int choice ;

    printf("%-5s %-17s %-12s %-7s %-20s %-15s %-20s\n", "ID", "Store", "Product ID", "Price", "Category", "Type", "Detail") ;
    printf("---------------------------------------------------------------------------------------------------------\n") ;

    fseek(file, 0, SEEK_SET) ;
    fgets(line, sizeof(line), file) ;

    while(fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "transaction_id", 14) == 0) continue ;

        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", id, store, productID, price, category, type, detail) ;

        printf("%-5s %-17.17s %-12.12s %-7.7s %-20.20s %-15.15s %-20.20s\n", id, store, productID, price, category, type, detail) ;
    }

    fclose(file) ;
}