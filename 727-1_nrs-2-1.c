








#include <stdio.h>
#include <math.h>

int main(void)
{
  int n,razn=0,x;
  scanf("%d",&n);
  while (n>=1)
  {
  	scanf("%d",&x);
  	razn=razn-x;
  	n--;
  }
  printf ("%d\n",razn);
  return 0;
}
