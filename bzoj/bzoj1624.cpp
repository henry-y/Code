#include <cstdio>
using namespace std;
int a[10010],n,m,f[110][110];
inline int min(int x,int y){return x<y?x:y;}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&f[i][j]);
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int ans=0,last=1;
	for(int i=1;i<=n;i++){
		ans+=f[last][a[i]];
		last=a[i];
	}
	printf("%d\n",ans);
	return 0;
} 
