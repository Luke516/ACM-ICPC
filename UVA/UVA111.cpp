#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int lis[25]={0},num[25],m[25]={0};

int main()
{
    int i,j,cur,x,order,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&order);
        m[i]=order;
    }
    while(scanf("%d",&x)!=EOF){
        cur=1;
        num[x]=1;
        for(i=2;i<=n;i++){
            scanf("%d",&x);
           num[x]=i;
        }
        lis[cur]=m[num[1]];
        for(i=1;i<=n;i++){
            x=m[num[i]];
            if(x>lis[cur]){
                lis[++cur]=x;
            }
            else{
                for(j=cur;j>0;j--){
                    if(x<lis[j] && x>lis[j-1])lis[j]=x;
                }
            }
        }
        printf("%d\n",cur);
    }
    return 0;
}
