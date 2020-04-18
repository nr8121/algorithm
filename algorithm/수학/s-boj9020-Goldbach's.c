#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int number)
{
    if (number == 1)
        return 0;
    for(int i = 2 ; i <= sqrt(number) ; i++ )
    {
        if((number % i) == 0)
            return 0;
    }
    return 1;
}
void gold_(int n)
{
    int a;
    int b;
    int middle = n / 2;
    int sub = n;
    for(int i = middle ; i >= 2 ; i--)
    {   
        if(middle - i > sub)
            break;
        if(isPrime(i))
        {
            for(int j = middle ; j < n ; j++)
            {
                if(j-i > sub)
                    break;
                if(isPrime(j))
                {
                    if(i + j == n)
                    {
                        a = i;
                        b = j;
                        sub = j - i;
                    }
                        
                }
            }
        }
    }
    printf("%d %d\n",a,b);
    

}
int main()
{
    int n;
    int temp[10000];

    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&temp[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        gold_(temp[i]);
    }
    return 0;
}