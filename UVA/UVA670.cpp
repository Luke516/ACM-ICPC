#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n,m,x[2][110],y[2][110];
bool select[110];
int match[2][110]={0};

double dis(int a,int b,int c,int d){
    int xx=x[a][b]-x[c][d];
    int yy=y[a][b]-y[c][d];
    return sqrt(xx*xx+yy*yy);
}

bool reach(int a,int b)
{
    if(2*dis(0,a+1,0,a)>=dis(1,b,0,a)+dis(0,a+1,1,b))return true;
    else return false;
}

bool find(int no)
{
    int i;
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
        scanf("%d %d",&n,&m);
        memset(match,0,sizeof(match));
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%d %d",&x[0][i],&y[0][i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d %d",&x[1][i],&y[1][i]);
        }
        for(j=1;j<n;j++){
            memset(select,false,sizeof(select));
            if(find(j)){
                ans++;
            }
            /*for(i=1;i<=n;i++){
                printf("%d ",match[0][i]);
            }printf("\n");
            for(i=1;i<=m;i++){
                printf("%d ",match[1][i]);
            }printf("\n");*/
        }
        printf("%d\n",n+ans);
        for(i=1;i<=n;i++){
            printf("%d %d",x[0][i],y[0][i]);
            if(match[0][i]!=0){
                printf(" %d %d",x[1][match[0][i]],y[1][match[0][i]]);
            }
            if(i!=n)printf(" ");
        }
        printf("\n");
        if(t<N)printf("\n");
    }
    return 0;
}
