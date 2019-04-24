#include <bits/stdc++.h>

using namespace std ;

#define N 100010

int n , a[ N ] ;
int vis[ N ] ;

set < int > st ;

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) scanf( "%d" , &a[ i ] ) , vis[ a[ i ] ] = 1 ;
	for( int i = 1 ; i <= 2 * n ; i ++ ) {
		if( !vis[ i ] ) {
			st.insert( i ) ;
		} 
	}
	int ans = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		set< int > :: iterator it = st.upper_bound( a[ i ] ) ;
		if( it != st.end() ) {
			ans ++ ;
			st.erase( *it ) ;
		}
	}
	printf( "%d\n" , ans ) ;
	return 0 ;
} 
