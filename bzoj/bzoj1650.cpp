#include <bits/stdc++.h>
using namespace std;
int n,a[100000],L,m;
bool check(int x){
	int tot=0,l=0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[l]<x)tot++;
		else l=i;
	}
	return tot<=m;
}
int main(){
	scanf("%d%d%d",&L,&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	a[++n]=L;
	int l=0,r=L,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
} 
