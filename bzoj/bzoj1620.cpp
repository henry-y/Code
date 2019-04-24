#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10000
int n;
struct node {int l,r;}a[N];
bool cmp(node a,node b){
	return a.r<b.r;
}
bool check(int x){
	for(int i=1;i<=n;i++){
		x+=a[i].l;
		if(x>a[i].r)return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=100000000,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
