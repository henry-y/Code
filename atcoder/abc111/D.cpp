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

int x[ N ] , y[ N ] , n , m ; 
int a[ 1000 ][ 1000 ] ;
char ans[ N ][ 100 ] ;
int arm[ 100 ] ;

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= 40 ; i ++ ) {
		for( int i1 = 1 ; i1 <= 1010 ; i1 ++ ) {
			for( int i2 = 1 ; i2 <= 41 ; i2 ++ ) {
				ans[ i1 ][ i2 ] = '\0' ;
			}
		}
		
	}
}
