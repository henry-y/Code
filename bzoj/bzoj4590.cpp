#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[100010];
bool check(int x){
	int sum=0,tot=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum<0)sum=0;
		if(sum>=x)tot++,sum=0;
	}
	if(tot>k)return 1;
	return 0;
}
bool check1(int x){
	int sum=0,tot=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum<0)sum=0;
		if(sum>=x)tot++,sum=0;
	}
	if(tot>=k)return 1;
	return 0;
}
main(){
	scanf("%lld%lld",&n,&k);
	int tot=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>0)tot+=a[i];
	}
	int l=1,r=tot,ans=-1;
	while(l<=r){//最小 
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	if(!check1(l))return puts("-1"),0;
	printf("%lld ",l);
	l=1,r=tot,ans=0;
	while(l<=r){//最大 
		int mid=(l+r)>>1;
		if(check1(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld\n",ans);
}
