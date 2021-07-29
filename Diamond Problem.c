#include<stdio.h>
void main()
{ 
    int row, col, space, n;
    printf("No. of rows =");
    scanf("%d", &n);  

    for (row = 1; row <= n; row++)
    {
        for (space = 0; space <= n-row; space++)
        printf(" ");
        for (col=1;col<=(2*row)-1;col++)
        printf("*");
        printf("\n");
    }
    
    for ( row = n-1 ; row >= 1; row--)
    {
        for (space = 0; space <= n-row; space++)
        printf(" ");
        for (col=1;col<=(2*row)-1;col++)
        printf("*");
        printf("\n");
    }

}
