#include <bits/stdc++.h>

using namespace std ;

char s[ 100010 ] ;

int main() {
	scanf( "%s" , s + 1 ) ;
	int n = strlen( s + 1 ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( s[ i ] == s[ i + 2 ] ) {
			printf( "%d %d\n" , i , i + 2 ) ;
			return 0 ;
		}
		if( s[ i ] == s[ i + 1 ] ) {
			printf( "%d %d\n" , i , i + 1 ) ;
			return 0 ;
		}
	}
	puts( "-1 -1" ) ;
	return 0 ;
}
