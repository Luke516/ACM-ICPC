#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int scale[5050],root[5050];
map<string,int>trans;

int find(int x)
{
    if(root[x]==x)return x;
    else return root[x]=find(root[x]);
}

int main()
{
    int i,n,m,a,b,max;
    char name[50],s1[50],s2[50];
   while(scanf("%d %d",&n,&m)){
       if(n==0 && m==0)break;
       max=1;
       for(i=0;i<n;i++){
           scanf("%s",name);
           trans[name]=i;
           root[i]=i;
           scale[i]=1;
       }
       for(i=0;i<m;i++){
           scanf("%s %s",s1,s2);
           a=trans[s1];
           b=trans[s2];
           root[a]=find(a);
           root[b]=find(b);
           if(root[a]!=root[b]){
              scale[root[a]]+=scale[root[b]];
               scale[a]=scale[root[a]];
               if(scale[a]>max)max=scale[a];
               root[root[b]]=root[a];
               root[b]=root[a];
           }
       }
       printf("%d\n",max);
   }   
   return 0;
}
