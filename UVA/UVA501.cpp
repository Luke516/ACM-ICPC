#include<vector>  
#include<cstdio>  
#include<cstring>  
#include<iostream>  

using namespace std;

int main()
{
   vector<int>v;
   vector<int>::iterator it;
   int N,n,m,i,j,ans=0,cur=0,get;
   int data[30010];
   scanf("%d",&N);
   while(N--){
       ans=0;
       cur=0;
       v.clear();
       scanf("%d %d",&n,&m);
       for(j=0;j<n;j++){
           scanf("%d",&data[j]);
       }
       for(j=0;j<m;j++){
           scanf("%d",&get);
           while(v.size()<get){
               it=lower_bound(v.begin(),v.end(),data[cur]);
               v.insert(it,data[cur]);
               cur++;
           }
           printf("%d\n",v[ans]);
           ans++;
       }
       if(N!=0)printf("\n");
   }
   return 0;
}
