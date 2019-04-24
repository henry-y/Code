#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) readl(a)
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
map<int,int>mp;
ll n,m,a[N],ans=0;
ll c[N];
int main(){
	in2(n,m);
	for(int i=1;i<=n;i++)in1(a[i]);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i],c[i]%=m,mp[c[i]]++;
	ll ans=mp[0];
	if(mp[0]>1)ans+=1ll*mp[0]*(mp[0]-1)/2;
	mp[0]=0;
	for(int i=1;i<=n;i++)
		if(mp[c[i]])
			ans+=1ll*mp[c[i]]*(mp[c[i]]-1)/2,mp[c[i]]=0; 
	printf("%lld\n",ans);
	return 0;
}
