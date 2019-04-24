#include <bits/stdc++.h>

using namespace std ;

#define N 500

int n ;
int t[ N ][ N ] ;
struct node {
	int x , id ;
} a[ N ] ;
int f[ N ] ;

bool cmp( node a , node b ){
	return a.x < b.x ;
}

int main(){
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf( "%d" , &a[ i ].x ) ;
		a[ i ].id = i ;
	}
	sort( a + 1 ,a + n + 1 , cmp ) ;
	for( int i = 1 ; i <= n ; i ++ ) 
		for( int j = 1 ; j <= n ; j ++ )
			scanf( "%d" , &t[i][j] ) ;
	int ans = 0 ;
	for( int i = 1 ; i <= n ; i ++ ){
		if( t[ 1 ][ a[ i ].id ] <= a[ i ].x ) f[ i ] = 1 ;
		for( int j = 1 ; j < i ; j ++ ){
			if( a[ j ].x + t[ a[ j ].id ][ a[ i ].id ] <= a[ i ].x ) f[ i ] = max( f[ i ] , f[ j ] + 1 ) ;
		}
		ans = max ( f[ i ] , ans ) ;
	}
	printf( "%d\n" , ans ) ;
	return 0 ;
}
