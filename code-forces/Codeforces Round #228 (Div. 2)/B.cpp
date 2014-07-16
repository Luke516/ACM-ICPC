#include <stdio.h>

int main()
{
    unsigned char c[101][101];
    int i,j,n;
    scanf("%d ",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==n-1)scanf("%c ",&c[i][j]);
            else scanf("%c",&c[i][j]);
        }
        
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(c[i][j]=='#'&&c[i][j-1]!='#'&&c[i][j+1]!='#'&&c[i+1][j]=='#'&&c[i+1][j+1]=='#'&&c[i+1][j-1]=='#'&&c[i+2][j]=='#'){
                c[i][j]='.';
                c[i+1][j]='.';
                c[i+1][j-1]='.';
                c[i+1][j+1]='.';
                c[i+2][j]='.';
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(c[i][j]=='#'){
                printf("NO");
                return 0;
            }
            //printf("%c",c[i][j]);
        }
        //printf("\n");
    }
    printf("YES");
    return 0;
    
}
