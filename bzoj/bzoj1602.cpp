#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 50000 ;
struct edge{int to,nxt,v;}e[N<<1];
int head[N<<1],cnt;
int siz[N],sz,fa[N],dep[N],top[N],n,m,c[N];
void ins(int u,int v,int w){
    e[++cnt].nxt=head[u];e[cnt].v=w;e[cnt].to=v;head[u]=cnt;
    e[++cnt].nxt=head[v];e[cnt].v=w;e[cnt].to=u;head[v]=cnt;
}
void dfs1(int x){
	siz[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		if(fa[x]==e[i].to)continue;
		fa[e[i].to]=x;
		dep[e[i].to]=dep[x]+1;
		c[e[i].to]=c[x]+e[i].v;
		dfs1(e[i].to);
		siz[x]+=siz[e[i].to]; 
	}
}
void dfs2(int x,int topf){
	top[x]=topf;
	int k=0;
	for(int i=head[x];i;i=e[i].nxt)
		if(siz[e[i].to]>siz[k]&&dep[e[i].to]>dep[x])
			k=e[i].to;
	if(!k)return;
	dfs2(k,topf);
	for(int i=head[x];i;i=e[i].nxt)
		if(dep[e[i].to]>dep[x]&&k!=e[i].to)
			dfs2(e[i].to,e[i].to);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]]; 
	}
	if(dep[x]>dep[y])swap(x,y); 
	return x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		ins(a,b,l);
	}
	dfs1(1);dfs2(1,1);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int LCA=lca(x,y);
		printf("%d\n",c[x]+c[y]-2*c[LCA]);
	}
	return 0;
}
