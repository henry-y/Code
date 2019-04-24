#include <bits/stdc++.h>

using namespace std ;

#define N 400010

int n , k , head[ N ] , cnt , s ;
int a[ N ] , fa[ N ] ;
int dep[ N ] , siz[ N ] , top[ N ] ;
int mx[ N ] ;
struct node {
	int to , nxt ;
} e[ N ] ;
vector < int > vt[ N ] ;

void ins( int u , int v ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ;
	head[ u ] = cnt ;
}

void dfs1( int u ) {
	siz[ u ] = 1 ;
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( e[ i ].to == fa[ u ] ) continue ;
		dep[ e[ i ].to ] = dep[ u ] + 1 ;
		dfs1( e[ i ].to ) ;
		siz[ u ] += siz[ e[ i ].to ] ;
	}
}

void dfs2( int u , int topf ) {
	top[ u ] = topf ;
	int k = 0 ;
	for( int i = head[ u ] ;  i ; i = e[ i ].nxt ) {
		if( e[ i ].to == fa[ u ] ) continue ;
		if( siz[ e[ i ].to ] > siz[ k ] ) k = e[ i ].to ;
	}
	if( !k ) return ;
	dfs2( k , topf ) ;
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( e[ i ].to == k || e[ i ].to == fa[ u ] ) continue ;
		dfs2( e[ i ].to , e[ i ].to ) ;
	}
}

int lca( int x , int y ) {
	while( top[ x ] != top[ y ] ) {
		if( dep[ top[ x ] ] < dep[ top[ y ] ] ) swap( x , y ) ;
		x = fa[ top[ x ] ] ;
	}
	if( dep[ x ] > dep[ y ] ) swap( x , y ) ;
	return x ;
}

bool cmp( int a , int b ) {
	return dep[ a ] > dep[ b ] ;
}

int main() {
	scanf( "%d%d" , &n , &k ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		int p ;
		scanf( "%d%d" , &a[ i ] , &p ) ;
		fa[ i ] = p ;
		if( p ) ins( i , p ) , ins( p , i ) ;
		vt[ a[ i ] ].push_back( i ) ;
		if( p == 0 ) s = i ;
	}
	dfs1( s ) ;
	dfs2( s , s ) ;
	for( int i = 1 ; i <= k ; i ++ ) {
		int ans = 0 ;
		sort( vt[ i ].begin() , vt[ i ].end() , cmp ) ;
		for( int j = 1 , len = vt[ i ].size() ; j < len ; j ++ ) {
			int l = lca( vt[ i ][ 0 ] , vt[ i ][ j ] ) ;
			ans = max( ans , dep[ vt[ i ][ 0 ] ] + dep[ vt[ i ][ j ] ] - 2 * dep[ l ] ) ;
		}
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}
