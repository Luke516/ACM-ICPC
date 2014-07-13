#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[310][310]={0};
int x[1000],y[1000];

int main()
{
    int N,n,m,i,j,l,ans,value;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d",&n,&m);
        ans=1000000;
        value=m*m;
        for(i=0;i<n;i++){
            scanf("%d %d",&x[i],&y[i]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<=m;j++){
                for(l=0;l*l+j*j<=value;l++){
                    if(x[i]<=j && y[i]<=l && dp[j-x[i]][l-y[i]]>0){
                        if(dp[j][l]==0)dp[j][l]=dp[j-x[i]][l-y[i]]+1;
                        else if(dp[j][l]>dp[j-x[i]][l-y[i]])dp[j][l]=dp[j-x[i]][l-y[i]]+1;
                    }
                    else if(j==x[i] && l==y[i]){
                        dp[j][l]=1;
                    }
                    if(j*j+l*l==value && dp[j][l]<ans && dp[j][l]>0)ans=dp[j][l];
                }
            }
        }
        if(ans!=1000000)printf("%d\n",ans);
        else printf("not possible\n");
        for(i=0;i<300;i++){
            memset(dp[i],0,sizeof(dp[i]));
        }
    }
    return 0;
}
