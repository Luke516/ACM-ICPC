#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;

int low[1010],dfn[1010],ans,t;
vector<int> v[1010],bridge;
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
            //printf("%d %d\n",cur,next);
            if(low[next]>dfn[cur]){
                ans++;
                if(next>cur){
                    bridge.push_back(next+cur*1000);
                }
                else bridge.push_back(cur+next*1000);
                //printf("%d %d\n",next,cur);
            }
        }
        else if (pa != next){
            if(dfn[next]<dfn[cur]){
                //printf("%d %d\n",cur,next);
            }
            if(dfn[next]<low[cur]){
                low[cur]=dfn[next];
            }
        }
    }
    return;
}

int main(){
    int x,y,n,i,j,a,b,m,num;
    while(scanf("%d",&n)!=EOF){
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(used, false, sizeof(used));
        ans=0;
        t=1;
        for(i=0;i<n;i++){
            scanf("%d (%d)",&a,&num);
            for(j=0;j<num;j++){
                scanf("%d",&b);
                v[a].push_back(b);
                v[b].push_back(a);
            }
            
        }
        for(i=0;i<n;i++){
            if(!used[i])dfs(-1,i);
        }
        sort(bridge.begin(),bridge.end());
        printf("%d critical links\n",ans);
        for(i=0;i<bridge.size();i++){
            a=bridge[i];
            printf("%d - %d\n",a/1000,a%1000);
        }
        printf("\n");
        for(i=0;i<=n;i++){
            v[i].clear();
        }
        bridge.clear();
	}
    return 0;
}