#include <bits/stdc++.h>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il void readl(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 1000010
int n,head[N],cnt;
struct edge{
	int to,nxt;
}e[N];
struct node {
	int id,dep,fa;
	bool operator < (const node &x)const {
		return x.dep>dep;
	}
}a[N];
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
bool vis[N];
priority_queue<node>q;
int main(){
	in1(n);
	for(int i=1;i<n;i++){
		int x,y;
		in2(x,y);
		ins(x,y);
	}
	dfs(1,1,0);
	for(int i=1;i<=n;i++){
		if(a[i].dep>2)q.push(a[i]);
		else vis[i]=1;
	}
	int ans=0;
	while(!q.empty()){
		node t=q.top();q.pop();
		if(vis[t.id])continue;
		ans++;
		int f=t.fa;
		vis[t.id]=vis[f]=1;
		for(int i=head[f];i;i=e[i].nxt){
			vis[e[i].to]=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}

