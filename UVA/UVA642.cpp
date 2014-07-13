#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char c[1000];
    unsigned int u;
    bool b;
}node;

int compare(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}

int main()
{
    char c[101][1000];
    node map[800];
    int i=0,j,sum,num;
    unsigned int sum2=1;
    for(i=0;i<750;i++){
        map[i].b=0;
    }
    i=0;
    for(;;){
        scanf("%s",c[i]);
        if(c[i][0]=='X')break;
        i++;
    }
    num=i;
    qsort(c,i,sizeof(char[1000]),compare);
    for(i=0;i<num;i++){
        for(j=0;j<strlen(c[i]);j++){
            sum+=c[i][j];
            sum2=sum2*c[i][j];
        }
        sum=sum+strlen(c[i])+sum2%7;
        
        if(map[sum].b==0){
            strcpy(map[sum].c,c[i]);
            map[sum].u=sum2;
            map[sum].b=1;
        }
        else if(sum2==map[sum].u){
            strcat(map[sum].c,"\n");
            strcat(map[sum].c,c[i]);
        }
        sum=0;
        sum2=1;
    }
    for(;;){
        scanf("%s",c[0]);
        if(c[0][0]=='X')break;
        for(j=0;j<strlen(c[0]);j++){
            sum+=c[0][j];
            sum2=sum2*c[0][j];
        }
        sum=sum+strlen(c[0])+sum2%7;
        if(map[sum].b!=0&&map[sum].u==sum2)printf("%s\n******\n",map[sum].c);
        else printf("NOT A VALID WORD\n******\n",map[sum].c);
        sum=0;
        sum2=1;
    }
    return 0;
}