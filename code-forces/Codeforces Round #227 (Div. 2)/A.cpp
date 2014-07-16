#include <stdio.h>

int main()
{
    int s1,s2,t1,t2,p1,p2;
    scanf("%d:%d",&s1,&s2);
    scanf("%d:%d",&t1,&t2);
    p1=s1-t1;
    p2=s2-t2;
    if(p2<0){
        p2+=60;
        p1--;
    }
    if(p1<0){
        p1+=24;
    }
    printf("%02d:%02d",p1,p2);
    return 0;
}
