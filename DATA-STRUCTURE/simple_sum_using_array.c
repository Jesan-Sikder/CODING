/*problem 1 = write a c program to sum of N number by using 1D Array.*/


#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("sum of N number is : %d", sum);
    return 0;
}
