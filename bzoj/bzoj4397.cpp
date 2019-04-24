#include <bits/stdc++.h>

using namespace std ;

#define N 100010 

int n , m ;
int c[ N ][ 4 ] ;

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		c[ i ][ 1 ] = c[ i - 1 ][ 1 ] ;
		c[ i ][ 2 ] = c[ i - 1 ][ 2 ] ;
		c[ i ][ 3 ] = c[ i - 1 ][ 3 ] ;
		int x ;
		scanf( "%d" , &x ) ;
		c[ i ][ x ] ++ ;
	} 
	for( int i = 1 ; i <= m ; i ++ ) {
		int a , b ;
		scanf( "%d%d" , &a , &b ) ;
		if( a > b ) swap( a , b ) ;
		printf( "%d %d %d\n" , c[ b ][ 1 ] - c[ a - 1 ][ 1 ] , c[ b ][ 2 ] - c[ a - 1 ][ 2 ] , c[ b ][ 3 ] - c[ a - 1 ][ 3 ] ) ;
	}
	return 0 ;
} 
