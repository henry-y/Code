#include <bits/stdc++.h>

using namespace std ;

#define N 200010
const int inf = 1e10 ;

inline void read( int &x ) {
	x = 0 ; int f = 1 ; char c = getchar() ;
	while( c < '0' || c > '9' ) { if( c == '-' ) f = -f ; c = getchar() ; }
	while( c >= '0' && c <= '9' ) { x = (x<<1) + (x<<3) + c - 48 ; c =getchar() ; } 
	x = x * f ;
}

int n , m1, m2 , s ;
int head[ N ] , cnt ;
int d[ N ] , vis[ N ] ;
struct edge {
	int to , nxt ,v ;
}e[ N ] ;

deque < int > q ;

void ins( int u , int v , int w ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	e[ cnt ].v = w ;
	head[ u ] = cnt ;
}

void spfa() {
	vis[ s ] = 1 ;
	for( int i = 1 ; i <= n ; i ++ ) d[ i ] = inf ;
	d[ s ] = 0 ;
	q.push_back( s ) ;
	while( !q.empty() ) {
		int u = q.front() ;
		q.pop_front() ;
		vis[ u ] = 0 ;
		for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
			int v = e[ i ].to ;
			if( d[ v ] > d[ u ] + e[ i ].v ) {
				d[ v ] = d[ u ] + e[ i ].v ;
				if( ! vis[ v ] ) {
					vis[ v ] = 1 ;
					if( !q.empty() && d[ v ] >= d[ q.front() ] ) q.push_back( v ) ;
					else q.push_front( v ) ;
				}
			}
		}
	}
}

int main() {
	read( n ) ; read( m1 ) ; read( m2 ) ; read( s ) ;
	for( int i = 1 ; i <= m1 ; i ++ ) {
		int u , v , w ;
		read( u ) ; read( v ) ; read( w ) ;
		ins( u , v , w ) ;
		ins( v , u , w ) ;
	}
	for( int i = 1 ; i <= m2 ; i ++ ) {
		int u , v , w ;
		read( u ) ;read( v ) ; read( w ) ;
		ins( u ,v , w ) ;
	}
	spfa() ;
	for( int i = 1 ; i <= n ; i ++ ){
		if( d[ i ] == inf ) {
			puts( "NO PATH" ) ;
		}else printf( "%d\n" , d[ i ] ) ;
	}
	return 0 ;
} 
