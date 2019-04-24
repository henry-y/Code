#include <bits/stdc++.h>

using namespace std ;

#define N 5000

int n , m ;
int f[ N ] , a[ N ] ;

int find( int x ) {
	if( f[ x ] == x ) {
		return x ;
	}return f[ x ] = find( f[ x ] ) ;
}

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= 2 * n ; i ++ ) f[ i ] = i ;
	for( int i = 1 ; i <= m ; i ++ ) {
		char ch[ 10 ] ;
		int x , y ;
		scanf( "%s%d%d" , ch , &x , &y ) ;
		if( ch[ 0 ] == 'F' ) f[ find( y ) ] = find( x ) ;
		else {
			f[ find( y + n ) ] = find( x ) ;
			f[ find( x + n ) ] = find( y ) ;
		}
	}
	int ans = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) f[ i ] = find( i ) ;
	sort( f + 1 , f + n + 1 ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( f[ i ] != f[ i - 1 ] ) ans ++ ;
	}
	printf( "%d\n" , ans ) ;
} 
