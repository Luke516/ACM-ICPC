#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> v[500];
int pa[500];
bool select[500];
bool flag;
queue<int> q;
vector<int> ans;

void find(int start,int end){
    int i,cur;
    q.push(start);
    pa[start]=start;
    select[start]=true;
    if(start==end)return;
    while(!flag && !q.empty()){
        cur=q.front(); q.pop();
        for(i=0;i<v[cur].size();i++){
            if(v[cur][i]==end){
                pa[v[cur][i]]=cur;
                select[v[cur][i]]=true;
                //printf("pa[%d]=%d\n",v[cur][i],cur );
                flag=true;
            }
            else if(!select[v[cur][i]]){
                pa[v[cur][i]]=cur;
                //printf("pa[%d]=%d\n",v[cur][i],cur );
                select[v[cur][i]]=true;
                q.push(v[cur][i]);
            }
        }
    }
    return;
}

int main()
{
    
    int i,n,start,end,j,l,m,x,num,len;
    char c,s[5000];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&num);
            scanf("%s",s);
            while(1){
                len=strlen(s);
                if(len<=1)break;
                j=sscanf(s,"%c%d%s",&c,&x,s);
                v[num].push_back(x);
                //printf("v[%d].push_back(%d)\n",num,x);
                if(j!=3)break;
            }
        }
        printf("-----\n");
        scanf("%d",&m);
        for(i=0;i<m;i++){
            memset(pa,0,sizeof(pa));
            flag=false;
            scanf("%d %d",&start,&end);
            find(start,end);
            //printf("find(%d,%d)\n",start,end);
            //if(start==end)printf("%d ",start);
            if(pa[end]==0)printf("connection impossible");
            else{
                j=end;
                for(;;){
                    ans.push_back(j);
                    l=pa[j];
                    if(j==l)break;
                    j=l;
                }
                for(j=ans.size()-1;j>=0;j--){
                    printf("%d",ans[j]);
                    if(j!=0)printf(" ");
                }
            }
            printf("\n");
            ans.clear();
            memset(select,false,sizeof(select));
            while(!q.empty())q.pop();
        }
        for(i=0;i<500;i++){
            v[i].clear();
        }
    }
    return 0;
}
