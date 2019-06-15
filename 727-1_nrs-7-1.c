#include <stdio.h>
#include <stdlib.h>
int sorting_function(int *arr, int arr_len)//Быстрая сортировка
{
	long i = 0, j = arr_len - 1, count=0;
	int tmp,seredina;
	seredina = arr[arr_len>>1];
	do 
	{
		while ( arr[i] < seredina ) 
			{
				i++;
				count++;
			}
		while ( arr[j] > seredina ) 
		{
			j--;
			count++;
		}

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			count++;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) 
		count=count+sorting_function(arr,j+1);
	if (arr_len > i)
		count=count+sorting_function(arr+i,arr_len-i);
	return count;

}
int main(void)
{
	int *arr,shetchik=0,n=0;
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	for (int i=0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	shetchik=sorting_function(arr,n);
	for (int i=0; i < n; i++)
	{
		if (i==(n-1))
			printf("%d",arr[i]);
		else
			printf("%d ",arr[i]);
	}
	printf("\n");




	return 0;
}
