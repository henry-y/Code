#include <bits/stdc++.h>

using namespace std ;

#define ll long long

int n , k ;
ll ans ;

int main() {
	scanf( "%d%d" , &n , &k ) ;
	int r = 0 ;
	if( n > k ) ans = 1ll * ( n - k ) * k , n = k ;
	for( int i = 1 ; i <= n ; i = r + 1 ) {
		int t = k / i ; r = k / t ;
		if( r >= n ) r = n ;
		ans = ans + 1ll * ( r - i + 1 ) * k - 1ll * ( i + r ) * ( r - i + 1 ) / 2 * t ;
	}
	printf( "%lld\n" , ans ) ;
}
