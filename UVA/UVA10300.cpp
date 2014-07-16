#include <cstdio>

using namespace std;

int main()
{
    int i,n,N;
    long long int a,b,c,ans;
    scanf("%d",&N);
    while(N--){
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld %lld %lld",&a,&b,&c);
            ans+=a*c;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
