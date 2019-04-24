#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define inf 0x3f3f3f3f 
#define il inline 
#define in1(a) readl(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)

inline void read( int &x ){
    x = 0 ; int f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) {
        if( c == '-' ) f = -1 ;
        c = getchar() ;
    }
    while( c >= '0' && c <= '9' ) {
        x = (x << 1) + (x << 3) + c - 48 ;
        c = getchar() ;
    }
    x *= f ;
}

using namespace std ;

#define N 100010

ll a,b,x,y;

int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	while(__gcd(x,y)!=1){
		ll t=__gcd(x,y);
		x/=t;y/=t;
	}
	ll ans = min( 1ll*a/x , 1ll*b/y ) ;
	printf("%lld\n",ans);
}
