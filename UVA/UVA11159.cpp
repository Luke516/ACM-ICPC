#include <cstdio>
#include <cstring>

using namespace std;

int n,m,a[2][110];
bool select[110];
int match[2][110]={0};

bool reach(int x,int y)
{
    if(a[0][x]==0 && a[1][y]==0)return true;
    else if(a[0][x]==0)return false;
    if(a[1][y]%a[0][x]==0)return true;
    else return false;
}

bool find(int no)
{
    int i,z;
    for(i=1;i<=m;i++){
        if(select[i])continue;
        if(!reach(no,i))continue;
        select[i]=true;
        if(match[1][i]==0){
            match[0][no]=i; match[1][i]=no;
            return true;
        }
        else {
            if(find(match[1][i])){
                match[0][no]=i; match[1][i]=no;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int N,t,ans,i;
    scanf("%d",&N);
    for(t=1;t<=N;t++){
        ans=0;
        memset(match,0,sizeof(match));
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[0][i]);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d",&a[1][i]);
        }
        for(i=1;i<=n;i++){
            memset(select,false,sizeof(select));
            if(find(i))ans++;
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
