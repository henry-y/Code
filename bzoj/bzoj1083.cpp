#include <cstdio>
#include <algorithm>
using namespace std;
struct edge{int x,y,v;}e[1000000];
int n,m,cnt,f[100000];
bool cmp(edge a,edge b){
	return a.v<b.v;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[++cnt].x=x;e[cnt].y=y;e[cnt].v=v;
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	int sum=0,ans=0;
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].x),y=find(e[i].y);
		if(x!=y){
			f[x]=y;
			ans=e[i].v;
			sum++;
			if(sum==n-1)break;
		}
	}
	printf("%d %d\n",sum,ans);
	return 0;
}
