#include <cstdio>
#include <cstring>
using namespace std;
inline char idx(char c){
	if(c>='a'&&c<='z')return c;
	else return c-'A'+'a';
}
#define N 1010
int n,m;
char a[N][N],b[N];
int ans[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]);
		int len=strlen(a[i]);
		for(int j=0;j<len;j++){
			a[i][j]=idx(a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%s",b);
		int len=strlen(b);
		for(int j=0;j<len;j++){
			b[j]=idx(b[j]);
		}
		for(int j=1;j<=n;j++){
			int l=0,L=strlen(a[j]);
			for(int k=0;k<L;k++){
				if(a[j][k]==b[l])l++;
				if(l==len)break;
			}
			if(l==len)ans[j]++;
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}
