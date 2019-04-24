#include <cstdio>
#include <set>

using namespace std ;

#define N 100010

int f[ N ] , g[ N ] ;
int n , a[ N ] ;
bool vis[ N ] ;
set< int > s , t ;

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ] ) ;
		vis[ a[ i ] ] = 1 ;
	}
	for( int i = 1 ; i <= 2 * n ; i ++ ) {
		if( ! vis[ i ] ) s.insert( i ) , t.insert( -i ) ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		set< int > :: iterator it  = s.upper_bound( a[ i ] ) ;
		if( it != s.end() ) f[ i ] = f[ i - 1 ] + 1 , s.erase( *it ) ;
		else f[ i ] = f[ i - 1 ] ;
	}
	for( int i = n ; i ; i -- ) {
		set< int > :: iterator it = t.upper_bound( -a[ i ] ) ;
		if( it != t.end() ) g[ i ] = g[ i + 1 ] + 1 , t.erase( *it ) ;
		else g[ i ] = g[ i + 1 ] ;
	}
	int ans = 0 ;
	for( int i = 0 ; i <= n ; i ++ ) {
		ans = max( ans , f[ i ] + g[ i + 1 ] ) ;
	}
	printf( "%d\n" , ans ) ;
}
