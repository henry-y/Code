#include <bits/stdc++.h>

using namespace std ;

#define N 1000010
#define ll long long

const ll mod = 1e9 + 7 ;
ll fac[ N ] ,ifac[ N ] ;
ll n , m ;
ll q[ N ] , cnt = 0 ;
map<int,int> mp ;

ll power( ll a , ll b ) {
	ll ans = 1 , base = a ; 
	while( b ) {
		if( b&1 ) ans = ( ans * base ) % mod ;
		base = ( base * base ) % mod ;
		b >>= 1 ;
	}
	return ans ;
}

ll C( ll n , ll m ) {
	return fac[ m ] * ifac[ n ] % mod * ifac[ m - n ] % mod ;
}

int main() {
	scanf( "%lld%lld" , &n , &m ) ;
	fac[ 0 ] = 1 ; 
	for( int i = 1 ; i < N ; i ++ ) fac[ i ] = ( fac[ i - 1 ] * i ) % mod ;
	for( int i = 0 ; i < N ; i ++ ) ifac[ i ] = power( fac[ i ] , mod - 2 ) % mod ;
	ll ln = m , tmp = 2 ; 
	while( ln != 1 && tmp * tmp <= ln ) {
		if( ln % tmp == 0 ) {
			mp[ tmp ] ++ ;
			if( mp[ tmp ] == 1 ) q[ ++ cnt ] = tmp ;
			ln /= tmp ;
	 	}else tmp ++ ;
	}
	if( ln != 1 ) {
		mp[ ln ] ++ ;
		if( mp[ ln ] == 1 ) q[ ++ cnt ] = ln ;
	} 
	ll ans = 1 ;
	for( int i = 1 ; i <= cnt ; i ++ ) {
		ans = ans * C( n - 1 , mp[ q[ i ] ] + n - 1 ) % mod ;
	}
	printf( "%lld\n" , ans ) ;
	return 0 ;
}
