#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int d[100000],d1[100000],q[1000000],n,m,s,a[100000],b[100000],c[100000];
bool vis[100000];
int cnt,head[500000];
struct edge{int to,nxt,v;}e[500000];
void ins(int u,int v,int w){
	e[++cnt].to=v;e[cnt].nxt=head[u];e[cnt].v=w;head[u]=cnt;
}
void spfa(){
	memset(d,127,sizeof(d));
	memset(vis,0,sizeof(vis));
	int l=1,r=2;
	d[s]=0;vis[s]=1;q[l]=s;
	while(l<r){
		int u=q[l++];
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(d[v]>d[u]+e[i].v){
				d[v]=d[u]+e[i].v;
				if(!vis[v])vis[v]=1,q[r++]=v;
			}
		}
		vis[u]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		ins(a[i],b[i],c[i]);
	}
	spfa();
	for(int i=1;i<=n;i++){
		d1[i]=d[i];
	}
	memset(head,0,sizeof(head));
	cnt=0;
	for(int i=1;i<=m;i++){
		ins(b[i],a[i],c[i]);
	}
	spfa();
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,d[i]+d1[i]);
	}
	printf("%d\n",ans);
	return 0;
}
