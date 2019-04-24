#include <bits/stdc++.h>

using namespace std ;

#define N 2010
#define ll long long

int n , f[ N ] ;
struct node {
	int x , y ;
	ll val ;
} a[ N * N ] ;

int find( int x ) {
	if( f[ x ] == x ) return x ;
	return f[ x ] = find( f[ x ] ) ;
}

bool cmp( node a ,node b ) {
	return a.val < b.val ;
}

int main() {
	int tot = 0 ;
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = i ; j <= n ; j ++ ) {
			a[ ++ tot ].x = i - 1 ;
			a[ tot ].y = j ;
			scanf( "%lld" ,&a[ tot ].val ) ;	
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) f[ i ] = i ;
	sort( a + 1 , a + tot + 1 , cmp ) ;
	int sum = 0 ;
	ll ans = 0 ;
	for( int i = 1 ; i <= tot ; i ++ ) {
		int u = find( a[ i ].x ) , v = find( a[ i ].y ) ;
		if( u != v ) {
			f[ v ] = u ;
			sum ++ ; 
			ans += a[ i ].val ;
			if( sum == n ) break ;
		} 
	}
	printf( "%lld\n" , ans ) ;
	return 0 ;
}
