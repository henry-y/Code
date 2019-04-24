#include <bits/stdc++.h>

using namespace std ;

int n ;
int a[ 50 ][ 50 ] ;

int main() {
	int sum = 0 ;
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ][ i + 1 ] ) ;
		sum += a[ i ][ i + 1 ] ;
	}
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = i + 1 ; j <= n ; j ++ ) {
			a[ i ][ j ] = a[ i ][ j - 1 ] + a[ j - 1 ][ j ] ;
		}
	}
	int ans = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = i + 1 ; j <= n ; j ++ ) {
			for( int k = j + 1 ; k <= n  ; k ++ ) {
				for( int l = k + 1 ; l <= n ; l ++ ) {
					if( a[ i ][ j ] == a[ k ][ l ] && a[ j ][ k ] == sum - a[ i ][ l ] ) ans ++ ;
				}
			}
		}
	}
	printf( "%d\n" , ans ) ;
} 
