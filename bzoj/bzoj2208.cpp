#include <bits/stdc++.h>

using namespace std ;

#define N 2010
#define ll long long 

int n , head[ N ] , cnt , vis[ N ] ;  
struct node {
	int to , nxt ;
}e[ N * N ] ;

void ins( int u , int v ) {
	e[ ++ cnt ].to = v ;
	e[ cnt ].nxt = head[ u ] ; 
	head[ u ] = cnt ; 
}

ll find( int u ) {
	ll ans = 1 ;
	vis[ u ] = 1 ;
	for( int i = head[ u ] ; i ; i = e[ i ].nxt ) {
		if( vis[ e[ i ].to ] ) continue ;
		ans += find( e[ i ].to ) ;
	}
	return ans ;
}

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		char ch[ 2010 ] ;
		scanf( "%s" , ch + 1 ) ;
		for( int j = 1 ; j <= n ; j ++ ) {
			if( ch[ j ] == '1' ) {
				ins( i , j ) ; 
			}
		}
	}
	ll ans = 0 ;
	for( int i = 1 ; i <= n ; i ++ ) {
		memset( vis , 0 ,sizeof( vis ) ) ;
		ans += find( i ) ;
//		printf( "Case #%d : %d\n" , i , ans - t ) ;
	}
	printf( "%lld\n" , ans ) ;
	return 0 ;
} 
