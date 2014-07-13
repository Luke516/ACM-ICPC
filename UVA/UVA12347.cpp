#include <map>
#include <iostream>
#include <cstdio>

using namespace std;

map<int,int>BST;

bool exist(int key)
{
    return ( BST.find(key) != BST.end() );
}

void find(int x)
{
    if(exist(x*2)==true)find(2*x);
    if(exist(x*2+1)==true)find(2*x+1);
    printf("%d\n",BST[x]);
    return;
}

int main()
{
    int data,cur;
    scanf("%d",&data);
    BST[1]=data;
    while(scanf("%d",&data)!=EOF){
        cur=1;
        for(;;){
            if(data>BST[cur]){
                if(exist(cur*2+1)==false){
                    BST[cur*2+1]=data;
                    break;
                }
                else{
                    cur=cur*2+1;
                }
            }
            else{
                if(exist(cur*2)==false){
                    BST[cur*2]=data;
                    break;
                }
                else{
                    cur=cur*2;
                }
            }
        }
    }
    find(1);
    return 0;
}
