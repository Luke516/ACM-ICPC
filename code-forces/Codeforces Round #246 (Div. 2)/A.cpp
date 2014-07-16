#include <cstdio>
#include <cstdlib>

using namespace std;
int num[2010];

int compare(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}

int main()
{
    int n,k,i,ans,a=0,b=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        num[i]+=k;
    }
    qsort(num,n,sizeof(int),compare);
    for(i=0;i<n;i++){
        if(num[i]>5){
            a=i; break;
        }
        if(i==n-1)a=n;
    }
    ans=a/3;
    printf("%d\n",ans);
    return 0;
}
