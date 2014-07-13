#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int cap[110][110],stream[110][110],path[110],n,m;
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
        for(i=1;i<=n+m;i++){
            if(!selected[i] && stream[x][i]<cap[x][i]){
                if(max[x]>cap[x][i]-stream[x][i])max[i]=cap[x][i]-stream[x][i];
                else max[i]=max[x];
                selected[i]=true;
                path[i]=x;
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
    int N,x,i,j,c,no,ans,num[30];
    scanf("%d",&N);
    for(c=1;c<=N;c++){
        scanf("%d %d",&n,&m);
        memset(cap,0,sizeof(cap));
        memset(stream,0,sizeof(stream));
        for(i=0;i<n;i++){
            scanf("%d",&x);
            memset(num,0,sizeof(num));
            for(j=0;j<x;j++){
                scanf("%d",&no);
                num[no]++;
            }
            for(j=1;j<=m;j++){
                if(i==0){
                    cap[0][j+n-1]=num[j];
                    cap[j+n-1][n+m]=1;
                }
                else if(num[j]>0){
                    cap[i][j+n-1]=num[j]-1;
                }
                else{
                    cap[j+n-1][i]=1;
                }
            }
        }
        ans=find(0,n+m);
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
