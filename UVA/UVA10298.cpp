#include <cstdio>
#include <cstring>

using namespace std;

char a[10000010];
int c[10000010],max;

int find(char *a,int len){ 
    int i,j; 
    j=c[0]=-1; 
    for(i=1;i<len;i++) 
    { 
       while(j!=-1&&a[i]!=a[j+1])j=c[j]; 
       if(a[j+1]==a[i])j++; 
        c[i]=j; 
        //printf("c[%d]=%d\n",i,j);
    } 
    //printf("return%d\n",j+1);
    return j+1;
} 

int main()
{
    int i,n,len;
    while(scanf("%s",a)!=EOF){
        len=strlen(a);
        if(len==1 && a[0]=='.')break;
        n=find(a,len);
        if(n==0)printf("1\n");
        else if(len%(len-n)==0){
            printf("%d\n",len/(len-n));
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}
