#include <stdio.h>
int main()
{
    int a = 2;
    int arr[a][a];

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            printf("%d -> ", arr[i][j]);
        }
    }
    return 0;
}