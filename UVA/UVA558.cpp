#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct wormhole{
    int a;
    int b;
    int y;
};

wormhole w[2010];
int g[1010];

int main()
{
    int N,n,m,j,i,num;
    bool flag;
    scanf("%d",&N);
    while(N--){
        memset(g,0,sizeof(g));
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&w[i].a,&w[i].b,&w[i].y);
        }
        num=i;
        for(j=0;;j++){
            flag=false;
            for(i=0;i<num;i++){
                if(g[w[i].a]+w[i].y<g[w[i].b]){
                    g[w[i].b]=g[w[i].a]+w[i].y;
                    flag=true;
                }
            }
            if(j>num)break;
        }
        if(flag)printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
