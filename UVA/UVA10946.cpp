#include <stdio.h>
#include <string.h>

int x,y;

typedef struct{
    char c;
    int i;
}ans;

int find(char c[50][50],int i,int j){
    int x=0;
    char temp;
    temp = c[i][j];
    c[i][j]='.';
    x++;
    if(c[i+1][j]==temp)x+=find(c,i+1,j);
    if(c[i-1][j]==temp)x+=find(c,i-1,j);
    if(c[i][j+1]==temp)x+=find(c,i,j+1);
    if(c[i][j-1]==temp)x+=find(c,i,j-1);
    return x;
}

int compare(const void *a,const void *b){
    const ans *aa=a,*bb=b;
    if(aa->i>bb->i)return -1;
    else if(aa->i<bb->i)return 1;
    else if(aa->c > bb->c)return 1;
    else if(aa->c < bb->c)return -1;
    else return 0;
}

int main()
{
    int i,j,cur=0,no=1;
    char c[50][50],w;
    ans a[2500];
    while(scanf("%d %d",&x,&y)){
        if(x==0&&y==0)break;
        printf("Problem %d:\n",no);
        for(i=0;i<x;i++){
            scanf("%c",&w);
            for(j=0;j<y;j++){
                scanf("%c",&c[i][j]);
            }
        }
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                printf("%c",c[i][j]);
            }
            printf("\n");
        }
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                if(c[i][j]!='.'){
                    a[cur].c=c[i][j];
                    a[cur].i=find(c,i,j);
                    cur++;
                }
            }
        }
        qsort(a,cur,sizeof(ans),compare);
        for(i=0;i<cur;i++){
            printf("%c %d\n",a[i].c,a[i].i);
        }
        cur=0;
        no++;
    }
    return 0;
}
