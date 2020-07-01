#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int _strlen(char* a)
{
    int i = 0;
    while(1)
    {
        if(a[i++] == 0)
            break;
    }
    return i-1;
}

int main()
{
    char* a = "!!!!!!!!!!";
    char* b = "!";
    char* c = malloc(sizeof(char)*100);
    memset(c,0,sizeof(char)*100);
    printf("%d \n", _strlen(a));
    for(int i = 0 ; i < _strlen(a); i++)
    {
        printf("%d \n", i);
        c[i] =a[i] ^ b[0];
    }
    printf("%x \n",*c);
    for(int i = 0 ; i < _strlen(a); i++)
    {
        printf("%d \n", c[i]);
    }

    for(int i = 0 ; i < _strlen(a); i++)
    {
        printf("%d \n", i);
        c[i] =c[i] ^ b[0];
    }
    printf("%x \n",*c);
    for(int i = 0 ; i < _strlen(a); i++)
    {
        printf("%d \n", c[i]);
    }


}