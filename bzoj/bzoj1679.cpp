#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10100];
int main(){
	int n;
	scanf("%d",&n);
	ll sum=0,ans=0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i];
		ans+=a[i]*i-sum;
	}
	printf("%lld\n",ans*2);
}
