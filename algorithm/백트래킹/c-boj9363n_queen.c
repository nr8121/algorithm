#include <stdio.h>
#include <stdlib.h>

int Put(int, int, int, int);
int delete(int, int, int);
int refresh(int, int, int);
int abs(int);

int temp[15][15] ={0,};
int count = 0;

int start(int n, int x, int y)
{
    delete(n,x,y);
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            printf("%d ",temp[j][i]);
        }
        printf("\n");
    }
}
int Put(int n, int x, int y, int depth)
{
    if(depth == n)
    {
        printf("end\n");
        count ++;
    }
    for(int i = y ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(temp[j][i] == 0)
            {
                delete(n, i, j);
                Put(n, j, i, depth+1);
                printf("%d %d\n",j,i);
            }
        }
    }
    
    
    
}

int delete(int n, int x, int y)
{
    //x 
    for(int i = 0 ; i < n ; i++)
    {
        temp[x][i]++; 
    }
    //y
    for(int i = 0 ; i < n ; i++)
    {
        temp[i][y]++;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(i > x) 
            temp[i][y+abs(x-i)]++;
        if(i < x)
            temp[i][y-abs(x-i)]++;
    }
}


int abs(int n)
{
    if(n < 0)
    {
        return -n;
    }
    return n;
}


int refresh(int n, int x, int y)
{
    //x 
    for(int i = 0 ; i < n ; i++)
    {
        temp[x][i]--; 
    }
    //y
    for(int i = 0 ; i < n ; i++)
    {
        temp[i][y]--;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(y+abs(x-i) < n )
            temp[i][y+abs(x-i)]--;
        if(y-abs(x-i) > 0)
            temp[i][y-abs(x-i)]--;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    start(5, 3, 2);
    printf("%d\n",count);
}