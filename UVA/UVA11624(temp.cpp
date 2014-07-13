#include <stdio.h>
#include <string.h>

void find(char c[1000][1000],int i,int j){
    if(c[i+1][j]=='.'){
        c[i+1][j]=c[i][j]+1;
        find(c,i+1,j);
    }
    if(c[i-1][j]=='.'){
        c[i-1][j]=c[i][j]+1;
        find(c,i-1,j);
    }
    if(c[i][j+1]=='.'){
        c[i][j+1]=c[i][j]+1;
        find(c,i,j+1);
    }
    if(c[i][j-1]=='.'){
        c[i][j-1]=c[i][j]+1;
        find(c,i,j-1);
    }
}

int main()
{
    int n;
    char c[1000][1000];
    int maze[1000][1000]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        for(j=0;j<a;j++){
            for(l=0;l<b;l++){
                scanf("%s",&c[j][l]);
                if(c[j][l]=='F'){
                    f1=j; f2=l;
                }
                if(c[j][l]=='J'){
                    j1=j; j2=l;
                }
                if(c[j][l]=='#'){
                    maze[j][l]=-1;
                }
            }
        }
        c[f1][f2]=0;
        find(c,f1,f2);
        for(j=0;j<1000;j++){
            if(c[j][0]>=0&&c[j][0]<)
        }
   
        
    }
}
