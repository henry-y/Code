#include <bits/stdc++.h>

using namespace std;

int n;
long long ans=0;

int main(){
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		ans+=n/i;

	printf("%lld\n",ans);
	return 0;
}
