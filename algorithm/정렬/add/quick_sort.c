#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b);
void partition(int* a, int begin, int end);
int quick_sort(int *a, int begin, int end);
void print_array(int* arr,size_t len);


void swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
int quick_sort(int* a, int begin, int end)
{
	int pivot = a[end];
	int index = begin;
	pivot = end;
	for(int i = begin ; i <= end; i++)
	{
		if(a[i] <= a[pivot])
		{
			swap(&a[index++], &a[i]);
		}
	}
	return index - 1;

}
void partition(int *a, int begin, int end)
{
	if (begin < end)
	{
		int p;
		p = quick_sort(a, begin, end);
		partition(a, begin, p - 1);
		partition(a, p + 1, end);
	}
}

void print_array(int ar[], size_t len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", ar[i]);
	}
}

int main(int argc,char* argv[])
{

	int n;
	int a[1000000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	partition(a, 0, n - 1);
	print_array(a, n);
}