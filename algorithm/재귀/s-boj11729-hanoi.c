#include <stdio.h>
#include <stdlib.h>
void move(int a, int b) // print a to b
{
    printf("%d %d\n", a, b);
}


int hanoi(int n, int start, int via, int end)
{
    if(n ==1)
    {
        move(start, end);
        return 0;
    }
    else
    {
        hanoi(n-1, start, end, via);
        move(start, end);
        hanoi(n-1, via, start, end);
    }
    
   
    return 0;
}
int count_hanoi(int a)
{
    int n1 = 1;
    for(int i = 1 ; i < a ; i++)
    {
        n1 = 2*n1 + 1;
    }
    return n1;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",count_hanoi(n));
    hanoi(n, 1, 2, 3);
    return 0;
}