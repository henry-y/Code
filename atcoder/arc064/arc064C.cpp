#include <bits/stdc++.h>

using namespace std ;

#define N 100010
#define ll long long

int n , a[ N ] , x ;
ll ans = 0 ;

int main() {
	scanf( "%d%d" , &n , &x ) ;
	for( int i = 1 ; i <= n ; i ++ )
		scanf( "%d" , &a[ i ] ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( a[ i ] + a[ i + 1 ] > x ) {
			ans += 1ll * ( a[ i ] + a[ i + 1 ] - x ) ;
			a[ i + 1 ] -= ( a[ i ] + a[ i + 1 ] - x ) ;
		}
	}
	printf( "%lld\n" , ans ) ;
	return 0 ;
}
