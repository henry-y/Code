#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
int n,m,a[N];
struct tree {
	int l,r,sum;bool flag;
}t[N<<2];
void build(int l,int r,int rt){
	t[rt].l=l,t[rt].r=r;
	int mid=(l+r)>>1;
	if(l==r){
		t[rt].sum=a[l];
		if(a[l]==0||a[l]==1)t[rt].flag=1;
		return;
	}
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
	t[rt].flag=t[rt<<1].flag&t[rt<<1|1].flag;
}
void upd(int L,int R,int rt){
	if(t[rt].flag)return;
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1;
	if(l==r){
		t[rt].sum=(int)sqrt(t[rt].sum);
		t[rt].flag=(t[rt].sum<=1);
		return;
	}
	if(mid>=R)upd(L,R,rt<<1);
	else if(mid<L)upd(L,R,rt<<1|1);
	else {
		upd(L,mid,rt<<1);
		upd(mid+1,R,rt<<1|1);
	}
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
	t[rt].flag=t[rt<<1].flag&t[rt<<1|1].flag;
}
int query(int L,int R,int rt){
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1;
	if(L==l&&r==R)return t[rt].sum;
	if(mid>=R)return query(L,R,rt<<1);
	else if(mid<L)return query(L,R,rt<<1|1);
	else return query(L,mid,rt<<1)+query(mid+1,R,rt<<1|1);
}
main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	build(1,n,1);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++){
		int x,l,r;
		scanf("%lld%lld%lld",&x,&l,&r);
		if(l>r)std::swap(l,r);
		if(x==1)printf("%lld\n",query(l,r,1));
		else upd(l,r,1);
	}
}
