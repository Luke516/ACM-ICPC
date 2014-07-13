#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int cap[110][110],stream[110][110],path[110],n;
bool selected[110];

int bfs(int start,int end)
{
    int i,x,max[110]={0};
    queue<int> q;
    memset(selected,false,sizeof(selected));
    memset(path,0,sizeof(path));
    max[start]=1000000;
    path[start]=start;
    selected[start]=true;
    q.push(start);
    while(!q.empty()){
        x=q.front(); q.pop();
        for(i=1;i<=n;i++){
            if(!selected[i] && stream[x][i]<cap[x][i]){
                selected[i]=true;
                path[i]=x;
                if(max[x]>cap[x][i]-stream[x][i])max[i]=cap[x][i]-stream[x][i];
                else max[i]=max[x];
                q.push(i);
                if(i==end){
                    return max[i];
                }
            }
        }
    }
    return 0;
}

int find(int start,int end)
{
    int flow,ans=0,i,j;
    for(;;){
        flow=bfs(start,end);
        if(flow==0)break;
        ans+=flow;
        i=end;
        while(i!=path[i]){
            j=path[i];
            stream[j][i]+=flow;
            stream[i][j]=-stream[j][i];
            i=j;
        }
    }
    return ans; 
}

int main()
{
    int a,b,c,ans,start,end,p,i,t=1;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        scanf("%d %d %d",&start,&end,&p);
        memset(cap,0,sizeof(cap));
        memset(stream,0,sizeof(stream));
        for(i=0;i<p;i++){
            scanf("%d %d %d",&a,&b,&c);
            cap[a][b]+=c;
            cap[b][a]+=c;
        }
        ans=find(start,end);
        printf("Network %d\nThe bandwidth is %d.\n\n",t,ans);
        t++;
    }
    return 0;
}
