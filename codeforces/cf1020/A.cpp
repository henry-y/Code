#include <cstdio>
#include <cstring>
#include <algorithm>
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
ll n,k,a,b,q; 
int main(){
	in4(n,k,a,b);in1(q);
	for(int i=1;i<=q;i++){
		ll t1,t2,d1,d2,ans=0;
		in4(t1,d1,t2,d2);
		if(t1==t2)printf("%lld\n",abs(d2-d1));
		else {
			if((d2<=b&&d2>=a)||(d1<=b&&d1>=a)){
				printf("%lld\n",abs(d2-d1)+abs(t2-t1));
			}else if((d2>b&&d1<a)||(d2<a&&d1>b)){
				printf("%lld\n",abs(d2-d1)+abs(t1-t2));
			}else {
				printf("%lld\n",min(abs(d2-a),abs(d2-b))+min(abs(d1-a),abs(d1-b))+abs(t2-t1));
			}
		}
	}
	return 0;
}
