#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
	int l,r,tag,mx;
}t[3000010];
void build(int l,int r,int rt){
	t[rt].l=l;t[rt].r=r;
	int mid=(l+r)>>1;
	if(l==r)return;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
}
void pushdown(int rt){
	if(t[rt].tag){
		t[rt<<1].tag+=t[rt].tag;
		t[rt<<1|1].tag+=t[rt].tag;
		t[rt<<1].mx+=t[rt].tag;
		t[rt<<1|1].mx+=t[rt].tag;
		t[rt].tag=0;
	}
}
void upd(int L,int R,int rt){
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1;
	if(L<=l&&r<=R){t[rt].tag++;t[rt].mx++;return;}
	pushdown(rt);
	if(L<=mid)upd(L,R,rt<<1);
	if(R>mid)upd(L,R,rt<<1|1);
	t[rt].mx=max(t[rt<<1].mx,t[rt<<1|1].mx);
}
int main(){
	scanf("%d",&n);
	build(1,1000000,1);
	for(int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		upd(l,r,1);
	}
	printf("%d\n",t[1].mx);
}
