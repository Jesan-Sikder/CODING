/*problem 2 = write a c program to sum of odd and even  number by using 1D Array.*/


#include <stdio.h>
int main()
{
    int n, i, odd_sum = 0,even_sum=0;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]%2==0){
            even_sum += arr[i];
        }
        else {
            odd_sum += arr[i];

        }
    }
    printf("sum of even number is : %d\n", even_sum);
    printf("sum of odd number is : %d\n", odd_sum);

    return 0;
}
