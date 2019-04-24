#include <bits/stdc++.h>

using namespace std ;

const int mod = 1e9 + 7 ;
const int N = 900010 ;
#define ll long long 

int n , m , k ;
ll fac[ N ] , ifac[ N ] , p[ N ] ; 

ll mul( ll x , ll  y ) {
	return ( 1ll * x * y ) % mod ;
}

ll add( ll x , ll y ) {
	return ( x + y ) % mod ;
}

ll power( ll a , ll b ) {
	int ans = 1 , base = a ;
	while( b ) {
		if( b&1 ) ans = mul( ans , base ) ;
		base = mul( base , base ) ; 
		b >>= 1 ;
	}
	return ans ;
}

ll inv( ll x ) {
	return power( x , mod - 2 ) % mod ;
}

ll C( ll x , ll y ) {
	return ( fac[ x ] * ifac[ y ] % mod * ifac[ x - y ] % mod ) % mod ;
}

int main() {
	scanf( "%d%d%d" , &n , &m , &k ) ;
	fac[ 0 ] = 1ll ;
	p[ 0 ] = 1ll ;
	for( int i = 1 ; i < N ; i ++ ) {
		fac[ i ] = fac[ i - 1 ] * i % mod ;
		p[ i ] = p[ i - 1 ] * 3ll % mod ;
	}
	for( int i = 0 ; i < N ; i ++ ) {
		ifac[ i ] = inv( fac[ i ] ) ;
	}
	ll ans = 0 , x = 1ll ;
	n -- ;
	for( int i = 0 ; i <= m + k ; i ++ ) {
		ans = ( ans + C( n + i , n ) * p[ m + k - i ] % mod * x )  % mod  ;
		
		for( int j = 0 ; j <= min( i , m - 1 ) ; j ++ ) {
			if( i  < k ) x = add( x , C( i , j ) ) ;
			else if( i < m ) x = add( x , C( i , i - k + 1 ) ) ;
			else x = add( x , C( i , j ) ) ;
		}
		/*
		if( i < k ) x = ( x * 2ll ) % mod ;
		else if( i < m ) x = ( x * 2ll - C( i , k ) ) % mod ;
		else  x = ( x * 2ll - C( i , k ) - C( i , m ) ) % mod ;
		*/
	}
	printf( "%lld\n" , add( ans , mod ) ) ;
	return 0 ;
} 

