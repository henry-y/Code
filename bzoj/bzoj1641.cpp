#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,t,f[1000][1000];
int main(){
	scanf("%d%d%d",&n,&m,&t);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=z;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
			}
		}
	}
	for(int i=1;i<=t;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(f[a][b]!=0x3f3f3f3f)printf("%d\n",f[a][b]);
		else puts("-1");
	}
	return 0;
}
