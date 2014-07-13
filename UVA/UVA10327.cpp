#include <stdio.h>

main()
{
    int i,j,ary[1000],n,ans=0,tmp;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&ary[i]);
        }
       for(i=n-1;i>0;i--){
          for(j=0;j<i;j++){ 
              if(ary[j]>ary[j+1]){
              ans++;
              tmp=ary[j]; 
              ary[j]=ary[j+1]; 
              ary[j+1]=tmp;
              }      
            }
        }
        printf("Minimum exchange operations : %d\n",ans);
        ans=0;
    }
    return 0;
}






#include <stdio.h>

main()
{
    int i,j,ary[500000],n,ans=0;
    while(scanf("%d",&n)!=EOF){
        if(n!=0){
        for(i=0;i<n;i++){
            scanf("%d",&ary[i]);
            for(j=0;j<=i;j++){
                if(ary[j]>ary[i])ans++;
            }
        }
        printf("Minimum exchange operations : %d\n",ans);
        ans=0;
        }
    }
    return 0;
}