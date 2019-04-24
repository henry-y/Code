#include <bits/stdc++.h>

using namespace std ;

#define N 1000010

int n , m ;
int head[ N ] , cnt ; 
int d[ N ] , vis[ N ] ;
bool check ;
struct node {
    int to , nxt , v ;
}e[ N ] ;

void ins( int u , int v , int w ) {
    e[ ++ cnt ].to = v ;
    e[ cnt ].nxt = head[ u ] ;
    e[ cnt ].v = w ;
    head[ u ] = cnt ;
} 

void dfs( int u ) {
	vis[ u ] = 1 ;
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		int v = e[ i ].to ;
		if( d[ v ] > d[ u ] + e[ i ].v ) {
			if( check || vis[ v ] ) {
				check = 1 ;
				break ;
			}
			d[ v ] = d[ u ] + e[ i ].v ;
			dfs( v ) ;
		} 
	}
	vis[ u ] = 0 ;
}

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		int  opt , a , b , c ;
		scanf( "%d%d%d" , &opt , &a , &b ) ;
		if( opt == 1 ) {
			scanf( "%d" , &c ) ;
			ins( a , b , -c ) ;
		}else if( opt == 2 ) {
			scanf( "%d" , &c ) ;
			ins( b , a , c ) ;
		}else {
			ins( a , b , 0 ) ;
			ins( b , a , 0 ) ;
		}
	}
	memset( d , 0x3f , sizeof( d ) ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		d[ i ] = 0 ;
		dfs( i ) ;
	}
	if( check ) puts( "No" ) ;
	else puts( "Yes" ) ;
}
