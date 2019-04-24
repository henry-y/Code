#include <bits/stdc++.h>

using namespace std ;

#define N 1000010

int n , k ;
int last[ N ] ;
struct node {
	int id , x ;
}a[ N ] ;

bool cmp( node a , node b ) {
	return a.x < b.x ;
}

int main() {
	scanf( "%d%d" , &n , &k ) ;
	int tot = 0 ;
	for( int i = 1 ; i <= k ; i ++ ) {
		int t ;
		scanf( "%d" , &t ) ;
		for( int j = 1 ; j <= t ; j ++ ) {
			scanf( "%d" , &a[ ++ tot ].x ) ;
			a[ tot ].id = i ;
		}
	}
	sort( a + 1 , a + n + 1 , cmp ) ;
	int l = 1 , ans = a[ n ].x - a[ 1 ].x , cnt = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		if( !last[ a[ i ].id ] ) cnt ++ ;
		last[ a[ i ].id ] = a[ i ].x ; 
		while( last[ a[ l ].id ] != a[ l ].x && l <= i ) l ++ ;
		if( cnt == k && a[ i ].x - a[ l ].x < ans ) ans = a[ i ].x - a[ l ].x ;
	}
	printf( "%d\n" , ans ) ;
	return 0 ; 
}
