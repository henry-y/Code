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
int cnt1[ N ] , cnt2[ N ] ;
int p1 , p2 , mx1 , mx2 , P1 , P2 , M1 , M2 ; 

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ] ) ; 
		if( i & 1 ) cnt1[ a[ i ] ] ++ ;
		else cnt2[ a[ i ] ] ++ ;
	}
	for( int i = 1 ; i <= int( 1e5 ) ; i ++ ) {
		if( cnt1[ i ] > mx1 ) {
			swap( p1 , p2 ) ;
			swap( mx1 , mx2 ) ;
			mx1 = cnt1[ i ] ;
			p1 = i ;
		}else if( cnt1[ i ] > mx2 ) {
			mx2 = cnt1[ i ] ;
			p2 = i ;
		}
		if( cnt2[ i ] > M1 ) {
			swap( P1 , P2 ) ;
			swap( M1 , M2 ) ;
			M1 = cnt2[ i ] ;
			P1 = i ;
		}else if( cnt2[ i ] > M2 ) {
			M2 = cnt2[ i ] ;
			P2 = i ;
		} 
	}
//	printf( "%d %d %d %d\n" , mx1 , mx2 , M1 , M2 ) ;
//	printf( "%d %d %d %d\n" , p1 , p2 , P1 , P2 ) ;
	if( p1 != P1 ) {
		printf( "%d\n" , n - M1 - mx1 ) ;
	}else {
		printf( "%d\n" , n - max( M1 + mx2 , M2 + mx1 ) ) ;
	}
	return 0 ;
}
