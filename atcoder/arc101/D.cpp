#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define inf 1<<30
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
#define lowbit(x) x&-x
int c[N*10];
int n,a[N],s[N*10];
void add(int x){
	for(int i=x;i<=2*N;i+=lowbit(i))c[i]++;
}
ll query(int x){
	ll sum=0;
	for(int i=x;i>0;i-=lowbit(i))sum+=c[i];
	return sum;
}
bool check(int x){
	for(int i=1;i<=2*N;i++)c[i]=0;
	s[0]=0;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+(a[i]>=x?1:-1);
	ll sum=0;
	for(int i=0;i<=n;i++){
		sum+=query(s[i]+N);
		add(s[i]+N);
	}
	return sum>=1ll*n*(n+1)/4;
}
int main(){
	in1(n);
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		in1(a[i]);
		r=max(r,a[i]);
	}
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
}
