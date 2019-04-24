#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 100010
#define ll long long
#define inf 0x3f3f3f3f 
#define il inline 
#define in1(a) read(a)
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

int n , m , a[ N ] ,b[N ];
int x ,y ;

int main(){
	int mn = inf , mx = 0 ;
	scanf( "%d%d" , &n , &m ) ;
	in2(x,y);
	for( int i = 1 ; i <= n ; i ++ ) {
		in1( a[ i ] ) ;
	}
	for( int i = 1 ; i <= m ; i ++ ) {
		in1( b[ i ] ) ;
	}
	a[ 0 ] = x ; b [ 0 ]  = y ;
	sort( a , a+ n + 1);
	sort( b , b + m + 1 ) ;
	if( a[ n ] < b[ 0 ] )puts("No War");
	else puts("War");
	return 0 ;
}
