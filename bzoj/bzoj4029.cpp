#include <bits/stdc++.h>

using namespace std ;

#define ll long long
ll m = 0x3f3f3f3f ;

int main() {
	ll l , r , t , ans = 0 ;
	scanf( "%lld" , &t ) ;
	while( t -- ) {
		scanf( "%lld%lld" , &l , &r ) ;
		while( l <= r ) {
			ll x = l , cnt = 0 ;
			while( !( x % 10 ) ) x /= 10 , cnt ++ ;
			ll y = x , len = 0 , sum = ( x % 10 == 5 ? -1 : 0 );
			while( y ) y/=10 , len ++ ;
			sum += 2 * len ;
			if( m > sum ) m = sum , ans = l ;
			l += pow( 10 , cnt ) ;
		}
		printf( "%lld\n" , ans ) ;
		m = 0x3f3f3f3f ;
	}
} 
