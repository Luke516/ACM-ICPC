#include <stdio.h>
#define MAX 1000000000
typedef struct{
    int x;
    int y;
}position;

position p[2][1000000];
char c[1001][1001]={0};
int a[1001][1001],a2[1001][1001],Z,X,Y,num=1,flag=0,flag2=1;

void find(int cur,int a[1001][1001]){
    int i,temp,j=0;
    for(i=0;i<num;i++){
        if(p[flag][i].x<X-1 && a[p[flag][i].x+1][p[flag][i].y]>cur){
            a[p[flag][i].x+1][p[flag][i].y]=cur;
            p[flag2][j].x=p[flag][i].x+1; p[flag2][j].y=p[flag][i].y;
            j++;
        }
        if(p[flag][i].x>0 && a[p[flag][i].x-1][p[flag][i].y]>cur){
            a[p[flag][i].x-1][p[flag][i].y]=cur;
            p[flag2][j].x=p[flag][i].x-1; p[flag2][j].y=p[flag][i].y;
            j++;
        }
        if(p[flag][i].y<Y-1 && a[p[flag][i].x][p[flag][i].y+1]>cur){
            a[p[flag][i].x][p[flag][i].y+1]=cur;
            p[flag2][j].x=p[flag][i].x; p[flag2][j].y=p[flag][i].y+1;
            j++;
        }
        if(p[flag][i].y>0 && a[p[flag][i].x][p[flag][i].y-1]>cur){
            a[p[flag][i].x][p[flag][i].y-1]=cur;
            p[flag2][j].x=p[flag][i].x; p[flag2][j].y=p[flag][i].y-1;
            j++;
        } 
    }
    num=j;
    temp=flag; flag=flag2; flag2=temp;
    if(num!=0){
        find(cur+1,a);
    }
    else return;
}

int main()
{
    int fire=0;
    int i,j,l,fx,fy,jx,jy,sl,N,ans=MAX;
    char w;
    scanf("%d",&N);
    for(l=0;l<N;l++){
        scanf("%d %d",&X,&Y);
        for(i=0;i<X;i++){
            scanf("%c",&w);
            for(j=0;j<Y;j++){
                scanf("%c",&c[i][j]);
                if(c[i][j]=='J'){
                    a[i][j]=1;
                    a2[i][j]=MAX;
                    jx=i;
                    jy=j;
                }
                if(c[i][j]=='F'){
                    p[flag][fire].x=i;
                    p[flag][fire].y=j;
                    fire++;
                    a[i][j]=MAX;
                    a2[i][j]=1;
                    fx=i;
                    fy=j;
                }
                else if(c[i][j]=='.'){
                    a[i][j]=MAX;
                    a2[i][j]=MAX;
                }
                else if(c[i][j]=='#'){
                    a[i][j]=-1;
                    a2[i][j]=-1;
                }
            }
        }
        num=fire;
        if(fire!=0)find(2,a2);
        p[flag][0].x = jx; p[flag][0].y = jy;
        num=1;
        find(2,a);
        for(j=0;j<X;j++){        
            if(a[j][0]<a2[j][0] && ans>a[j][0])ans=a[j][0];
            if(a[j][Y-1]<a2[j][Y-1] && ans>a[j][Y-1])ans=a[j][Y-1];
        }
        for(j=0;j<Y;j++){
            if(a[0][j]<a2[0][j] && ans>a[0][j])ans=a[0][j];
            if(a[X-1][j]<a2[X-1][j] && ans>a[X-1][j])ans=a[X-1][j];
        }
        if(ans!=MAX)printf("%d\n",ans);
        else printf("IMPOSSIBLE\n");
        num=1;
        ans=MAX;
        fire=0;
    }
    return 0;
}
