#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct{
    int a;
    int b;
    double dis;
}st;

int compare(const void *a,const void *b)
{
    st *aa=(st *)a;
    st *bb=(st *)b;
    float dis=aa->dis-bb->dis;
    if(dis>0)return 1;
    else if(dis<0)return -1;
    else return 0;
}

int main()
{
    st dis[10001];
    double data[110][2],ans,x,y;
    int size,cur,root[110],i,j,N,n,start;
    scanf("%d",&N);
    while(N--){
        size=0; cur=0; ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
           scanf("%lf %lf",&data[i][0],&data[i][1]);
           root[i]=i;
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                dis[cur].a=i;
                dis[cur].b=j;
                x=data[i][0]-data[j][0];
                y=data[i][1]-data[j][1];
                dis[cur].dis=sqrt(x*x+y*y);
                cur++;
            }
        }
        qsort(dis,cur,sizeof(st),compare);
        if(n>1){
            root[dis[0].b]=root[dis[0].a];
            start=dis[0].a;
            size=2;
            ans=dis[0].dis;
        }
        else{
            size=1;
            ans=0;
        }
        for(;;){
            for(i=1;i<cur;i++){
                if(root[dis[i].a]==start && root[dis[i].b]!=start){
                    root[dis[i].b]=start;
                    ans+=dis[i].dis;
                    size++;
                    break;
                }
                else if(root[dis[i].a]!=start && root[dis[i].b]==start){
                    root[dis[i].a]=start;
                    ans+=dis[i].dis;
                    size++;
                    break;
                }
            }
            if(size==n)break;
        }
        printf("%.2lf\n",ans);
        if(N!=0)printf("\n");
    }
    return 0;
}
