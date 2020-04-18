#include <stdlib.h>
#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}
void print_arr(int* arr, size_t len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
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
int lis(int* arr, size_t len)
{
    if(len == 0)
        return 0;
    int ret = 0;
    for(int i = 0 ; i < len ; i++)
    {
        int brr[len];
        int p = 0;
        for(int j = i + 1 ; j < len; j++)
        {
            if(arr[i] < arr[j])
            {
                brr[p++] = arr[j];
            }
            ret = max(ret , 1 + lis(brr, p));
        }
    }
    return ret;
}
int main()
{
    int n = 10;
    int brr[n];

    for(int i = 0; i < n ; i ++)
    {
        printf("0 ");
    }
}