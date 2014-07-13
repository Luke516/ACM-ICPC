#include <stdio.h>

int compare(const void*a,const void *b)
{
    return (*(int *)a-*(int *)b);
}

int main()
{
    int a[501]={0},i,j,n,N,ans=0,mid;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",&a[j]);
        }
        qsort(a,n,sizeof(int),compare);
        mid=a[n/2];
        for(j=0;j<n;j++){
            if(a[j]>mid)ans+=a[j]-mid;
            else ans+=mid-a[j];
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
