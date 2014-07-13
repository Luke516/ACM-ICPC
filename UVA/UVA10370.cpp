#include <stdio.h>

int compare(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int main()
{
    int n,num,i,j,sum=0,data[10000]={0};
    double ave,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        for(j=0;j<num;j++){
            scanf("%d",&data[j]);
            sum+=data[j];
        }
        ave=(double)sum/num;
        qsort(data,num,sizeof(int),compare);
        for(j=0;j<num;j++){
            if(data[j]<=ave){
                break;
            }
            else ans++;
        }
        printf("%.3lf\%\n",(ans/num)*100);
        ans=0;
        sum=0;
    }
    return 0;
}
