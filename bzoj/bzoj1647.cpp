#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[20][20];
int vis[20][20],t[20];
int now[20][20];

const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};

bool check(int x,int y){
	if(x<1||y<1||x>n||y>m)return 0;
	return 1;
}

#define inf 0x3f3f3f3f
int tot=inf,sum;
int ans[20][20];

void find(){
	for(int x=2;x<=n;x++){
		for(int y=1;y<=m;y++){
			if(vis[x-1][y]){
				for(int i=0;i<4;i++){
					int nx=x+dx[i],ny=y+dy[i];
					if(check(nx,ny))vis[nx][ny]^=1;
				}
				vis[x][y]^=1;
				now[x][y]=1;
				sum++;
				if(sum>tot)return;
			}else now[x][y]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j])return;
		}
	}
	if(sum>=tot)return;
	tot=sum;
	memcpy(ans,now,sizeof(ans));
	return;
}

void dfs(int x){
	if(x==m+1){
		memcpy(vis,a,sizeof(vis));
		memset(now,0,sizeof(now));
		sum=0;
		for(int i=1;i<=m;i++){
			if(t[i]){
				sum++;
				now[1][i]=1;
				vis[1][i]^=1;
				vis[2][i]^=1;
				if(i+1<=m)vis[1][i+1]^=1;
				if(i-1>0)vis[1][i-1]^=1;
			}else now[1][i]=0;
		}
		find();
		return;
	}
	t[x]=0;dfs(x+1);
	t[x]=1;dfs(x+1);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1);
	if(tot!=inf){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",ans[i][j]);
			}
			putchar('\n');
		}
		return 0;
	}
	return puts("IMPOSSIBLE"),0;
}
