#include <stdio.h>

int compare(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
  int num[10001],num2[10001],mid,i=0,j;
  while(scanf("%d",&num[i++])!=EOF){
      qsort(num,i,sizeof(int),compare);
      if(i%2!=0)printf("%d\n",num[i/2]);
      else printf("%d\n",(num[i/2]+num[i/2-1])/2);
  }
  return 0;
}
