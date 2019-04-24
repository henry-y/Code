#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int n,m;
struct tree{int l,r,cnt,tag;}t[N<<2];
void build(int l,int r,int rt){
	t[rt].l=l;t[rt].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
}
void pushdown(int rt){
	if(t[rt].tag){
		t[rt<<1].tag^=1;
		t[rt<<1|1].tag^=1;
		t[rt<<1].cnt=t[rt<<1].r-t[rt<<1].l+1-t[rt<<1].cnt;
		t[rt<<1|1].cnt=t[rt<<1|1].r-t[rt<<1|1].l+1-t[rt<<1|1].cnt;
		t[rt].tag=0;
	}
}
void upd(int L,int R,int rt){
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1;
	if(L<=l&&r<=R){t[rt].cnt=t[rt].r-t[rt].l+1-t[rt].cnt;t[rt].tag^=1;return;}
	pushdown(rt);
	if(L<=mid)upd(L,R,rt<<1);
	if(R>mid)upd(L,R,rt<<1|1);
	t[rt].cnt=t[rt<<1].cnt+t[rt<<1|1].cnt;
}
int query(int L,int R,int rt){
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1,ans=0;
	if(L<=l&&r<=R)return t[rt].cnt;
	pushdown(rt);
	if(L<=mid)ans+=query(L,R,rt<<1);
	if(R>mid)ans+=query(L,R,rt<<1|1);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(!opt)upd(x,y,1);
		else printf("%d\n",query(x,y,1));
	}
	return 0;
} 
