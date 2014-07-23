#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int ad[50][50];
int num[50];
bool flag[50],select[50];

int trans(char c){
    return (int)(c-'A');
}

void find2(int no){
	int i,x;
    queue<int>q ;
    q.push(no);
    while(!q.empty()){
        x=q.front(); q.pop();
        for(i=0;i<30;i++){
            if(ad[x][i]==1 && !select[i]){
                select[i]=true;
                q.push(i);
            }
        }
    }
    return;
}

void find(){
	int i,acorn=0,tree=0;
    for(i=0;i<30;i++){
        if(!select[i] && flag[i] && num[i]==0){
            select[i]=true;
            acorn++;
        }
        else if(flag[i] && !select[i]){
            select[i]=true;
            find2(i);
            tree++;
        }
    }
    printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
    return;
}

int main()
{
    int N,a,b,i;
    char A,B,c;

    scanf("%d",&N);
    while(N--){
    	memset(flag,false,sizeof(flag));
    	memset(select,false,sizeof(select));
    	memset(ad,0,sizeof(ad));
    	memset(num,0,sizeof(num));
        for(;;){
            scanf(" %c",&c);
            if(c=='('){
                scanf("%c,%c)",&A,&B);
                //printf("%c,%c\n",A,B);
                a=trans(A); b=trans(B);
                ad[a][b]=1; ad[b][a]=1;
                num[a]++; num[b]++;
            }
            else{
                for(;;){
                    scanf("%c",&c);
                    if(c=='\n')break;
                }
                break;
            }  
        }
        for(;;){
            scanf("%c",&A);
            a=trans(A);
            flag[a]=true;
            if(scanf("%c",&c)==EOF)break;
            if(c=='\n')break;
        }
        find();
    }
    return 0;
}
