#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>

using namespace std;

map<string,int> trans;
char str[110][50];
int low[110],dfn[110],t,countt;
vector<int> v[110],ans[110];
stack<int> s;
bool used[110];

bool exist(string key){
    return trans.find(key) != trans.end();
}

void dfs(int cur){
    int next,children=0,i,x;
    low[cur]=t;
    dfn[cur]=t;
    t++;
    s.push(cur);
    for(i=0;i<v[cur].size();i++){
        next=v[cur][i];
        if(dfn[next]==0){
            children++;
            dfs(v[cur][i]);
            if(low[cur]>low[next])low[cur]=low[next];
        }
        else if(!used[next]){
            if(dfn[next]<low[cur]){
                low[cur]=dfn[next];
            }
        }
    }
    if(low[cur]==dfn[cur]){
        for(;;){
            x=s.top(); s.pop();
            used[x]=true;
            ans[countt].push_back(x);
            if(x==cur){
                countt++;
                break;
            }
        }
    }
    return;
}

int main()
{
    int n,i,j,cur,m,a,b,c=1,num;
    char s1[50],s2[50];
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0 && m==0)break;
        countt=0;
        t=1;
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        memset(used,false,sizeof(used));
        if(c!=1)printf("\n");
        printf("Calling circles for data set %d:\n",c++);
        for(i=0;i<m;i++){
            scanf("%s %s",s1,s2);
            if(!exist(s1)){
                trans[s1]=countt;
                sscanf(s1,"%s",str[countt]);
                countt++;
            }
            if(!exist(s2)){
                trans[s2]=countt;
                sscanf(s2,"%s",str[countt]);
                countt++;
            }
            a=trans[s1]; b=trans[s2];
            v[a].push_back(b);
        }
        num=countt;
        countt=0;
        for(i=0;i<num;i++){
            if(!used[i]){
                dfs(i);
            }
        }
        for(i=0;i<countt;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        sort(ans,ans+countt);
        for(i=0;i<countt;i++){
            for(j=0;j<ans[i].size();j++){
                if(j!=0)printf(", ");
                printf("%s",str[ans[i][j]]);
            }
            printf("\n");
        }
        trans.clear();
        for(i=0;i<n;i++){
            v[i].clear();
            ans[i].clear();
        }
    }
    return 0;
}
