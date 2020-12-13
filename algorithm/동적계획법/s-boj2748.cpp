#include <iostream>
#include <stdio.h>
#include <stdlib.h>

long int fibo(long int n)
{
    if(n == 0 )
    {
        return 0;
    }
    if(n == 1 )
    {
        return 1;
    }
    else
    {
        long int result = 0;
        long int last = 0;
        long int first = 1;
        for(long int i = 2 ; i <= n; i++)
        {
            result =  first + last;
            last = first;
            first = result;
        }
        return result;
    }
    
}


int main()
{
    long int n;
    scanf("%ld",&n);
    if(n <= 90 && 0<= n)
    {
        printf("%ld\n",fibo(n));
    }
}