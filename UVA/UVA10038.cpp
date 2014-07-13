#include <cstdio>
#include <cstring>

using namespace std;

bool flag[5000];
int num[5000];
int x,n,i;

int main()
{
    while(scanf("%d",&n)!=EOF){
        
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        
        for(i=1;i<n;i++){
            x=num[i]-num[i-1];
            if(x<0)x=-x;
            if(!flag[x] && x<n && x>0)flag[x]=true;
            else{
                printf("Not jolly\n");
                break;
            }
            if(i==n-1)printf("Jolly\n");
        }
        if(n==1)printf("Jolly\n");
            
        memset(flag,false,sizeof(flag));

    }
   
   return 0;
}
