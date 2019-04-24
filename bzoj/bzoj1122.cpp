#include <bits/stdc++.h>

using namespace std ;

#define ll long long
const int N = 2e6 + 10 ;

ll n , p , q , x , y ;
char s[ N ] ;
ll a[ N ] , b[ N ]; 
ll sum[ N ] ;
deque <int> Q ; 

int main() {
	scanf( "%lld%lld%lld%lld%lld" , &n , &p , &q , &x , &y ) ;
	scanf( "%s" , s + 1 ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		a[ i ] = s[ i ] == '+' ? 1 : -1 ;
		a[ i + n ] = a[ i ] ;
	}
	for( int i = n * 2 ; i ; i -- ) {
		sum[ i ] = sum[ i + 1 ] + a[ i ] ;
	}
	for( int i = n * 2 ; i ; i -- ) {
		if( i <= n ) b[ i ] = sum[ i ] - sum[ Q.back() ] ;
		while( !Q.empty() && sum[ Q.front() ] <= sum[ i ] ) Q.pop_front() ;
		Q.push_front( i ) ;
		while( Q.back() >= i + n ) Q.pop_back() ;
	}
	ll ans = 0x7fffffff ;
	for( int i = 1 ; i <= n ; i ++ ) {
		ll now =  y * ( ( n - i + 1 ) % n ) ;
		if( p + sum[ n + 1 ] >= q ) now += ( p + sum[ n + 1 ] - q ) / 2 * x ;
		else {
			now += ( q- p - sum[ n + 1 ] ) / 2 * x ;
			b[ i ] += ( q - p - sum[ n + 1 ] ) ;
		}
		if( p + b[ i ] < 0 ) now -= ( p + b[ i ] - 1 ) / 2 * 2  * x ;
		ans = min( ans , now ) ;
	}
	printf( "%lld\n" , ans ) ;
}
