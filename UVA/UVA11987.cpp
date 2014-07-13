#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> num,root;
vector<long long int> sum;

int group[100010];

int find(int x)
{
    if(x==-1)return -1;
    if(root[x]==x)return x;
    else return root[x]=find(root[x]);
}

int main(){
    int n,m,i,j,c,x,y,cur;
    while(scanf("%d %d",&n,&m)!=EOF){
        cur=0;
        for(i=1;i<=n;i++){
            group[i]=-1;
        }
        for(j=0;j<m;j++){
            scanf("%d",&c);
            if(c==1 || c==2)scanf("%d %d",&x,&y);
            else scanf("%d",&x);
            switch(c){
                case 1:
                if(group[x]==-1 && group[y]==-1){//都還不屬於任何集合->創造新集合
                    if(x==y)break;
                    group[x]=cur;
                    group[y]=cur;
                    sum.push_back((long long int)(x+y));
                    num.push_back(2);
                    root.push_back(cur);
                    cur++;
                }
                else if(group[x]==-1){//其中之一屬於其他集合->將另一個併入集合
                    group[y]=find(group[y]);
                    group[x]=group[y];
                    num[group[y]]++;
                    sum[group[y]]+=(long long int)x;
                }
                else if(group[y]==-1){
                    group[x]=find(group[x]);
                    group[y]=group[x];
                    num[group[x]]++;
                    sum[group[x]]+=(long long int)y;
                }
                else if(group[x]!=group[y]){//將兩個集合融合
                    group[x]=find(group[x]);
                    group[y]=find(group[y]);
                    if(group[x]==group[y])break;
                    sum[group[x]]+=sum[group[y]];
                    num[group[x]]+=num[group[y]];
                    root[group[y]]=root[group[x]];
                    group[y]=group[x];
                }
                break;
                case 2:
                if(group[y]==-1 && group[x]==-1){
                    if(x==y)break;
                    group[x]=cur;
                    group[y]=cur;
                    sum.push_back((long long int)(x+y));
                    num.push_back(2);
                    root.push_back(cur);
                    cur++;
                }
                else if(group[x]==-1){
                    group[y]=find(group[y]);
                    group[x]=group[y];
                    sum[group[y]]+=(long long int)x;
                    num[group[y]]++;
                }
                else if(group[y]==-1){
                    group[x]=find(group[x]);
                    sum[group[x]]-=(long long int)x;
                    num[group[x]]--;
                    group[y]=cur;
                    sum.push_back((long long int)(x+y));
                    num.push_back(2);
                    root.push_back(cur);
                    group[x]=group[y];
                    cur++;
                }
                else if(group[x]!=group[y]) {
                    group[x]=find(group[x]);
                    group[y]=find(group[y]);
                    if(group[x]==group[y])break;
                    sum[group[y]]+=(long long int)x;
                    num[group[y]]++;
                    sum[group[x]]-=(long long int)x;
                    num[group[x]]--;
                    group[x]=group[y];
                }
                    break;
                case 3:
                group[x]=find(group[x]);
                if(group[x]!=-1)printf("%d %lld\n",num[group[x]],sum[group[x]]);
                else printf("1 %d\n",x);
                break;
            }
        }
        sum.clear();
        num.clear();
        root.clear();
    }
    return 0;
}
