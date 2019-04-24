#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define inf 0x3f3f3f3f 
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il void readl(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 100010
int n;
ll X;
ll x[N];
int main(){
	int i;
	ll ans=0;
	read(n);
	readl(X);
	for(i=1;i<=n;i++)readl(x[i]);
	sort(x+1,x+n+1);
	if(n==1){
		printf("%lld",abs(x[1]-X));
		return 0;
	}
	if(X>=x[n]){
		ans=X-x[n];
		for(int j=n-1;j>=1;j--) {
			ans=__gcd(ans,x[j+1]-x[j]);
		}
		printf("%lld",ans);
	} else {
		if(X<=x[1]){
			ans=x[1]-X;
			for(int j=2;j<=n;j++)ans=__gcd(ans,x[j]-x[j-1]);
			printf("%lld",ans);
		} else {
			for(i=1;i<=n;i++)if(x[i]<=X&&x[i+1]>=X) break;
			ans=X-x[i];
			ans=__gcd(ans,x[i+1]-X);
			for(int j=i-1;j>=1;j--)ans=__gcd(ans,x[j+1]-x[j]);
			for(int j=i+1;j<=n;j++)ans=__gcd(ans,x[j]-x[j-1]);
			printf("%lld",ans);
		}
	}
	return 0;
}

