#include <stdio.h>

int compare(const void *a, const void *b){
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}               
      else if (c == d) {return 0;}      
      else return 1;                          
}

int main()
{
    int i,j,n,m,max=0,ans=0;
    int a[3000],b[3000],aa[3000]={0},bb[3000]={0};
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    qsort(a,n,sizeof(int),compare);
    qsort(b,m,sizeof(int),compare);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i]<=b[j]&&bb[j]==0){
                aa[i]=1;
                bb[j]=1;
                break;
            }
        }
    }
    for(i=n-1;i>=0;i--){
        if(aa[i]==0)ans++;
    }
    printf("%d",ans);
    return 0;
}
