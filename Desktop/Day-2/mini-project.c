#include <stdio.h>
#include <string.h>

int main(){

    int choice;
    int number_of_books = 0;
    int choice_2;
    char title[100][40];
    char author[100][40];
    float price[100];
    int quantity[100];
    int sum = 0;
    

    while (1)
    {

        printf("1.Add a book to the library\n");
        printf("2.Show all books in the library\n");
        printf("3.Search for a book in the library\n");
        printf("4.Update the quantity of a book\n");
        printf("5.Remove a book from the library\n");
        printf("6.Show the total number of books in the library\n");
        scanf("%d", &choice);
        getchar(); // eat the leftover '\n'

        if (number_of_books >= 100 && choice == 1){
            printf("Cannot add more books. Library is full.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            printf("Enter the title of the book to add:\n");
            fgets(title[number_of_books], sizeof(title[number_of_books]), stdin);
            title[number_of_books][strcspn(title[number_of_books], "\n")] = 0;  // Remove newline character
            printf("Enter the author of the book to add:\n");
            fgets(author[number_of_books], sizeof(author[number_of_books]), stdin);
            author[number_of_books][strcspn(author[number_of_books], "\n")] = 0;  // Remove newline character
            printf("Enter the price of the book to add (in dollars):\n");
            scanf("%f", &price[number_of_books]);
            printf("Enter the quantity of the book to add:\n");
            scanf("%d", &quantity[number_of_books]);
            getchar(); // eat the leftover '\n'
            printf("Book added successfully!\n");
            number_of_books++;
            break;
        case 2:
            printf("Showing all books in the library...\n");
            for (int i = 0; i < number_of_books; i++)
            {
                printf("Book %d:\n", i + 1);
                printf("Title: %s\n", title[i]);
                printf("Author: %s\n", author[i]);
                printf("Price: %.2f$\n", price[i]);
                printf("Quantity: %d\n", quantity[i]);
            }
            break;
        case 3:{
            char search_title[40];

            printf("Enter the title of the book to search: (upper/lower case matter)\n");
            fgets(search_title, sizeof(search_title), stdin);
            search_title[strcspn(search_title, "\n")] = 0;  // Remove newline character
            printf("Searching for the book...\n");
            int found = 0;

            for (int i = 0; i < number_of_books; i++){
                if (strcmp(title[i], search_title) == 0)
                {
                    printf("Book found:\n");
                    printf("Title: %s\n", title[i]);
                    printf("Author: %s\n", author[i]);
                    printf("Price: %.2f\n", price[i]);
                    printf("Quantity: %d\n", quantity[i]);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("Book not found.\n");
            }
            break;
        }
        case 4:{
            char update_title[40];
            int found =0;
            printf("Enter the title of the book to update quantity:\n");
            fgets(update_title, sizeof(update_title), stdin);
            printf("Updating the quantity of a book...\n");
            update_title[strcspn(update_title,"\n")] = 0;
            for (int i = 0; i < number_of_books; i++){
                if (strcmp(title[i], update_title) == 0){
                    printf("Enter new quantity: \n");
                    scanf("%d", &quantity[i]);
                    getchar();
                    printf("Quantity updated successfully!\n");
                    found = 1;
                }
            }
            if (!found){
                printf("This title is not present in the library.\n");
            }
            break;
        }
        case 5:{
            char delete_title[40];
            int found = 0;

            printf("Enter the title of the book to remove:\n");
            fgets(delete_title, sizeof(delete_title), stdin);
            delete_title[strcspn(delete_title, "\n")] = 0;

            for (int i = 0; i < number_of_books; i++){    
                if (strcmp(title[i], delete_title) == 0){
                    strcpy(title[i], title[number_of_books - 1]);
                    strcpy(author[i], author[number_of_books - 1]);
                    price[i] = price[number_of_books - 1];
                    quantity[i] = quantity[number_of_books - 1];
                    number_of_books --;
                    found = 1;
                    break;
                }
                continue;
            }
            if (! found){
                printf("This title is not present in the library. \n");
            }
            break;
        }
        case 6:
            for (int i = 0; i < number_of_books; i++){
                sum += quantity[i];
            }
            printf("Total books: %d\n", sum);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
        printf("Do you want to continue? (1 for Yes, 0 for No):\n");
        scanf("%d", &choice_2);
        getchar();
        if (choice_2 == 0)
        {
            break;
        }
    }

    return 0;
}