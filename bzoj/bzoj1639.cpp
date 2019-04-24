#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010];
bool check(int x){
	int sum=0,tot=1;
	for(int i=1;i<=n;i++){
		if(a[i]>x)return 0;
		if(sum+a[i]>x)tot++,sum=a[i];
		else sum+=a[i];
	}
	if(tot>m)return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	int ans=0,l=1<<30,r=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l=min(l,a[i]); 
		r+=a[i];
	}
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
} 
