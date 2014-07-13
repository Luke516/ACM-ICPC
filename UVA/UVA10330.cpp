#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int cap[220][220],stream[220][220],path[220],n;
bool selected[220];


int bfs(int start,int end)
{
    int i,x,max[220]={0};
    queue<int> q;
    memset(selected,false,sizeof(selected));
    memset(path,0,sizeof(path));
    max[start]=1000000;
    path[start]=start;
    selected[start]=true;
    q.push(start);
    while(!q.empty()){
        x=q.front(); q.pop();
        for(i=1;i<=2*n+1;i++){
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
    int a,b,c,ans,start,end,p,i,t,s,m;
    while(scanf("%d",&n)!=EOF){
        memset(cap,0,sizeof(cap));
        memset(stream,0,sizeof(stream));
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            cap[2*i][2*i+1]=a;
            cap[2*i+1][2*i]=a;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            cap[a*2+1][b*2]+=c;
        }
        scanf("%d %d",&s,&t);
        for(i=0;i<s;i++){
            scanf("%d",&a);
            cap[0][a*2]=100000000;
        }
        for(i=0;i<t;i++){
            scanf("%d",&a);
            cap[a*2+1][1]=100000000;
        }
        ans=find(0,1);
        printf("%d\n",ans);
    }
    return 0;
}
