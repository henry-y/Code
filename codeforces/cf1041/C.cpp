#include <bits/stdc++.h>

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

inline void readl( ll &x ){
    x = 0 ; ll f = 1 ; char c = getchar() ;
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

#define N 300010

ll n,m,d;
ll t[ N ] , a[ N ] ;

priority_queue<ll,vector<ll>,greater<ll> >q;
map<ll,ll>ans;

int main(){
	in3(n,m,d);
	for(int i = 1;  i <=n  ; i ++ ) in1(a[i]) , t[i]=a[i] ;
	sort(t+1,t+n+1);
	ll day = 0 ;
	for(int i = 1;  i  <= n ; i ++ ) {
		ll x = t[ i ] ;
		if( !q.empty() && q.top() + d < x ) {
			ans[ x ] = ans[ q.top() ] ,q.pop() , q.push( x ) ;	
		}
		else {
			ans[ x ] = ++ day ;
			q.push( x ) ;
		}
	}
	printf("%lld\n" , day );
	for( int i = 1 ; i <= n ; i ++ )printf("%lld ",ans[a[i]]) ;
}
