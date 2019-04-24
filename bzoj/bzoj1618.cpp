#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[100000],n,h,w[200],c[200];
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&c[i]);
	}
	memset(f,127,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=w[i];j<=h+500;j++){
			f[j]=min(f[j],f[j-w[i]]+c[i]);
		}
	}
	int ans=0x7fffffff;
	for(int i=h;i<=h+500;i++)
		ans=min(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
