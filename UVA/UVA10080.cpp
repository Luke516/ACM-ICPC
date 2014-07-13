#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

double x[2][110],y[2][110];
bool select[110];
int match[2][110]={0};
int n,m,s,v,dis;

bool reach(int a,int b)
{
    double xx=x[0][a]-x[1][b];
    double yy=y[0][a]-y[1][b];
    if(xx*xx+yy*yy<=dis*dis){
        return true;
    }
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
    int i,j,ans;
    while(scanf("%d %d %d %d",&n,&m,&s,&v)!=EOF){
        dis=v*s; ans=0;
        memset(match,0,sizeof(match));
        for(i=1;i<=n;i++){
            scanf("%lf %lf",&x[0][i],&y[0][i]);
        }
        for(i=1;i<=m;i++){
            scanf("%lf %lf",&x[1][i],&y[1][i]);
        }
        for(i=1;i<=n;i++){
            memset(select,false,sizeof(select));
            if(find(i)){
                ans++;
            }
        }
        printf("%d\n",n-ans);
    }
    return 0;
}