#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<string,int> m;
int root[100001],scale[100001];
 
int find(int x)
{
    if(root[x]==x)return x;
    else return find(root[x]);
}

bool exist(string key)
{
    //string key(c);
    return ( m.find(key) != m.end() );
}

int main()
{
    int N,n,a,b,i,ans,cur;
    char s1[50],s2[50];
    scanf("%d",&N);
    while(N--){
        cur=1;
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s %s",s1,s2);
            if(!exist(s1)){
                root[cur]=cur;
                scale[cur]=1;
                m[s1]=cur;
                cur++;
            }
            if(!exist(s2)){
                root[cur]=cur;
                scale[cur]=1;
                m[s2]=cur;
                cur++;
            }
            a=m[s1];
            b=m[s2];
            root[a]=find(a);
            root[b]=find(b);
            if(root[a]!=root[b]){
                if(root[b]!=b)root[root[b]]=root[a];
                if(scale[root[a]]==0){
                    scale[root[a]]++;
                }
                else {
                    scale[root[a]]+=scale[root[b]];
                }
                root[b]=root[a];
            }
            printf("%d\n",scale[root[a]]);
        }
        m.clear();
    }
    return 0;
}
