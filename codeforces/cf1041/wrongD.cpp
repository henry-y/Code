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

#define N 200010

struct node {
	ll l , r  ;
}a[ N ] ;

ll n , h ;
ll sum[ N ];

bool check( int l ,int r ) {
	return sum[ r ] - sum[ l ] ;
}

int main(){
	in2( n , h );
	for( int i = 1 ; i <= n ; i ++ ) {
		in2( a[ i ].l , a[ i ].r ) ;
	}
	for( int i = 2 ; i <= n ; i ++ ) {
		sum[i]=a[i].l-a[i-1].r+sum[ i - 1 ];
	}
	ll Ans = 0 ;
	sum[ n + 1 ] = 2e9 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		ll l = i  ,r = n+1 ;
		while( l < r ) {
			ll mid = ( l + r ) >> 1 ;
			if( check( i , mid ) < h ) {
				l = mid + 1 ;
			}else r = mid  ;
		}
		Ans = max(h + a[ l - 1 ].r - a[ i ].l - check( i , l-1 ), Ans ) ; 
	}
	printf("%lld\n",Ans);
}
