#include <stdio.h>

int main()
{

    int a;

    printf("Entrer le nombre d'element: ");
    scanf("%d",&a);
    int arr[a];
    int hold =0;
    for (int i = 0; i < a ; i++)
    {      
        scanf("%d", &arr[i]);        
    }
    for (int x = 0 ; x > a ; x++)
    {        
        if (hold < arr[x]){             //
            hold = arr[x]; 
        }   
    }    
    printf("Max : %d",hold);
}