#include "header.h"

void addNewData()
{
    char transaction_id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    char confirm ;
    int choice, idExists ;

    do
    {
        system("CLS") ;
        printf("\033[30m\033[47m|----------------------------------|\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|       Add New Coffee Sales       |\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|----------------------------------|\033[0m\033[0m\n\n") ;

        FILE *file ;

        do
        {
            idExists = 0 ;
            printf("Enter the Transaction ID: ") ;
            scanf("%s", transaction_id) ;

            file = fopen("coffeeshopsales.csv", "r") ;
            if (file != NULL)
            {
                char line[512], existingID[256] ;
                fgets(line, sizeof(line), file) ;
                while (fgets(line, sizeof(line), file))
                {
                    sscanf(line,  "%[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*s", existingID) ;
                    if (strcmp(transaction_id, existingID) == 0)
                    {
                        printf("\033[31mERROR - Transaction ID already exists. Please enter a different ID.\033[0m\n\n") ;
                        idExists = 1 ;
                        break ;
                    }
                }
                fclose(file) ;
            }
        } while (idExists) ;


        printf("   Enter the Store Location: ") ;
        scanf(" %[^\n]", store) ;

        printf("   Enter the Product ID: ") ;
        scanf("%s", productID) ;

        printf("   Enter the Price: ") ;
        scanf("%s", price) ;

        printf("   Enter the Category: ") ;
        scanf(" %[^\n]", category) ;

        printf("   Enter the Type: ") ;
        scanf(" %[^\n]", type) ;

        printf("   Enter the Detail: ") ;
        scanf(" %[^\n]", detail) ;

        printf("\nYou entered:\n") ;
        printf("%-5s %-17s %-12s %-7s %-20s %-15s %-20s\n", "ID", "Store", "Product ID", "Price", "Category", "Type", "Detail") ;
        printf("%-5s %-17.17s %-12.12s %-7.7s %-20.20s %-15.15s %-20.20s\n", transaction_id, store, productID, price, category, type, detail) ;

        printf("\n Confirm adding this entry? (Y/N): ") ;
        scanf(" %c", &confirm) ;

        if (confirm == 'Y' || confirm == 'y')
        {
            file = fopen("coffeeshopsales.csv", "a+") ;
            if (file == NULL)
            {
                printf("\033[31mERROR - Cannot open file\033[0m\n") ;
            }

            else
            {
                fseek(file, 0, SEEK_END) ;
                long pos = ftell(file) ;
                if (pos > 0)
                {
                    fseek(file, -1, SEEK_END) ;
                    char lastChar ;
                    fread(&lastChar, 1, 1, file) ;
                    if (lastChar != '\n') fputc('\n', file) ;
                }

                fprintf(file, "%s,%s,%s,%s,%s,%s,%s\n", transaction_id, store, productID, price, category, type, detail) ;
                fclose(file) ;
                printf("\e[32mSUCCESS - Entry added successfully!\e[0m\n") ;
            }
        }

        else
        {
            printf("Entry cancelled.\n") ;
        }

        printf("\nPress 0 to return to the menu: ") ;
        scanf("%d", &choice) ;


    } while (choice != 0) ;

}