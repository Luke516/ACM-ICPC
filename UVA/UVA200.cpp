#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

char c[100000][25],used[50];
int num[50]={0},ans[50];
map<char,int> m;
vector<int> v[50];
queue<int> q;

bool exist(char key)
{
    return ( m.find(key) != m.end() );
}

void find(int front,int last,int x)
{
    int cur=front,i,a,b;
    if(last-front<=1)return;
    
    for(i=front+1;i<=last;i++){
        if(strlen(c[i])<=x || strlen(c[i-1])<=x || i==0){}
        else if(c[i][x]!=c[i-1][x]){
            a=m[c[i-1][x]]; b=m[c[i][x]];
            v[a].push_back(b);
            num[b]++;
            find(cur,i-1,x+1);
            cur=i;
        }
        if(i==last)find(cur,i,x+1);
    }
    return;
}

int main()
{
   int i,j,count=0,n=0,x;
   while(scanf("%s",c[n])!=EOF){
       if(c[n][0]=='#')break;
       for(i=0;i<strlen(c[n]);i++){
           if(!exist(c[n][i])){
               m[c[n][i]]=count;
               used[count]=c[n][i];
               count++;
           }
       }
       n++;
   } 
   find(0,n-1,0);
   
   for(i=0;i<count;i++){
       if(num[i]==0){
           q.push(i);
       }
   }
   count=0;
   
   while(!q.empty()){
       i=q.front();
       q.pop();
       ans[count++]=i;
        for(j=0;j<v[i].size();j++){
            x=v[i][j];
            num[x]--;
            if(num[x]==0){
                q.push(x);
            }
        }
   }
   
   for(i=0;i<count;i++){
       printf("%c",used[ans[i]]);
   }
   printf("\n");
   
   return 0;
}
