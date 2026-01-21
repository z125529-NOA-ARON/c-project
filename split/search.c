#include "header.h"

void searchData()
{
    FILE *file ;
    char line[512] ;
    char transaction_id[256], store[256], productID[256], price[256], category[256], type[256], detail[256] ;
    char searchLocation[256] ;
    char selectedCategory[256] ;
    int choice, searchType, found ;


    do
    {
        system("CLS") ;
        found = 0 ;

        printf("\033[30m\033[47m|--------------------------------|\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|       SEARCH COFFEE DATA       |\033[0m\033[0m\n") ;
        printf("\033[30m\033[47m|--------------------------------|\033[0m\033[0m\n\n") ;

        printf("Search by: \n") ;
        printf("   1. Category\n") ;
        printf("   2. Location") ;
        printf("\n0. Return to main menu\n\n") ;

        printf("Choose a search mode: ") ;
        scanf("%d", &searchType) ;

        if (searchType == 0)
            return ;

        if (searchType == 1)
        {
            system("CLS") ;
            printf("\033[30m\033[47m|--------------------------------|\033[0m\033[0m\n") ;
            printf("\033[30m\033[47m|        COFFEE SHOP MENU        |\033[0m\033[0m\n") ;
            printf("\033[30m\033[47m|--------------------------------|\033[0m\033[0m\n") ;

            printf("\n            \033[30m\033[47mHOT DRINKS\033[0m\033[0m\n") ;
            printf("       1. Coffee\n") ;
            printf("       2. Tea\n") ;
            printf("       3. Drinking Chocolate\n") ;
            printf("       4. Espresso\n") ;
            printf("       5. Latte\n") ;

            //printf("--------------------------------") ;

            printf("\n            \033[30m\033[47mCOLD DRINKS\033[0m\033[0m\n") ;
            printf("       6. Iced Coffee\n") ;
            printf("       7. Cold Brew\n") ;
            printf("       8. Iced Tea\n") ;

            //printf("--------------------------------") ;

            printf("\n               \033[30m\033[47mFOOD\033[0m\033[0m\n") ;
            printf("       9. Bakery\n") ;
            printf("       10. Snacks\n") ;

            //printf("--------------------------------") ;

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
        }

        else if (searchType == 2)
        {
            system("CLS") ;
            file = fopen("coffeeshopsales.csv", "r") ;
            if (file == NULL)
            {
                printf("\033[31mERROR - Cannot open file\033[0m\n") ;
                printf("Press Enter to continue...") ;
                getchar() ; getchar() ;
                return ;
            }

            fgets(line, sizeof(line), file) ;

            char locations[100][256] ;
            int locCount = 0 ;
            int exists, i ;

            while(fgets(line, sizeof(line), file))
            {
                sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", transaction_id, store, productID, price, category, type, detail) ;

                exists = 0 ;

                for (i = 0 ; i < locCount ; i++)
                {
                    if (strcmp(store, locations[i]) == 0)
                    {
                        exists = 1 ;
                        break ;
                    }
                }

                if (!exists)
                {
                    strcpy(locations[locCount], store) ;
                    locCount++ ;
                }
            }

            fclose(file) ;

            printf("Available store locations: \n") ;

            for (i = 0 ; i < locCount ; i++)
            {
                printf("   - %s\n", locations[i]) ;
            }

            printf("\nEnter location: ") ;
            getchar() ;
            fgets(searchLocation, sizeof(searchLocation), stdin) ;
            searchLocation[strcspn(searchLocation, "\n")] = '\0' ;
        }

        else
        {
            printf("\n\e[31mERROR - Invalid choice\e[0m\n") ;
            printf("Press Enter to continue...") ;
            getchar() ; getchar() ;
            continue ;
        }

        system("CLS") ;

        if (searchType == 1)
        {
            printf("========== CATEGORY: %s ==========\n\n", selectedCategory) ;
        }

        else if (searchType == 2)
        {
            printf("========== LOCATION: %s ==========\n\n", searchLocation) ;
        }

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

            if ((searchType == 1 && strcmp(category, selectedCategory) == 0) || (searchType == 2 && strcmp(store, searchLocation) == 0))
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
            if (searchType == 1)
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

            else if (searchType == 2)
            {
                char notFoundMsg[] = "STORE NOT FOUND" ;
                int len, msgLen, spaces, i ;

                len = strlen("========== CATEGORY: ") + strlen(searchLocation) + strlen(" ==========") ;
                msgLen = strlen(notFoundMsg) ;
                spaces = (len - msgLen) / 2 ;



                for(i = 0 ; i < spaces ; i++)
                {
                    printf(" ") ;
                }
                printf("\033[41m%s\033[0m\n\n", notFoundMsg) ;

                for(i = 0 ; i < len ; i++)
                {
                    printf("=") ;
                }
            }
        }

        printf("\n\nPress 0 to return to the menu: ") ;
        scanf("%d", &choice) ;

    } while (choice != 0) ;
}
