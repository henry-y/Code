#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int inf = 0x7fffffff;
const int N = 500;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int q[1000000][3];
int a[N][N],n;
bool vis[N][N];
struct node{int x,y,t;}k[100000];
bool cmp(node a,node b){return a.t<b.t;}
void bfs(){
	int l=1,r=2;
	vis[0][0]=1;
	q[l][0]=0,q[l][1]=0,q[l][2]=0;
	while(l<r){
		int x=q[l][0],y=q[l][1],t=q[l++][2];
//		printf("%d %d %d\n",x,y,t);
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(vis[nx][ny])continue;
			if(nx<0||ny<0)continue;
			if(a[nx][ny]>t+1){
				q[r][0]=nx,q[r][1]=ny,q[r++][2]=t+1;
				vis[nx][ny]=1;
			}
			if(a[nx][ny]==inf){printf("%d",t+1);exit(0);}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			a[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		a[x][y]=min(a[x][y],t);
		for(int j=0;j<4;j++){
			int nx=x+dx[j],ny=y+dy[j];
			a[nx][ny]=min(a[nx][ny],t);
		}
	}
	bfs();
	puts("-1");
	return 0;
} 
