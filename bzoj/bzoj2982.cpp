#include <bits/stdc++.h>

using namespace std ;

const int mod = 10007 ;

int t , n , m ;
int fac[ mod + 10 ] , ifac[ mod + 10 ] ; 

int power( int a , int b ) {
	int ans = 1 , base = a ;
	while( b ) {
		if( b & 1 ) ans = ans * base % mod ;
		base = base * base % mod ;
		b >>= 1 ;
	}
	return ans ;
}

int lucas( int a , int b ) {
	if( a > b ) return 0 ;
	if( b <= mod ) return fac[ b ] % mod * ifac[ a ] % mod * ifac[ b - a ] % mod ;
	return lucas( a % mod , b % mod ) % mod * lucas( a / mod , b / mod ) % mod ;
}

int main() {
	scanf( "%d" , &t ) ;
	fac[ 0 ] = 1 ; 
	for( int i = 1 ; i <= mod ; i ++ ) fac[ i ] = fac[ i - 1 ] * i % mod ;
	for( int i = 0 ; i <= mod ; i ++ ) ifac[ i ] = power( fac[ i ] , mod - 2 ) % mod ;
	while( t -- ) {
		scanf( "%d%d" , &n , &m ) ;
		printf( "%d\n" , lucas( m , n ) ) ;
	}
	return 0 ;
} 
