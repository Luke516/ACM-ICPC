#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string,int> trans;
int low[110],dfn[110],t;
vector<int> v[110],ans;
char s[110][50];
bool used[110];

int compare(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}

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
        ans.push_back(cur);
    }
    return;
}

int main()
{
    int n,i,j,cur,m,a,b,c=1;
    char s1[50],s2[50];
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        memset(used,false,sizeof(used));
        t=1;
        for(i=0;i<n;i++){
            scanf("%s",s[i]);
        }
        qsort(s,n,sizeof(char[50]),compare);
        for(i=0;i<n;i++){
            trans[s[i]]=i;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%s %s",s1,s2);
            a=trans[s1]; b=trans[s2];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=0;i<n;i++){
            if(!used[i])dfs(-1,i);
        }
        sort(ans.begin(),ans.end());
        if(c!=1)printf("\n");
        printf("City map #%d: %d camera(s) found\n",c++,ans.size());
        for(i=0;i<ans.size();i++){
            printf("%s\n",s[ans[i]]);
        }
        for(i=0;i<n;i++){
            v[i].clear();
        }
        ans.clear();
        trans.clear();
    }
    return 0;
}
