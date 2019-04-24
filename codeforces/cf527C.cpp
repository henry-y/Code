#include <cstdio>
#include <algorithm>
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
#define int long long
int n,w,h;
const int N = 200010;
struct tree {
	int l,r,sum,lm,rm,len,tag;
}t1[N<<2],t2[N<<2];
void pushup1(int rt){
	if(t1[lc].sum==t1[lc].len)
		t1[rt].lm=t1[lc].sum+t1[rc].lm;
	else t1[rt].lm=t1[lc].lm;
	if(t1[rc].sum==t1[rc].len)
		t1[rt].rm=t1[rc].sum+t1[lc].rm;
	else t1[rt].rm=t1[rc].rm;
	t1[rt].sum=max(t1[lc].sum,t1[rc].sum);
	t1[rt].sum=max(t1[rt].sum,t1[lc].rm+t1[rc].lm);
}
void pushup2(int rt){
	if(t2[lc].sum==t2[lc].len)
		t2[rt].lm=t2[lc].sum+t2[rc].lm;
	else t2[rt].lm=t2[lc].lm;
	if(t2[rc].sum==t2[rc].len)
		t2[rt].rm=t2[rc].sum+t2[lc].rm;
	else t2[rt].rm=t2[rc].rm;
	t2[rt].sum=max(t2[lc].sum,t2[rc].sum);
	t2[rt].sum=max(t2[rt].sum,t2[lc].rm+t2[rc].lm);
}
void build1(int l,int r,int rt){
	t1[rt].l=l;t1[rt].r=r;
	t1[rt].len=t1[rt].sum=t1[rt].rm=t1[rt].lm=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build1(l,mid,lc);
	build1(mid+1,r,rc);
}
void build2(int l,int r,int rt){
	t2[rt].l=l;t2[rt].r=r;
	t2[rt].len=t2[rt].sum=t2[rt].rm=t2[rt].lm=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build2(l,mid,lc);
	build2(mid+1,r,rc);
}
void upd1(int L,int rt){
	int l=t1[rt].l,r=t1[rt].r,mid=(l+r)>>1;
	if(l==L&&r==L){
		t1[rt].sum=t1[rt].lm=t1[rt].rm=0;
		return;
	}
	if(L<=mid)upd1(L,lc);
	else upd1(L,rc);
	pushup1(rt);
}
void upd2(int L,int rt){
	int l=t2[rt].l,r=t2[rt].r,mid=(l+r)>>1;
	if(l==L&&r==L){
		t2[rt].sum=t2[rt].lm=t2[rt].rm=0;
		return;
	}
	if(L<=mid)upd2(L,lc);
	else upd2(L,rc);
	pushup2(rt);
}
main(){
	scanf("%lld%lld%lld",&w,&h,&n);
	build1(1,w-1,1);
	build2(1,h-1,1);
	for(int i=1;i<=n;i++){
		char ch[10];int x;
		scanf("%s%lld",ch,&x);
		if(ch[0]=='H')upd2(x,1);
		else upd1(x,1);
		int ans=(t1[1].sum+1)*(t2[1].sum+1);
		printf("%lld\n",ans);
	}
	return 0;
} 
