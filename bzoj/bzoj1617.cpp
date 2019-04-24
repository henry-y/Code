#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[5000],f[3000],c[5000];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=c[i-1]+a[i];
	}
	memset(f,127,sizeof(f));
	f[0]=0;
	//送第i头奶牛过河时船上有j头牛 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i]=min(f[i],f[i-j]+c[j]+2*m);
		}
	}
	printf("%d\n",f[n]-m);
	return 0;
} 
