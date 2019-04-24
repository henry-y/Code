#include <bits/stdc++.h>
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
struct tree{ll l,r,sum,add;}t[N<<2];
ll a[N];
ll n,m;
void build(ll l,ll r,ll rt){
    t[rt].l=l;t[rt].r=r;
    if(l==r){t[rt].sum=a[l];return;}
    ll mid=(l+r)>>1;
    build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
    t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
}
ll ans=0;
void query(ll rt){
    ll l=t[rt].l,r=t[rt].r;
	if(t[rt].sum<m){
		ans++;
		printf("%lld %lld %lld\n",t[rt].l,t[rt].r,t[rt].sum);
	}
    if(l==r){
    	return;
	}
	query(rt<<1);
	query(rt<<1|1);
}
int main(){
    in2(n,m);
    for(int i=1;i<=n;i++)in1(a[i]);
    build(1,n,1);
    query(1);
    printf("%lld\n",ans);
    return 0 ;
}
