#include <bits/stdc++.h>
#define lc (rt<<1)
#define rc (rt<<1|1)
using namespace std;
struct tree{
	int l,r,lm,rm,sum,len,tag;
}t[500010];
int n,m;
void build(int l,int r,int rt){
	int mid=(l+r)>>1; 
	t[rt].l=l;t[rt].r=r;
	t[rt].len=t[rt].lm=t[rt].rm=t[rt].sum=r-l+1;
	if(l==r)return;
	build(l,mid,lc);
	build(mid+1,r,rc);
}
void pushup(int rt){
	if(t[lc].len==t[lc].sum)t[rt].lm=t[lc].len+t[rc].lm;
	else t[rt].lm=t[lc].lm;
	if(t[rc].len==t[rc].sum)t[rt].rm=t[rc].len+t[lc].rm;
	else t[rt].rm=t[rc].rm;
	t[rt].sum=max(t[lc].sum,t[rc].sum);
	t[rt].sum=max(t[rt].sum,t[lc].rm+t[rc].lm);
}
void pushdown(int rt){
	if(!t[rt].tag)return;
	if(t[rt].l==t[rt].r)return;
	if(t[rt].tag==1){//全部变1 
		t[lc].lm=t[lc].rm=t[lc].sum=0;
		t[rc].lm=t[rc].rm=t[rc].sum=0;
		t[lc].tag=t[rc].tag=1;
	}
	if(t[rt].tag==2){//全部变0 
		t[lc].lm=t[lc].rm=t[lc].sum=t[lc].len;
		t[rc].lm=t[rc].rm=t[rc].sum=t[rc].len;
		t[lc].tag=t[rc].tag=2;
	}
	t[rt].tag=0;
}
void upd(int L,int R,int c,int rt){
	//c为1变1 2变0 
	pushdown(rt);
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1;
	if(L<=l&&r<=R){
		t[rt].tag=c;
		if(c==2)t[rt].sum=t[rt].lm=t[rt].rm=t[rt].len;
		else t[rt].sum=t[rt].lm=t[rt].rm=0;
		return;
	}
	if(L<=mid)upd(L,R,c,lc);
	if(R>mid)upd(L,R,c,rc);
	pushup(rt);
}
int query(int c,int rt){
	pushdown(rt);
	int l=t[rt].l,r=t[rt].r,mid=(l+r)>>1;
	if(l==r)return l;
	if(t[lc].sum>=c)return query(c,lc);
	if(t[lc].rm+t[rc].lm>=c)return mid-t[lc].rm+1;
	if(t[rc].sum>=c)return query(c,rc);
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt==1){
			if(t[1].sum>=x){
				int ans=query(x,1);
				printf("%d\n",ans);
				upd(ans,ans+x-1,1,1);
			}else puts("0");
		}else {
			scanf("%d",&y);
			upd(x,x+y-1,2,1);
		}
	}
}
