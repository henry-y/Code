#include <bits/stdc++.h>
using namespace std;
int n,beginl,Max,c[2000];
bool f[2100][2010];
int main(){
	scanf("%d%d%d",&n,&beginl,&Max);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	f[0][beginl]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=Max;j++){
			if(f[i-1][j])f[i][j+c[i]]=1;
			if(f[i-1][j]&&j-c[i]>=0)f[i][j-c[i]]=1;
		}
	}
	int ans=-1;
	for(int i=Max;i;i--){
		if(ans!=-1)break;
		if(f[n][i])ans=i;
	}
	printf("%d\n",ans);
	return 0;
} 
