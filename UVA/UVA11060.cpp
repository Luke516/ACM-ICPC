#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm> 

using namespace std;

vector<int> edge[1000];
int num[1000],ans[1000];

int main ()
{
    priority_queue<int> q;
    map<string,int>pp;
    char s[110][60],s1[60],s2[60];
    bool flag=1;
    int i,j,n,m,a,b,x,cur=0,count=0;
    while(scanf("%d",&n)!=EOF){
        count++;
        for (i = 1; i <= n; ++i) edge[i].clear();  
        memset(num, 0, sizeof(num)); 
        
        for(i=n;i>0;i--){
            scanf("%s",s[i]);
            pp[s[i]]=i;
        }
        scanf("%d",&m);
        while(m--){
            scanf("%s %s",&s1,&s2);
            edge[pp[s1]].push_back(pp[s2]);
            num[pp[s2]]++;
        }
        for(i=1;i<=n;i++){
            if(num[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            x=q.top();
            q.pop();
            ans[cur++]=x;
            for(j=0;j<edge[x].size();j++){
                num[edge[x][j]]--;
                if(num[edge[x][j]]==0){
                    q.push(edge[x][j]);
                }
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",count);
        for(i=0;i<cur;i++){
            x=ans[i];
            printf("%s",s[x]);
            if(i<cur-1)printf(" ");
        }
        printf(".\n\n");
        cur=0;
    }
    return 0;
}