#include <cstdio>

using namespace std;

int main()
{
    int i,ans,x,aa,bb,cc;
    long long int a,b,c;
    while(scanf("%lld %lld",&a,&b)!=EOF){
        if(a==0 && b==0)break;
        c=a+b;
        x=0;
        ans=0;
        for(;;){
            if(c==0)break;
            aa=a%10;
            bb=b%10;
            cc=c%10;
            if((aa+bb+x)!=cc){
                ans++; x=1;
            }
            else x=0;
            a=a/10;
            b=b/10;
            c=c/10;
            if(c<=0)break;
        }
        if(ans==0)printf("No carry operation.\n");
        else if(ans==1)printf("1 carry operation.\n");
        else printf("%d carry operations.\n",ans);
    }
    return 0;
}
