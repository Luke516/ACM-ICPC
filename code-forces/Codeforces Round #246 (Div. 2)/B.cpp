#include <cstdio>
#include <vector>

using namespace std;

vector<int> v[100010];
int home[100010],away[100010];

int main()
{
    int n,k,i,ans,a=0,b=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&home[i],&away[i]);
        v[home[i]].push_back(i);
    }
    k=(n-1);
    for(i=0;i<n;i++){
        printf("%d %d\n",k+v[away[i]].size(),k-v[away[i]].size());
    }
    return 0;
}
