#include <stdio.h>

int main()
{
    int n,x,i,sum=0,t=0,num[1010]={0};
    scanf("%d %d",&n,&x);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    if(sum<0)sum=-sum;
    while(sum>x){
        sum-=x;
        t++;
    }
    t++;
    printf("%d\n",t);
    return 0;
}
