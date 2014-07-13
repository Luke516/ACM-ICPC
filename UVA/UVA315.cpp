#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;

int low[110],dfn[110],ans,t;
vector<int> v[110];
bool used[110];

void dfs(int pa,int cur){
    int next,children=0,i;
    bool flag=false;
    low[cur]=t;
    dfn[cur]=t;
    used[cur]=true;
    t++;
    for(i=0;i<v[cur].size();i++){
        next=v[cur][i];
        if(dfn[next]==0){
            children++;
            dfs(cur,v[cur][i]);
            if(low[cur]>low[next])low[cur]=low[next];
            if(low[next]>=dfn[cur]){
                flag=true;
            }
        }
        else if (pa != next){
            if(dfn[next]<low[cur])low[cur]=dfn[next];
        }
    }
    if(flag && (children>1 || pa!=-1)){
        ans++;
    }
    return;
}

int main(){
    int x,y,n,i;
	char c;
	while(scanf("%d", &n)!=EOF){
        if(n==0)break;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(used, false, sizeof(used));
        ans=0;
        t=1;
		while(scanf("%d", &x) == 1) {
            if(x==0)break;
			while(scanf("%d%c", &y, &c) == 2) {
				v[x].push_back(y);
                v[y].push_back(x);
				if(c == '\n')	break;
			}
		}
		dfs(-1,1);
		printf("%d\n",ans);
        for(i=0;i<=n;i++){
            v[i].clear();
        }
	}
    return 0;
}