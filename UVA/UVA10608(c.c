#include <stdio.h>
#include <string.h>

int root[30010],f[30010],scale[30010]={0};

int find(int x)
{
    if(root[x]==x)return x;
    else return find(root[x]);
}

int main()
{
    int N,n,m,a,b,i,ans;
    scanf("%d",&N);
    while(N--){
        ans=0;
        scanf("%d %d",&n,&m);
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
            if(scale[i]>ans)ans=scale[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
