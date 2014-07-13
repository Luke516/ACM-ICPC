#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v,ans;

int find(int a,int b,int c){
    int aa=1<<(a-1);
    int bb=1<<(b-1);
    int cc=1<<(c-1);
    return aa+bb+cc;
}

int main()
{
    int n,a,c,b,d,x,i,j,l,t=1;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        for(i=0;i<n;i++){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            x=find(a,b,c);
            x+=d*10000;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(i=v.size()-1;i>=0;i--){
            for(j=i-1;j>=0;j--){
                for(l=j-1;l>=0;l--){
                    a=v[i]%10000;
                    b=v[j]%10000;
                    c=v[l]%10000;
                    if(a|b==a+b && a|c==a+c && b|c==b+c && a+b+c==511){
                        ans.push_back(v[i]/10000+v[j]/10000+v[l]/10000);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        printf("Case %d: ",t++);
        if(ans.size()>0)printf("%d\n",ans.back());
        else printf("-1\n");
        v.clear();
        ans.clear();
    }
    return 0;
}
