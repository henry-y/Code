#include <bits/stdc++.h>
using namespace std;
#define N 2010
int n,a[N],f[N][N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)f[i][i]=a[i]*n;
	for(int len=2;len<=n;len++){
		for(int l=1;l<=n;l++){
			int r=len+l-1;
			if(r>n)break;
			f[l][r]=max(f[l][r-1]+a[r]*(n-len+1),f[l+1][r]+a[l]*(n-len+1));
		}
	}
	printf("%d\n",f[1][n]);
}
