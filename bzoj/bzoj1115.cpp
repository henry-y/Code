#include <bits/stdc++.h>

using namespace std ;

#define N 200010

int n ;
int a[ N ] , c[ N ] ;

int main() {
	int t ;
	scanf( "%d" , &t ) ;
	while( t -- ) {
		scanf( "%d" , &n ) ;
		for( int i = 1 ; i <= n ; i ++ ) {
			scanf( "%d" , &a[ i ] ) ;
			c[ i ] = a[ i ] - a[ i - 1 ] ;
		}
		int x = 0 ;
		for( int i = n ; i >= 1 ; i -= 2 ) x = x ^ c[ i ] ;
		if( x ) puts( "TAK" ) ;
		else puts( "NIE" ) ;
	}
} 
