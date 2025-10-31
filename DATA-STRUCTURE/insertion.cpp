/*problem 1 = write a c program for insertion*/
#include <stdio.h>
int main()
{
  int n;
  printf("Give the size of the array:\n");
  scanf("%d", &n);
  int arr[n];
  printf("before insertion:\n");
   for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("enter the position:\n");
   int position;
  scanf("%d", &position);
  printf("enter the value:\n");
   int value;
  scanf("%d", &value);
  n++;
  for (int i = n - 1; i >= position; i--)
  {
    arr[i] = arr[i - 1];
  }

  arr[position] = value;
  printf("After insertion:\n");
   for (int i = 0; i < n; i++)
  {

    printf("%d ", arr[i]);
  }
  return 0;
}