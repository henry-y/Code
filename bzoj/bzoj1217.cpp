#include <bits/stdc++.h>
using namespace std;
#define N 5000
int n;
struct edge{int to,nxt;}e[N];
struct node{
	int dep,id,fa;
	bool operator < (const node &x) const {
		return dep<x.dep;
	}
}a[N];
int head[N],cnt=0,ans=0;
bool vis[N];
void ins(int u,int v){
	e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;
	e[++cnt].to=u;e[cnt].nxt=head[v];head[v]=cnt;
}
void dfs(int x,int f,int dep){
	a[x].fa=f;
	a[x].id=x;
	a[x].dep=dep;
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].to==f)continue;
		dfs(e[i].to,x,dep+1);
	}
}
priority_queue<node>q;
void dfs1(int x,int dep){
	if(dep>2)return;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		dfs1(e[i].to,dep+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x;
		scanf("%d",&x);
		ins(x,i+1);
	}
	dfs(1,1,1);
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
	while(!q.empty()){
		node t=q.top();q.pop();
		if(vis[t.id])continue; 
		int f=a[t.fa].fa;
		ans++;
		dfs1(f,0);
	}
	printf("%d\n",ans);
} 
