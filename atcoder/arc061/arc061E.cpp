#include <bits/stdc++.h>

using namespace std ;

#define N 500010
#define inf 0x3f3f3f3f

struct node {
	int to , nxt , belong ;
}e[ N << 2 ];

int n , m ; 
int head[ N << 2 ] , cnt ;


int d[ N * 2 ]  ;

void ins( int u , int v , int c ) {
	e[ ++ cnt ].to = v ;
	e[  cnt ].nxt = head[ u ] ;
	e[ cnt ].belong = c ;
	head[ u ] = cnt ;
}

std::set< int > st[ N ] ;
priority_queue< pair<int,int> > q;

void spfa() {
	for( int i = 1 ; i <= n ; i ++ ) d[ i ] = inf ;
	d[ 1 ] = 0 ;
	q.push( { 0 , 1 } ) ;
	while(!q.empty()){
		int u = q.top().second , ans = -q.top().first;
		q.pop() ;
		if( d[ u ] < ans ) continue ;
		for( int i = head[ u ] ; i ; i =e[ i ].nxt ) {
			int v = e[ i ].to ;
			int num = ans + !st[ u ].count( e[ i ].belong ) ;
			if( d[ v ] > num ) {
				d[ v ] = num ;
				q.push( { -num , v } ) ;
				st[ v ].clear() ;
				st[ v ].insert( e[ i ].belong ) ;
			}else if( d[ v ] == num ) {
				st[ v ].insert( e[ i ].belong ) ;
			}
		}
	}
	if( d[ n ] == inf ) puts( "-1" ) ;
	else printf( "%d\n" , d[ n ] ) ;
}

int main() {
	scanf( "%d%d" , &n ,&m ) ;
	for( int i = 1 ; i <= m ; i ++ ) {
		int x , y , c ;
		scanf( "%d%d%d" , &x , &y , &c ) ;
		ins( x , y , c ) ;
		ins( y , x , c ) ;
	}
	spfa() ;
}

