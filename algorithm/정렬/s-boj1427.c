#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int* arr , size_t len)
{
    for(int i = len-1 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < i ; j++ )
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i],&arr[j]);
            } 
        }
    }
}
void print_arr(int* arr , size_t len)
{
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");

}
int main()
{
    int N;
    int arr[10];
    int temp;
    int i;

    scanf("%d",&N);
    temp = N;
    for(i = 0 ; i < 10 ; i++)
    {
        
        arr[i] = temp % 10 ;
        if((temp = temp / 10 ) == 0)
        {
            i++;
            break;
        }
    }
    sort(arr,i);
    print_arr(arr,i);
    return (0);
}
//더 나은 방법 ---> 카운팅정렬 