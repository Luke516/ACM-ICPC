#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s[21000];
    int n,i,max=0,ans=0;
    int val[30];
    
    scanf("%s",s);
    scanf("%d",&n);
    for(i=0;i<26;i++){
        scanf("%d",&val[i]);
        if(val[i]>max)max=val[i];
    }
    for(i=0;i<strlen(s);i++){
        ans+=(i+1)*(val[s[i]-'a']);
    }
    for(i=strlen(s);i<strlen(s)+n;i++){
        ans+=(i+1)*max;
    }

    printf("%d\n",ans);
    
   return 0;
}
