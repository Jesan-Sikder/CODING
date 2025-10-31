/*problem 3 = write a c program that takes N x N matrix's size as input from the user.
now calculate the sum of all the elements of the matrix's and print the sum as output (2D Array).*/

#include <stdio.h>

int main()
{
    int column, row, i, j, sum = 0;
    scanf("%d", &row);
    scanf("%d", &column);

    int arr[row][column];

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    }

    printf("The sum of all elements in the 2D array is: %d\n", sum);

    return 0;
}
