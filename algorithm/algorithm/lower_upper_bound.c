#include <stdio.h>
#include <stdlib.h>

int lower_bound(int* arr, int len, int key)
{
    int start = 0;
    int end = len;

    int middle = len;
    while(end - start >0)
    {
        middle = (start + end) / 2;
        if(key > arr[middle])
        {
            start = middle + 1;
        }
        else
        {
            end = middle;
        }
        
    }
    return end + 1;
}

int upper_bound(int* arr, int len, int key)
{
    int start = 0;
    int end = len;

    int middle = end;
    while(end - start > 0)
    {
        middle = (start + end) / 2;
        if(key >= arr[middle])
        {
            start = middle +1;
        }
        else
        {
            end = middle;
        }
        
    }
    return end + 1;
}

int main()
{
    int arr[] = { 2, 3, 4, 6, 7, 9, 10, 12, 15, 17, 23, 25, 27 };
    printf("lower bound = %d\n", lower_bound(arr, 13, 27));
    printf("upper bound = %d\n", upper_bound(arr, 13, 27));
}