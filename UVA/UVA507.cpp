#include <stdio.h>

int main()
{
    int N,n,num,sum,max,j,i,first,last,f,len;
    scanf("%d",&N);
    for(j=1;j<=N;j++){
        scanf("%d",&n);
        sum=0;
        max=0;
        f=1;
        for(i=1;i<n;i++){
            scanf("%d",&num);
            if(sum+num>=0){
                sum+=num;
                if(sum>max){
                    max=sum;
                    last=i;
                    first=f;
                    len=last-first;
                }
                else if(sum==max){
                    if(i-f>len){
                        last=i;
                    first=f;
                    len=last-first;
                    }
                }
            }
            else{
                sum=0;
                f=i+1;
            }
        }
        if(max>0)printf("The nicest part of route %d is between stops %d and %d\n",j,first,last+1);
        else printf("Route %d has no nice parts\n",j);
    }
    return 0;
}
