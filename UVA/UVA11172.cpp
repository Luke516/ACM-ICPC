#include <cstdio>

using namespace std;

int main()
{
    int N;
    long long int a,b;
    scanf("%d",&N);
    while(N--){
        scanf("%lld %lld",&a,&b);
        if(a>b)printf(">\n");
        else if(a<b)printf("<\n");
        else printf("=\n");
    }
   
   return 0;
}
