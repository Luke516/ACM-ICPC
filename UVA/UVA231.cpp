#include <iostream>
#include <cstdio>

using namespace std;

int h[5000000],lis[100000];

int main()
{
    int num=0,i,j,cur=0,c=0;
    lis[0]=9999999;
    while(scanf("%d",&h[num])!=EOF){
        if(h[num]==-1){
            c++;
            for(i=0;i<num;i++){
                if(h[i]<=lis[cur]){
                    cur++;
                    lis[cur]=h[i];
                }
                else{
                    for(j=cur;j>0;j--){
                        if(h[i]>lis[j] && h[i]<=lis[j-1]){
                            lis[j]=h[i];
                        }
                    }
                }
            }
            if(cur==0)break;
            if(c!=1)printf("\n");
            printf("Test #%d:\n  maximum possible interceptions: %d\n",c,cur);
            cur=0;
            num=0;
        }
        else{
            num++;
        }
    }
    return 0;
}
