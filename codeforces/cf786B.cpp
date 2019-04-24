#include <bits/stdc++.h>
using namespace std;
#define N 1000100
#define int long long
#define ls ch[now][0]
#define rs ch[now][1]
int ch[N<<2][2];
int n,Q,s,cnt,head[N<<2],tot;
struct edge{int to,nxt,v;}e[N<<2];
void ins(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].v=w;
	head[u]=cnt;
}
int build1(int l,int r){
	if(l==r)return l;
	int mid=(l+r)>>1,now=++tot;
	ls=build1(l,mid);
	rs=build1(mid+1,r);
	ins(now,ls,0);
	ins(now,rs,0);
	return now;
}
int build2(int l,int r,int rt){
	if(l==r)return l;
	int mid=(l+r)>>1,now=++tot;
	ls=build2(l,mid,ch[rt][0]);
	rs=build2(mid+1,r,ch[rt][1]);
	ins(ls,now,0);
	ins(rs,now,0);
	ins(rt,now,0);
	return now;
}
int root[2],f=0;
void upd(int now,int l,int r,int L,int R,int pos,int w){
	if(L==l&&r==R){
		if(f==1)ins(pos,now,w);
		else ins(now,pos,w);
		return;
	}
	int mid=(L+R)>>1;
	if(r<=mid)upd(ls,l,r,L,mid,pos,w);
	else if(l>mid)upd(rs,l,r,mid+1,R,pos,w);
	else upd(ls,l,mid,L,mid,pos,w),upd(rs,mid+1,r,mid+1,R,pos,w);
}
int d[N],q[N<<3];
bool vis[N];
const int inf=0x3f3f3f3f3f3f3f3f;
void spfa(){
	memset(d,0x3f,sizeof(d));
	d[s]=0;q[1]=s;vis[s]=1;
	int l=1,r=2;
	while(l<r){
		int u=q[l++];vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(d[v]>d[u]+e[i].v){
				d[v]=d[u]+e[i].v;
				if(!vis[v])vis[v]=1,q[r++]=v;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==inf)printf("-1 ");
		else printf("%lld ",d[i]);
	}
}
main(){
	scanf("%lld%lld%lld",&n,&Q,&s);
	tot=n;
	root[0]=build1(1,n);
	root[1]=build2(1,n,root[0]);
	int opt,u,v,w,l,r;
	for(int i=1;i<=Q;i++){
		scanf("%lld",&opt);
		if(opt==1){
			scanf("%lld%lld%lld",&u,&v,&w);
			ins(u,v,w);
		}else if(opt==2){
			scanf("%lld%lld%lld%lld",&u,&l,&r,&w);
			f=1;
			upd(root[0],l,r,1,n,u,w);
		}else {
			scanf("%lld%lld%lld%lld",&v,&l,&r,&w);
			f=0;
			upd(root[1],l,r,1,n,v,w);
		}
	}
	spfa();
	return 0;
}
