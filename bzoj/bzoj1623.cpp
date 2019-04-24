#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,d,l,a[50010],vis[50010];
int main(){
	scanf("%d%d%d%d",&n,&m,&d,&l);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=1,ans=0;
	sort(a+1,a+n+1);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if((a[i]-vis[cnt]*d)>=l){
			vis[cnt]++;cnt++;ans++;
		}else continue;
		if(cnt==m+1)cnt=1;
	}
	printf("%d\n",ans);
	return 0;
} 
