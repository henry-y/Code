#include <bits/stdc++.h>

using namespace std ;

#define N 50000

int n , k , m ;
int f[ N ] ;
struct node {
	int x , y , c1 , c2 ;
} e[ N ] ;

int find( int x ) {
	if( f[ x ] == x ) {
		return x ;
	}return f[ x ] = find( f[ x ] ) ;
}

bool check( int t ) {
	for( int i = 1 ; i <= n ; i ++ ) f[ i ] = i ;
	int cnt = 0 ;
	for( int i = 1 ; i < m ; i ++ ) {
		if( e[ i ].c1 > t ) continue ;
		int x = find( e[ i ].x ) , y = find( e[ i ].y ) ;
		if( x != y ) f[ y ] = x , cnt ++ ; 
	}
	if( cnt < k ) return 0 ;
	for( int i = 1 ; i < m ; i ++ ) {
		if( e[ i ].c2 > t ) continue ;
		int x = find( e[ i ].x ) , y = find( e[ i ].y ) ;
		if( x != y ) f[ y ] = x , cnt ++ ;
	}
	if( cnt != n - 1 ) return 0 ;
	return 1 ;
}

int main() {
	scanf( "%d%d%d" , &n , &k , &m ) ;
	for( int i = 1 ; i < m ; i ++ ) {
		int x , y , v  , v2 ;
		scanf( "%d%d%d%d" , &x , &y , &v , &v2 ) ;
		e[ i ] = ( node ) { x , y , v , v2 } ;
	}
	int l = 1 , r = 30000 , ans = 0 ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ;
		if( check( mid ) ) r = mid - 1 , ans = mid ;
		else l = mid + 1 ; 
	}
	printf( "%d\n" , ans ) ;
} 
