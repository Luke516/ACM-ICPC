#include <stdio.h>
#include<math.h>

typedef struct{
    double x;
    double y;
}P;

P p[10005];

int compare(const void *a,const void *b)
{
    P *c,*d;
    c=(P*)a;d=(P*)b;
    if(c->x > d->x)return 1;
    else if(c->x < d->x)return -1;
    else return 0;
}

float find(P p[],int a,int b)
{
    if(a==b)return 10001;
    int i,j;
    double dx,dy,d1,d2,d3=10001,d;
    int r,l;
    if(b-a==1){
        dx=p[b].x-p[a].x; dy=p[b].y-p[a].y;
        return sqrt(dx*dx+dy*dy);
    }
    d1=find(p,a,(a+b)/2);
    d2=find(p,(a+b)/2,b);
    d=d1<d2?d1:d2;
    int mid=(a+b)/2;
    for(r=mid;p[r].x-p[mid].x<d;r++){
        if(r==b)break;
    }
    for(l=mid;p[mid].x-p[l].x<d;l--){
        if(l==a)break;
    }
    if(l!=r){
        for(i=l;i<=r;i++){
            for(j=i+1;j<=r;j++){
                dx=p[i].x-p[j].x; dy=p[i].y-p[j].y;
                if(sqrt(dx*dx+dy*dy)<d)d=sqrt(dx*dx+dy*dy);
            }
        }
    }
    return d;
}

int main()
{
   int i,n;
   double ans=0;
   while(scanf("%d",&n)!=EOF){
       if(n==0)return 0;
       for(i=0;i<n;i++){
           scanf("%lf %lf",&p[i].x,&p[i].y);
       }
       qsort(p,n,sizeof(P),compare);
       if(n-1!=0)ans=find(p,0,n-1);
       if(ans>10000||n==1)printf("INFINITY\n");
       else printf("%.4lf\n",ans);
   }
   return 0;
}
