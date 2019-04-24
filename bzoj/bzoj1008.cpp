#include <cstdio>

using namespace std;

#define mod 100003
#define ll long long

ll n,m;

ll power(ll a,ll b){
	ll ans=1ll,base=a;
	while(b){
		if(b&1ll)ans=(ans*base)%mod;
		base=(base*base)%mod;
		b>>=1ll;
	}
	return ans%mod;
}

int main(){
	scanf("%lld%lld",&m,&n);
	printf("%lld\n",(power(m,n)-(((m%mod)*power(m-1,n-1))%mod)+mod)%mod);
}
