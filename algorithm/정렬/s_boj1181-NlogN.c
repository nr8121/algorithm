#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int _len(char*);
void _strcpy(char*, char*);
void print_str_arr(char**, size_t);
void merge(char**, int, int);
void partition(char** ,int ,int);
int _compare(char*, char*);

char* sorted[20000];

int _compare(char* a, char* b)
{
    // a > b = 1 ; a = b = 0 ; a < b = -1
    int a_len = _len(a);
    int b_len = _len(b);
    if (a_len > b_len)
    {
        return 1;

    }
    if (a_len == b_len)
    {
        for(int i = 0 ; i < a_len ; i++)
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
    return -1; 
}
void _copy(char** a, char** b, int pos)
{
    a[pos] = b[pos];
}
void merge(char** arr, int start, int end)
{
    int middle = (start + end)/2;
    int left = start;
    int right = middle + 1;
    int index = start;
    while(left <= middle && right <= end)
    {
        int comp = _compare(arr[right], arr[left]);
        if(comp > 0)
        {
            sorted[index] = arr[left++];
        }
        else
        {
            sorted[index] = arr[right++];
        }
        index++;
    }
    if(left > middle)
    {
        for(int i = right ; i <= end ; i++)
        {
            sorted[index] = arr[i];
            index++;
        }
        
    }
    else
    {
        for(int i = left ; i <= middle ; i++)
        {
            sorted[index] = arr[i];
            index++;
        }
    }
    for(int i = start ; i <= end ; i++)
    {   
        _copy(arr,sorted,i);
    }
}
void partition(char** arr, int start, int end)
{

    int middle = (start + end) / 2;
    if(start < end)
    {
        partition(arr, start, middle);
        partition(arr, middle+1, end);
        merge(arr, start, end);
    }
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
        if(i ==0)
        {
            printf("%s\n",str[i]);
        }
        else
        {
            if(_compare(str[i-1],str[i]) == 0)
                continue;
            printf("%s\n",str[i]);
        }
        // printf("%s\n",str[i]);
        
    }
    printf("\n");
}

int main()
{
    int n;
    char* str[20000];
    char temp[51];
    
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",&temp);
        int l = _len(temp);
        str[i] = malloc(sizeof(char)*(l+1));
        _strcpy(temp,str[i]);
    }
    partition(str,0,n-1);
    print_str_arr(str,n);
    return 0;
}