#include <stdio.h>
#include <stdlib.h>
int sorting_function(int *arr, int arr_len)//Пирамидальная сортировка
{
	long i, count=0,new_element,leave,p;
	int tmp;
	for (i = arr_len/2-1; i >= 0; i--)
	{
		p=i;
		new_element = arr[p];
		while(p <= (arr_len-1)/2)
		{
			leave= 2*p;
			if (leave < arr_len-1 && arr[leave] < arr[leave+1] )
			{
				leave++;
				count++;
			}
			if (new_element >= arr[leave])
				break;
			arr[p] = arr[leave];
			p = leave;
			count++;
		}
		arr[p]= new_element;
	}
	for (i = arr_len-1; i > 0; i--)
	{
		tmp=arr[i];
		arr[i]=arr[0];
		arr[0]=tmp;
		count++;
		p=0;
		new_element = arr[p];
		while(p <= (i-1)/2)
		{
			leave= 2*p;
			if (leave < i-1 && arr[leave] < arr[leave+1] )
			{
				leave++;
				count++;
			}
			if (new_element >= arr[leave])
				break;
			arr[p] = arr[leave];
			p = leave;
			count++;
		}
		arr[p]= new_element;

	}
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
