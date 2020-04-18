#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* arcv)
{
    int n;
    int arr[10001] = {0,};
    int temp;
    scanf("%d",&n);
    //n < 10,000,000 , 최대값 10000 이하 
    for(int i = 0 ; i < n ; i++)
    {
       scanf("%d",&temp);
       arr[temp]++; 
    }
    for(int i = 0 ; i < 10001; i++)
    {
        for(int j = 0; j < arr[i]; j++) 
        {
            printf("%d\n",i);
        }
    }


}