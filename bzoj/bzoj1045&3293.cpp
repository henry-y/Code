#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define N 1000100

int n ;
ll a[ N ] , c[ N ] , sum = 0 , ans = 0 ;

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%lld" , &a[ i ] ) ;
		sum += a[ i ] ;
	}
	ll m = sum / n ;
	for( int i = 1 ;  i <= n ; i ++ ) {
		c[ i ] = c[ i - 1 ] + a[ i ] - m ;
	}
	sort( c + 1 , c + n + 1 ) ;
	ll t = c[ n & 1 ? ( n + 1 ) >> 1 : n >> 1 ] ;
	for( int i = 1 ; i <= n ; i ++ ) {
		ans += abs( c[ i ] - t ) ;
	}
	printf( "%lld\n" , ans ) ;
	return 0 ;
} 
