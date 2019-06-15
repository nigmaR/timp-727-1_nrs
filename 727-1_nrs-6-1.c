#include <stdio.h>
#include <stdlib.h>
int sorting_function(int *arr, int arr_len)
{
	int tmp=0,i=0,j=0,shetch=0,step=arr_len;
	double factor_umensenia=1.2473309;
	while (step > 1)
	{
		if (step > 1)
			step=step/factor_umensenia;

		for (j=0;j <= arr_len-step-1;j++)
		{
			shetch++;
			if(arr[j] > arr[j+step])
			{
				tmp=arr[j];
				arr[j]=arr[j+step];
				arr[j+step]=tmp;
				shetch++;
			}
		}
	}
	return shetch;
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
	//printf("%d\n", shetchik);




	return 0;
}
