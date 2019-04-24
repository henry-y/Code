#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std ;

#define N 5000010
int n , sa , sb , sc ,sd , mod ;
int a[ N ] ;

int F( int x ) {
	return ( ( ( 1ll * sa * x % mod * x % mod * x % mod + 1ll * sb * x % mod * x % mod ) % mod + 1ll * sc * x % mod ) % mod + 1ll * sd % mod ) % mod ;
}

bool check( int x ) {
	int mx = 0 ; 
	for( int i = 1 ; i <= n ; i ++ ) {
		mx = std::max( mx , a[ i ] - x ) ;
		if( a[ i ] + x < mx ) return 0 ;
	}
	return 1 ;
}

int main() {
	scanf( "%d%d%d%d%d%d%d" , &n , &sa , &sb , &sc , &sd , &a[ 1 ] , &mod ) ;
	a[ 0 ] = 0 ;
	for( int i = 2 ; i <= n ; i ++ ) {
		a[ i ] = F( a[ i - 1 ] ) + F( a[ i - 2 ] ) ;
		a[ i ] = a[ i ] % mod ;
	}
	int l = 0 , r = mod , ans = mod ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if( check( mid ) ) r = mid - 1 , ans = mid ;
		else l = mid + 1 ;
	}
	printf( "%d\n" , ans ) ;
}
