#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m,cnt=0;
int X[10000],Y[10000],map[2000][2000];
struct edge {int u,v;double w;}e[10000000];
double dist(int x1,int y1,int x2,int y2) {
    return sqrt(pow((double)(x1 - x2), 2) + pow((double)(y1 - y2), 2));
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int f[1010];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&X[i],&Y[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=map[y][x]=1;
		e[++cnt].u=x;e[cnt].v=y;e[cnt].w=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(map[i][j])continue;
			e[++cnt].u=i;e[cnt].v=j;
			e[cnt].w=dist(X[i],Y[i],X[j],Y[j]);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	double ans=0;int sum=0;
	for(int i=1;i<=cnt;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u!=v){
			f[u]=v;
			ans+=e[i].w;
			sum++;
			if(sum==n-1)break;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
} 
