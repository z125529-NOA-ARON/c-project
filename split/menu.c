#include "header.h"

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
