#include <bits/stdc++.h>

using namespace std ;

char s[ 100010 ] ;
int n ; 

int main() {
	scanf( "%s" , s + 1 ) ;
	n = strlen( s + 1 ) ;
	int cnt = 0 ;
	for( int i = 2 ; i <= n ; ) {
		if( s[ i ] != s[ i - 1 ] ) {
			cnt ++ ;
			i ++ ;
			while( s[ i ] == s[ i - 1 ] ) i ++ ;
		} else i ++ ; 
	}
	printf( "%d\n" , cnt ) ;
}
