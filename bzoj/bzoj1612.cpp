#include <cstdio>
using namespace std;
int n,m;
int f[500][500];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=f[i][j]|(f[i][k]&f[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			t=t&(f[i][j]|f[j][i]);
		}
		ans+=t;
	}
	printf("%d\n",ans);
	return 0;
}
