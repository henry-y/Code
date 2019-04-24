#include <bits/stdc++.h>

using namespace std ;

#define ll long long
ll t , n , m ;

int main() {
	scanf( "%lld" , &t ) ;
	while( t -- ) {
		scanf( "%lld%lld" , &n , &m ) ;
		ll x = 1ll * n / m * ( m - 1 ) + n % m + !( n % m ) - 1 ;
		x % 2 ? puts( "0" ) : puts( "1" ) ;
	}
	return 0 ;
}
