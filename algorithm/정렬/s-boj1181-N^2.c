#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int _sort(char**, size_t);
int _len(char*);
void _strcpy(char*, char*);
void printf_str_arr(char**, size_t);
void swap(char**, char**);
int compare_str(char*, char*, size_t);

int compare_str(char* a, char* b, size_t len)
{   
    int ret; // a > b = 1 ; a = b = 0 ; a < b = -1
    for(int i = 0 ; i < len ; i++)
    {
        if(a[i] > b[i])
        {
            return 1;
        }
        else if(a[i] < b[i])
        {
            return -1;
        }
    }
    return 0;
}
void swap(char** a, char** b)
{
    char* temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int _len(char* str)
{
    int ret = 0;

    if(str == 0)
        return ret;
    while(1)
    {
        if(*str !='\0')
        {
            str++;
            ret++;
        }
        else
        {
            break;
        }
        
    }
    return ret;
}
int _sort(char** str_arr, size_t len)
{
    for(int i = 0 ; i < len-1 ; i++)
    {
        for(int j = i+1 ; j < len; j++)
        {
            int i_len = _len(str_arr[i]);
            int j_len = _len(str_arr[j]);

            if(i_len > j_len)
            {
                swap(&str_arr[i], &str_arr[j]);
                continue;
            }
            if(i_len == j_len)
            {
                if(compare_str(str_arr[i], str_arr[j], _len(str_arr[i])) == 1)
                {
                    swap(&str_arr[i], &str_arr[j]);
                }
                continue;
            }
        }
    }
}

//a to b
void _strcpy(char* origin, char* copy)
{
    int l = _len(origin);
    
    for(int i = 0 ; i < l ; i ++)
    {
        *(copy+i) = *(origin+i);
    }
    *(copy+l) = 0;
}
void print_str_arr(char** str, size_t len)
{
    for(int i = 0 ; i < len ; i ++)
    {
        printf("%d : ",i);
        printf("%s ",str[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    char* str[20000];
    char temp[50];
    
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",&temp);
        int l = _len(temp);
        str[i] = malloc(sizeof(char)*(l+1));
        _strcpy(temp,str[i]);
    }
    _sort(str,n);
    print_str_arr(str,n);
    return 0;
}