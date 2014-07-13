#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[100010]={0};

int main()
{
    int n,m,t,i,temp,beer;
   while(scanf("%d %d %d",&n,&m,&t)!=EOF){
       memset(dp,0,sizeof(dp));
       
       if(n>m){
           temp=n ;n=m; m=temp;
       }
       for(i=1;i<=t;i++){
           if(i>=n){
               if(i==n || dp[i-n]>0)dp[i]=dp[i-n]+1;
           }
       }
       for(i=1;i<=t;i++){
           if(i>=m && dp[i]<=dp[i-m]){
               if(i==m || dp[i-m]>0)dp[i]=dp[i-m]+1;
           }
       }
       if(dp[t]>0)printf("%d\n",dp[t]);
       else{
           beer=0;
           for(i=t;i>=0;i--){
               if(dp[i]>0 || i==0){
                   printf("%d ",dp[i]);
                   break;
               }
               else beer++;
           }
           printf("%d\n",beer);
       }
   }
   return 0;
}
