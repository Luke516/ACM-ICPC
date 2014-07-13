#include <stdio.h>
#include <string.h>

int main()
{
    long long int a,b,ans;
    while(scanf("%lld %lld",&a,&b)!=EOF){
        ans=a-b;
        if(ans<0)ans=-ans;
        printf("%lld\n",ans);
    }
    return 0;
}
