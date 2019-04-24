#include <bits/stdc++.h>
using namespace std;
int last[1000000];
int n,ans=0;
struct node {int x,d;}a[1000000];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].d,&a[i].x);
		if(!a[i].d)a[i].d=-1;
	}
	sort(a+1,a+n+1,cmp);
	int now=0;
	for(int i=1;i<=n;i++){
		now+=a[i].d;
		if(!last[now])last[now]=a[i+1].x;
		else ans=max(ans,a[i].x-last[now]);
	}
	printf("%d\n",ans);
	return 0;
}
