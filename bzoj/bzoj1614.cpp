#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,p,k,head[100000],cnt;
struct node {int to,nxt,v;}e[100000];
void ins(int u,int v,int w){
	e[++cnt].to=v;e[cnt].nxt=head[u];e[cnt].v=w;head[u]=cnt;
	e[++cnt].to=u;e[cnt].nxt=head[v];e[cnt].v=w;head[v]=cnt;
}
int d[100000],q[1000000],vis[100000];
#define inf (1<<30)
bool spfa(int x){
	for(int i=1;i<=n;i++)d[i]=inf;
	memset(vis,0,sizeof(vis));
	int l=1,r=2;
	d[1]=0;q[l]=1;vis[1]=1;
	while(l<r){
		int u=q[l++];
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(d[v]>d[u]+(e[i].v>x)){
				d[v]=d[u]+(e[i].v>x);
				if(!vis[v])vis[v]=1,q[r++]=v;
			}
		}
		vis[u]=0;
	}
	return d[n]<=k;
}
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=p;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ins(x,y,z);
	}
	int l=0,r=1000000,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(spfa(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
