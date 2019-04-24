#include <bits/stdc++.h> 

using namespace std ;

#define N 210010

int n , x ;
int a[ N ] , f[ N ] , g[ N ] , now[ N ] ;

int main() {
	scanf( "%d%d" , &n , &x ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &a[ i ] ) ;
	}
	memset( now , 0x3f , sizeof( now ) ) ;
	int m = 1 ;
	now[ 1 ] = a[ 1 ] ; f[ 1 ] = 1 ;
	for( int i = 2 ; i <= n ; i ++ ) {
		if( a[ i ] > now[ m ] ) {
			now[ ++ m ] = a[ i ] ;
			f[ i ] = m ;
		} else if( a[ i ] + x > now[ m ] ) {
			f[ i ] = m + 1 ;
			int t = lower_bound( now + 1 , now + m + 1 , a[ i ] ) - now ;
			now[ t ] = a[ i ] ;
		} else {
			int t = lower_bound( now + 1 , now + m + 1 , a[ i ] ) - now ;
			f[ i ] = lower_bound( now + 1 , now + m + 1 , a[ i ] + x ) - now ;
			now[ t ] = a[ i ] ;
		}
	}
	int ans = m ;
	m = 1 ; 
	memset( now , 0x3f , sizeof( now ) ) ;
	g[ n ] = 1 ; 
	now[ 1 ] = -a[ n ] ;
	ans = max( ans , f[ n ] + g[ n ] - 1 ) ;
	for( int i = n - 1 ; i >= 1 ; i -- ) {
		if( -a[ i ] > now[ m ] ) {
			now[ ++ m ] = -a[ i ] ;
			g[ i ] = m ;
		} else {
			int t = lower_bound( now + 1 , now + m + 1 , -a[ i ] ) - now ;
			g[ i ] = t ;
			now[ t ] = -a[ i ] ;
		}
		ans = max( ans , f[ i ] + g[ i ] - 1 ) ;
	}
	printf( "%d\n" , ans ) ;
}
