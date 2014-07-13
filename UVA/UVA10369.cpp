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

st dis[200010];
int root[505];

int compare(const void *a,const void *b)
{
    st *aa=(st *)a;
    st *bb=(st *)b;
    float dis=aa->dis-bb->dis;
    if(dis>0)return 1;
    else if(dis<0)return -1;
    else return 0;
}

int find(int x)
{
    if(root[x]==x)return x;
    else return root[x]=find(root[x]);
}

int main()
{
    double data[505][2],ans[1000],x,y;
    int cur,scale[505],i,j,N,n,m,a,b,count;
    scanf("%d",&N);
    while(N--){
        cur=0; count=0;
        scanf("%d %d",&m,&n);
        for(i=0;i<n;i++){
           scanf("%lf %lf",&data[i][0],&data[i][1]);
           root[i]=i;
           scale[i]=1;
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
        for(i=0;i<cur;i++){
            a=dis[i].a;
            b=dis[i].b;
            root[a]=find(a);
            root[b]=find(b);
            if(root[a]!=root[b]){
                scale[root[a]]+=scale[root[b]];
                root[root[b]]=root[a];
                root[b]=root[a];
                ans[count++]=dis[i].dis;
                if(scale[root[a]]==n){
                    break;
                }
            }
        }
        if(count<m)printf("0.00\n");
        else printf("%.2lf\n",ans[count-m]);
    }
    return 0;
}
