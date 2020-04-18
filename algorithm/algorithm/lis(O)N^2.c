#include <stdio.h>
#include <stdlib.h>

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
int lis(int* arr, size_t len)
{

    if(len == 0)
        return 0;
    int ret = 0;
    for(int i = 0 ; i < len ; i++)
    {
        int brr[100];
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
    int arr[100] = { 1, 3, 88, 57, 24, 45, 3, 34, 66, 35};
    printf("%d\n",lis(arr, 10));
}