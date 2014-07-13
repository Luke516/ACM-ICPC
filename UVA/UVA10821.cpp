#include<iostream>
#include<map>

using namespace std;

map<int,int>m;

bool exist(int key)
{
    return ( m.find(key) != m.end() );
}

int ipow(int x)
{
    int ans=1;
    while(x--){
        ans=ans*2;
    }
    return ans;
}

int find(int a,int b,int h,int start)
{
    int i;
    if(b-a+1>ipow(h)-1){
        return 0;
    }
    if(a==b){
        m[start]=a;
        return 1;
    }
    for(i=a;i<=b;i++){
        if(find(i+1,b,h-1,start*2+1)!=0){
            if(i!=a)find(a,i-1,h-1,start*2);
            break;
        }
    }
    m[start]=i;
    return 1;
}

void print(int x)
{
    printf("% d",m[x]);
    if(exist(x*2))print(x*2);
    if(exist(x*2+1))print(x*2+1);
    return;
}

int main()
{
    int n,h,t=1;
    while(scanf("%d %d",&n,&h)){
       if(n==0 && h==0)break;
       printf("Case %d:",t++);
       if(find(1,n,h,1)==0)printf(" Impossible.");
       else{
           print(1);
       }
       printf("\n");
       m.clear();
   }
   return 0;
}
