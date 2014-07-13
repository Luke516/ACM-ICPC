#include <cstdio>
#include <cstring>

using namespace std;

int n,m,a[2][510];
bool select[510];
int match[2][510]={0},b[510][510];

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
    int N,t,ans,i,j;
    scanf("%d",&N);
    for(t=1;t<=N;t++){
        ans=0;
        memset(match,0,sizeof(match));
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&b[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            memset(select,false,sizeof(select));
            if(find(i))ans++;
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",t,ans);
    }
    return 0;
}
