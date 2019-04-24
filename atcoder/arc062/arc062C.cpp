#include <bits/stdc++.h>

using namespace std ;

#define ll long long

int n ;
ll a = 1 , b = 1 ;

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		ll x , y ;
		scanf( "%lld%lld" , &x , &y ) ;
		ll t = max( ( a - 1 ) / x + 1 , ( b - 1 ) / y + 1 ) ;
		a = x * t ; b = y * t ;
 	}
	printf( "%lld\n" , 1ll * ( a + b ) ) ;
	return 0 ;
}
