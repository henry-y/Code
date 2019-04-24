#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define N 1010
#define inf 0x3f3f3f3f

ll t[ N ] , w[ N ] , f[ N ] ;
int n , m ;

bool check( int x ) {
	for( int i = 1 ; i <= m ; i ++ ) f[ i ] = -inf ;
	for( int i = 1 ; i <= n ; i ++ ) {
		ll v = t[ i ] - w[ i ] * x ;
		for( int j = m ; j >= 0 ; j -- ) {
			if( f[ j ] == -inf ) continue ;
			int k = j + w[ i ] ;
			if( k > m ) k = m ;
			f[ k ] = max( f[ k ] , f[ j ] + v ) ;
		}
	}
	return f[ m ] >= 0 ;
}

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%lld%lld" , &w[ i ] , &t[ i ] ) ;
		t[ i ] *= 1000 ;
	}
	int ans = 0 , l = 0 , r = 1e7 ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if( check( mid ) ) l = mid + 1 , ans = mid ;
		else r = mid - 1 ;
	}
	printf( "%d\n" , ans ) ;
} 
