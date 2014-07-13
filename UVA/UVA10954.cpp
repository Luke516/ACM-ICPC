#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int>::iterator it;

int main()
{
    int n,i,sum,pay,num;
    while(scanf("%d",&n)){
        if(n==0)break;
        v.clear();
        pay=0;
        for(i=0;i<n;i++){
            scanf("%d",&num);
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        while(v.size()>1){
            sum=v[0]+v[1];
            pay+=sum;
            v.erase(v.begin(),v.begin()+2);
            it=lower_bound(v.begin(),v.end(),sum);
            v.insert(it,sum);
        }
        printf("%d\n",pay);
    }
   return 0;
}
