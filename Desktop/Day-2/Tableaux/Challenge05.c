#include <stdio.h>

int main()
{

    int a, hold;

    printf("Entrer le nombre d'element: ");
    scanf("%d",&a);
    int arr[a];   
    for (int i = 0; i < a ; i++)
    {      
        scanf("%d", &arr[i]);        
    }
    
    hold = arr[0];
    
    for (int x = 1 ; x < a ; x++)
    {        
        if (hold > arr[x]){
            hold = arr[x];
        }      
    }    
    printf("Min = %d\n", hold);
}