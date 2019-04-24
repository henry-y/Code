#include <bits/stdc++.h>

using namespace std ;

#define N 4000100
#define ll long long

int n , m , c[ N ] , fa[ N ] , ans = 0 ;
vector <int> e[ N ] ;

bool cmp( int a , int b ) { 
	return c[ a ] < c[ b ] ;
}

void dfs( int u ) {
	for( int i = 0 , len = e[ u ].size() ; i < len ; i ++ ) {
		dfs( e[ u ][ i ] ) ;
	}
	sort( e[ u ].begin() , e[ u ].end() , cmp ) ;
	c[ u ] += e[ u ].size() ;
	for( int i = 0 , len = e[ u ].size() ; i < len ; i ++ ) {
		if( c[ e[ u ][ i ] ] + c[ u ] - 1 <= m ) {
			c[ u ] += c[ e[ u ][ i ] ] - 1 ;
			ans ++ ; 
		} else break ;
	}
}

int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%d" , &c[ i ] ) ;
	} 
	for( int i = 1 ; i <= n ; i ++ ) {
		int k , x ;
		scanf( "%d" , &k ) ; 
		for( int j = 1 ; j <= k ; j ++ ) {
			scanf( "%d" , &x ) ;
			x ++ ;
			e[ i ].push_back( x ) ;
		}
	}
	dfs( 1 ) ;
	printf( "%d\n" , ans ) ;
} 
