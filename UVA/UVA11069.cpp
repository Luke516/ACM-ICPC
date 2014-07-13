#include <stdio.h>

int main()
{
    int i,n,a[80];
    for(i=0;i<80;i++){
        if(i==0)a[i]=1;
        else if(i<3)a[i]=2;
        else a[i]=a[i-2]+a[i-3];
    }
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",a[n-1]);
        
    }
    return 0;
}
