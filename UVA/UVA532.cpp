#include <stdio.h>
#define MAX 1000000000
typedef struct{
    int x;
    int y;
    int z;
}position;

position p[2][10000];
char c[30][30][30]={0};
int a[30][30][30],Z,X,Y,num=1,flag=0,flag2=1,ei,ej,el;

void find(int cur){
    int i,temp,j=0;
    for(i=0;i<num;i++){
        if(p[flag][i].z<Z-1 && a[p[flag][i].z+1][p[flag][i].x][p[flag][i].y]>cur+1){
            a[p[flag][i].z+1][p[flag][i].x][p[flag][i].y]=cur;
            p[flag2][j].x=p[flag][i].x; p[flag2][j].y=p[flag][i].y;
            p[flag2][j].z=p[flag][i].z+1;  j++;
        }
        if(p[flag][i].z>0 && a[p[flag][i].z-1][p[flag][i].x][p[flag][i].y]>cur+1){
            a[p[flag][i].z-1][p[flag][i].x][p[flag][i].y]=cur;
            p[flag2][j].x=p[flag][i].x; p[flag2][j].y=p[flag][i].y;
            p[flag2][j].z=p[flag][i].z-1;  j++;
        }
        if(p[flag][i].x<X-1 && a[p[flag][i].z][p[flag][i].x+1][p[flag][i].y]>cur+1){
            a[p[flag][i].z][p[flag][i].x+1][p[flag][i].y]=cur;
            p[flag2][j].x=p[flag][i].x+1; p[flag2][j].y=p[flag][i].y;
            p[flag2][j].z=p[flag][i].z;  j++;
        }
        if(p[flag][i].x>0 && a[p[flag][i].z][p[flag][i].x-1][p[flag][i].y]>cur+1){
            a[p[flag][i].z][p[flag][i].x-1][p[flag][i].y]=cur;
            p[flag2][j].x=p[flag][i].x-1; p[flag2][j].y=p[flag][i].y;
            p[flag2][j].z=p[flag][i].z;  j++;
        }
        if(p[flag][i].y<Y-1 && a[p[flag][i].z][p[flag][i].x][p[flag][i].y+1]>cur+1){
            a[p[flag][i].z][p[flag][i].x][p[flag][i].y+1]=cur;
            p[flag2][j].x=p[flag][i].x; p[flag2][j].y=p[flag][i].y+1;
            p[flag2][j].z=p[flag][i].z;  j++;
        }
        if(p[flag][i].y>0 && a[p[flag][i].z][p[flag][i].x][p[flag][i].y-1]>cur+1){
            a[p[flag][i].z][p[flag][i].x][p[flag][i].y-1]=cur;
            p[flag2][j].x=p[flag][i].x; p[flag2][j].y=p[flag][i].y-1;
            p[flag2][j].z=p[flag][i].z;  j++;
        } 
    }
    num=j;
    temp=flag; flag=flag2; flag2=temp;
    if(a[ei][ej][el]<MAX){
        return;
    }
    else if(num!=0){
        find(cur+1);
    }
    else return;
}

int main()
{
    int i,j,l,si,sj,sl;
    char w;
    while(scanf("%d %d %d",&Z,&X,&Y)){
        if(X==0 && Y==0 && Z==0)break;
        for(i=0;i<Z;i++){
            for(j=0;j<X;j++){
                scanf("%c",&w);
                for(l=0;l<Y;l++){
                    scanf("%c",&c[i][j][l]);
                    if(c[i][j][l]=='S'){
                        si=i; sj=j; sl=l;
                        a[i][j][l]=1;
                        p[flag][0].z=i;
                        p[flag][0].x=j;
                        p[flag][0].y=l;
                    }
                    if(c[i][j][l]=='E'){
                        ei=i; ej=j; el=l;
                        a[i][j][l]=MAX;
                    }
                    else if(c[i][j][l]=='.'){
                        a[i][j][l]=MAX;
                    }
                    else if(c[i][j][l]=='#'){
                        a[i][j][l]=-1;
                    }
                }
            }
            scanf("%c",&w);
        }
        find(2);
        if(a[ei][ej][el]!=MAX)printf("Escaped in %d minute(s).\n",a[ei][ej][el]-1);
        else printf("Trapped!\n");
        num=1;
    }
    return 0;
}
