#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> v[110];
queue<int> q;
int graph[1000];

int main()
{
    int n,i,max,a,b,cur,start,c=0,maxp;
   while(scanf("%d",&n)!=EOF){
       if(n==0)break;
       c++;
       memset(graph,0,sizeof(graph));
       scanf("%d",&start);
       max=0;
       maxp=start;
       while(scanf("%d %d",&a,&b)){
           if(a==0 && b==0)break;
           v[a].push_back(b);
       }

       q.push(start);
       while(!q.empty()){
           cur=q.front();
           q.pop();
           for(i=0;i<v[cur].size();i++){
               if(graph[cur]+1>graph[v[cur][i]]){
                   graph[v[cur][i]]=graph[cur]+1;
                   q.push(v[cur][i]);
                   if(graph[v[cur][i]]>max){
                       max=graph[v[cur][i]];
                       maxp=v[cur][i];
                   }
                   if(graph[v[cur][i]]==max && v[cur][i]<maxp){
                       maxp=v[cur][i];
                   }
               }
           }
       }
       printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",c,start,max,maxp);
       for(i=0;i<n;i++){
            v[i].clear();
        }
   }
   return 0;
}
