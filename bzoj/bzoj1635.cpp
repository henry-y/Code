#include <cstdio>
#include <algorithm>
using namespace std;
int maxh,x,d[20000],n,m,ans;
struct node {int l,r;}a[20000];
bool cmp(node a,node b){
	if(a.l==b.l)return a.r<b.r;
	else return a.l<b.l;
}
int main(){
	scanf("%d%d%d%d",&n,&x,&maxh,&m);
	for(int i=1;i<=m;i++){
		int y,b;
		scanf("%d%d",&y,&b);
		if(y>b)swap(y,b);
		a[i].l=y;a[i].r=b;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(a[i].l==a[i-1].l&&a[i].r==a[i-1].r)continue;
		d[a[i].l+1]++;d[a[i].r]--;
	}
	for(int i=1;i<=n;i++){
		ans+=d[i];
		printf("%d\n",maxh-ans);
	}
} 
