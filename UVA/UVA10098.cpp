#include <stdio.h>
#include <string.h>

int LEN;

int compare(const void *a,const void *b)
{
    char aa = *(char*)a; 
    char bb = *(char*)b; 
    return aa - bb; 
}

void find(int len,int x,char cc[],char anss[])
{
    int i;
    char temp,c[11],ans[11];
    strcpy(c,cc);
    strcpy(ans,anss);
    if(len==0){
        printf("%s\n",ans);
    }
    else{
        qsort(c,LEN,sizeof(char),compare);
        for(i=0;i<len;i++){
            if(c[i]!=c[i-1]||i==0){
                ans[x]=c[i];
                ans[x+1]='\0';
                c[i]=124;
                find(len-1,x+1,c,ans);
                c[i]=ans[x];
            }
         
        }
    }
    
}

int main()
{
    int i,n,len;
    char c[11],ans[11]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",c);
        len=strlen(c);
        LEN=len;
        find(len,0,c,ans);
        printf("\n");
    }
    return 0;
}
