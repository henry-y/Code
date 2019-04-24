#include <bits/stdc++.h>

using namespace std ;

#define N 1010
#define ll long long 

int n ;
ll c[ N ][ 4 ] ;
ll h[ N ] , ans = 0 ;
map< ll , ll > mp ;

ll hash( ll *a ) {
	ll res = 0 ;
	for( int i = 0 ; i < 4 ; i ++ ) {
		res |= ( a[ i ] << ( i * 10ll ) ) ;
	}
	return res ;
}

void upd( ll  x , ll d ) {
	for( int i = 0 ; i < 4 ; i ++ , x = ( ( x&1023ll ) << 30ll ) | ( x >> 10ll ) ) {
		mp[ x ] += d ;
	}
}

int main() {
	scanf( "%d" , &n ) ;
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = 0 ; j < 4 ; j ++ ) {
			scanf( "%lld" , &c[ i ][ j ] ) ;
		}
		h[ i ] = hash( c[ i ] ) ;
		upd( h[ i ] , 1ll ) ;
	}
	for( int i = 1 ; i <= n - 5 ; i ++ ) {
		upd( h[ i ] , -1ll ) ;
		for( int j = i + 1 ; j <= n ; j ++ ) {
			upd( h[ j ] , -1ll ) ;
			for( int a = 0 ; a < 4 ; a ++ ) {
				ll res = 1ll , val[ 4 ] ;
				bool check = 0 ;
				for( int b = 0 ; b < 4 ; b ++ ) {
					ll x[] = { c[ i ][ ( b + 1 ) & 3 ] , c[ i ][ b ] , c[ j ][ ( 3 - b + a ) & 3 ] , c[ j ][ ( 6 - b + a ) & 3 ] } ;
					val[ b ] = hash( x ) ;
					if( !mp.count( val[ b ] ) ) {
						check = 1 ; 
						break ;
					}
				}
				if( !check ) {
					for( int k = 0 ; k < 4 ; k ++ ) {
						res = res * mp[ val[ k ] ] ;
						upd( val[ k ] , -1ll ) ; 
					}
					ans += res ;
					for( int k = 0 ; k < 4 ; k ++ ) {
						upd( val[ k ] , 1ll ) ;
					}
				}
			}
			upd( h[ j ] , 1ll ) ; 
		}
	}
	printf( "%lld" , ans ) ;
}
