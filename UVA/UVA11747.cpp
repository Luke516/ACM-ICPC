#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct edge_data{
    int a;
    int b;
    int w;
};

int ans[30000],root[1100],pass[1100],cur,ring;
edge_data node[25100];

int compare(const void *a,const void *b)
{
    edge_data *aa,*bb;
    aa=(edge_data *)a;
    bb=(edge_data *)b;
    return(aa->w - bb->w);
}


int find(int x)
{
    if(root[x]==x)return x;
    else return find(root[x]);
}

int main()
{
    int N,n,m,a,b,i,w;
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0)break;
        cur=0;
        ring=0;
         for(i=0;i<n;i++){
            root[i]=i;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&w);
            node[i].a=a;
            node[i].b=b;
            node[i].w=w;
        }
        qsort(node,m,sizeof(edge_data),compare);
        for(i=0;i<m;i++){
            a=node[i].a;
            b=node[i].b;
            w=node[i].w;
            root[a]=find(a);
            root[b]=find(b);
            if(root[a]!=root[b]){
                root[root[b]]=root[a];
                root[b]=root[a];
            }
            else{
                ans[cur]=w;
                cur++;
            }
        }
         for(i=0;i<cur;i++){
            if(i==0){
                printf("%d",ans[i]);
            }
            else if(ans[i]!=ans[i-1]){
                printf(" %d",ans[i]);
            }
        }
        if(cur==0)printf("forest");
        printf("\n");
    }
    return 0;
}
