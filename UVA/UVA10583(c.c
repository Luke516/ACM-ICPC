#include <stdio.h>
#include <string.h>

int root[50010],f[50010],scale[50010]={0};

int find(int x)
{
    if(root[x]==x)return x;
    else return find(root[x]);
}

int main()
{
    int N,n,m,a,b,i,ans,t=1;
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0)break;
        ans=0;
        for(i=1;i<=n;i++){
            f[i]=i;
            root[i]=i;
            scale[i]=0;
        }
        for(i=0;i<m;i++){
            scanf("%d %d ",&a,&b);
            root[a]=find(a);
            root[b]=find(b);
            if(root[a]!=root[b]){
                root[root[b]]=root[a];
                root[b]=root[a];
            }
        }
        for(i=1;i<=n;i++){
            root[i]=find(i);
            scale[root[i]]++;
        }
        for(i=1;i<=n;i++){
            if(scale[i]>0)ans++;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
