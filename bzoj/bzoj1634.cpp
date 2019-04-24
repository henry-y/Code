#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
int n;
struct node {int t,d;}a[100010];
bool cmp(node a,node b){
	return a.t*b.d<a.d*b.t;
}
signed main(){
	scanf("%lld",&n);
	long long ans=0,tot=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].t,&a[i].d);
		tot+=a[i].d;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		tot-=a[i].d;
		ans+=2*a[i].t*tot;
	}
	printf("%lld",ans);
	return 0;
}
