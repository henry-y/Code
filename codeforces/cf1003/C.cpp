#include <cstdio>
#include <cstring>
#define ll long double
#define inf 1<<30
#define il inline 
il ll max(ll x,ll y){return x>y?x:y;}
il ll min(ll x,ll y){return x<y?x:y;}
il ll abs(ll x){return x>0?x:-x;}
il void swap(ll &x,ll &y){ll t=x;x=y;y=t;}
il void read(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 6000
ll a[N],c[N];
int n,k;
ll mx=0.0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)c[i]=a[i]+c[i-1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j-i+1>=k)mx=max(mx,(c[j]-c[i-1])/(j-i+1));
		}
	}
	printf("%.15Lf\n",mx);
	return 0;
}
