#include <stdio.h>
#include <stdlib.h>
int sorting_function(int *arr, int arr_len)
{
	int i, j, k,tmp=0,shetch=0;
	for(k = arr_len / 2; k > 0; k =k/2)
	{
        for(i = k; i < arr_len; i++)
        {
            tmp = arr[i];
            for(j = i; j >= k; j -= k)
            {
            	shetch++;
                if(tmp < arr[j - k])
                {
                	shetch++;
                    arr[j] = arr[j - k];
                }
                else
                    break;
            }
            arr[j] = tmp;
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
