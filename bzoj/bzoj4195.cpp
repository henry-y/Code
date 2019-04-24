#include <bits/stdc++.h>

using namespace std ;

#define N 2000100
const int mod = 1000007 ; 

int T , n ;
int f[ 2 * N ] ; 
int a[ N ] , b[ N ] ;

int find( int x ) {
	if( f[ x ] == x ) return x ;
	else return f[ x ] = find( f[ x ] ) ;
}

int main() {
	scanf( "%d" , &T ) ;
	while( T -- ) {
		int cnt = 0 ;
		scanf( "%d" , &n ) ; 
		for( int i = 1 ; i < N ; i ++ ) f[ i ] = i ;
		for( int i = 1 ; i <= n ; i ++ ) {
			int x , y , opt ;
			scanf( "%d%d%d" , &x , &y , &opt ) ;
			x %= mod ; y %= mod ;
			if( opt == 0 ) a[ ++ cnt ] = x , b[ cnt ] = y ;
			else f[ find( x ) ] = find( y ) ; 
		}
		bool check = 0 ;
		for( int i = 1 ; i <= cnt ; i ++ ) {
			if( find( a[ i ] ) == find( b[ i ] ) ) {
				puts( "NO" ) ;
				check = 1 ;
				break ;
			}
		}
		if( ! check ) puts( "YES" ) ;
	}
	return 0 ;
}
