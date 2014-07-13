#include <stdio.h>
#include <string.h>

char word[10000][200],c[200];
int i=0;

void set(char c[]){
    int j;
    char garbage[200]={0},remain[200]={0},temp[200]={0};
    for(j=0;j<200;j++){
        if(c[j]<91 && c[j]>64)c[j]+=32;
    }
    if(c[0]>96&&c[0]<123)sscanf(c,"%[a-z]%s",temp,remain);
    else sscanf(c,"%[^(a-z)]%[a-z]%s",garbage,temp,remain);
    if(strlen(temp)!=0){
        strcpy(word[i],temp);
        i++;
    }
    if(strlen(remain)!=0)set(remain);
}
int compare(const void* a, const void* b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main()
{
    char c[200];
    int  j,max;
    while(scanf("%s",c)!=EOF){
        set(c);
        if(i>9900){
            qsort(word,i,sizeof(char[200]),compare);
            for(j=0;j<10000;j++){
                if(strcmp(word[j-1],word[j])==0){
                    word[j-1][0]=123;
                }
            }
            qsort(word,i ,sizeof(char[200]),compare);
            for(j=0;j<10000;j++){
                if(word[j][0]==123)break;
            }
            i=j;
        }
        
    }
    max=i;
    qsort(word,max,sizeof(char[200]),compare);
    for(i=0;i<max;i++){
        if(word[i][0]==' '){}
        else if(i==0)printf("%s\n",word[i]);
        else if(strcmp(word[i-1],word[i])!=0){
                printf("%s\n",word[i]);
        }
    }
    return 0;
    
}
