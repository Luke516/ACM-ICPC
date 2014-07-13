#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int,int>m;

int ipow(int x)
{
    int i=1;
    while(x--){
        i=i*2;
    }
    return i;
}

int main()
{
    int num[1000],order[10];
    int i,j,n,k,x,z,cur,t=1;
    char g;
    while(scanf("%d",&n)){
        if(n==0)break;
        printf("S-Tree #%d:\n",t++);
        for(i=0;i<n;i++){
            scanf(" %c",&g);
            scanf("%d",&z);
            num[z]=i;
        }
        x=ipow(n);
        for(i=0;i<x;i++){
            scanf("%1d",&z);
            m[x+i]=z;
        }
        scanf("%d",&k);
        for(i=0;i<k;i++){
            cur=1;
            for(j=1;j<=n;j++){
                scanf("%1d",&order[num[j]]);
            }
            for(j=0;j<n;j++){
                if(order[j]==0){
                    cur=cur*2;
                }
                else if(order[j]==1){
                    cur=cur*2+1;
                }
                else printf("QAQ\n");
            }
            printf("%d",m[cur]);
        }
        printf("\n\n");
    }
    return 0;
}
