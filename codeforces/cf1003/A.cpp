#include <cstdio>
#include <cstring>
#define ll int
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
il void print(ll x){if(x<0)putchar('-');x=abs(x);if(x>9)print(x/10);putchar(x%10+'0');}
il void writeln(ll x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
il void write(ll x){if(x<0)putchar('-');x=abs(x);print(x);putchar(' ');}
using namespace std;
/*===================Header Template=====================*/
#define N 1000
ll aaa[N],f[N],n,maaaxnum=0,aaans=0;
int main(){
	read(n);
	for(ll i=1;i<=n;i++){
		read(aaa[i]);f[aaa[i]]++;
		maaaxnum=max(maaaxnum,aaa[i]);
	}
	for(ll i=1;i<=maaaxnum;i++){if(f[i])aaans=max(aaans,f[i]);}
	writeln(aaans);
	return 0;
}
