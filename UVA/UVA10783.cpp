#include <stdio.h>

int main()
{
    int n,a,b,i,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        if(a%2==0)a++;
        if(b%2==0)b--;
        ans=(a+b)*((b-a)/2+1)/2;
        printf("Case %d: %d\n",i+1,ans);
    }
    return 0;
}
