#include <bits/stdc++.h>
using namespace std;
int n,m,d,t[3000][2];
int a[3000][3000];
int f[3000][3000];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			int y;
			scanf("%d",&y);
			a[i][y]++;
		}
	}
	for(int i=1;i<=n;i++){
		f[i][m]=a[i][m];
		if(f[i][m]>t[m][0]){
			t[m][0]=f[i][m];
			t[m][1]=i;
		}
	}
	for(int j=m-1;j;j--){
		for(int i=1;i<=n;i++){
			f[i][j]=max(f[i][j],f[i][j+1]+a[i][j]);
			if(j<=m-d){
				if(t[j+d][1]!=i){
					f[i][j]=max(f[i][j],t[j+d][0]+a[i][j]);
				}else {
					for(int k=1;k<=n;k++){
						if(k==i)continue;
						f[i][j]=max(f[i][j],f[k][j+d]+a[i][j]);
					}
				}
			}
			if(f[i][j]>t[j][0]){
				t[j][0]=f[i][j];
				t[j][1]=i;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i][1]);
	}
	printf("%d\n",ans);
} 
