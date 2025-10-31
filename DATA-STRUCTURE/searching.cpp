#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;
/*linear search support insorted array but
it can take much time than binary search*/
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
/*binary search is only for sorted array and
it take less time than the linear search*/
int binarySearch(int arr[], int size, int element)
{
    int low=0, mid, high=size-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid]==element)
        {
            return mid;
        }
        if (arr[mid]<element)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
        
    }
    return -1;
}
int main()
{
    /*that code is for linear search*/

    // int arr[] = {1, 3, 5, 56, 4, 54634, 56, 34};
    // int size = sizeof(arr) / sizeof(int); //----> 32 / 4 = 8 (size)
    // int element = 1;
    // int searchIndex = linearSearch(arr, size, element);
    // cout << "the element " << element << " was found at index " << searchIndex << endl;

    /*that code is for binary search*/
    int arr[]={1,3,5,56,64,73,123,444};
    int size = sizeof(arr) / sizeof(int); //----> 32 / 4 = 8 (size)
    int element = 444;
    int searchIndex = binarySearch(arr, size, element);
    cout << "the element " << element << " was found at index " << searchIndex << endl;
    return 0;
}