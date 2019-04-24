#include <cstdio>
#include <algorithm>
using namespace std;
int n,f[1000],cnt=0;
struct edge{int u,v,w;}e[500*500];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int w;
		scanf("%d",&w);
		e[i].u=i;e[i].v=n+1;e[i].w=w;
	}
	int w;cnt=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			if(j>i){
				e[++cnt].u=i;e[cnt].v=j;e[cnt].w=w;
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int ans=0,sum=0;
	for(int i=1;i<=n+1;i++)f[i]=i;
	for(int i=1;i<=cnt;i++){
		if(sum==n)break;
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			f[u]=v;
			ans+=e[i].w;
			sum++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
