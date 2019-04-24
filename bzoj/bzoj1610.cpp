#include <bits/stdc++.h> 
using namespace std;
#define N 205
int n,x[N],y[N];
double d[N*N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(x[i]==x[j])d[++cnt]=10000;
			else if(y[i]==y[j])d[++cnt]=100000;
			else d[++cnt]=(double)(y[j]-y[i])/(double)(x[j]-x[i]);
		}
	}
	int ans=0;
	sort(d+1,d+cnt+1);
	for(int i=2;i<=cnt;i++){
		if(d[i]!=d[i-1])ans++;
	}
	printf("%d\n",ans+1);
	return 0;
} 
