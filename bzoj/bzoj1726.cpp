#include <bits/stdc++.h>

using namespace std ;

#define N 200010
#define inf 0x3f3f3f3f

int n , m ;
int d[ N ][ 2 ] , vis[ N ] , q[ N ] ;
// 0最短路 ， 1次短路 
int head[ N ] , cnt ;
struct node {
	int to , nxt , v ;
} e[ N ] ;

void ins( int u , int v , int w ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	e[ cnt ].v = w ;
	head[ u ] = cnt ;
}

void spfa() {
	int l = 1 , r = 2 ;
	for( int i = 1 ; i <= n ; i ++ ) d[ i ][ 0 ] = d[ 1 ][ 1 ] = inf ;
	q[ l ] = 1 ; vis[ 1 ] = 1 ; d[ 1 ][ 0 ] = d[ 1 ][ 1 ] = 0 ; 
	while( l != r ) {
		int u = q[ l ++ ] ;
		if( l == 200000 ) l = 1 ;
		vis[ u ] = 0 ;
		for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
			int v = e[ i ].to ;
			if( d[ v ][ 0 ] > d[ u ][ 0 ] + e[ i ].v ) {
				d[ v ][ 1 ] = d[ v ][ 0 ] ;
				d[ v ][ 1 ] = d[ u ][ 0 ] + e[ i ].v ;
				if( !vis[ v ] ) {
					vis[ v ] = 1 , q[ r ++ ] = v ;
					if( r == 200000 ) r = 1 ;
				}
			} else {
				d[ v ][ 1 ] = min( d[ v ][ 1 ] , d[ u ][ 0 ] + e[ i ].v ) ;
			}
		}
	}
}

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 , u , v , w ; i <= m ; i ++ ) {
		scanf( "%d%d%d" , &u , &v , &w ) ;
		ins( u , v , w ) ; ins( v , u , w ) ;
	}
	spfa() ;
	printf( "%d\n" , d[ n ][ 1 ] ) ;
}
