#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[10000],f[100000];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i];j--){
			f[j]=max(f[j],f[j-a[i]]+a[i]);
		}
		if(f[m]==m){printf("%d\n",m);return 0;}
	}
	printf("%d\n",f[m]);
	return 0;
}
