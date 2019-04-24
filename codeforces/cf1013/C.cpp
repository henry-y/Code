#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll unsigned long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il int max(int x,int y){return x>y?x:y;}
il int min(int x,int y){return x<y?x:y;}
il int abs(int x){return x>0?x:-x;}
il void swap(int &x,int &y){int t=x;x=y;y=t;}
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
#define N 400010
int n;
int a[N];
int main(){
	in1(n);
	for(int i=1;i<=n*2;i++)in1(a[i]);
	sort(a+1,a+n*2+1);
	ll ans=(ll)(a[2*n]-a[n+1])*(ll)(a[n]-a[1]);
	for(int i=2;i<=n;i++)
		ans=min(ans,(ll)(a[n+i-1]-a[i])*(ll)(a[2*n]-a[1]));
	printf("%llu\n",ans);
	return 0;
}
/*
input
2
1 5 6 10
output
9
*/
