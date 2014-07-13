#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

char s[10000], c[100];
int num[50];
vector<int> v[50];
map<char,int>m;
int ans[50],cur=0,n=0;
bool flag;

void find(int x)
{
	int z;
	unsigned int i,j;
	if(x==n){
		flag=1;
		for(i=0;i<n;i++){
			printf("%c",c[ans[i]]);
			if(i!=n-1)printf(" ");
		}
		printf("\n");
		return;
	}
	for(i=0;i<30;i++){
		if(num[i]==0){
			ans[x]=i;
			num[i]+=100;
			for(j=0;j<v[i].size();j++){
				z=v[i][j];
				num[z]--;
			}
			find(x+1);
			for(j=0;j<v[i].size();j++){
				z=v[i][j];
				num[z]++;
			}
			num[i]-=100;
		}
	}
	return;
}

int main() {
	unsigned int N = 0 ,i, j;
	int a,b,x;
	scanf("%d", &N);
	gets(s);
	for (i = 0; i < N; i++) {
		flag=0;
		memset(num,100,sizeof(num));
		n = 0;
		cur=0;
		gets(s);
		gets(s);
		for (j = 0; j < strlen(s); j++) {
			if (s[j] != ' ') {
				x=(int)s[j]-65;
				m[s[j]]=x;
				c[x]=s[j];
				num[x]=0;
				n++;
			}
		}
		gets(s);
		for (j = 0; j < strlen(s); j++) {
			if (s[j] == '<') {
				a=m[s[j-1]]; b=m[s[j+1]];
				v[a].push_back(b);
				num[b]++;
				j+=3;
			}
		}
		find(0);
		if(flag==0)printf("NO\n");
		if(i!=N-1)printf("\n");
	}
	return 0;
}
