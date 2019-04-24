#include <bits/stdc++.h>

using namespace std;

#define N 500010

int n,m;
int head[N],cnt;
int in[N];
bool vis[N];
struct edge {
	int to,nxt;
}e[N];

vector<int>vt[N];

void ins(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}

priority_queue<int,vector<int>,greater<int> > q;;

void topsort(int x){
	memset(vis,0,sizeof(vis));
	memset(in,0,sizeof(in));
	memset(head,0,sizeof(head));
	cnt=0;
	for(int i=1;i<=x;i++){
		int len=vt[i].size();
		for(int j=1;j<len;j++){
			ins(vt[i][j-1],vt[i][j]);
			in[vt[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!in[i])q.push(i),vis[i]=1;
	}
	while(!q.empty()){
		int u=q.top();q.pop();
		printf("%d ",u);
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			in[v]--;
			if(!in[v]&&!vis[v])q.push(v),vis[v]=1;
		}
	}
}

bool check(int x){
	memset(in,0,sizeof(in));
	memset(vis,0,sizeof(vis));
	memset(head,0,sizeof(head));
	cnt=0;
	for(int i=1;i<=x;i++){
		int len=vt[i].size();
		for(int j=1;j<len;j++){
			ins(vt[i][j-1],vt[i][j]);
			in[vt[i][j]]++;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!in[i])q.push(i),vis[i]=1,sum++;
	}
	while(!q.empty()){
		int u=q.top();q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			in[v]--;
			if(!in[v]&&!vis[v])q.push(v),vis[v]=1,sum++;
		}
	}
	return sum==n;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int num;
		scanf("%d",&num);
		int x;
		for(int j=1;j<=num;j++){
			scanf("%d",&x);
			vt[i].push_back(x);
		}
	}
	int l=1,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	topsort(ans);
	return 0;
} 
