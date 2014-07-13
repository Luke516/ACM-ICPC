#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int coin[5]={1,5,10,25,50};
int bag[7500];

int main()
{
    int num,ans,i,j;
    for(i=0;i<7500;i++){
        bag[i]=1;
    }
    for(i=1;i<5;i++){
        for(j=1;j<7500;j++){
            if(j>=coin[i]){
                bag[j]+=bag[j-coin[i]];
            }
        }
    }
    
    while(scanf("%d",&num)!=EOF){
        ans=bag[num];
        printf("%d\n",ans);
    }
   
   return 0;
}
