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
#define N 500010
ll n,k;
ll ans1 = 0 , ans2 = 0 , ans = 1;
int main(){
	scanf("%lld%lld",&n,&k);
	ans = (n/k)*(n/k)*(n/k);
	if(!(k%2)){
		ans2 = (n+(k/2))/k;
		ans += ans2 * ans2 * ans2;
	}
	printf("%lld\n",ans);
}
/*
a+b%k=0
b+c%k=0
a+c%k=0
2a+2b+2c%k=0
2b%k=0
2a%k=0
2c%k=0
*/




