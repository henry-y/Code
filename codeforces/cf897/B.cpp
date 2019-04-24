#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
ll k,mod;
ll ans=0;
ll find(ll x){
	ll y=x;
	while(y){x=x*10+y%10;y/=10;}
	return x;
}
int main(){
	scanf("%lld%lld",&k,&mod);
	for(int i=1;i<=k;i++){
		ans+=find(i);
		ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
