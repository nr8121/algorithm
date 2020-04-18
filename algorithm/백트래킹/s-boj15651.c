#include <stdio.h>
#include <stdlib.h>
void print_arr(int[], size_t);
void permutation_(int[], int[], int, int, int, int);

int arr2[8];
void permutation_(int arr[], int pick[], int n, int m, int index, int start)
{
    if (m == index)
    {
        print_arr(arr2,m);
    }
    if(m > index)
    {
        for(int i = start ; i < n ; i ++)
        {
            arr2[index] = arr[i];
            permutation_(arr, pick, n, m, index+1, 0);
        }
    }
    
}

void print_arr(int arr[], size_t len)
{
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[8];
    int pick[8] = {0,};
    int n;
    int m;
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = i+1;
    }
    permutation_(arr, pick, n, m, 0, 0);

    return 0;
}