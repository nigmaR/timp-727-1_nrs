#include <stdio.h>

int main(void)
{
  int n,summ=0,x;
  scanf("%d",&n);
  for (int i=1;i<=n;i++)
  {
    scanf("%d",&x);
    summ=summ+x-i;
  }
  printf ("%d\n",summ);
  return 0;
}
