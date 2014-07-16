#include <stdio.h>

int main()
{
    int i,j,N,card[100][100],no[100],first[100]={0},last[100]={0},flag=1,selected;
    int a=0,b=0,cur,curr;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&no[i]);
        for(j=0;j<no[i];j++){
            scanf("%d",&card[i][j]);
        }
    }
    for(i=0;i<N;i++){
        //printf("%d",no[i]);
        for(j=0;j<no[i];j++){
            //printf(" %d ",card[i][j]);
        }
        //printf("\n");
    }
    for(;;){
        selected=-1;
        if(flag==1){
            for(i=0;i<N;i++){
                if(card[i][first[i]]>selected&&first[i]<no[i]){
                    selected=card[i][first[i]];
                    cur=i;
                }
            }
            //printf("~%d ",cur);
            card[cur][first[cur]]=-1;
            //printf("~no:%d ~[%d][%d] ",no[cur],cur,first[cur]);
            first[cur]++;
            if(selected==-1)break;
            else {
                a+=selected;
                //printf("a+%d\n",selected);
            }
        }
        else if(flag==-1){
            for(i=0;i<N;i++){
                if(card[i][no[i]-1-last[i]]>selected&&no[i]-1-last[i]>=0){
                    selected=card[i][no[i]-1-last[i]];
                    cur=i;
                }
            }
            //printf("~%d ",cur);
            card[cur][no[cur]-1-last[cur]]=-1;
            //printf("~[%d][%d] ",cur,no[cur]-1-last[cur]);
            last[cur]++;
            if(selected==-1)break;
            else {
                b+=selected;
                //printf("b+%d\n",selected);
            }
        }
        flag = -flag;
    }
    printf("%d %d",a,b);
    return 0;
}
