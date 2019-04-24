#include <cstdio>
using namespace std;
bool vis[500];
int len=0,ans[500];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)vis[j]=1;
	}
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			ans[++len]=i;
		}
	}
	printf("%d\n",len);
	for(int i=1;i<=len;i++)
		printf("%d ",ans[i]);
	return 0;
}
