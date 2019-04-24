#include <bits/stdc++.h>

using namespace std ;

#define N 100010
#define ll long long

int n , m ;
int c[ N ] ;
ll ans = 0 ;

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <=n ; i ++ ) {
		scanf( "%d" , &c[ i ] ) ;
		ans -= c[ i ] ;
		c[ i ] *= 2 ;
	}	
	for( int i = 1 ; i <= m ; i ++ ) {
		int x , y , z ; 
		scanf( "%d%d%d" , &x , &y , &z ) ;
		c[ x ] += z ; c[ y ] += z ;
		ans -= z ;
	}
	sort( c + 1 , c + n + 1 ) ;
	for( int i = n ; i ; i -= 2 ) {
		ans += c[ i ] ;
	}
	printf( "%lld\n" , ans ) ;
	return 0 ;
} 
