#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
int f[500000];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int head[500000],h[500000];
struct edge{int to,nxt,f;}e[500000];
void ins(int u,int v){
	e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;e[cnt].f=u;
	e[++cnt].to=u;e[cnt].nxt=head[v];head[v]=cnt;e[cnt].f=v;
}
int ans[500000];
bool vis[500000];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x++;y++;
		ins(x,y);
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		x++;
		vis[x]=1;
		h[i]=x;
	}
	int tot=n-k;
	for(int i=1;i<=cnt;i++){
		if(!vis[e[i].to]&&!vis[e[i].f]){
			if(find(e[i].to)!=find(e[i].f)){
				tot--;
				f[find(e[i].to)]=find(e[i].f);
			}
		}
	}
	ans[k+1]=tot;
	for(int i=k;i;i--){
		tot++;
		vis[h[i]]=0;
		for(int x=head[h[i]];x;x=e[x].nxt){
			int u=find(e[x].f),v=find(e[x].to);
			if(!vis[e[x].to]&&u!=v){
				f[v]=u;
				tot--;
			}
		}
		ans[i]=tot;
	}
	for(int i=1;i<=k+1;i++)printf("%d\n",ans[i]);
	
}
