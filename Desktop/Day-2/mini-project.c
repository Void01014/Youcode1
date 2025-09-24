#include <stdio.h>
#include <string.h>

int main(){

    int choix;                  //Le choix de quel option l'utilisateur souhaite utiliser
    int choix_2;                //Le choix de continuer ou pas
    int nombre_de_livres = 0;   //Fait meme role que i dans une for loop
    char titre[100][40];
    char auteur[100][40];
    float prix[100];
    int quantite[100];
    int somme = 0;              //La somme totale de toutes les livres
    

    while (1)
    {

        printf("1.Add a book to the library\n");
        printf("2.Show all books in the library\n");
        printf("3.Search for a book in the library\n");
        printf("4.Update the quantite of a book\n");
        printf("5.Remove a book from the library\n");
        printf("6.Show the total number of books in the library\n");
        scanf("%d", &choix);
        getchar(); // pour eliminer '\n' additionnel

        if (nombre_de_livres >= 100 && choix == 1){
            printf("Cannot add more books. Library is full.\n"); // un detail pour eviter les erreurs de "overload"
            continue;
        }
        switch (choix)
        {
        case 1:
            printf("Entrez le titre du livre\n");
            fgets(titre[nombre_de_livres], sizeof(titre[nombre_de_livres]), stdin);
            titre[nombre_de_livres][strcspn(titre[nombre_de_livres], "\n")] = 0;  //Eliminer '\n'
            printf("Entrez l'autheur du livre\n");
            fgets(auteur[nombre_de_livres], sizeof(auteur[nombre_de_livres]), stdin);
            auteur[nombre_de_livres][strcspn(auteur[nombre_de_livres], "\n")] = 0;  //Eliminer '\n'
            printf("Enter the prix of the book to add (in dollars):\n");
            scanf("%f", &prix[nombre_de_livres]);
            printf("Enter the quantite of the book to add:\n");
            scanf("%d", &quantite[nombre_de_livres]);
            getchar(); // Eliminer '\n'
            printf("Book added successfully!\n");
            nombre_de_livres++;
            break;
        case 2:
            printf("Showing all books in the library...\n");

            for (int i = 0; i < nombre_de_livres; i++)
            {
                printf("Book %d:\n", i + 1);
                printf("titre: %s\n", titre[i]);
                printf("auteur: %s\n", auteur[i]);
                printf("prix: %.2f$\n", prix[i]);
                printf("quantite: %d\n", quantite[i]);
            }
            break;
        case 3:{
            char cherecher_titre[40];  //Le titre que l'utilisateur souhaite chercher
            int trouve = 0;            //Indique si le livre à été trouvé ou pas

            printf("Entrez le titre du livre à rechercher : (la casse majuscule/minuscule est importante)\n");
            fgets(cherecher_titre, sizeof(cherecher_titre), stdin);
            cherecher_titre[strcspn(cherecher_titre, "\n")] = 0;  // Eliminer '\n'

            for (int i = 0; i < nombre_de_livres; i++){
                if (strcmp(titre[i], cherecher_titre) == 0)
                {
                    printf("Book trouve:\n");
                    printf("titre: %s\n", titre[i]);
                    printf("auteur: %s\n", auteur[i]);
                    printf("prix: %.2f\n", prix[i]);
                    printf("quantite: %d\n", quantite[i]);
                    trouve = 1;
                    break;
                }
            }
            if (!trouve)
            {
                printf("Le titre n'ete pas trouve.\n");
            }
            break;
        }
        case 4:{
            char mettre_a_jour_titre[40];   //Le titre que l'utilisateur souhaite changer son quantite
            int trouve =0;                  //Indique si le livre à été trouvé ou pas

            printf("Entrez le titre du livre pour mettre à jour la quantité :\n");
            fgets(mettre_a_jour_titre, sizeof(mettre_a_jour_titre), stdin);
            mettre_a_jour_titre[strspn(mettre_a_jour_titre, '\n')];      //Eliminer '\n'

            for (int i = 0; i < nombre_de_livres; i++){
                if (strcmp(titre[i], mettre_a_jour_titre) == 0){
                    printf("Entrez la nouvelle quantite: \n");
                    scanf("%d", &quantite[i]);
                    getchar();      // Eliminer '\n'
                    printf("Quantite mise a jour avec succes !\n");
                    trouve = 1;
                }
            }
            if (!trouve){
                printf("Ce titre n'est pas présent dans la bibliothèque.\n");
            }
            break;
        }
        case 5:{
            char supprimer_titre[40];
            int trouve = 0;

            printf("Entrez le titre que vous souhaitez supprimer:\n");
            fgets(supprimer_titre, sizeof(supprimer_titre), stdin);
            supprimer_titre[strcspn(supprimer_titre, "\n")] = 0;

            for (int i = 0; i < nombre_de_livres; i++){    
                if (strcmp(titre[i], supprimer_titre) == 0){
                    strcpy(titre[i], titre[nombre_de_livres - 1]);
                    strcpy(auteur[i], auteur[nombre_de_livres - 1]);
                    prix[i] = prix[nombre_de_livres - 1];
                    quantite[i] = quantite[nombre_de_livres - 1];
                    nombre_de_livres --;
                    trouve = 1;
                    break;
                }
            }
            if (! trouve){
                printf("Ce titre n'est pas present dans la bibliotheque.\n");
            }
            break;
        }
        case 6:
            for (int i = 0; i < nombre_de_livres; i++){
                somme += quantite[i];
            }
            printf("Total books: %d\n", somme);
            break;
        default:
            printf("Choix invalid, entrez un nombre de 1 a 6.\n");
            break;
        }
        printf("Est-ce-que vous souhaitez continuer (1: pour Ouis, 0: pour Non):\n");
        scanf("%d", &choix_2);
        getchar();      // Eliminer '\n'
        if (choix_2 == 0)
        {
            break;
        }
    }

    return 0;
}