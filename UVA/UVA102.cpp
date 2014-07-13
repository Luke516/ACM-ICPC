#include <cstdio>
#include <cstring>

using namespace std;

int bin[3][3];
int ans,cur,x[6];

int main()
{
    while(scanf("%d %d %d %d %d %d %d %d %d",&bin[0][0],&bin[0][1],&bin[0][2]
    ,&bin[1][0],&bin[1][1],&bin[1][2],&bin[2][0],&bin[2][1],&bin[2][2])!=EOF){
        
        ans=1;
        
        x[1]=bin[0][1]+bin[0][2]+bin[1][0]+bin[1][1]+bin[2][0]+bin[2][2];
        if(x[1]<x[ans])ans=1;
        x[0]=bin[0][1]+bin[0][2]+bin[1][0]+bin[1][2]+bin[2][0]+bin[2][1];
        if(x[0]<x[ans])ans=0;
        x[4]=bin[0][1]+bin[0][0]+bin[1][1]+bin[1][2]+bin[2][0]+bin[2][2];
        if(x[4]<x[ans])ans=4;
        x[5]=bin[0][1]+bin[0][0]+bin[1][0]+bin[1][2]+bin[2][2]+bin[2][1];
        if(x[5]<x[ans])ans=5;
        x[2]=bin[0][0]+bin[0][2]+bin[1][1]+bin[1][2]+bin[2][0]+bin[2][1];
        if(x[2]<x[ans])ans=2;
        x[3]=bin[0][0]+bin[0][2]+bin[1][0]+bin[1][1]+bin[2][2]+bin[2][1];
        if(x[3]<x[ans])ans=3;
        
        if(ans==0)printf("BGC");
        if(ans==1)printf("BCG");
        if(ans==2)printf("GBC");
        if(ans==3)printf("GCB");
        if(ans==4)printf("CBG");
        if(ans==5)printf("CGB");
        
        printf(" %d\n",x[ans]);
    }
   
   return 0;
}
