#include <stdio.h>

int find(int a,int b) {
    
    while(a>0 && b>0) {
        if(a > b)a = a % b;
        else b = b % a;
    }
    if(a == 0)return b;
    else return a;
}
int main() {
    int i,n,num[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n-1;i++){
        num[i+1]=find(num[i],num[i+1]);
    }
    printf("%d",num[n-1]*n);
    return 0;
}