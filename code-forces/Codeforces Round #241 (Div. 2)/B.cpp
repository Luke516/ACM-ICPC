#include <iostream>
#include <cstdio>

using namespace std;

int paint[50010][6]={0};
int t[6][50010]={0};

int main()
{
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&paint[i][j]);
        }
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(t[i-1][j]>t[i][j-1])t[i][j]=t[i-1][j]+paint[j][i];
            else t[i][j]=t[i][j-1]+paint[j][i];
        }
    }
    for(i=1;i<=n;i++){
        printf("%d ",t[m][i]);
    }
    return 0;
}
