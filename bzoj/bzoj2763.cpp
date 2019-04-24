#include <bits/stdc++.h>

using namespace std ;

#define N 1000010
#define inf 0x3f3f3f3f

int n , m , k , s , t ;
int cnt , head[ N ] ;
int q[ N ] , d[ N ][ 11 ] ;
bool vis[ N ] ;
struct node {
	int to , nxt , v ;
}e[ N ] ;

void ins( int u , int v , int w ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	e[ cnt ].v = w ;
	head[ u ] = cnt ;
}

void spfa() {
	memset( d , 0x3f , sizeof( d ) ) ;
	for( int i = 0 ; i <= k ; i ++ ) d[ s ][ i ] = 0 ;
	q[ 1 ] = s ;vis[ s ] = 1 ;
	int l = 1 , r = 2 ;
	while( l != r ) {
		int u = q[ l ++ ] ;
		vis[ u ] = 0 ;
		if( l == 500000 ) l = 1 ;
		for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
			int v = e[ i ].to ,now = 0 ;
			for( int j = 0 ; j <= k ; j ++ ) {
				if( !j ) now = d[ u ][ j ] + e[ i ].v ;
				else now = min( d[ u ][ j - 1 ] , d[ u ][ j ] + e[ i ].v ) ;
				if( d[ v ][ j ] > now ) {
					d[ v ][ j ] = now ;
					if( !vis[ v ] ) vis[ v ] = 1 , q[ r ++ ] = v ;
					if( r == 500000 ) r = 1 ;
				}
			}
		}
	}
}

int main() {
	scanf( "%d%d%d%d%d" , &n , &m , &k , &s , &t ) ;
	s ++ ; t ++ ;
	for( int i = 1 ; i <= m ; i ++ ) {
		int u , v , w ;
		scanf( "%d%d%d" , &u , &v , &w ) ;
		u ++ , v ++ ;
		ins( u , v , w ) ;
		ins( v , u , w ) ;
	}
	spfa() ;
	int ans = inf ;
	for( int i = 0 ; i <= k ; i ++ ) {
		ans = min( ans , d[ t ][ i ] ) ;
	}
	printf( "%d\n" , ans ) ;
	return 0 ;
}
