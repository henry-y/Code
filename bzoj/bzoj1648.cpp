#include <bits/stdc++.h>

using namespace std;

#define N 100010

int n,k,m;
int tot[N],head[N],cnt,a[N];
bool vis[N];
struct edge {
	int to,nxt;
}e[N];

void ins(int u,int v){
	e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;
}

void dfs(int x){
	tot[x]++;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		if(!vis[e[i].to])dfs(e[i].to);
	}
}

int main(){
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);
	}
	for(int i=1;i<=k;i++){
		dfs(a[i]);
		for(int i=1;i<=n;i++)vis[i]=0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(tot[i]>=k)ans++;
	}
	printf("%d\n",ans);
}
