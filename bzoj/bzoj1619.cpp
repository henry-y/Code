#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[8]={1,-1,0,0,1,-1,1,-1};
const int dy[8]={0,0,1,-1,1,1,-1,-1};
int vis[1000][1000],a[1000][1000],n,m;
struct node {int x,y,h;}t[10000000];
void dfs(int x,int y,int c){
	if(x<1||y<1||x>n||y>m)return;
	vis[x][y]=c;
	for(int i=0;i<8;i++){
		if(a[x+dx[i]][y+dy[i]]<=a[x][y]&&!vis[x+dx[i]][y+dy[i]])dfs(x+dx[i],y+dy[i],c);
	}
}
bool cmp(node a,node b){
	return a.h>b.h;
}
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			t[++cnt].x=i;t[cnt].y=j;t[cnt].h=a[i][j];
		}
	}
	int color=0;
	sort(t+1,t+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(!vis[t[i].x][t[i].y])dfs(t[i].x,t[i].y,++color);
	}
	printf("%d\n",color);
}
