#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <string>
#include <cstring>

using namespace std;

char m[1010][100];
int cap[1010][1010],stream[1010][1010],path[1010],cur;
bool selected[1010];

int bfs(int start,int end)
{
    int i,x,max[1010]={0};
    queue<int> q;
    memset(selected,false,sizeof(selected));
    memset(path,0,sizeof(path));
    max[start]=1000000;
    path[start]=start;
    selected[start]=true;
    q.push(start);
    while(!q.empty()){
        x=q.front(); q.pop();
        for(i=1;i<=cur;i++){
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
    int N,x,i,j,c,n,ans,curr,l;
    scanf("%d",&N);
    for(c=1;c<=N;c++){
        scanf("%d",&n);
        cur=30;
        memset(cap,0,sizeof(cap));
        memset(stream,0,sizeof(stream));
        for(i=0;i<n;i++){
            scanf("%d",&x);
            curr=cur++;
            cap[0][curr]=1;
            for(j=0;j<x;j++){
                scanf("%s",m[cur]);

                for(l=1;l<strlen(m[cur]);l++){
                	if(m[cur][l]>='A' && m[cur][l]<='Z'){
                		m[cur][l]=m[cur][l]-'A'+'a';
                	}
                }
                if('a'<=m[cur][0] && m[cur][0]<='z')m[cur][0]='A'+m[cur][0]-'a';

                cap[curr][cur]=1;
                cap[cur][(int)(m[cur][0]-'A'+1)]=1;
                cur++;
            }
        }
        for(i=1;i<30;i++){
        	cap[i][cur]=1;
        }
        ans=find(0,cur);
        printf("Case #%d:\n",c);
        for(i=1;i<30;i++){
        	for(j=31;j<cur;j++){
        		if(stream[j][i]>0){
        			printf("%s\n",m[j]);
        			break;
        		}
        	}
        }

    }
    return 0;
}
