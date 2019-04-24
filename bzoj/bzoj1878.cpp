#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

#define il inline
#define ri register

namespace zdy{
#define ll int
#define pob (fwrite(fob::b,sizeof(char),fob::f-fob::b,stdout),fob::f=fob::b,0)
#define pc(x) (*(fob::f++)=(x),(fob::f==fob::g)?pob:0)
#define gc ((*fib::f)?(*(fib ::f++)):(fgets(fib::b,sizeof(fib::b),stdin)?(fib::f=fib::b,*(fib::f++)):-1))
namespace fib{char b[300000]= {},*f=b;}inline void in(ll &x){x=0;char c;bool f=0;while((c=gc)>'9'||c<'0')if(c=='-')f=!f;x=c-48;while((c=gc)<='9'&&c>='0')x=x*10+c-48;if(f)x=-x;}namespace fob{char b[300000]= {},*f=b,*g=b+300000-2;}struct foce{~foce(){pob;fflush(stdout);}} _foce;namespace ib{char b[100];}inline void out(ll x){if(x==0){pc(48);return;}if(x<0){pc('-');x=-x;}char *s=ib::b;while(x) *(++s)=x%10,x/=10;while(s!=ib::b) pc((*(s--))+48);}inline void outn(ll x){out(x);pc('\n');}
}using namespace zdy;

int n,m,a[50010],pre[50010],p[1000010];
int block,num,l[50010],r[50010],belong[50010],sum[50010];

il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}

il void build(){
	block=sqrt(sqrt(n)*log(n));
	num=n/block;
	if(n%block)num++;
	for(ri int i=1;i<=num;i++){
		l[i]=block*(i-1)+1;
		r[i]=block*i;
	}
	r[num]=n;
	for(ri int i=1;i<=n;i++){
		belong[i]=(i-1)/block+1;
		sum[i]=pre[i];
	}
	for(ri int i=1;i<=num;i++){
		sort(sum+l[i],sum+r[i]+1);
	}
}

il int find(int L,int R,int x){
	while(L<=R){
		int mid=(L+R)>>1;
		if(sum[mid]<x)L=mid+1;
		else R=mid-1;
	}
	return L;
}

il int query(int L,int R){
	int ans=0;
	if(belong[L]==belong[R]){
		for(ri int i=L;i<=R;i++){
			if(pre[i]<L)ans++;
		}
		return ans;
	}
	for(ri int i=L;i<=r[belong[L]];i++){
		if(pre[i]<L)ans++;
	}
	for(ri int i=l[belong[R]];i<=R;i++){
		if(pre[i]<L)ans++;
	}
	for(ri int i=belong[L]+1;i<=belong[R]-1;i++){
		ans+=find(l[i],r[i],L)-l[i];
	}
	return ans;
}

int main(){
	in(n);
	for(ri int i=1;i<=n;i++){
		in(a[i]);
		pre[i]=p[a[i]];
		p[a[i]]=i;
	}
	in(m);
	build();
	while(m--){
		int fl,fr;
		in(fl);in(fr);
		outn(query(fl,fr));
	}
	return 0;
}
