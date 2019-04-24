#include <bits/stdc++.h>
#define N 100000
using namespace std;
int n,a[N],q;
struct tree{int l,r,min,max;}t[N<<2];
void pushup(int rt){
	t[rt].max=max(t[rt<<1].max,t[rt<<1|1].max);
	t[rt].min=min(t[rt<<1].min,t[rt<<1|1].min);
}
void build(int l,int r,int rt){
	t[rt].l=l;t[rt].r=r;
	if(l==r){
		t[rt].max=a[l];
		t[rt].min=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}
#define inf (1<<30)
int query_min(int L,int R,int rt){
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1,ans=inf;
	if(L<=l&&r<=R)return t[rt].min;
	if(L<=mid)ans=min(ans,query_min(L,R,rt<<1));
	if(R>mid)ans=min(ans,query_min(L,R,rt<<1|1));
	return ans;
}
int query_max(int L,int R,int rt){
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1,ans=0;
	if(L<=l&&r<=R)return t[rt].max;
	if(L<=mid)ans=max(ans,query_max(L,R,rt<<1));
	if(R>mid)ans=max(ans,query_max(L,R,rt<<1|1));
	return ans;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,n,1);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans1=query_min(x,y,1);
		int ans2=query_max(x,y,1);
		printf("%d\n",ans2-ans1);
	}
	return 0;
}
