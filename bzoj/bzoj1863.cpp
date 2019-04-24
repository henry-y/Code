#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,a[30000];
int dp[30000],f[30000];
bool check(int x){
	//f[i]表示第i个和第1个最多能冲突多少个
	//dp[i]表示第i个和第一个最少能冲突几个 
	f[1]=dp[1]=a[1];
	int t=0;
	for(int i=2;i<=n;i++){
		f[i]=min(a[i],a[1]-dp[i-1]);
		dp[i]=max(t,a[i]+a[1]+a[i-1]-f[i-1]-x);
	}
	if(!dp[n])return 1;
	return 0;
}
main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	int l=0;
	for(int i=2;i<=n;i++){
		l=max(l,a[i]+a[i-1]);
	}
	l=max(l,a[n]+a[1]);
	if(!(n%2)){
		printf("%lld\n",l);
		return 0;
	}else {
		int r=10000000,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1,ans=mid;
			else l=mid+1;
		}
		printf("%lld\n",ans);
		return 0;
	}
}
