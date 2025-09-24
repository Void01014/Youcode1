#include<stdio.h>

int main()
{
    int a;
    printf("Entrer le nombre d'element: ");
    scanf("%d",&a);

    int arr[a];
    int sum =0;
    for (int i = 0; i < a ; i++)
    {      
        scanf("%d", &arr[i]);
        
    }    
    for (int x = 0 ; x < a ; x++)
    {
        //printf("%d",arr[x]);
        sum += arr[x];
    }   
    printf("la somme egale : %d",sum);

}