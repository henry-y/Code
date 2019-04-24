#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100010
int f[N],a[N],n,k;
struct edge{int u,v,w;}e[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);} 
int main(){
	int ans=10000000;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=i;
		ans=min(a[i],ans);
	}
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].w=e[i].w*2+a[e[i].u]+a[e[i].v]; 
	}
	sort(e+1,e+k+1,cmp);
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(cnt==n-1)break;
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			f[v]=f[u];
			ans+=e[i].w;
			cnt++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
