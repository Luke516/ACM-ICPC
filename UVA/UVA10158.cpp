#include <stdio.h>
#include <string.h>

int root[10010],enemy[10010];

int find(int x)
{
    if(x==-1)return -1;
    if(root[x]==x)return x;
    else return find(root[x]);
}

int main()
{ 
    int i,n,c,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        root[i]=i;
        enemy[i]=-1;
    }
    while(scanf("%d %d %d",&c,&x,&y)){
        if(c==0 && x==0 && y==0)break;
        root[x]=find(x);
        root[y]=find(y);
        enemy[root[x]]=find(enemy[root[x]]);
        enemy[root[y]]=find(enemy[root[y]]);
        enemy[x]=enemy[root[x]];
        enemy[y]=enemy[root[y]];
        switch(c){
        case 1:
            if(enemy[x]!=root[y]){
                if(enemy[y]==-1){
                    root[root[y]]=root[x];
                    root[y]=root[x];
                }
                else if(enemy[x]==-1){
                    root[root[x]]=root[y];
                    root[x]=root[y];
                }
                else{
                    root[root[y]]=root[x];
                    root[y]=root[x];
                    root[enemy[y]]=root[enemy[x]];
                }
            }
            else printf("-1\n");
            break;
        case 2:
            if(root[x]!=root[y]){
                if(enemy[x]!=-1 && enemy[y]!=-1){
                    root[root[y]]=enemy[x];
                    root[y]=enemy[x];
                    root[root[x]]=enemy[y];
                    root[x]=enemy[y];
                }
                else if(enemy[x]!=-1 && enemy[y]==-1){
                    root[root[y]]=enemy[x];
                    root[y]=enemy[x];
                }
                else if(enemy[x]==-1 && enemy[y]!=-1){
                    root[root[x]]=enemy[y];
                    root[x]=enemy[y];
                }
                else{
                    enemy[root[x]]=root[y];
                    enemy[x]=root[y];
                    enemy[root[y]]=root[x];
                    enemy[y]=root[x];
                }
            }
            else printf("-1\n");
            break;
        case 3:
            if(root[x]==root[y])printf("1\n");
            else printf("0\n");
            break;
        case 4:
            if(enemy[x]==root[y])printf("1\n");
            else printf("0\n");
            break;
        }
    }
    return 0;
   }
