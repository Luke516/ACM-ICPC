#include <iostream>
#include <cstdio>

using namespace std;

int a[50],b[50],select=0,n,t=0;

void find(int x)
{
    int i;
    if((select+n-x)<6)return;
    b[x]=1;
    select++;
    if(select==6){
        for(i=0;i<=x;i++){
            if(b[i]==1){
                printf("%d",a[i]);
                if(i!=x)printf(" ");
            }
            
        }
        printf("\n");
    }
    else find(x+1);
    
    b[x]=0;
    select--;
    find(x+1);
    return;
}

int main()
{
    int i;
    while(scanf("%d",&n)){
        if(n==0)break;
        if(t!=0)printf("\n");
        select=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            b[i]=0;
        }
        find(0);
        t++;
        select=0;
    }
   return 0;
}
