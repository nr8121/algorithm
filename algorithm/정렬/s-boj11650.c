#include <stdio.h>
#include <stdlib.h>
int sorted_x[100000];
int sorted_y[100000];
int arr_x[100000];
int arr_y[100000];
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int* arr, int start, int end)
{
    int middle = (start + end)/2;
    int left = start;
    int right = middle + 1;
    int index = start;
    while(left <= middle && right <= end)
    {
        if(arr[left] < arr[right])
        {
            sorted_x[index] = arr[left]; 
            sorted_y[index] = arr_y[left];
            left++;
        }
        else if(arr[left] == arr[right])
        {
            sorted_x[index] = arr[left];
            if(arr_y[left] < arr_y[right])
            {
                sorted_y[index] = arr_y[left];
                left++;
            }
            else
            {
                sorted_y[index] = arr_y[right];
                right++;
            }
            
            
        }
        else
        {
            sorted_x[index] = arr[right];
            sorted_y[index] = arr_y[right];
            right++;
        }
        index++;
    }
    if(left > middle)
    {
        for(int i = right ; i <= end ; i++)
        {
            sorted_x[index] = arr[i];
            sorted_y[index] = arr_y[i];
            index++;
        }
        
    }
    else
    {
        for(int i = left ; i <= middle ; i++)
        {
            sorted_x[index] = arr[i];
            sorted_y[index] = arr_y[i];
            index++;
        }
    }
    for(int i = start ; i <= end ; i++)
    {
        arr[i] = sorted_x[i];
        arr_y[i] = sorted_y[i];
    }
}
void partition(int* arr, int start, int end)
{

    int middle = (start + end) / 2;
    if(start < end)
    {
        partition(arr, start, middle);
        partition(arr, middle+1, end);
        merge(arr, start, end);
    }
}
void print_arr(int* arr_x ,int* arr_y, size_t len)
{
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d %d\n",arr_x[i],arr_y[i]);
    }
    printf("\n");

}
int main()
{
    int n;

    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++)
    {
        scanf("%d %d",&arr_x[i],&arr_y[i]);
    }
    partition(arr_x,0,n-1);
    print_arr(arr_x,arr_y,n);
    return 0;
}