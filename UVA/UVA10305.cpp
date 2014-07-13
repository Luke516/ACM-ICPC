#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

vector<int> edge[1000];
int num[1000],ans[1000];

int main ()
{
    queue<int> q;
    bool flag=1;
    int i,j,n,m,a,b,x,cur=0;
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0)break;
        
        for (i = 1; i <= n; ++i) edge[i].clear();  
        memset(num, 0, sizeof(num)); 
        
        while(m--){
            scanf("%d %d",&a,&b);
            edge[a].push_back(b);
            num[b]++;
        }
        for(i=1;i<=n;i++){
            if(num[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            x=q.front();
            ans[cur++]=x;
            for(j=0;j<edge[x].size();j++){
                num[edge[x][j]]--;
                if(num[edge[x][j]]==0){
                    q.push(edge[x][j]);
                }
            }
            q.pop();
        }
        for(i=1;i<=n;i++){
            if(num[i]!=0){
                printf("IMPOSSIBLE\n");
                flag=0;
                break;
            }
        }
        for(i=0;i<cur;i++){
            printf("%d",ans[i]);
            if(i<cur-1)printf(" ");
        }
        printf("\n");

        cur=0;
    }
    return 0;
}