#include <cstdio>

int n , tot , t , x ;

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &x ) ;
		if( x == t ) tot ++ ;
		else if( !tot ) t = x , tot = 1 ;
		else tot -- ;
	}
	printf( "%d\n" , t ) ;
}
