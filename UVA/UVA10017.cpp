#include <stdio.h>

int a[300],b[300],c[300],x,m;

void find(int *sourse,int *target,int *other,int num)
{
    int i,temp;
    if(x==m)return;
    if(num==1&&x<m){
        for(i=0;;i++){
            if(*(sourse+i+1)==0){
                temp=*(sourse+i);
                *(sourse+i)=0;
                break;
            }
        }
        for(i=0;;i++){
            if(*(target+i)==0){
                *(target+i)=temp;
                break;
            }
        }
        printf("A=>");
        if(a[0]!=0)printf("   ");
        for(i=0;;i++){
            if(a[i]!=0)printf("%d",a[i]);
            if(a[i+1]!=0)printf(" ");
            else break;
        }
        printf("\n");
        printf("B=>");
        if(b[0]!=0)printf("   ");
        for(i=0;;i++){
            if(b[i]!=0)printf("%d",b[i]);
            if(b[i+1]!=0)printf(" ");
            else break;
        }
        printf("\n");
        printf("C=>");
        if(c[0]!=0)printf("   ");
        for(i=0;;i++){
            if(c[i]!=0)printf("%d",c[i]);
            if(c[i+1]!=0)printf(" ");
            else break;
        }
        printf("\n\n");
        x++;
    }
    else{
        find(sourse,other,target,num-1);
        find(sourse,target,other,1);
        find(other,target,sourse,num-1);
    }
}

int main()
{
    int n,i,j;
    int *aa=a,*bb=b,*cc=c;
    for(j=1;;j++){
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)break;
        printf("Problem #%d\n\n",j);
        for(i=0;i<300;i++){
            if(i<n) a[i]=n-i;
            else a[i]=0;
            b[i]=0;
            c[i]=0;
        }
        printf("A=>");
        if(a[0]!=0)printf("   ");
        for(i=0;;i++){
            if(a[i]!=0)printf("%d",a[i]);
            if(a[i+1]!=0)printf(" ");
            else break;
        }
        printf("\n");
        printf("B=>");
        printf("\n");
        printf("C=>");
        printf("\n\n");
        x=0;
        find(aa,cc,bb,n);
        if(x<m){
            while(x!=m){
                printf("A=>");
                if(a[0]!=0)printf("   ");
                for(i=0;;i++){
                    if(a[i]!=0)printf("%d",a[i]);
                    if(a[i+1]!=0)printf(" ");
                    else break;
                }
                printf("\n");
                printf("B=>");
                if(b[0]!=0)printf("   ");
                for(i=0;;i++){
                    if(b[i]!=0)printf("%d",b[i]);
                    if(b[i+1]!=0)printf(" ");
                    else break;
                }
                printf("\n");
                printf("C=>");
                if(c[0]!=0)printf("   ");
                for(i=0;;i++){
                    if(c[i]!=0)printf("%d",c[i]);
                    if(c[i+1]!=0)printf(" ");
                    else break;
                }
                printf("\n\n");
                x++;
            }
        }
        
    }
    return 0;
    
}
