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
using namespace std;
/*===================Header Template=====================*/
#define N 1000010
ll q,n;
int main(){
	in2(n,q);
	for(int i=1;i<=q;i++){
		ll x,y;
		in2(x,y);
		if(n%2==0){
			if((x+y)%2==0){
				if(x%2==0){
					printf("%lld\n",(n>>1)*(x-1)+(y>>1));
				}
				else{
					printf("%lld\n",(n>>1)*(x-1)+(y>>1)+1);
				}
			}
			else{
				if(x%2==1){
					printf("%lld\n",(n*n>>1)+(n>>1)*(x-1)+(y>>1));
				}
				else{
					printf("%lld\n",(n*n>>1)+(n>>1)*(x-1)+(y>>1)+1);
				}
			}
		}
		else{
			if((x+y)%2==0){
				if(x%2==0){
					printf("%lld\n",(x>>1)*n-(n>>1)+(y>>1));
				}
				else{
					printf("%lld\n",(x>>1)*n+(y>>1)+1);
				}
			}
			else{
				if(x%2==0){
					printf("%lld\n",(n*n>>1)+1+(x>>1)*n-(n>>1)+(y>>1));
				}
				else{
					printf("%lld\n",(n*n>>1)+1+(x>>1)*n+(y>>1));
				}
			}
		}
	}
}

