#include <cstdio>

using namespace std;

int num[60];

int main()
{
    int N,n,i,j,ans;
    scanf("%d",&N);
    while(N--){
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            for(j=0;j<i;j++){
                if(num[j]>num[i])ans++;
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",ans);
    }
    
    return 0;
}
