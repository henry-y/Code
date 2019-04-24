#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,c[10000],w[10000],f[50000];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=c[i];j--){
			f[j]=max(f[j],f[j-c[i]]+w[i]);
		}
	}
	printf("%d\n",f[m]);
} 
