#include "header.h"

void deleteData()
{
    FILE *file, *temp ;
    char searchID[256] ;
    char line[512] ;
    char transaction_id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    int choice, found ;

    do
    {
        system("CLS") ;
        printf("\033[30m\033[47m|---------------------------------|\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|       Delete Coffee Sales       |\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|---------------------------------|\033[0m\033[0m\n\n") ;
        displayAllData() ;

        file = fopen("coffeeshopsales.csv", "r") ;
        temp = fopen("temp.csv", "w") ;

        if (file == NULL || temp == NULL)
        {
            printf("\033[31mERROR - Cannot open file\033[0m\n") ;
            printf("\nPress 0 to return to menu: ") ;
            scanf("%d", &choice) ;
            return ;
        }

        printf("\nEnter the Transaction ID to delete: ") ;
        scanf("%s", searchID) ;

        found = 0 ;

        fgets(line, sizeof(line), file) ;
        fputs(line, temp) ;

        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", transaction_id, store, productID, price, category, type, detail) ;

            if (strcmp(transaction_id, searchID) == 0)
            {
                found = 1 ;
                continue ;
            }

            fprintf(temp, "%s,%s,%s,%s,%s,%s,%s\n", transaction_id, store, productID, price, category, type, detail) ;
        }

        fclose(file) ;
        fclose(temp) ;

        if (found)
        {
            remove("coffeeshopsales.csv") ;
            rename("temp.csv", "coffeeshopsales.csv") ;
            printf("\n\e[32mSUCCESS - Entry deleted successfully!\e[0m\n") ;
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
