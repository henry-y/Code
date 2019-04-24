#include <bits/stdc++.h>
using namespace std;
#define N 300010
struct edge {
	int to,nxt;
}e[N];
int n,k;
int cnt,head[N];
int fa[N],dep[N],siz[N],top[N],d[N];
void ins(int u,int v){
	e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;
	e[++cnt].to=u;e[cnt].nxt=head[v];head[v]=cnt;
}
void dfs1(int x,int f,int D){
	fa[x]=f;
	dep[x]=D;
	siz[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].to==fa[x])continue;
		dfs1(e[i].to,x,D+1); 
		siz[x]+=siz[e[i].to];
	}
}
void dfs2(int x,int topf){
	top[x]=topf;
	int k=0;
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].to==fa[x])continue;
		if(siz[e[i].to]>siz[k])k=e[i].to;
	}
	if(!k)return;
	dfs2(k,topf);
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].to==fa[x])continue;
		if(e[i].to==k)continue;
		dfs2(e[i].to,e[i].to);
	}
}
int ans=0;
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x; 
}
void dfs(int x){
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].to==fa[x])continue;
		dfs(e[i].to);
		d[x]+=d[e[i].to];
	}
	ans=max(ans,d[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);
	}
	dfs1(1,1,1);dfs2(1,1);
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		d[x]++;d[y]++;
		int l=lca(x,y);
		d[l]--;d[fa[l]]--;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
} 
