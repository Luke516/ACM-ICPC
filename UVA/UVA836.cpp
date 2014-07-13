#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char c[30][30];
int i,j;

int find2(int a,int b)
{
    int i,len=0;
    for(i=b;;i++){
        if(c[a][i]=='1')len++;
        else break;
    }
    return len;
}

int find(int x,int y)
{   
    int a,b,l,len=100,area,max=0;
    for(a=x;;a++){
        if(c[a][y]=='1'){
            l = find2(a,y);
            if(l<len)len=l;
            area=len*(a-x+1);
            if(area>max)max=area;
        }
        else break;
    }
    return max;
}

int main()
{
    int n,len,a,max;
    scanf("%d",&n);
    while(n--){
        max=0;
        scanf("%s",c[0]);
        len=strlen(c[0]);
        for(i=1;i<len;i++){
            scanf("%s",c[i]);
        }
        for(i=0;i<len;i++){
            for(j=0;j<len;j++){
                if(c[i][j]=='1'){
                    a=find(i,j);
                    if(a>max)max=a;
                }
            }
        }
        printf("%d\n",max);
        if(n!=0)printf("\n");
    }
    return 0;
}
