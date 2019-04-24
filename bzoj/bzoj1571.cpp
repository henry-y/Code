#include <bits/stdc++.h>

using namespace std;

#define N 10010

int t,s,n;
int f[N][100],g[N],l[N];
int vis[N][100];
//f[i][j]表示is能力值为j的最优解 
//vis[i][j]表示上完课时间为i，能力值为j 时，最晚开始的时间 
//l[i]表示能力值为i，最小的滑雪时间是多少 
//g[i]表示第is的最优解 

int main(){
	scanf("%d%d%d",&t,&s,&n);
	for(int i=1;i<=s;i++){
		int m,l,a;
		scanf("%d%d%d",&m,&l,&a);
		vis[m+l-1][a]=max(m,vis[m+l-1][a]);
	}
	memset(l,0x3f,sizeof(l));
	for(int i=1;i<=n;i++){
		int c,d;
		scanf("%d%d",&c,&d);
		for(int j=c;j<=100;j++){
			l[j]=min(l[j],d);
		}
	}
	memset(f,128,sizeof(f));
	f[0][1]=0;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=100;j++){
			f[i][j]=f[i-1][j];
			if(vis[i-1][j])f[i][j]=max(f[i][j],g[vis[i-1][j]]);
			if(i-l[j]>=0)f[i][j]=max(f[i][j],f[i-l[j]][j]+1);
			g[i]=max(g[i],f[i][j]);
		}
	}
	printf("%d\n",g[t]);
	return 0;
}
