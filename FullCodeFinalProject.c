# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* --------------- Prototype --------------- */
void viewData() ;
void addNewData() ;
void editData() ;
void deleteData() ;
void searchData() ;
void menu() ;

/* --------------- Main --------------- */
int main()
{
    menu() ;
    return 0 ;
}

/* --------------- Menu --------------- */
void menu()
{
    int choice ;

    do
    {
        system("CLS") ;
        printf("===== COFFEE SHOP SALES MENU =====\n") ;

        printf("1. View Data\n") ;
        printf("2. Add New Data\n") ;
        printf("3. Edit Data\n") ;
        printf("4. Delete Data\n") ;
        printf("5. Search Data\n") ;
        printf("6. Quit\n") ;

        printf("Choose an option (1-6): ") ;

        scanf("%d", &choice) ;

        if (choice == 1)
        {
            viewData() ;
        }

        else if (choice == 2)
        {
            addNewData() ;
        }

        else if (choice == 3)
        {
            editData() ;
        }

        else if (choice == 4)
        {
            deleteData() ;
        }

        else if (choice == 5)
        {
            searchData() ;
        }

        else if (choice == 6)
        {
            printf("Exiting program...\n") ;
        }

        else
        {
            printf("\e[31mInvalid choice.\e[0m\n") ;
            printf("\nPress Enter to continue...") ;
            getchar() ; getchar() ;
        }

    } while (choice != 6 ) ;
}

/* --------------- Functions --------------- */
void viewData()
{
    FILE *file = fopen("coffeeshopsales.csv", "r") ;
    if (file == NULL)
    {
        printf("Error: cannot open coffeeshopsales.csv\n") ;
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
        printf("Error: cannot open coffeeshopsales.csv\n") ;
        return ;
    }

    char line[512] ;
    char id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    int choice ;

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

    fclose(file) ;
}

void addNewData()
{
    char transaction_id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    char confirm ;
    int choice ;

    do
    {
        system("CLS") ;
        printf("===== Add New Coffee Sales ===== \n") ;

        printf("Enter the Transaction ID: ") ;
        scanf("%s", transaction_id) ;

        printf("Enter the Store Location: ") ;
        scanf(" %[^\n]", store) ;

        printf("Enter the Product ID: ") ;
        scanf("%s", productID) ;

        printf("Enter the Price: ") ;
        scanf("%s", price) ;

        printf("Enter the Category: ") ;
        scanf(" %[^\n]", category) ;

        printf("Enter the Type: ") ;
        scanf(" %[^\n]", type) ;

        printf("Enter the Detail: ") ;
        scanf(" %[^\n]", detail) ;

        printf("\nYou entered:\n") ;
        printf("%-5s %-17s %-12s %-7s %-20s %-15s %-20s\n", "ID", "Store", "Product ID", "Price", "Category", "Type", "Detail") ;
        printf("%-5s %-17.17s %-12.12s %-7.7s %-20.20s %-15.15s %-20.20s\n", transaction_id, store, productID, price, category, type, detail) ;

        printf("\n Confirm adding this entry? (Y/N): ") ;
        scanf(" %c", &confirm) ;

        if (confirm == 'Y' || confirm == 'y')
        {
            FILE *file = fopen("coffeeshopsales.csv", "a+") ;
            if (file == NULL)
            {
                printf("Error: cannot open coffeeshopsales.csv\n") ;
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
                printf("Entry added successfully!\n") ;
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
            printf("Error: cannot open file\n") ;
            printf("\nPress 0 to return to menu: ") ;
            scanf("%d", &choice) ;
            return ;
        }

        printf("===== Edit Coffee Sales =====\n") ;
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

                    printf("Choose an option (1-7): ") ;
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
                        printf("\e[31mInvalid choice.\e[0m\n") ;
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
            printf("\n\e[32mEntry updated successfully!\e[0m\n") ;
        }

        else
        {
            remove("temp.csv") ;
            printf("\n\e[31mTransaction ID not found.\e[0m\n") ;
        }

        printf("\nPress 0 to return to the menu: ") ;
        scanf("%d", &choice) ;

    } while (choice != 0) ;
}

void deleteData()
{
    FILE *file, *temp ;
    char searchID[256] ;
    char line[512] ;
    char transaction_id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    int choice ;
    int found ;

    do
    {
        system("CLS") ;
        printf("===== Delete Coffee Sales =====\n") ;
        displayAllData() ;

        file = fopen("coffeeshopsales.csv", "r") ;
        temp = fopen("temp.csv", "w") ;

        if (file == NULL || temp == NULL)
        {
            printf("Error: cannot open file\n") ;
            printf("\nPress 0 to return to menu: ") ;
            scanf("%d", &choice) ;
            return ;
        }

        printf("\nEnter the Transaction ID to delete: ") ;
        scanf("%s", searchID) ;

        system("CLS") ;

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
            printf("\n\e[32mEntry deleted successfully!\e[0m\n") ;
        }
        else
        {
            remove("temp.csv") ;
            printf("\n\e[31mTransaction ID not found.\e[0m\n") ;
        }

        printf("\nPress 0 to return to the menu: ") ;
        scanf("%d", &choice) ;

    } while (choice != 0) ;
}

void searchData()
{
    int choice ;

    do
    {
        system("CLS") ;
        printf("searchData called\n") ;

        printf("\nPress 0 to return to the menu: ") ;
        scanf("%d", &choice) ;

    } while (choice != 0) ;
}
