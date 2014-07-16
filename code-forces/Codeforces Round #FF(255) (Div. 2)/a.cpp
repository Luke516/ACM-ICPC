#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    bool b[500];
    int n,m,i,x;
    memset(b,false,sizeof(b));
    
    scanf("%d %d",&n,&m);

    for(i=1;i<=m;i++){
        scanf("%d",&x);
        if(b[x%n]){
            printf("%d\n",i);
            break;
        }
        else b[x%n]=true;
        if(i==m)printf("-1\n");
    }
   
   return 0;
}
