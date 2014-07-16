#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}               
      else if (c == d) {return 0;}      
      else return 1;                        
}

int main()
{
    int cur,CurStr,piled,ans=0,n,i,box[105];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&box[i]);
    }
    qsort(box,n,sizeof(int),compare);

    while(box[0]!=1000){
        piled=0;
        cur=0;
        for(i=0;i<n;i++){
            if(box[i]!=1000){
                if(box[i]>=piled){
                    box[cur]=1000;
                    cur=i;
                    piled++;
                }
            }
            else break;
        }
        box[cur]=1000;
        ans++;
        qsort(box,n,sizeof(int),compare);
    }
    printf("%d",ans);
    return 0;
}
