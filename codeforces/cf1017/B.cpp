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
#define N 100010
/*===================Header Template=====================*/
char a[N],b[N]; 
ll ans=0;
//显然对于某一位上的数字，只有b=0才可以换出不同的数
//那么考虑对于a的不同情况
//当a=0的时候，可以匹配的是a1=1的情况，这个不用判重 
//当a=1的时候，只可以匹配a1=0&&b1=1或a1=0&&b1=0 的情况
//但是会发现当a=1的时候匹配到的a1=0 && b1=0 会被用过 用来累加答案所以不用匹配 
int main(){
	int n;
	in1(n);
	scanf("%s%s",a+1,b+1);
	int c1=0,c2=0;
	ll ans=0;
	for(int i=n;i;i--){
		if(a[i]=='1')c1++;
		if(a[i]=='0'&&b[i]=='1')c2++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]=='0'){
			if(a[i]=='0')ans+=c1;
			else ans+=c2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
