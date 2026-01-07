# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/* --------------- Prototype --------------- */
void viewData() ;
void addNewData() ;
void editData() ;
void deleteData() ;
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
        printf("5. Quit\n") ;

        printf("Choose an option (1-5): ") ;

        scanf("%d", &choice) ;

        if (choice == 1)
        {
            viewData() ;
            printf("\nPress Enter to continue...") ;
            getchar() ; getchar() ;
        }
        else if (choice == 2)
        {
            addNewData() ;
            printf("\nPress Enter to continue...") ;
            getchar() ; getchar() ;
        }
        else if (choice == 3)
        {
            editData() ;
            printf("\nPress Enter to continue...") ;
            getchar() ; getchar() ;
        }
        else if (choice == 4)
        {
            deleteData() ;
            printf("\nPress Enter to continue...") ;
            getchar() ; getchar() ;
        }
        else if (choice == 5)
        {
            printf("Exiting program...\n") ;
        }
        else
        {
            printf("\e[31mInvalid choice.\e[0m\n") ;
            printf("\nPress Enter to continue...") ;
            getchar() ; getchar() ;
        }

    } while (choice != 5 ) ;
}

/* --------------- Functions --------------- */
void viewData()
{
    FILE *file = fopen("coffeeshopsales.csv", "r") ;
    if (file == NULL)
    {
        printf("Error: cannot open coffeeshopsales.csv\n") ;
    }

    char line[256] ;
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
        scanf(" %[^\n]s", store) ;

        printf("Enter the Product ID: ") ;
        scanf("%s", productID) ;

        printf("Enter the Price: ") ;
        scanf("%s", price) ;

        printf("Enter the Category: ") ;
        scanf(" %[^\n]s", category) ;

        printf("Enter the Type: ") ;
        scanf(" %[^\n]s", type) ;

        printf("Enter the Detail: ") ;
        scanf(" %[^\n]s", detail) ;

        printf("\nYou entered:\n") ;
        printf("%-5s %-17s %-12s %-7s %-20s %-15s %-20s\n", "ID", "Store", "Product ID", "Price", "Category", "Type", "Detail") ;
        printf("%-5s %-17.17s %-12.12s %-7.7s %-20.20s %-15.15s %-20.20s\n", transaction_id, store, productID, price, category, type, detail) ;

        printf("\n Confirm adding this entry? (Y/N): ") ;
        scanf(" %c", &confirm) ;

        if (confirm == 'Y' || confirm == 'y')
        {
            FILE *file = fopen("coffeeshopsales.csv", "a") ;
            if (file == NULL)
            {
                printf("Error: cannot open coffeeshopsales.csv\n") ;
            }

            else
            {
                fprintf(file, "%s,%s,%s,%s,%s,%s,%s", transaction_id, store, productID, price, category, type, detail) ;
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
    printf("editData called\n") ;
}

void deleteData()
{
    printf("deleteData called\n") ;
}
