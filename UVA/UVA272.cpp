#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int i,count=0;
    char c;
    
    while(scanf("%c",&c)!=EOF){
        if(c=='\"'){
            if(count%2!=0)printf("\'\'");
            else printf("``");
            count++;
        }
        else printf("%c",c);
    } 
   
    return 0;
}
