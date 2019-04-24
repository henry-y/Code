#include <bits/stdc++.h>

using namespace std ;

#define ll long long
#define N 500010

int n , m ;
ll a[ N ] , c[ N ] , ans = 0 ;
bool vis[ N ] ;
 
int main() {
	scanf( "%d%d" , &n , &m ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		scanf( "%lld" , &a[ i ] ) ;
		c[ i ] = c[ i - 1 ] ^ a[ i ] ;
	}	
	for( int i = 62 ; i >= 0 ; i -- ) {
		int cnt = 0 ;
		for( int j = 1 ; j <= n ; j ++ ) {
			if( !vis[ j ] && ( c[ j ] & ( 1ll << i ) ) == 0 ) cnt ++ ;
		}
		if( cnt >= m && ( c[ n ] & ( 1ll << i ) ) == 0 ) {
			for( int j = 1 ; j <= n ; j ++ ) {
				if( ( c[ j ] & ( 1ll << i ) ) != 0 ) vis[ j ] = 1 ;
			}
		}else ans = ans | ( 1ll << i ) ;
	}
	printf( "%lld\n" ,  ans ) ;
	return 0 ;
} 
