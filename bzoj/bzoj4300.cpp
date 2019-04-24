#include <bits/stdc++.h>

using namespace std ;

#define N 100010

int n , ans ;
int a[ N ] , f[ 40 ] ;

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) scanf( "%d" , &a[ i ] ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		int tmp = 0 ;
		for( int j = 0 ; j <= 30 ; j ++ ) {
			if( a[ i ] & ( 1 << j ) ) tmp = max( tmp , f[ j ] + 1 ) ;
		}
		for( int j = 0 ; j <= 30 ; j ++ ) {
			if( a[ i ] & ( 1 << j ) ) f[ j ] = tmp ;
		}
		ans = max( ans , tmp ) ;
	}
	printf( "%d\n" , ans ) ;
} 
