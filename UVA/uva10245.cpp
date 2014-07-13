#include <stdio.h>
#include<math.h>

int main()
{
   int i,n,dd=200000000,dx=10000,dy=10000,j,x[10001],y[10001];
   float distance;
   while(scanf("%d",&n)!=EOF){
       if(n==0)return 0;
       for(i=0;i<n;i++){
           scanf("%d %d",&x[i],&y[i]);
        
       }
       for(i=0;i<n;i++){
           for(j=i+1;j<n;j++){
               dx=x[i]-x[j];
               dy=y[i]-y[j];
               if(dx*dx+dy*dy<dd)dd=dx*dx+dy*dy;
           }
           distance=sqrt(dd);
       }
       if(distance>10000)printf("INFINITY\n");
       else printf("%.4f\n",dd,distance);
   }
   return 0;
}
