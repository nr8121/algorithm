#include <stdio.h>
#include <stdlib.h>
int sorted[1000000];

void print_arr(int* arr, size_t len)
{
    for(int i =0 ; i < len ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int* arr, int start, int end)
{
    int middle = (start + end)/2;
    int left = start;
    int right = middle + 1;
    int index = start;
    while(left <= middle && right <= end)
    {
        if(arr[left] <= arr[right])
        {
            sorted[index] = arr[left++]; 
        }
        else
        {
            sorted[index] = arr[right++];
        }
        index++;
    }
    if(left > middle)
    {
        for(int i = right ; i <= end ; i++)
        {
            sorted[index] = arr[i];
            index++;
        }
        
    }
    else
    {
        for(int i = left ; i <= middle ; i++)
        {
            sorted[index] = arr[i];
            index++;
        }
    }
    print_arr(sorted,start-end);
    for(int i = start ; i < end ; i++)
    {
        arr[i] = sorted[i];
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

int main()
{
    int arr[1000000];
    int n;

    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&arr[i]);
    }
	partition(arr,0,n-1);
	print_arr(arr,n);
}