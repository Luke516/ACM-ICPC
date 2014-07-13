#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char c[100000];
    while(scanf("%[^\n]\n",c)!=EOF){
        for(i=0;i<strlen(c);i++){
            printf("%c",c[i]-7);
        }
        printf("\n");
    }
    return 0;
}
