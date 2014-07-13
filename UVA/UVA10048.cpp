#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct data{
    int target;
    int dis;
};

vector<data> v[200];
queue<int> q;
int graph[1000];

int find(int start,int end)
{
    int i,x,dis,cur;
    graph[start]=0;
    q.push(start);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        for(i=0;i<v[cur].size();i++){
            x=v[cur][i].target;
            dis=v[cur][i].dis;
            if(dis<graph[x] && graph[cur]<graph[x]){
                graph[x]=dis>graph[cur]?dis:graph[cur];
                q.push(x);
            }
        }
    }
    return graph[end];
}

int main()
{
    data p;
    int n,m,num,c,i,a,b,dis,ans,j;
    while(scanf("%d %d %d",&n,&m,&num)!=EOF){
        if(n==0 && m==0 && num==0)break;
        if(c>0)printf("\n");
        c++;
        for(j=0;j<=n;j++){
            graph[j]=1000000;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&dis);
            p.target=b; p.dis=dis;
            v[a].push_back(p);
            p.target=a;
            v[b].push_back(p);
        }
        printf("Case #%d\n",c);
        for(i=0;i<num;i++){
            scanf("%d %d",&a,&b);
            
            for(j=0;j<=n;j++){
               graph[j]=1000000;
            }
            
            ans=find(a,b);
            if(ans!=1000000)printf("%d\n",ans);
            else printf("no path\n");
            
        }
        for(i=0;i<=n;i++){
            v[i].clear();
        }
    }
   return 0;
}
