#include <cstdio>
using namespace std;
int n,m;
char s[1000];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		int x,y;char a,b;
		scanf("%d%d %c %c",&x,&y,&a,&b);
		for(int j=x;j<=y;j++){
			if(s[j]==a)s[j]=b;
		}
	}
	printf("%s",s+1);
	return 0;
}
