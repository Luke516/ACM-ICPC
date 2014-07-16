#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char *b[100001],c[100001];
    int i,num=0;
    scanf("%s",c);
    for(i=0;i<strlen(c);i++){
        sscanf(c,"%1s",&b[i]);
        if(*b[i]=='0'){
            strcat(b[i-1],b[i]);
        }
        else num++;
    }
    return 0;
}
