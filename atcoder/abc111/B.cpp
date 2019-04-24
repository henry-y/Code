#include <cstdio>
#include <cstring>
#include <algorithm>

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

#define N 100010

int a[ N ] , n , m ; 

bool check( int x ) {
	int  cnt = 0 ;
	int c[ 1000 ] ;
	while( x ) {
		c[ ++ cnt ] = x %10 ;
		x /= 10 ;
	}
	for( int i = 2 ; i <= cnt ; i ++ ) if( c[ i ] != c[ i - 1 ] ) return 0 ;
	return 1 ; 
}

int main() {
	scanf( "%d" , &n ) ;
	while( 1 ) {
		if( check( n ) ) break ;
		n ++ ;
	} 
	printf( "%d" , n ) ;
}
