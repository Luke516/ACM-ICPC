#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> 
#include <cstring>

using namespace std;

char c[200][200],s1[20010],s2[20010];
vector<int> p[128]; 
vector<int> v;
    

int main()
{
    int n,cur,i,j,l,step,a,b,x,y,ans,N;
    char side;
   scanf("%d",&N);
   for(i=1;i<=N;i++){
       v.push_back(-1);
       cur=0;
       memset(s1,0,sizeof(s1));
       memset(s2,0,sizeof(s2));
       scanf("%d %d",&a,&b);
       for(j=0;j<a;j++){
           for(l=0;l<b;l++){
               scanf(" %c",&c[j][l]);
           }
       }
       scanf("%d %d %d",&step,&x,&y);
       s1[cur++]=c[--x][--y];
       for(j=0;j<step;j++){
           scanf(" %c",&side);
           if(side=='S'){
               s1[cur++]=c[++x][y];
           }
           else if(side=='N'){
               s1[cur++]=c[--x][y];
           }
           else if(side=='W'){
               s1[cur++]=c[x][--y];
           }
           else if(side=='E'){
               s1[cur++]=c[x][++y];
           }
       }
       cur=0;
       scanf("%d %d %d",&step,&x,&y);
       s2[cur++]=c[--x][--y];
       for(j=0;j<step;j++){
           scanf(" %c",&side);
           if(side=='S'){
               s2[cur++]=c[++x][y];
           }
           else if(side=='N'){
               s2[cur++]=c[--x][y];
           }
           else if(side=='W'){
               s2[cur++]=c[x][--y];
           }
           else if(side=='E'){
               s2[cur++]=c[x][++y];
           }
        }
        for (j = 0; j < strlen(s2); j++){
            p[(int)s2[j]].push_back(j);
        }    

        for (j = 0; j < strlen(s1); j++){
            for ( l = p[s1[j]].size() - 1; l >= 0; l--){
                n = p[s1[j]][l];
                if (n > v.back())
                    v.push_back(n);
                else
                    *lower_bound(v.begin(), v.end(), n) = n;
            }
        }
        
        ans=v.size() - 1;
        printf("Case %d: %d %d\n",i,strlen(s1)-ans,strlen(s2)-ans);
        v.clear();
        for(j=33;j<128;j++){
            p[j].clear();
        }
    }
    return 0;
}
