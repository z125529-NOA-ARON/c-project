# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* --------------- Prototype --------------- */
void viewData() ;
void displayAllData() ;
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
        printf("\033[30m\033[47m|----------------------------------|\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|      COFFEE SHOP SALES MENU      |\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|----------------------------------|\033[0m\033[0m\n\n") ;

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
            printf("\e[31mERROR - Invalid choice\e[0m\n") ;
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

void searchData()
{
    FILE *file ;
    char line[512] ;
    char transaction_id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    char selectedCategory[256] ;
    int choice, found ;


    do
    {
        system("CLS") ;
        found = 0 ;

        printf("\033[30m\033[47m|--------------------------------|\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|        COFFEE SHOP MENU        |\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|--------------------------------|\033[0m\033[0m\n\n") ;

        printf("\n   HOT DRINKS\n") ;
        printf("    1. Coffee\n") ;
        printf("    2. Tea\n") ;
        printf("    3. Drinking Chocolate\n") ;
        printf("    4. Espresso\n") ;
        printf("    5. Latte\n") ;

        printf("\n   COLD DRINKS\n") ;
        printf("    6. Iced Coffee\n") ;
        printf("    7. Cold Brew\n") ;
        printf("    8. Iced Tea\n") ;

        printf("\n   FOOD\n") ;
        printf("    9. Bakery\n") ;
        printf("    10. Snacks\n") ;

        printf("\n0. Return to main menu\n\n") ;
        printf("Choose a category: ") ;
        scanf("%d", &choice) ;

        if (choice == 0)
            return ;

        if (choice == 1)
            strcpy(selectedCategory, "Coffee") ;
        else if (choice == 2)
            strcpy(selectedCategory, "Tea") ;
        else if (choice == 3)
            strcpy(selectedCategory, "Drinking Chocolate") ;
        else if (choice == 4)
            strcpy(selectedCategory, "Espresso") ;
        else if (choice == 5)
            strcpy(selectedCategory, "Latte") ;
        else if (choice == 6)
            strcpy(selectedCategory, "Iced Coffee") ;
        else if (choice == 7)
            strcpy(selectedCategory, "Cold Brew") ;
        else if (choice == 8)
            strcpy(selectedCategory, "Iced Tea") ;
        else if (choice == 9)
            strcpy(selectedCategory, "Bakery") ;
        else if (choice == 10)
            strcpy(selectedCategory, "Snacks") ;
        else
        {
            printf("\n\e[31mERROR - Invalid choice\e[0m\n") ;
            printf("Press Enter to continue...") ;
            getchar() ; getchar() ;
            continue ;
        }

        system("CLS") ;
        printf("========== CATEGORY: %s ==========\n\n", selectedCategory) ;

        file = fopen("coffeeshopsales.csv", "r") ;
        if (file == NULL)
        {
            printf("\033[31mERROR - Cannot open file\033[0m\n") ;
            printf("Press Enter to continue...") ;
            getchar() ; getchar() ;
            return ;
        }

        fgets(line, sizeof(line), file) ;

        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                   transaction_id, store, productID, price,
                   category, type, detail) ;

            if (strcmp(category, selectedCategory) == 0)
            {
                if (!found)
                {
                    printf("%-5s %-17s %-12s %-7s %-20s %-15s %-20s\n",
                           "ID", "Store", "Product ID", "Price",
                           "Category", "Type", "Detail") ;
                    printf("-------------------------------------------------------------------------------------------------------------\n") ;
                }

                found = 1 ;

                printf("%-5s %-17.17s %-12.12s %-7.7s %-20.20s %-15.15s %-20.20s\n",
                       transaction_id, store, productID, price,
                       category, type, detail) ;
            }
        }

        fclose(file) ;

        if (!found)
        {
            char soldOutMsg[] = "SOLD OUT - NO ITEMS FOUND" ;
            int len, msgLen, spaces, i ;

            len = strlen("========== CATEGORY: ") + strlen(selectedCategory) + strlen(" ==========") ;
            msgLen = strlen(soldOutMsg) ;
            spaces = (len - msgLen) / 2 ;



            for(i = 0 ; i < spaces ; i++)
            {
                printf(" ") ;
            }
            printf("\033[41m%s\033[0m\n\n", soldOutMsg) ;

            for(i = 0 ; i < len ; i++)
            {
                printf("=") ;
            }
        }

        printf("\n\nPress 0 to return to the menu: ") ;
        scanf("%d", &choice) ;

    } while (choice != 0) ;
}
