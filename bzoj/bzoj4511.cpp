#include <bits/stdc++.h>
using namespace std;
int a[100000],c[100000];
map<int,int>mp;
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=c[i-1]+a[i];
		c[i]%=7;
		if(!mp[c[i]])mp[c[i]]=i;
		else ans=max(ans,i-mp[c[i]]);
	}
	printf("%d\n",ans);
	return 0;
}
