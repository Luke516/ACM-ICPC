#include <stdio.h>

int main()
{
    int zero,one;
    scanf("%d %d",&zero,&one);
    if(one<2 || one>(zero*2+2)){
        printf("-1\n");
        return 0;
    }
    one--;
    while(one>zero && one>=2 && zero>=1){
        printf("110");
        one-=2;
        zero--;
    }
    if(one==zero){
        while(one--){
            printf("10");
        }
    }
    if(zero==0){
        while(one--){
            printf("1");
        }
    }
    printf("1\n");
    return 0;
}
