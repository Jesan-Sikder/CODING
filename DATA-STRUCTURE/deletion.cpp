/*problem 2 = write a c program for deletion*/
#include <stdio.h>
int main()
{
  int n,position;
  printf("Give the size of the array:\n");
  scanf("%d", &n);
  int arr[n],value;
  printf("Before deletion:\n");
   for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("which value you want to remove? :\n");
  scanf("%d",&value);
  for(int i=0; i<n ; i++){
    if(arr[i]==value){
        position = i;
    }
  }
  for( int i= position ; i<=n ; i++){
    arr[i]=arr[i+1];
  }

  printf("After deletion:\n");
  n--;
   for (int i = 0; i < n; i++)
  {

    printf("%d ", arr[i]);
  }
  return 0;
}









/*#include<stdio.h>
int main()
{
    int n;
    printf("Enter the Array Value: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);

    int position;
    printf("Enter the desired position\n");
    scanf("%d",&position);

    for(int i= position; i< n-1; i++)
        arr[i]=arr[i+1];

    n--;
    printf("After the deletion\n");
    for(int i=0; i<n; i++)
        printf("%d",arr[i]);

        printf("\n");
    return 0;
}
*/