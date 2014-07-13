#include <cstdio>
#include <cstring>

using namespace std;

int n,m,a[2][110];
bool select[110];
int match[2][110]={0},b[110][110];

bool reach(int x,int y)
{
    if(b[x][y]==1)return true;
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
    int N,t,ans,i,j,k,x,y;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        memset(b,0,sizeof(b));
        memset(match,0,sizeof(match));
        ans=0;
        scanf("%d %d",&m,&k);
        for(i=0;i<k;i++){
            scanf("%d %d %d",&i,&x,&y);
            b[x][y]=1;
        }
        for(i=1;i<=n;i++){
            memset(select,false,sizeof(select));
            if(find(i))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
