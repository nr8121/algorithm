#include <stdio.h>
#include <stdlib.h>

int arr[20][20];
int count;

int check(int column, int row)
{
    int check = arr[column][row];
    if(check > 0)
    {
        return -1;
    }
    else if(check < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
    
    return 0;
}


int put(int column, int row, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        arr[i][row]++;
        arr[column][i]++;
    }
    arr[column][row]--;
    for(int i = 1; column + i < n; i++)
    {
        if(row + i < n)
        {
            arr[column+i][row+i]++;
        }
        if(row - i >= 0)
        {
            arr[column+i][row-i]++;
        }

    }
    for(int i = 1; column - i >= 0; i++)
    {
        if(row + i < n)
        {
            arr[column-i][row+i]++;
        }
        if(row - i >= 0)
        {
            arr[column-i][row-i]++;
        }
    }


    return 0;
}

int take(int column, int row, int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        arr[i][row]--;
        arr[column][i]--;
    }
    arr[column][row]++;
    for(int i = 1; column + i < n; i++)
    {
        if(row + i < n)
        {
            arr[column+i][row+i]--;
        }
        if(row - i >= 0)
        {
            arr[column+i][row-i]--;
        }

    }
    for(int i = 1; column - i >= 0; i++)
    {
        if(row + i < n)
        {
            arr[column-i][row+i]--;
        }
        if(row - i >= 0)
        {
            arr[column-i][row-i]--;
        }
    }

    return 0;
}

void printf_arr(int n)
{
    for(int j = 0 ; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        { 
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int nqueen(int n, int row)
{
    if(row == n)
    {
        count++;
        return 0; 
    }
        
        
    for(int column = 0 ; column < n ; column++)
    {
        
        //printf("check . %d %d\n", column, row);

        if(check(column,row) == 0)
        {
            //printf("here\n");
            put(column, row, n);

            //printf("before -------------------------\n");
            //printf_arr(n);
            //printf("before -------------------------\n");

            nqueen(n, row+1);

            take(column, row, n);

            // printf("after -------------------------\n");
            // printf_arr(n);
            // printf("after -------------------------\n");
        }
        else
        {
            continue;
        }
        
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);

    nqueen(n,0);

    printf("%d\n",count);
}