#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;

int low[1010],dfn[1010],ans,t;
vector<int> v[1010];
bool used[1010];

void dfs(int pa,int cur){
    int next,i,paa=0;
    bool flag=false;
    low[cur]=t;
    dfn[cur]=t;
    t++;
    for(i=0;i<v[cur].size();i++){
        next=v[cur][i];
        if(dfn[next]==0){
            dfs(cur,v[cur][i]);
            if(low[cur]>low[next])low[cur]=low[next];
            printf("%d %d\n",cur,next);
            if(low[next]>dfn[cur]){
                printf("%d %d\n",next,cur);
            }
        }
        else if (pa != next){
            if(dfn[next]<dfn[cur]){
                printf("%d %d\n",cur,next);
            }
            if(dfn[next]<low[cur]){
                low[cur]=dfn[next];
            }
        }
    }
    return;
}

int main(){
    int x,y,n,i,a,b,m,c=0;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0 && m==0)break;
        c++;
        printf("%d\n\n",c);
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(used, false, sizeof(used));
        ans=0;
        t=1;
		for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
		}
        dfs(-1,1);
        printf("#\n");
        for(i=0;i<=n;i++){
            v[i].clear();
        }
	}
    return 0;
}