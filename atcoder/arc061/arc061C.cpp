#include <bits/stdc++.h>

using namespace std ;

#define ll long long

ll ans = 0 , num = 0 ;
int vis[ 11 ] , n , a[ 11 ] ;
char s[ 11 ] ;

void dfs( int x ) {
	if( x == n ) {
		ll sum = a[ 1 ] ;
		for( int i = 1 ; i < n ; i ++ ) {
			if( vis[ i ] == 1 ) {
				ans += sum ;
				sum = a[ i + 1 ] ;
			}else sum *= 10 , sum += a[ i + 1 ] ;
		}
		ans += sum ;
		return ;
	}
	vis[ x ] = 1 ;
	dfs( x + 1 ) ;
	vis[ x ] = 0 ;
	dfs( x + 1 ) ;
}

int main() {
	scanf( "%s" , s + 1 ) ;
	for( int i = 1 , len = strlen( s + 1 ) ; i <= len ; i ++ ) {
		a[ i ] = s[ i ] - '0' ;
	}
	n = strlen( s + 1 ) ;
	dfs( 1 ) ;
	printf( "%lld\n" , ans ) ;
}
