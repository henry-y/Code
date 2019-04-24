#include <bits/stdc++.h>

using namespace std ;

int n ;
struct node {
	int l , r ;
}a[ 100000 ] ;

bool cmp ( node a , node b ) {
	return a.r < b.r ;
}

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf( "%d%d" , &a[i].l , &a[i].r ) ;
		a[i].r += a[i].l ; 
	}
	sort( a + 1 , a + n + 1 , cmp ) ;
	int ans = 1 , now = a[ 1 ].r ;
	for( int i = 2 ; i <= n ; i ++ ){
		if( now <= a[ i ].l ) ans ++ , now = a[ i ].r ;
	}
	printf( "%d" , ans ) ;
	return 0;
}
