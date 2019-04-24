#include <bits/stdc++.h>
using namespace std;
#define N 10010
int n,m,x[N],y[N],t[N];
int f[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)f[i]=1;
	int ans=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		for(int j=1;j<i;j++){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
				f[i]=max(f[i],f[j]+1);
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
}
