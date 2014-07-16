#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct request{
    int size;
    int money;
    int no;
};

struct t{
    int no;
    int size;
};

bool compare(const request a,const request b)
{
    return a.money<b.money;
}

bool compare2(const t a,const t b)
{
    return a.size<b.size;
}

vector<request> requests;
vector<t> table;
int anss[2000][2];

int main()
{
    request r;
    t tt;
    int i,j,n,size,money,cur,ts,k,sum=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&size,&money);
        r.size=size; r.money=money; r.no=i+1;
        requests.push_back(r);
    }
    scanf("%d",&k);
    tt.no=0; tt.size=0;
    table.push_back(tt);
    for(i=0;i<k;i++){
        scanf("%d",&ts);
        tt.no=i+1; tt.size=ts;
        table.push_back(tt);
    }
    sort(requests.begin(),requests.end(),compare);
    sort(table.begin(),table.end(),compare2);
    
    cur=k;
    for(i=n-1;i>=0;i--){
        for(j=cur;j>0;j--){
            if(table[j].size>requests[i].size&&table[j-1].size<requests[i].size){
                anss[ans][0]=requests[i].no; anss[ans][1]=table[j].no;
                ans++;
                sum+=requests[i].money;
                cur--;
            }
        }
        if(cur<0)break;
    }
    printf("%d %d\n",ans,sum);
    for(i=0;i<ans;i++){
        printf("%d %d\n",anss[i][0],anss[i][1]);
    }
    return 0;
}
