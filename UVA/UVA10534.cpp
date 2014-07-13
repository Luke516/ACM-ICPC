#include <iostream>
#include <cstdio>

int data[10010],in[10010]={0},de[10010]={0},x1[10010],x2[10010];

int main()
{
    int a,b,ans,len,l,i,inn,dee,j,cur;
    while(scanf("%d",&l)!=EOF){
        a=1;b=0;ans=1;inn=1;dee=1;
        for(i=0;i<l;i++){
            scanf("%d",&data[i]); 
        }
        in[inn]=data[0];
        x1[0]=1;
        for(i=1;i<l;i++){
            if(data[i]>in[inn]){
                in[++inn]=data[i];
            }
            else{
                for(j=inn;j>0;j--){
                    if(data[i]>in[j-1] && data[i]<in[j]){
                        in[j]=data[i];
                    }
                }
            }
            x1[i]=inn;
        }
        de[dee]=data[l-1];
        x2[l-1]=1;
        for(i=l-2;i>=0;i--){
            if(data[i]>de[dee]){
                de[++dee]=data[i];
            }
            else{
                for(j=dee;j>0;j--){
                    if(data[i]>de[j-1] && data[i]<de[j]){
                        de[j]=data[i];
                    }
                }
            }
            x2[i]=dee;
        }
        for(i=0;i<l;i++){
            if(x1[i]>x2[i]){
                cur=x2[i]*2-1;
            }
            else cur=x1[i]*2-1;
            if(cur>ans)ans=cur;
        }
        
        printf("%d\n",ans);
    }
    return 0;
}
