#include <cstdio>
#include <cstdlib>

using namespace std;

int num[100010],numm[100010],x[100010];
int ans[100010][2];

int compare(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}

int main()
{
    int n,i,j,cur;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        numm[i]=num[i];
        x[num[i]]=i;
    }
    qsort(numm,n,sizeof(int),compare);
    for(i=0;i<n;i++){
        if(num[i]!=numm[i]){
            ans[cur][0]=i;
            ans[cur][1]=x[numm[i]];
            cur++;
            num[x[numm[i]]]=num[i];
        }
    }
    printf("%d\n",cur);
    for(i=0;i<cur;i++){
        printf("%d %d\n",ans[i][0]+1,ans[i][1]+1);
    }
    return 0;
}
