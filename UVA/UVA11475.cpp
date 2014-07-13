#include<cstdio>
#include<cstring>

char a[100010], b[100010];
int c[100010];

void find(char *a) {
    int i, j;
    int len=strlen(a);
    c[0] = -1; j = -1;
    for(i=1;i<len;i++) {
        while(j >= 0 && a[j+1] != a[i])j = c[j];
        if(a[j+1] == a[i])
            j++;
        c[i] = j;
    }
}
int kmp(char *a, char *b) {
    find(b);
    int i, j, len;
    len = strlen(a);
    for(i = 0, j = -1; i < len; i++) {
        while(j >= 0 && b[j+1] != a[i])
            j = c[j];
        if(b[j+1] == a[i])    j++;

    }
    return j;
}
int main() {
    int i,j,len,n;
    while(scanf("%s",a)!=EOF){
        len = strlen(a);
        for(i = 0; i < len; i++)
            b[i] = a[len-i-1];
        b[len] = '\0';
        n = kmp(a,b);
        for(i = len-1; i > n; i--)
            printf("%c", b[i]);
        printf("%s\n", b);
    }
    return 0;
}
