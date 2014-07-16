#include <stdio.h>

int compare(const void *a,const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int i,j,d,n=0,a,b,min,max,num[5010]={0},have[5010]={0};
    scanf("%d %d",&a,&b);
    for(i=0;i<b;i++){
        scanf("%d",&d);
        if(d==1){
            scanf("%d %d",&num[n],&num[n+1]);
            n+=2;
        }
        else{
            scanf("%d",&num[n]);
            n++;
        }
    }
    max=a-n-1;
    min=max;
    qsort(num,n,sizeof(int),compare);
    for(i=1;i<a;i++){
        for(j=0;j<n;j++){
            if(num[j]==i){
                have[i]=1;
                break;
            }
            if(num[j]>i)break;
        }
    }
    for(i=1;i<a;i++){
        if(have[i]==0){
            if(i+1<a && have[i+1]==0){
                min--;
                i++;
            }
        }
    }
    printf("%d %d\n",min,max);
    return 0;
}
