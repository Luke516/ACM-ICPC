#include <stdio.h>

int main()
{
    long long int max=0,count=0,x[1000001]={0};
    int i,temp,cur,a,b,min,maxx;
    
    while(scanf("%d %d",&a,&b)!=EOF){
        if(a>b){
            min=b; maxx=a;
        }
        else{
            min=a; maxx=b;
        } 
        for(i=min;i<=maxx;i++){
            count=0;
            cur=i;
            while(cur!=1){
                if(cur<1000001){
                    if(x[cur]!=0){
                        count+=x[cur];
                        break;
                    }
                }
                if(cur%2==0)cur=cur/2;
                else cur=cur*3+1;
                count++;
            }
            x[i]=count;
            if(count>max)max=count;
        }
        printf("%d %d %lld\n",a,b,max+1); 
        max=0;
    }
    return 0;
}
