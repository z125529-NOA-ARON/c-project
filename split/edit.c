#include "header.h"

void editData()
{
    FILE *file ;
    FILE *temp ;

    char searchID[256] ;
    char line[512] ;
    char transaction_id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;

    int choice ;
    int found = 0 ;

    do
    {
        system("CLS") ;

        file = fopen("coffeeshopsales.csv", "r") ;
        temp = fopen("temp.csv", "w") ;

        if (file == NULL || temp == NULL)
        {
            printf("\e[31mERROR - cannot open file\e[0m\n") ;
            printf("\nPress 0 to return to menu: ") ;
            scanf("%d", &choice) ;
            return ;
        }

        printf("\033[30m\033[47m|---------------------------------|\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|        Edit Coffee Sales        |\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|---------------------------------|\033[0m\033[0m\n\n") ;
        displayAllData() ;

        printf("\nEnter the Transaction ID to edit: ") ;
        scanf("%s", searchID) ;

        system("CLS") ;

        fgets(line, sizeof(line), file) ;
        fputs(line, temp) ;

        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", transaction_id, store, productID, price, category, type, detail) ;

            if (strcmp(transaction_id, searchID) == 0)
            {
                found = 1 ;

                printf("\nCurrent data:\n") ;
                printf("%-5s %-17s %-12s %-7s %-20s %-15s %-20s\n", "ID", "Store", "Product ID", "Price", "Category", "Type", "Detail") ;
                printf("%-5s %-17.17s %-12.12s %-7.7s %-20.20s %-15.15s %-20.20s\n", transaction_id, store, productID, price, category, type, detail) ;

                int editChoice ;

                do
                {
                    printf("\nWhat do you want to edit?\n") ;
                    printf("1. Store Location\n") ;
                    printf("2. Product ID\n") ;
                    printf("3. Price\n") ;
                    printf("4. Category\n") ;
                    printf("5. Type\n") ;
                    printf("6. Detail\n") ;
                    printf("7. Finish editing (save & quit)\n") ;

                    printf("\nChoose an option (1-7): ") ;
                    scanf("%d", &editChoice) ;

                    if (editChoice == 1)
                    {
                        printf("New Store Location: ") ;
                        scanf(" %[^\n]", store) ;
                        getchar() ;
                    }

                    else if (editChoice == 2)
                    {
                        printf("New Product ID: ") ;
                        scanf("%s", productID) ;
                        getchar() ;
                    }

                    else if (editChoice == 3)
                    {
                        printf("New Price: ") ;
                        scanf("%s", price) ;
                        getchar() ;
                    }

                    else if (editChoice == 4)
                    {
                        printf("New Category: ") ;
                        scanf(" %[^\n]", category) ;
                        getchar() ;
                    }

                    else if (editChoice == 5)
                    {
                        printf("New Type: ") ;
                        scanf(" %[^\n]", type) ;
                        getchar() ;
                    }

                    else if (editChoice == 6)
                    {
                        printf("New Detail: ") ;
                        scanf(" %[^\n]", detail) ;
                        getchar() ;
                    }

                    else if (editChoice == 7)
                    {
                        printf("Exiting Edit Menu...") ;
                    }

                    else
                    {
                        printf("\e[31mERROR - Invalid choice\e[0m\n") ;
                        printf("\nPress Enter to continue...") ;
                        getchar() ; getchar() ;
                    }
                } while (editChoice != 7) ;
            }

            fprintf(temp, "%s,%s,%s,%s,%s,%s,%s\n", transaction_id, store, productID, price, category, type, detail) ;
        }

        fclose(file) ;
        fclose(temp) ;

        if (found)
        {
            remove("coffeeshopsales.csv") ;
            rename("temp.csv", "coffeeshopsales.csv") ;
            printf("\n\n\e[32mSUCCESS - Entry updated successfully!\e[0m\n") ;
        }

        else
        {
            remove("temp.csv") ;
            printf("\n\e[31mERROR - Transaction ID not found\e[0m\n") ;
        }

        printf("\nPress 0 to return to the menu: ") ;
        scanf("%d", &choice) ;

    } while (choice != 0) ;
}
