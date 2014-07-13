#include <cstdio>

using namespace std;

bool check(char c){
    if( c>='a' && c<='z' )return true;  
    if( c>='A' && c<='Z' )return true;
    return false;
}

int main()
{
    char c;
    int ans=0;
    bool flag=true;
    while(scanf("%c",&c)!=EOF){
        if(flag && check(c)){
            flag=false;
            ans++;
        }
        else if(!flag && !check(c)){
            flag=true;
        }
        if(c=='\n'){
            printf("%d\n",ans);
            ans=0;
            flag=true;
        }
    }
   
    return 0;
}
